/****************************************************************
 *
 *        Copyright 2013, Big Switch Networks, Inc. 
 * 
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *        http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 ****************************************************************/

/**************************************************************************//**
 *
 *
 *
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_datatypes.h>
#include <AIM/aim_list.h>
#include "aim_int.h"


#if AIM_CONFIG_INCLUDE_MODULES_INIT == 1

int
aim_modules_init(void)
{
    /*
     * Call the module-init function for all modules.
     */
    int count = 0;

#define DEPENDMODULE_INIT(_mod)                      \
    {                                                \
        extern void __##_mod##_module_init__(void);  \
        __##_mod##_module_init__();                  \
        count++;                                     \
    }                                                \

#include <dependmodules.x>

    return count;
}

#endif /* AIM_CONFIG_INCLUDE_MODULES_INIT */




#if AIM_CONFIG_INCLUDE_MODULES_DENIT == 1

void
aim_modules_denit(void)
{
    /*
     * Call the module-denit function for all modules.
     */
#define DEPENDMODULE_DENIT(_mod)                        \
    {                                                   \
        extern void __##_mod##_module_denit__(void);    \
        __##_mod##_module_denit__();                    \
    }

#include <dependmodules.x>
}

#endif /* AIM_CONFIG_INCLUDE_MODULES_DENIT */



#if AIM_CONFIG_INCLUDE_MAIN == 1


#if AIM_CONFIG_INCLUDE_ENV_ARGV == 1

typedef struct arg_s {
    list_links_t links;
    char* arg;
} arg_t;

static void
env_args_replace__(const char* env_argv,
                   char* arg0,
                   int* rv_argc, char*** rv_argv)
{
    struct list_head args;
    char* s, *tok, *p, *saveptr = NULL;
    int count = 0, i;
    char** argv;
    list_links_t* cur;
    list_links_t* next;
    char d;

    /*
     * Build a list of argument tokens
     */
    list_init(&args);
    s = aim_strdup(env_argv);

    /*
     * Cheap quote escapes.
     * Replace all spaces between quotes with the ESC character.
     * They will be returned to their former (empty) glory after token parsing.
     */
#define ESC 0x8
    for(d = ' ', p = s; *p; p++) {
        if(*p == '"' && d == ' ') {
            *p = d;
            d = ESC;
        }
        else if(*p == '"' && d == ESC) {
            d = ' ';
            *p = ' ';
        }
        else if(*p == ' ') {
            *p = d;
        }
    }

    count = 0;
    tok = aim_strtok_r(s, " ", &saveptr);
    while(tok) {
        arg_t* a = aim_zmalloc(sizeof(*a));
        a->arg = aim_strdup(tok);
        /* Revert escaped spaces */
        for(p = a->arg; *p; p++) {
            if(*p == ESC) *p = ' ';
        }
        list_push(&args, &a->links);
        count++;
        tok = aim_strtok_r(NULL, " ", &saveptr);
    }

    /*
     * Allocate a new ARGV, copy arguments, free list.
     */
    argv = aim_zmalloc(sizeof(char*)*(count+2));
    argv[0] = arg0;
    i = 1;
    LIST_FOREACH_SAFE(&args, cur, next) {
        arg_t* a = container_of(cur, links, arg_t);
        argv[i++] = a->arg;
        AIM_FREE(a);
    }
    AIM_FREE(s);

    *rv_argc = count+1;
    *rv_argv = argv;
}

static void
env_args_free__(char** argv)
{
    char** p;
    /* We don't free arg[0], since this came from the original argv array */
    for(p = argv+1; *p; p++) {
        AIM_FREE(*p);
    }
    AIM_FREE(argv);
}

#endif /* AIM_CONFIG_INCLUDE_ENV_ARGV */

/* fixme */
char** __aim_argv__ = NULL;

int
main(int argc, char* argv[])
{
    int rv = 0;
    char* env_argv = NULL;
    extern int aim_main(int argc, char* argv[]);

    /*
     * The AIM module itself must be initialized first.
     */
    __aim_module_init__();

#if AIM_CONFIG_INCLUDE_ENV_ARGV == 1
    /* Only check if we received no command line arguments. */
    if(argc == 1) {
        env_argv = getenv(AIM_CONFIG_ENV_ARGV_NAME);
        if(env_argv) {
            env_args_replace__(env_argv, argv[0], &argc, &argv);
        }
    }
#endif

    __aim_argv__ = argv;

#if AIM_CONFIG_INCLUDE_MODULES_INIT == 1
    aim_modules_init();
#endif

    rv = aim_main(argc, argv);

#if AIM_CONFIG_INCLUDE_MODULES_DENIT == 1
    aim_modules_denit();
#endif

    __aim_module_denit__();

#if AIM_CONFIG_INCLUDE_ENV_ARGV == 1
    if(env_argv) {
        env_args_free__(argv);
    }
#endif

    AIM_REFERENCE(env_argv);

    return rv;
}

#endif /* AIM_CONFIG_INCLUDE_MAIN */









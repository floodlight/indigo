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

/******************************************************************************
 *
 *  /utest/main.c
 *
 *  AIM Unit Testing
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <AIM/aim_rl.h>

#define AIM_LOG_MODULE_NAME aim_utest
#include <AIM/aim_log.h>

AIM_LOG_STRUCT_DEFINE(1, 0xFFFF, NULL, 0);

extern int utest_list(void);

int aim_main(int argc, char* argv[])
{
    int i;

    {
        const char* tstStrings[] = { "This", "is", "a", "complete", "sentence." };
        char* join = aim_strjoin(" ", tstStrings, AIM_ARRAYSIZE(tstStrings));
        if(strcmp(join, "This is a complete sentence.")) {
            printf("fail: join='%s'\n", join);
        }
        AIM_FREE(join);
    }

    for(i = 0; i < argc; i++) {
        aim_printf(&aim_pvs_stdout, "arg%d: '%s'\n", i, argv[i]);
    }

    {
        /* Test data */
        char data[2500];
        memset(data, 0xFF, sizeof(data));
        aim_printf(&aim_pvs_stdout, "data is %{data}", data, sizeof(data));
    }

    utest_list();

    AIM_LOG_MSG("Should print 1-27");
    AIM_LOG_MSG("%d %d %d %d %d %d %d %d %d "
                "%d %d %d %d %d %d %d %d %d "
                "%d %d %d %d %d %d %d %d %d",
                1, 2, 3, 4, 5, 6, 7, 8, 9,
                10, 11, 12, 13, 14, 15, 16, 17, 18,
                19, 20, 21, 22, 23, 24, 25, 26, 27);


    aim_printf(&aim_pvs_stdout, "aim_pvs_stdout from %s:%d\n",
               __FILE__, __LINE__);


    {
        char c;
        aim_pvs_t* pvs = aim_pvs_buffer_create();
        aim_printf(pvs, "\nConsider ");
        aim_printf(pvs, "%s ", "the");
        aim_printf(pvs, "alphabet: ");
        for(c = 'A'; c <= 'Z'; c++) {
            aim_printf(pvs, "%c", c);
        }
        aim_printf(pvs, "\n");
        {
            char* s = aim_pvs_buffer_get(pvs);
            aim_printf(&aim_pvs_stdout, "first: %s", s);
            free(s);
            aim_printf(pvs, "(second)");
            s = aim_pvs_buffer_get(pvs);
            aim_printf(&aim_pvs_stdout, "second: %s", s);
            free(s);
            aim_pvs_destroy(pvs);
        }
        {
            aim_ratelimiter_t rl;
            aim_ratelimiter_init(&rl, 10, 5, NULL);

            /* 5 (6?) tokens available at t=0 */
            assert(aim_ratelimiter_limit(&rl, 0) == 0);
            assert(aim_ratelimiter_limit(&rl, 0) == 0);
            assert(aim_ratelimiter_limit(&rl, 0) == 0);
            assert(aim_ratelimiter_limit(&rl, 0) == 0);
            assert(aim_ratelimiter_limit(&rl, 0) == 0);
            assert(aim_ratelimiter_limit(&rl, 0) == 0);
            assert(aim_ratelimiter_limit(&rl, 0) < 0);

            /* Another token at t=10 */
            assert(aim_ratelimiter_limit(&rl, 10) == 0);
            assert(aim_ratelimiter_limit(&rl, 10) < 0);

            /* Nothing at t=15 */
            assert(aim_ratelimiter_limit(&rl, 15) < 0);

            /* 4 more tokens granted by t=50 */
            assert(aim_ratelimiter_limit(&rl, 50) == 0);
            assert(aim_ratelimiter_limit(&rl, 50) == 0);
            assert(aim_ratelimiter_limit(&rl, 50) == 0);
            assert(aim_ratelimiter_limit(&rl, 50) == 0);
            assert(aim_ratelimiter_limit(&rl, 50) < 0);
        }
        {
            aim_printf(&aim_pvs_stdout, "valgrind_status=%d\n",
                       aim_valgrind_status());
        }

        AIM_LOG_MSG("%{aim_error}", AIM_ERROR_PARAM);
    }

    return 0;
}

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
 *  /module/src/aim_log.c
 *
 *  AIM Logger
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim.h>
#include <AIM/aim_utils.h>
#include <AIM/aim_rl.h>
#include "aim_util.h"

#define AIM_LOG_MODULE_NAME aim
#include <AIM/aim_log.h>

#if AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES == 1
static void aim_log_env_init__(aim_log_t* l);
#endif

/**
 * Log colors.
 * This is done functionality (instead of through a static array)
 * to avoid buffer overruns if the flags increase (since there is no
 * 'count' member defined) and to catch at compile time a missing entry.
 */

#define TTY_FG_BLACK  30
#define TTY_FG_RED    31
#define TTY_FG_GREEN  32
#define TTY_FG_YELLOW 33
#define TTY_FG_BLUE   34
#define TTY_FG_VIOLET 35
#define TTY_FG_CYAN   36
#define TTY_FG_WHITE  37
#define TTY_FG_NONE   00

#define TTY_BG_BLACK  40
#define TTY_BG_RED    41
#define TTY_BG_GREEN  42
#define TTY_BG_YELLOW 43
#define TTY_BG_BLUE   44
#define TTY_BG_VIOLET 45
#define TTY_BG_CYAN   46
#define TTY_BG_WHITE  47
#define TTY_BG_NONE   00

#define TTY_DULL      0
#define TTY_BRIGHT    1

#define _TTY_COLOR(_intensity, _fg) "\x1B[" #_intensity ";" #_fg "m"
#define TTY_COLOR(_i, _f) _TTY_COLOR(_i, _f)

static const char* color_reset__ = "\x1B[39m";
static const char*
aim_log_flag_color__(aim_log_flag_t flag)
{
#if AIM_CONFIG_LOG_INCLUDE_TTY_COLOR == 1
    switch(flag)
        {
        case AIM_LOG_FLAG_INTERNAL:
        case AIM_LOG_FLAG_BUG:
        case AIM_LOG_FLAG_ERROR:
            return TTY_COLOR(TTY_DULL, TTY_FG_RED);
        case AIM_LOG_FLAG_FATAL:
            return TTY_COLOR(TTY_BRIGHT, TTY_FG_RED);
        case AIM_LOG_FLAG_WARN:
            return TTY_COLOR(TTY_DULL, TTY_FG_YELLOW);
        case AIM_LOG_FLAG_MSG:
        case AIM_LOG_FLAG_INFO:
        case AIM_LOG_FLAG_VERBOSE:
        case AIM_LOG_FLAG_TRACE:
        case AIM_LOG_FLAG_FTRACE:
            return NULL;
        }
#endif
    return NULL;
}

/**
 * All registered modules.
 */
static aim_log_t* aim_log_list__;

#define AIM_LOG_FOREACH(_lobj) \
    for(_lobj = aim_log_list__; _lobj; _lobj = _lobj->next)

/**
 * Find a module.
 */
aim_log_t*
aim_log_find(const char* name)
{
    aim_log_t* aml;
    AIM_LOG_FOREACH(aml) {
        if(!AIM_STRCMP(aml->name, name)) {
            return aml;
        }
    }
    return NULL;
}

/**
 * Register a module.
 */
void
aim_log_register(aim_log_t* log)
{
    /** Make sure we only register once */
    aim_log_t* aml;
    AIM_LOG_FOREACH(aml) {
        if(aml == log) {
            /* Already registered */
            return;
        }
    }

    /* Add to list */
    log->next = aim_log_list__;
    aim_log_list__ = log;

#if AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES == 1
    aim_log_env_init__(log);
#endif

}

/**
 * Get the global log list.
 */
aim_log_t*
aim_log_list(void)
{
    return aim_log_list__;
}

/**
 * Show log settings.
 */
void
aim_log_show(aim_log_t* lobj, aim_pvs_t* pvs)
{
    int i;
    int count;
    aim_map_si_t* map;

    aim_printf(pvs, "name: %s\n", lobj->name);

    count = 0;
    aim_printf(pvs, "enabled options: ");
    /* @fixme */
    for(i = 0; i <= AIM_LOG_OPTION_TIMESTAMP; i++) {
        if(AIM_BIT_GET(lobj->options, i)) {
            aim_printf(pvs, "%s ", aim_log_option_name(i));
            count++;
        }
    }
    if(count == 0) {
        aim_printf(pvs, "none.");
    }
    aim_printf(pvs, "\n");


    count = 0;
    aim_printf(pvs, "disabled options: ");
    for(i = 0; i <= AIM_LOG_OPTION_TIMESTAMP; i++) {
        if(AIM_BIT_GET(lobj->options, i) == 0) {
            aim_printf(pvs, "%s ", aim_log_option_name(i));
            count++;
        }
    }
    if(count == 0) {
        aim_printf(pvs, "none. ");
    }
    aim_printf(pvs, "\n");

    aim_printf(pvs, "enabled: ");
    count = 0;
    /* @fixme */
    for(i = 0; i <= AIM_LOG_FLAG_FTRACE; i++) {
        if(AIM_BIT_GET(lobj->common_flags, i)) {
            aim_printf(pvs, "%s ", aim_log_flag_name(i));
            count++;
        }
    }
    for(map = lobj->custom_map; map && map->s; map++) {
        if(AIM_BIT_GET(lobj->custom_flags, map->i)) {
            aim_printf(pvs, "%s ", map->s);
            count++;
        }
    }
    if(count == 0) {
        aim_printf(pvs, "none.");
    }
    aim_printf(pvs, "\n");

    aim_printf(pvs, "disabled: ");
    count = 0;
    for(i = 0; i < AIM_LOG_FLAG_FTRACE; i++) {
        if(AIM_BIT_GET(lobj->common_flags, i) == 0) {
            aim_printf(pvs, "%s ", aim_log_flag_name(i));
            count++;
        }
    }
    for(map = lobj->custom_map; map && map->s; map++)  {
        if(AIM_BIT_GET(lobj->custom_flags, map->i) == 0) {
            aim_printf(pvs, "%s ", map->s);
            count++;
        }
    }
    if(count == 0) {
        aim_printf(pvs, "none");
    }
    aim_printf(pvs, "\n");
}

/**
 * Get the PVS
 */
aim_pvs_t*
aim_log_pvs_get(aim_log_t* lobj)
{
    return (lobj) ? lobj->pvs : NULL;
}

/**
 * Set the PVS
 */
aim_pvs_t*
aim_log_pvs_set(aim_log_t* lobj, aim_pvs_t* pvs)
{
    aim_pvs_t* rv = NULL;
    if(lobj) {
        rv = lobj->pvs;
        lobj->pvs = pvs;
    }
    return rv;
}
void
aim_log_pvs_set_all(aim_pvs_t* pvs)
{
    aim_log_t* lobj;
    AIM_LOG_FOREACH(lobj) {
        aim_log_pvs_set(lobj, pvs);
    }
}


/**
 * Which bits to check
 */
static int
aim_log_bits__(aim_log_t* alt, const char* flag, uint32_t* common,
               uint32_t* custom)
{
    /*
     * Check custom flags first, then common flags.
     */
    int i;
    *common = 0;
    *custom = 0;

    if(!AIM_STRCMP(flag, "all")) {
        *custom = ~0;
        *common = ~0;
        return 1;
    }

    if(alt->custom_map && aim_map_si_s(&i, flag, alt->custom_map, 0)) {
        *custom = (1 << i);
        return 1;
    }

    if(aim_map_si_s(&i, flag, aim_log_flag_map, 0)) {
        *common = (1 << i);
        return 1;
    }

    return 0;
}


/**
 * Get a log flag by name.
 */
int
aim_log_flag_get(aim_log_t* lobj, const char* flag)
{
    uint32_t common, custom;
    if(aim_log_bits__(lobj, flag, &common, &custom)) {
        if(common) {
            return (lobj->common_flags & common) ? 1 : 0;
        }
        else {
            return (lobj->custom_flags & custom) ? 1 : 0;
        }
    }
    return -1;
}

/**
 * Get a common log flag.
 */
int
aim_log_fid_get(aim_log_t* lobj, aim_log_flag_t fid)
{
    return (lobj) ? AIM_BIT_GET(lobj->common_flags, fid) : -1;
}

/**
 * Get a custom log flag.
 */
int
aim_log_custom_fid_get(aim_log_t* lobj, int fid)
{
    return (lobj) ? AIM_BIT_GET(lobj->custom_flags, fid) : -1;
}

/**
 * Set a log flag by name.
 */
int
aim_log_flag_set(aim_log_t* lobj, const char* flag, int value)
{
    uint32_t common, custom;
    if(aim_log_bits__(lobj, flag, &common, &custom)) {
        if(common) {
            AIM_BITS_SET(lobj->common_flags, common, value);
        }
        if(custom) {
            AIM_BITS_SET(lobj->custom_flags, custom, value);
        }
        return 1;
    }
    return 0;
}

int
aim_log_flag_set_all(const char* flag, int value)
{
    aim_log_t* lobj;
    AIM_LOG_FOREACH(lobj) {
        aim_log_flag_set(lobj, flag, value);
    }
    return 0;
}

/**
 * Set a common log flag.
 */
int
aim_log_fid_set(aim_log_t* lobj, aim_log_flag_t fid, int value)
{
    if(lobj) {
        AIM_BIT_SET(lobj->common_flags, fid, value);
        return 1;
    }
    return 0;
}

int
aim_log_fid_set_all(aim_log_flag_t fid, int value)
{
    aim_log_t* lobj;
    AIM_LOG_FOREACH(lobj) {
        aim_log_fid_set(lobj, fid, value);
    }
    return 0;
}

/**
 * Set a custom log flag.
 */
int
aim_log_custom_fid_set(aim_log_t* lobj, int fid, int value)
{
    if(lobj) {
        AIM_BIT_SET(lobj->custom_flags, fid, value);
        return 1;
    }
    return 0;
}

int
aim_log_custom_fid_set_all(int fid, int value)
{
    aim_log_t* lobj;
    AIM_LOG_FOREACH(lobj) {
        aim_log_custom_fid_set(lobj, fid, value);
    }
    return 0;
}

/**
 * Set a log option.
 */
int
aim_log_option_set(aim_log_t* lobj, aim_log_option_t option, int value)
{
    if(lobj) {
        AIM_BIT_SET(lobj->options, option, value);
        return 1;
    }
    return 0;
}

int
aim_log_option_set_all(aim_log_option_t option, int value)
{
    aim_log_t* lobj;
    AIM_LOG_FOREACH(lobj) {
        aim_log_option_set(lobj, option, value);
    }
    return 0;
}

/**
 * Set a log option by name.
 */
int
aim_log_option_name_set(aim_log_t* lobj, const char* name, int value)
{
    aim_log_option_t opt;
    if(aim_log_option_value(name, &opt, 0) < 0) {
        return -1;
    }
    return aim_log_option_set(lobj, opt, value);
}
int
aim_log_option_name_set_all(const char* name, int value)
{
    aim_log_t* lobj;
    AIM_LOG_FOREACH(lobj) {
        aim_log_option_name_set(lobj, name, value);
    }
    return 0;
}

/**
 * Get a log option.
 */
int
aim_log_option_get(aim_log_t* lobj, aim_log_option_t option)
{
    if(lobj) {
        return AIM_BIT_GET(lobj->options, option);
    }
    return 0;
}

/**
 * Get a log option by name.
 */
int
aim_log_option_name_get(aim_log_t* lobj, const char* name)
{
    aim_log_option_t opt;
    if(aim_log_option_value(name, &opt, 0) < 0) {
        return -1;
    }
    return aim_log_option_get(lobj, opt);
}

/**
 * Current timestamp.
 */
#if AIM_CONFIG_LOG_INCLUDE_LINUX_TIMESTAMP == 1

#include <time.h>
#include <sys/time.h>

#endif

static void
aim_log_time__(aim_pvs_t* pvs)
{
#if AIM_CONFIG_LOG_INCLUDE_LINUX_TIMESTAMP == 1
    struct timeval timeval;
    struct tm *loctime;
    char lt[128];

    gettimeofday(&timeval, NULL);
    loctime = localtime(&timeval.tv_sec);
    strftime(lt, sizeof(lt), "%b %d %T", loctime);
    aim_printf(pvs, "%s.%.03d ", lt, (int)timeval.tv_usec/1000);
#else
    AIM_REFERENCE(pvs);
    AIM_REFERENCE(size);
#endif
}

/**
 * Basic output function for all log messages.
 */
static void
aim_log_output__(aim_log_t* l, const char* fname, const char* file,
                 int line, const char* fmt, va_list vargs)
{
    aim_pvs_t* msg;
    char* pmsg;

    msg = aim_pvs_buffer_create();
    if(AIM_BIT_GET(l->options, AIM_LOG_OPTION_TIMESTAMP)) {
        aim_log_time__(msg);
    }
    aim_vprintf(msg, fmt, vargs);
    if(l->options & (1 << AIM_LOG_OPTION_FUNC)) {
        aim_printf(msg, " [%s]", fname);
    }
    if(l->options & (1 << AIM_LOG_OPTION_FILE_LINE)) {
        aim_printf(msg, " [%s:%d]", file, line);
    }
    aim_printf(msg, "\n");
    pmsg = aim_pvs_buffer_get(msg);
    aim_printf(l->pvs, "%s", pmsg);
    AIM_FREE(pmsg);
    aim_pvs_destroy(msg);
}


#if AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES == 1

static void
aim_log_env_init__(aim_log_t* l)
{
    if(l->env == 0) {
        char envname[64];
        char* env;
        AIM_SNPRINTF(envname, sizeof(envname), "%s_log_flags", l->name);
        if((env = getenv(envname))) {
            int i;
            for(i = 0; aim_log_flag_map[i].s; i++) {
                if(AIM_STRSTR(env, aim_log_flag_map[i].s)) {
                    AIM_BIT_SET(l->common_flags, i, 1);
                }
            }
            if(AIM_STRSTR(env, "all")) {
                AIM_BITS_SET(l->common_flags, (1<<i)-1, 1);
            }
            for(i = 0; l->custom_map && l->custom_map[i].s; i++) {
                if(AIM_STRSTR(env, l->custom_map[i].s)) {
                    AIM_BIT_SET(l->custom_flags, i, 1);
                }
            }
            if(AIM_STRSTR(env, "all")) {
                AIM_BITS_SET(l->custom_flags, (1<<i)-1, 1);
            }
        }
        l->env = 1;
    }
}

#endif

int
aim_log_enabled(aim_log_t* l, aim_log_flag_t flag)
{
#if AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES == 1
    if(l->env == 0) {
        aim_log_env_init__(l);
    }
#endif
    return (l && l->pvs && AIM_BIT_GET(l->common_flags, flag));
}

int
aim_log_custom_enabled(aim_log_t* l, int fid)
{
#if AIM_CONFIG_LOG_INCLUDE_ENV_VARIABLES == 1
    if(l->env == 0) {
        aim_log_env_init__(l);
    }
#endif
    return (l && l->pvs && AIM_BIT_GET(l->custom_flags, fid));
}


void
aim_log_common(aim_log_t* l, aim_log_flag_t flag,
               aim_ratelimiter_t* rl, uint64_t time,
               const char* fname, const char* file, int line,
               const char* fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);
    aim_log_vcommon(l, flag, rl, time, fname, file, line, fmt, vargs);
    va_end(vargs);
}

void
aim_log_vcommon(aim_log_t* l, aim_log_flag_t flag,
                aim_ratelimiter_t* rl, uint64_t time,
                const char* fname, const char* file, int line,
                const char* fmt, va_list vargs)
{
    const char* color = NULL;

    if(flag == AIM_LOG_FLAG_MSG || flag == AIM_LOG_FLAG_FATAL ||
       aim_log_enabled(l, flag)) {
        if(rl == NULL || aim_ratelimiter_limit(rl, time) == 0) {

            if(aim_pvs_isatty(l->pvs)) {
                if((color = aim_log_flag_color__(flag))) {
                    aim_printf(l->pvs, color);
                }
            }

            aim_log_output__(l, fname, file, line, fmt, vargs);

            if(color) {
                aim_printf(l->pvs, color_reset__);
            }
        }
    }
}

void
aim_log_custom(aim_log_t* l, int fid,
               aim_ratelimiter_t* rl, uint64_t time,
               const char* fname, const char* file, int line,
               const char* fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);
    aim_log_vcustom(l, fid, rl, time, fname, file, line, fmt, vargs);
    va_end(vargs);
}


void
aim_log_vcustom(aim_log_t* l, int fid,
                aim_ratelimiter_t* rl, uint64_t time,
                const char* fname, const char* file, int line,
                const char* fmt, va_list vargs)
{
    if(aim_log_custom_enabled(l, fid)) {
        if(rl == NULL || aim_ratelimiter_limit(rl, time) == 0) {
            aim_log_output__(l, fname, file, line, fmt, vargs);
        }
    }
}

/**************************************************************************//**
 *
 * This is the log structure for the AIM module.
 *
 *
 *****************************************************************************/
AIM_LOG_STRUCT_DEFINE(
                      AIM_LOG_OPTIONS_DEFAULT,
                      AIM_LOG_BITS_DEFAULT,
                      NULL,
                      0x0       /* Initial Custom Flags */
                      );

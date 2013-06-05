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
 *  /module/src/aim_enums.c
 *
 *  AIM Enum Definitions
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim.h>
#include "aim_int.h"
#include <AIM/aim_log.h>
#include <AIM/aim_error.h>

/* <auto.start.enum(ALL).source> */
aim_map_si_t aim_log_flag_map[] =
{
    { "msg", AIM_LOG_FLAG_MSG },
    { "fatal", AIM_LOG_FLAG_FATAL },
    { "error", AIM_LOG_FLAG_ERROR },
    { "warn", AIM_LOG_FLAG_WARN },
    { "info", AIM_LOG_FLAG_INFO },
    { "verbose", AIM_LOG_FLAG_VERBOSE },
    { "trace", AIM_LOG_FLAG_TRACE },
    { "internal", AIM_LOG_FLAG_INTERNAL },
    { "bug", AIM_LOG_FLAG_BUG },
    { "ftrace", AIM_LOG_FLAG_FTRACE },
    { NULL, 0 }
};

aim_map_si_t aim_log_flag_desc_map[] =
{
    { "None", AIM_LOG_FLAG_MSG },
    { "None", AIM_LOG_FLAG_FATAL },
    { "None", AIM_LOG_FLAG_ERROR },
    { "None", AIM_LOG_FLAG_WARN },
    { "None", AIM_LOG_FLAG_INFO },
    { "None", AIM_LOG_FLAG_VERBOSE },
    { "None", AIM_LOG_FLAG_TRACE },
    { "None", AIM_LOG_FLAG_INTERNAL },
    { "None", AIM_LOG_FLAG_BUG },
    { "None", AIM_LOG_FLAG_FTRACE },
    { NULL, 0 }
};

const char*
aim_log_flag_name(aim_log_flag_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_flag_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_flag'";
    }
}

int
aim_log_flag_value(const char* str, aim_log_flag_t* e, int substr)
{
    int i;
    AIM_REFERENCE(substr);
    if(aim_map_si_s(&i, str, aim_log_flag_map, 0)) {
        /* Enum Found */
        *e = i;
        return 0;
    }
    else {
        return -1;
    }
}

const char*
aim_log_flag_desc(aim_log_flag_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_flag_desc_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_flag'";
    }
}

int
aim_log_flag_valid(aim_log_flag_t e)
{
    return aim_map_si_i(NULL, e, aim_log_flag_map, 0) ? 1 : 0;
}


aim_map_si_t aim_log_option_map[] =
{
    { "enable", AIM_LOG_OPTION_ENABLE },
    { "file_line", AIM_LOG_OPTION_FILE_LINE },
    { "func", AIM_LOG_OPTION_FUNC },
    { "timestamp", AIM_LOG_OPTION_TIMESTAMP },
    { NULL, 0 }
};

aim_map_si_t aim_log_option_desc_map[] =
{
    { "None", AIM_LOG_OPTION_ENABLE },
    { "None", AIM_LOG_OPTION_FILE_LINE },
    { "None", AIM_LOG_OPTION_FUNC },
    { "None", AIM_LOG_OPTION_TIMESTAMP },
    { NULL, 0 }
};

const char*
aim_log_option_name(aim_log_option_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_option_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_option'";
    }
}

int
aim_log_option_value(const char* str, aim_log_option_t* e, int substr)
{
    int i;
    AIM_REFERENCE(substr);
    if(aim_map_si_s(&i, str, aim_log_option_map, 0)) {
        /* Enum Found */
        *e = i;
        return 0;
    }
    else {
        return -1;
    }
}

const char*
aim_log_option_desc(aim_log_option_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_option_desc_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_option'";
    }
}

int
aim_log_option_valid(aim_log_option_t e)
{
    return aim_map_si_i(NULL, e, aim_log_option_map, 0) ? 1 : 0;
}


aim_map_si_t aim_log_bit_map[] =
{
    { "msg", AIM_LOG_BIT_MSG },
    { "fatal", AIM_LOG_BIT_FATAL },
    { "error", AIM_LOG_BIT_ERROR },
    { "warn", AIM_LOG_BIT_WARN },
    { "info", AIM_LOG_BIT_INFO },
    { "verbose", AIM_LOG_BIT_VERBOSE },
    { "trace", AIM_LOG_BIT_TRACE },
    { "internal", AIM_LOG_BIT_INTERNAL },
    { "bug", AIM_LOG_BIT_BUG },
    { "ftrace", AIM_LOG_BIT_FTRACE },
    { NULL, 0 }
};

aim_map_si_t aim_log_bit_desc_map[] =
{
    { "None", AIM_LOG_BIT_MSG },
    { "None", AIM_LOG_BIT_FATAL },
    { "None", AIM_LOG_BIT_ERROR },
    { "None", AIM_LOG_BIT_WARN },
    { "None", AIM_LOG_BIT_INFO },
    { "None", AIM_LOG_BIT_VERBOSE },
    { "None", AIM_LOG_BIT_TRACE },
    { "None", AIM_LOG_BIT_INTERNAL },
    { "None", AIM_LOG_BIT_BUG },
    { "None", AIM_LOG_BIT_FTRACE },
    { NULL, 0 }
};

const char*
aim_log_bit_name(aim_log_bit_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_bit_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_bit'";
    }
}

int
aim_log_bit_value(const char* str, aim_log_bit_t* e, int substr)
{
    int i;
    AIM_REFERENCE(substr);
    if(aim_map_si_s(&i, str, aim_log_bit_map, 0)) {
        /* Enum Found */
        *e = i;
        return 0;
    }
    else {
        return -1;
    }
}

const char*
aim_log_bit_desc(aim_log_bit_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_bit_desc_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_bit'";
    }
}

int
aim_log_bit_valid(aim_log_bit_t e)
{
    return aim_map_si_i(NULL, e, aim_log_bit_map, 0) ? 1 : 0;
}


aim_map_si_t aim_error_map[] =
{
    { "none", AIM_ERROR_NONE },
    { "param", AIM_ERROR_PARAM },
    { "not_found", AIM_ERROR_NOT_FOUND },
    { "internal", AIM_ERROR_INTERNAL },
    { NULL, 0 }
};

aim_map_si_t aim_error_desc_map[] =
{
    { "No error.", AIM_ERROR_NONE },
    { "One of the function parameters was invalid.", AIM_ERROR_PARAM },
    { "The requested object was not found.", AIM_ERROR_NOT_FOUND },
    { "An unexpected internal error occurred.", AIM_ERROR_INTERNAL },
    { NULL, 0 }
};

const char*
aim_error_name(aim_error_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_error_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_error'";
    }
}

int
aim_error_value(const char* str, aim_error_t* e, int substr)
{
    int i;
    AIM_REFERENCE(substr);
    if(aim_map_si_s(&i, str, aim_error_map, 0)) {
        /* Enum Found */
        *e = i;
        return 0;
    }
    else {
        return -1;
    }
}

const char*
aim_error_desc(aim_error_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_error_desc_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_error'";
    }
}

int
aim_error_valid(aim_error_t e)
{
    return aim_map_si_i(NULL, e, aim_error_map, 0) ? 1 : 0;
}


aim_map_si_t aim_log_option_bit_map[] =
{
    { "enable", AIM_LOG_OPTION_BIT_ENABLE },
    { "file_line", AIM_LOG_OPTION_BIT_FILE_LINE },
    { "func", AIM_LOG_OPTION_BIT_FUNC },
    { "timestamp", AIM_LOG_OPTION_BIT_TIMESTAMP },
    { NULL, 0 }
};

aim_map_si_t aim_log_option_bit_desc_map[] =
{
    { "None", AIM_LOG_OPTION_BIT_ENABLE },
    { "None", AIM_LOG_OPTION_BIT_FILE_LINE },
    { "None", AIM_LOG_OPTION_BIT_FUNC },
    { "None", AIM_LOG_OPTION_BIT_TIMESTAMP },
    { NULL, 0 }
};

const char*
aim_log_option_bit_name(aim_log_option_bit_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_option_bit_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_option_bit'";
    }
}

int
aim_log_option_bit_value(const char* str, aim_log_option_bit_t* e, int substr)
{
    int i;
    AIM_REFERENCE(substr);
    if(aim_map_si_s(&i, str, aim_log_option_bit_map, 0)) {
        /* Enum Found */
        *e = i;
        return 0;
    }
    else {
        return -1;
    }
}

const char*
aim_log_option_bit_desc(aim_log_option_bit_t e)
{
    const char* name;
    if(aim_map_si_i(&name, e, aim_log_option_bit_desc_map, 0)) {
        return name;
    }
    else {
        return "-invalid value for enum type 'aim_log_option_bit'";
    }
}

int
aim_log_option_bit_valid(aim_log_option_bit_t e)
{
    return aim_map_si_i(NULL, e, aim_log_option_bit_map, 0) ? 1 : 0;
}

/* <auto.end.enum(ALL).source> */

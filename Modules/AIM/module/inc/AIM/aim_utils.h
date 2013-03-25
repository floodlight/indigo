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
 *  /module/inc/AIM/aim_utils.h
 *
 * @file
 * @brief Generic Macros and Utility Definitions.
 *
 * @addtogroup aim-utils
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_UTILS_H__
#define __AIM_UTILS_H__

#include <AIM/aim_config.h>

/**
 * Number of elements in an array.
 */
#define AIM_ARRAYSIZE(_x) (sizeof(_x)/sizeof(_x[0]))

/**
 * Safe pointer casting.
 */
#define AIM_PCAST_SAFE(_type, _condition, _value)       \
    (_type) (_condition) ? (_value) : NULL

/**
 * Declare a variable and assign a safe cast.
 */
#define AIM_VAR_PCAST_SAFE(_type, _varname, _condition, _value) \
    _type _varname = AIM_PCAST_SAFE(_type, _condition, _value)


/**
 * Unused expression or variable.
 */
#define AIM_REFERENCE(_expr) ( (void) (_expr) )

/**
 * Success -- a return value that is >= 0
 */
#define AIM_SUCCESS(_expr) ( (_expr) >= 0 )

/**
 * Failure -- less than zero
 */
#define AIM_FAILURE(_expr) ( ! AIM_SUCCESS(_expr) )

/**
 * Evaluate the expression and return on failure.
 */
#define AIM_SUCCESS_OR_RETURN(_expr)            \
    do {                                        \
        int _rv = (_expr);                      \
        if(AIM_FAILURE(_rv)) {                  \
            return _rv;                         \
        }                                       \
    } while(0)



/**
 * If you've defined AIM_CONFIG_INCLUDE_POSIX support you can use this macro
 * for simple nano sleeps that will be compliant.
 */

#define AIM_NANOSLEEP(_nsecs)                      \
    do {                                           \
        struct timespec _t;                        \
        _t.tv_sec = 0;                             \
        _t.tv_nsec = _nsecs;                       \
        nanosleep(&_t, NULL);                      \
    } while(0)

/**
 * If you've defined AIM_CONFIG_INCLUDE_POSIX support you can use this macro
 * for simple micro sleeps that will be compliant.
 */
#define AIM_USLEEP(_usecs) AIM_NANOSLEEP((_usecs)*1000)


/** Stringify an argument (internal helper) */
#define ___AIM_STRINGIFY(_x) #_x
/** Stringify an argument (internal helper) */
#define __AIM_STRINGIFY(_x) ___AIM_STRINGIFY(_x)
/** Stringify an argument (internal helper) */
#define _AIM_STRINGIFY(_x) __AIM_STRINGIFY(_x)

/**
 * Stringify the given argument.
 */
#define AIM_STRINGIFY(_x) _AIM_STRINGIFY(_x)


/**
 * Set or clear bits in an integer.
 */
#define AIM_BITS_SET(_dst, _bits, _value)       \
    do {                                        \
        if( (_value) ) {                        \
            (_dst) |= (_bits);                  \
        }                                       \
        else {                                  \
            (_dst) &= ~(_bits);                 \
        }                                       \
    } while(0)


/**
 * Set or clear a bit position in an integer.
 */
#define AIM_BIT_SET(_dst, _bit, _value)         \
    AIM_BITS_SET(_dst, (1<<_bit), _value)

/**
 * Get a bit value.
 */
#define AIM_BIT_GET(_src, _bit)                 \
    ( ((_src) & (1 << (_bit))) ? 1 : 0 )

/**
 * Assert a condition at compile time.
 * The _name argument must be a valid C identifier and
 * will be included in the failure message.
 */
#define AIM_STATIC_ASSERT(_name, _cond) \
    extern int static_assert_##_name[(_cond) ? 1 : -1]

/**
 * Only execute a function once.
 */
#define AIM_RUN_ONCE(_expr)                     \
    do {                                        \
        static int __called__ = 0;              \
        if(__called__ != 0) {                   \
            _expr;                              \
        }                                       \
        __called__++;                           \
    } while(0)


#if AIM_CONFIG_INCLUDE_MODULES_INIT == 1
extern int aim_modules_init(void);
#endif

/**
 * Printing an empty string that may be NULL.
 */
#define AIM_STRING_EMPTY_IF_NULL(_str) ( (_str) ? (_str) : "")

/**
 * @brief Zero'ed memory alloc.
 * @param size Size.
 */
void* aim_zmalloc(int size);


/**
 * @brief Duplicate memory.
 * @param src Source memory.
 * @param size Size.
 * @returns a new copy of the data.
 */
void* aim_memdup(void* src, int size);

/**
 * @brief Duplicate memory.
 * @param src Source memory;
 * @param src_size Size to copy.
 * @param alloc_size Size to allocate.
 */
void* aim_memndup(void* src, int src_size, int alloc_size);


/**
 * Expression log and assert.
 */
#define AIM_TRY_OR_DIE(_expr)                                   \
    do {                                                        \
        int _rv;                                                \
        _rv = (_expr);                                          \
        if(_rv < 0) {                                           \
            AIM_LOG_FATAL("'%s' returned %d @%s:%d",            \
                          #_expr, _rv, __FILE__, __LINE__);     \
            exit(1);                                            \
        }                                                       \
    } while(0)

/**
 * Expression true log and assert. =
 */
#define AIM_TRUE_OR_DIE(_expr, ...)                                     \
    do {                                                                \
        if (!(_expr)) {                                                 \
            AIM_DIE("assertion failed: '" #_expr "': " __VA_ARGS__);     \
        }                                                               \
    } while(0)

#endif /* __AIM_UTILS_H__ */
/*@}*/

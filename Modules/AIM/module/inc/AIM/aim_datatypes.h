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
 * @file
 * @brief AIM Argument Parsing and Output Datatypes.
 *
 * @addtogroup aim-datatypes
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_DATATYPES_H__
#define __AIM_DATATYPES_H__

#include <AIM/aim_map.h>
#include <AIM/aim_valist.h>
#include <AIM/aim_pvs.h>

/** Return this if your datatype handler encounters an error. */
#define AIM_DATATYPE_ERROR -1
/** Return this if your datatype handler succeeds. */
#define AIM_DATATYPE_OK     0

/** Datatype forward. */
struct aim_datatype_s;

/** Context passed to all datatype handlers. */
typedef struct aim_datatype_context_s {
    /** The registrant's datatype structure. */
    struct aim_datatype_s* dt;
    /** PVS for error messages if appropate. */
    aim_pvs_t* epvs;
} aim_datatype_context_t;

/**************************************************************************//**
 *
 * The "from_string" prototype.
 *
 *****************************************************************************/
typedef int (*aim_datatype_from_str_f)(aim_datatype_context_t* dtc,
                                       const char* arg,
                                       aim_va_list_t* vargs);

/**************************************************************************//**
 *
 * The "to_string" prototype.
 *
 *****************************************************************************/
typedef int (*aim_datatype_to_str_f)(aim_datatype_context_t* dtc,
                                     aim_va_list_t* vargs,
                                     const char** rv);

/**
 * @brief Register a custom datatype.
 * @param c Optional single character that refers to this datatype.
 * @param type The full name of this datatype.
 * @param desc The description of this datatype.
 * @param froms The handler that converts a string to this datatype.
 * @param tos The handler that converts this datatype to a string.
 * @param cookie Client cookie to be passed to the handlers when called.
 */
int aim_datatype_register(char c, const char* type, const char* desc,
                          aim_datatype_from_str_f froms, aim_datatype_to_str_f tos,
                          void* cookie);

/**
 * @brief Unregister the given datatype.
 * @param c Optional single character that refers to this datatype.
 * @param type The full name of the datatype to unregister.
 */
int aim_datatype_unregister(char c, const char* type);

/**
 * @brief Initialize the datatypes infrastructure.
 */
int aim_datatypes_init(void);

/**
 * @brief Deinitialize the datatypes infrastructure.
 */
void aim_datatypes_denit(void);


/**
 * The builtin {map} datatype provides conversion between strings
 * and integers.
 *
 * This structure defines the input data for the {map} datatype.
 */
typedef aim_map_si_t aim_datatype_map_t;


/**
 * @brief Register a mapping datatype.
 * @param c The optional single character that refers to this datatype.
 * @param type The full name for this datatype.
 * @param desc The description of this datatype.
 * @param map The map table defining the allowable values for this datatype.
 */
int aim_datatype_register_map(char c, const char* type, const char* desc,
                               aim_datatype_map_t* map);

/**
 * You can use this macro to register a pre-existing enumeration or map.
 * _name -- Name of the type to register
 * _table -- map table describing the type
 * _desc -- type description
 * _elog -- log macro to call if registration fails
 */
#define AIM_DATATYPE_MAP_REGISTER(_name, _table, _desc, _elog)         \
    do {                                                                \
        int _rv;                                                        \
        extern aim_datatype_map_t _table [];                           \
        _rv = aim_datatype_register_map(0, #_name, _desc, _table);     \
        if(_rv < 0) {                                                   \
            _elog ("aim_datatype_register_map(" #_name ") failed.");   \
        }                                                               \
    } while(0)                                                          \



/**************************************************************************//**
 *
 * The format handlers for argument parsing and output are all invoked
 * automatically during aim_argparse() and aim_printf().
 *
 * If you want to access them directly, they are defined and managed
 * through this structure definition.
 *
 *****************************************************************************/
typedef struct aim_datatype_s {
    /** character shortcut */
    char c;

    /** typename, used with "{type}" */
    const char* type;

    /**
     * Human description of this type
     */
    const char* desc;

    /** from-string handler for this datatype. */
    aim_datatype_from_str_f from_str;

    /** to-string handler for this datatype. */
    aim_datatype_to_str_f to_str;

    /** private cookie */
    void* cookie;

} aim_datatype_t;

/**
 * @brief Register a datatype using the native datatype structure.
 * @param dt Pointer to the datatype structure.
 */
int aim_datatype_register_struct(aim_datatype_t* dt);

/**
 * @brief Find the datatype management structure for the requested type.
 * @param c Optional shortcut character for the datatype.
 * @param type The full name of the datatype.
 *
 * @returns NULL if there is no datatype registered by that name.
 * @returns The pointer to the datatype information structure if found.
 *
 */
aim_datatype_t* aim_datatype_find(char c, const char* type);


#endif /* __AIM_DATATYPES_H__ */
/*@}*/

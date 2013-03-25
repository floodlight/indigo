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
 * @brief AIM Object Header
 *
 * @addtogroup aim-object
 * @{
 *
 *****************************************************************************/
#ifndef __AIM_OBJECT_H__
#define __AIM_OBJECT_H__

/**
 * Provides a common structure definition for facilitating
 * polymorphic interfaces where appropriate.
 */
typedef struct aim_object_s {

    /**
     * Unique Object Identifier (String)
     *
     * Set this to a statically allocated string buffer
     * in your own compilation unit.
     *
     * The ADDRESS of the string is what guarantees the uncoordinated
     * uniqueness of your object id, not the CONTENTS of the string.
     *
     * The CONTENTS of the string are only for humans.
     */
    const char* id;

    /**
     * Optional Object Subtype.
     *
     * Set to whatever makes sense for your object.
     */
    int subtype;

    /**
     * Object data pointer. Optional.
     */
    void* cookie;

    /**
     * You can specify a destructor for your object.
     */
    void (*destructor)(struct aim_object_s* object);

} aim_object_t;

/**
 * Typedef for destructors.
 */
typedef void (*aim_object_dtor)(aim_object_t*);


/**
 * You can use this macro to statically initialize the aim_object
 * member of a given structure.
 */
#define AIM_STATIC_OBJECT_INIT(_id, _subtype, _cookie, _dtor)   \
    { _id, _subtype, _cookie, _dtor }

/**
 * You can use this macro to dynamically initialize the aim_object
 * member of a given structure.
 *
 * The object pointer must be equivalent to an aim_object_t*.
 */
#define AIM_OBJECT_INIT(_object, _id, _subtype, _cookie, _dtor) \
    do {                                                        \
        aim_object_t* _op_ = (aim_object_t*)(_object);          \
        if(_op_) {                                              \
            _op_->id = _id;                                     \
            _op_->subtype = _subtype;                           \
            _op_->cookie = _cookie;                             \
            _op_->destructor = _dtor;                           \
        }                                                       \
    } while(0)


/**
 * Define an object identfier.
 */
#define AIM_OBJECT_ID_DEFINE(_name, _str)       \
    static char _name[] = _str

/**
 * Get the object id.
 */
#define AIM_OBJECT_ID(_name)                    \
    (& _name [0])

/**
 * Test whether the given pointer is an object of the given type.
 */
#define AIM_OBJECT_IS(_object, _id)             \
    ( ((aim_object_t*)(_object))->id == _id)

/**
 * Test whether the given pointer is not an object of the given type.
 */
#define AIM_OBJECT_IS_NOT(_object, _id) \
    (!AIM_OBJECT_IS(_object,_id))


/**
 * @brief Allocate an aim_object.
 * @param size The size of the object.
 * @param id The object id
 * @param subtype The object subtype
 * @param cookie The object cookie
 * @param dtor The object destructor.
 */
aim_object_t* aim_object_create(unsigned int size, const char* id, int subtype,
                                void* cookie, aim_object_dtor dtor);

/**
 * @brief Destroy an aim_object.
 * @param obj The object.
 */
void aim_object_destroy(aim_object_t* obj);

#endif /* __AIM_OBJECT_H__ */
/* @}*/

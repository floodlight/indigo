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
 * aim_datatypes.c
 *
 *
 *****************************************************************************/
#include <AIM/aim_config.h>
#include <AIM/aim_datatypes.h>
#include <AIM/aim_utils.h>
#include <AIM/aim_string.h>
#include <AIM/aim_log.h>
#include <AIM/aim_list.h>
#include <AIM/aim_error.h>
#include <AIM/aim_bitmap.h>
#include <AIM/aim_pvs_buffer.h>

/* FIXME */
#define AIM_STATUS_E_ARG -1
#define AIM_STATUS_OK 0

/*
 * Not necessary, but the aim_list conflicts with the list module
 * at the moment, so we don't want it exported yet.
 */
typedef struct __aim_datatype_s {
    aim_datatype_t dt;
    /** Internal list management */
    list_links_t links;
} __aim_datatype_t;

static LIST_DEFINE(aim_datatype_list__);

#define DT_LIST_FOREACH(_ll) LIST_FOREACH(&aim_datatype_list__, _ll)
#define DT_LIST_FOREACH_SAFE(_cur, _next) \
    LIST_FOREACH_SAFE(&aim_datatype_list__, _cur, _next)

#define DT_ENTRY(_ll) (aim_datatype_t*) container_of(_ll, links, __aim_datatype_t)

static int
aim_datatype_equals__(const aim_datatype_t* dt, char c, const char* type)
{
    if( ( (c==0) || (dt->c == c)) &&
        ( (type==NULL || type[0]==0) || (dt->type && !AIM_STRCMP(type, dt->type)))) {
        return 1;
    }
    return 0;
}

/*
 * Find a datatype handler
 */
aim_datatype_t*
aim_datatype_find(char c, const char* type)
{
    list_links_t* ll;
    aim_datatype_t* dt;

    if(c == 0 && type == NULL) {
        return NULL;
    }
    DT_LIST_FOREACH(ll) {
        dt = DT_ENTRY(ll);
        if(aim_datatype_equals__(dt, c, type)) {
            return dt;
        }
    }
    return NULL;
}


/*
 * Register a datatype handler
 */
int
aim_datatype_register(char c, const char* type, const char* desc,
                      aim_datatype_from_str_f froms, aim_datatype_to_str_f tos,
                      void* cookie)
{
    aim_datatype_t dt;
    AIM_MEMSET(&dt, 0, sizeof(dt));
    dt.c = c;
    dt.type = type;
    dt.desc = desc;
    dt.from_str = froms;
    dt.to_str = tos;
    dt.cookie = cookie;
    return aim_datatype_register_struct(&dt);
}

int
aim_datatype_register_struct(aim_datatype_t* dt)
{
    __aim_datatype_t* ndt = NULL;

    if( (dt == NULL) || (dt->c == 0 && dt->type == NULL) ||
        (dt->from_str == NULL && dt->to_str == NULL) ) {
        return -1;
    }

    if(aim_datatype_find(dt->c, dt->type) != NULL) {
        return -1;
    }

    ndt = aim_zmalloc(sizeof(*ndt));
    ndt->dt = *dt;
    list_push(&aim_datatype_list__, &ndt->links);
    return 0;
}

int
aim_datatype_unregister(char c, const char* type)
{
    list_links_t* ll;
    aim_datatype_t* dt;

    DT_LIST_FOREACH(ll) {
        dt = DT_ENTRY(ll);
        if(aim_datatype_equals__(dt, c, type)) {
            list_remove(&((__aim_datatype_t*)dt)->links);
            AIM_FREE(dt);
            break;
        }
    }
    return 0;
}

aim_datatype_map_t*
aim_datatype_map_find_value(aim_datatype_map_t* map, const char* name)
{
    aim_datatype_map_t* p;
    for(p = map; p->s; p++) {
        if(!AIM_STRCMP(p->s, name)) {
            return p;
        }
    }
    return NULL;
}
aim_datatype_map_t*
aim_datatype_map_find_name(aim_datatype_map_t* map, int value)
{
    aim_datatype_map_t* p;
    for(p = map; p->s; p++) {
        if(p->i == value) {
            return p;
        }
    }
    return NULL;
}

static int
aim_datatype_fs__rmap__(aim_datatype_context_t* dtc, const char* arg,
                        aim_va_list_t* vargs)
{
    int* rv = va_arg(vargs->val, int*);
    aim_datatype_map_t* map = (aim_datatype_map_t*) dtc->dt->cookie;
    aim_datatype_map_t* p;

    if((p = aim_datatype_map_find_value(map, arg))) {
        *rv = p->i;
        return 0;
    }

    /* fixme */
    aim_pvs_printf(dtc->epvs,
                   "%s is not a valid %s. Choices are: ", arg, dtc->dt->desc);
    for(p = map; p->s; p++) {
        aim_pvs_printf(dtc->epvs, "%s%s ", p->s, (p+1)->s ? "," : "");
    }
    aim_pvs_printf(dtc->epvs, "\n");
    return -1;
}

static int
aim_datatype_ts__rmap__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                        const char** rv)
{
    aim_datatype_map_t* map = (aim_datatype_map_t*) dtc->dt->cookie;
    aim_datatype_map_t* p;
    if((p = aim_datatype_map_find_name(map, va_arg(vargs->val, int)))) {
        *rv = aim_strdup(p->s);
    }
    else {
        *rv = aim_strdup("[Unknown]");
    }
    return 0;
}

int
aim_datatype_register_map(char c, const char* type, const char* desc,
                           aim_datatype_map_t* map)
{
    return aim_datatype_register(c, type, desc,
                                 aim_datatype_fs__rmap__,
                                 aim_datatype_ts__rmap__,
                                 map);
}

/**************************************************************************//**
 *
 * Builtin handlers
 *
 *
 *****************************************************************************/

/**************************************************************************//**
 *
 * String Argument Parser
 *
 * type 's', {string}
 *
 * varargs: (char**)
 *
 *****************************************************************************/
static int
aim_datatype_fs__string__(aim_datatype_context_t* dtc, const char* arg,
                           aim_va_list_t* vargs)
{
    const char**  rv;
    AIM_REFERENCE(dtc);
    rv = va_arg(vargs->val, const char**);
    *rv = arg;
    return 0;
}

int
aim_datatype_fs_int(const char* str, int* value)
{
    int x;

    if(str == NULL) {
        return -1;
    }

    if( (AIM_SSCANF(str, "0x%x", (unsigned int*)&x) == 1) ||
        (AIM_SSCANF(str, "%d", &x) == 1) ||
        (AIM_SSCANF(str, "%x", (unsigned int*)&x) == 1) ) {
        if(value) {
            *value = x;
        }
        return 0;
    }
    return -1;
}


/**************************************************************************//**
 *
 * Integer Argument Parser
 *
 * type 'i', {integer}
 *
 * varargs: (int*)
 *
 *****************************************************************************/

static int
aim_datatype_fs__int__(aim_datatype_context_t* dtc, const char* arg,
                        aim_va_list_t* vargs)
{
    int* rv = va_arg(vargs->val, int*);
    if(aim_datatype_fs_int(arg, rv) != 0) {
        return AIM_STATUS_E_ARG;
    }
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

/**************************************************************************//**
 *
 * Ranged Integer Argument Parser
 *
 * The given integer must be between the low and high value, inclusive.
 *
 * varargs: (int*, int low, int high, char* argumentDescription)
 *
 *****************************************************************************/

static int
aim_datatype_fs__rint__(aim_datatype_context_t* dtc, const char* arg,
                         aim_va_list_t* vargs)
{
    int* rv = va_arg(vargs->val, int*);
    int low = va_arg(vargs->val, int);
    int high = va_arg(vargs->val, int);
    char* desc = va_arg(vargs->val, char*);

    if(aim_datatype_fs_int(arg, rv) != 0) {
        aim_pvs_printf(dtc->epvs, "%s is not an integer.\n", arg);
        return AIM_STATUS_E_ARG;
    }
    if(*rv < low || *rv > high) {
        aim_pvs_printf(dtc->epvs, "value %d [for argument %s] must be between %d and %d.\n",
                       *rv, desc, low, high);
        return AIM_STATUS_E_ARG;
    }
    return AIM_STATUS_OK;
}

/**************************************************************************//**
 *
 * Data Argument Parser
 *
 *
 *****************************************************************************/
static int
aim_datatype_fs__data__(aim_datatype_context_t* dtc, const char* arg,
                         aim_va_list_t* vargs)
{
    uint8_t** data = va_arg(vargs->val, uint8_t**);
    int* size = va_arg(vargs->val, int*);
    *data = aim_bytes_from_string(arg, size);
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

static int
aim_datatype_fs__idata__(aim_datatype_context_t* dtc, const char* arg,
                          aim_va_list_t* vargs)
{
    uint8_t* data = va_arg(vargs->val, uint8_t*);
    int*     size = va_arg(vargs->val, int*);

    uint8_t* _data;
    int      _size;
    _data = aim_bytes_from_string(arg, &_size);
    if(_size > *size) {
        aim_pvs_printf(dtc->epvs, "too much data.\n");
    }
    AIM_MEMCPY(data, _data, _size);
    *size = _size;
    AIM_FREE(_data);
    return AIM_STATUS_OK;
}


static int
aim_datatype_ts__data__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                        const char** rv)
{
    uint8_t* data = va_arg(vargs->val, uint8_t*);
    int size = va_arg(vargs->val, int);
    *rv = aim_bytes_to_string(data, size, 16);
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}


/**************************************************************************//**
 *
 * Argument Map Parser
 *
 * Validate a given argument against a map of possible values.
 * Returns the matching value.
 *
 * varargs: (aim_argparse_map_t** retval, aim_argparse_map_t* map, char* description)
 *
 *
 *****************************************************************************/
static int
aim_datatype_fs__map__(aim_datatype_context_t* dtc, const char* arg,
                        aim_va_list_t* vargs)
{
    aim_datatype_map_t** rv = va_arg(vargs->val, aim_datatype_map_t**);
    aim_datatype_map_t* map = va_arg(vargs->val, aim_datatype_map_t*);
    const char* desc = va_arg(vargs->val, const char*);
    aim_datatype_map_t* p;

    for(p = map; p->s; p++) {
        if(!AIM_STRCMP(p->s, arg)) {
            *rv = p;
            return AIM_STATUS_OK;
        }
    }
    aim_pvs_printf(dtc->epvs, "%s is not a valid %s. Choices are: ", arg, desc);
    for(p = map; p->s; p++) {
        aim_pvs_printf(dtc->epvs, "%s%s ", p->s, (p+1)->s ? "," : "");
    }
    aim_pvs_printf(dtc->epvs, "\n");
    return AIM_STATUS_E_ARG;
}

/**************************************************************************//**
 *
 * Choice Argument Parser
 *
 * Validate a given argument against a set of possible values.
 * Returns the index of the matching value.
 *
 * varargs: (int* rv, char* description, int count, char* choice1, ...)
 *
 *****************************************************************************/
static int
aim_datatype_fs__choice__(aim_datatype_context_t* dtc, const char* arg,
                          aim_va_list_t* vargs)
{
    int* rv = va_arg(vargs->val, int*);
    const char* desc = va_arg(vargs->val, const char*);
    int count = va_arg(vargs->val, int);
    int i;
    char** choices = aim_zmalloc(sizeof(char*)*count);

    *rv = -1;
    for(i = 0; i < count; i++) {
        /* Note -- we must pull all the arguments regardless of
         * which one matched. */
        choices[i] = va_arg(vargs->val, char*);
        if(*rv == -1 && AIM_STRCMP(choices[i], arg) == 0) {
            *rv = i;
        }
    }
    if(*rv == -1) {
        aim_pvs_printf(dtc->epvs, "%s is not a valid %s. Choices are: ", arg, desc);
        for(i = 0; i < count; i++) {
            aim_pvs_printf(dtc->epvs, "%s%s ", choices[i], i != (count-1) ? "," : "");
        }
        aim_pvs_printf(dtc->epvs, "\n");
        aim_free(choices);
        return AIM_STATUS_E_ARG;
    }
    else {
        aim_free(choices);
        return AIM_STATUS_OK;
    }
}


/**************************************************************************//**
 *
 * Boolean Argument Parser
 *
 * Expects "1,0,true,True,False,false"
 *
 * varargs(int**)
 *
 *****************************************************************************/
static int
aim_datatype_fs__bool__(aim_datatype_context_t* dtc, const char* arg,
                        aim_va_list_t* vargs)
{
    int* rv = va_arg(vargs->val, int*);

    AIM_REFERENCE(dtc);

    if(!AIM_STRCMP(arg, "0") ||
       !AIM_STRCMP(arg, "false") ||
       !AIM_STRCMP(arg, "False") ||
       !AIM_STRCMP(arg, "FALSE")) {
        *rv = 0;
        return AIM_STATUS_OK;
    }
    else if(!AIM_STRCMP(arg, "1") ||
            !AIM_STRCMP(arg, "true") ||
            !AIM_STRCMP(arg, "True") ||
            !AIM_STRCMP(arg, "TRUE")) {
        *rv = 1;
        return AIM_STATUS_OK;
    }
    else {
        return AIM_STATUS_E_ARG;
    }
}

static int
aim_datatype_ts__bool__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                        const char** rv)
{
    int v = va_arg(vargs->val, int);
    *rv = aim_strdup( (v) ? "True" : "False");
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

/**************************************************************************//**
 *
 * Move These
 *
 *
 *****************************************************************************/
static int
aim_datatype_fs__ipv4a__(aim_datatype_context_t* dtc, const char* arg,
                          aim_va_list_t* vargs)
{
    uint32_t* rv = va_arg(vargs->val, uint32_t*);
    int octets[4];
    int i;

    AIM_REFERENCE(dtc);

    if(AIM_SSCANF(arg, "%d.%d.%d.%d", octets+3, octets+2, octets+1, octets+0) != 4) {
        return AIM_STATUS_E_ARG;
    }
    *rv = 0;

    for(i = 3; i >= 0; i--) {
        if(octets[i] < 0 || octets[i] > 255) {
            return AIM_STATUS_E_ARG;
        }
        *rv |= (octets[i] << 8*i);
    }
    return AIM_STATUS_OK;
}

static int
aim_datatype_ts__ipv4a__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                         const char** rv)
{
    char b[64];
    uint32_t v = va_arg(vargs->val, uint32_t);
    AIM_SNPRINTF(b, sizeof(b), "%d.%d.%d.%d",
                  ( v >> 24) & 0xFF, (v >> 16) & 0xFF,
                  ( v >> 8 ) & 0xFF, (v >> 0 ) & 0xFF);
    *rv = aim_strdup(b);

    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

static int
aim_datatype_fs__ip4conn__(aim_datatype_context_t* dtc, const char* arg,
                            aim_va_list_t* vargs)
{
    char* caddr = va_arg(vargs->val, char*);
    int* cport = va_arg(vargs->val, int*);
    int octets[4];

    AIM_REFERENCE(dtc);

    if(AIM_SSCANF(arg, "%d.%d.%d.%d:%d", octets+3, octets+2, octets+1,
                   octets+0, cport) != 5) {

        if(AIM_SSCANF(arg, ":%d", cport) != 1) {
            return AIM_STATUS_E_ARG;
        }
        else {
            /* Local interface implied */
            octets[3] = 127;
            octets[2] = 0;
            octets[1] = 0;
            octets[0] = 1;
        }
    }
    if(*cport < 0 || *cport > 0xFFFF) {
        return AIM_STATUS_E_ARG;
    }
    if( (octets[3] & 0xFF) != octets[3] ||
        (octets[2] & 0xFF) != octets[2] ||
        (octets[1] & 0xFF) != octets[1] ||
        (octets[0] & 0xFF) != octets[0] ) {
        return AIM_STATUS_E_ARG;
    }
    else {
        AIM_SNPRINTF(caddr, 32, "%d.%d.%d.%d", octets[3],
                     octets[2], octets[1], octets[0]);
        return AIM_STATUS_OK;
    }
}

static int
aim_datatype_ts__ip4conn__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                           const char** rv)
{
    char* caddr = va_arg(vargs->val, char*);
    int cport = va_arg(vargs->val, int);
    unsigned int len = AIM_STRLEN(caddr)+7;
    *rv = aim_zmalloc(len);
    AIM_SNPRINTF((char*)*rv, len, "%s:%hd", caddr, (uint16_t)cport);
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

static int
aim_datatype_fs__aim_log__(aim_datatype_context_t* dtc, const char* arg,
                            aim_va_list_t* vargs)
{
    aim_log_t** lobj = va_arg(vargs->val, aim_log_t**);
    *lobj = aim_log_find(arg);
    if(*lobj == NULL) {
        return AIM_STATUS_E_ARG;
    }
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

static int
aim_datatype_ts__aim_error__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                             const char** rv)
{
    aim_error_t e = va_arg(vargs->val, aim_error_t);
    *rv = aim_fstrdup("%d::%s: %s", e, aim_error_name(e), aim_error_desc(e));
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

static int
aim_datatype_ts__aim_bitmap__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                              const char** rv)
{
    aim_bitmap_t* bmap = va_arg(vargs->val, aim_bitmap_t*);
    if(bmap == NULL) {
        *rv = aim_strdup("NULL");
    }
    else {
        aim_pvs_t* pvsb = aim_pvs_buffer_create();
        int bit;

        AIM_BITMAP_ITER(bmap, bit) {
            aim_pvs_printf(pvsb, "%d ", bit);
        }

        *rv = aim_pvs_buffer_get(pvsb);
        if(*rv == NULL) {
            *rv = aim_strdup("None");
        }
        aim_pvs_destroy(pvsb);
    }
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

static int
aim_datatype_fs__mac__(aim_datatype_context_t* dtc, const char* arg,
                       aim_va_list_t* vargs)
{
    uint8_t* dst = va_arg(vargs->val, uint8_t*);
    unsigned int data[8];
    if(AIM_SSCANF(arg, "%x:%x:%x:%x:%x:%x",
                  data, data+1, data+2, data+3, data+4, data+5) == 6) {
        int i;
        for(i = 0; i < 6; i++) {
            if(data[i] > 255) {
                return AIM_DATATYPE_ERROR;
            }
            dst[i] = data[i];
        }
        return AIM_DATATYPE_OK;
    }
    else {
        return AIM_DATATYPE_ERROR;
    }
    AIM_REFERENCE(dtc);
}

static int
aim_datatype_ts__mac__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                       const char** rv)
{
    uint8_t* mac = va_arg(vargs->val, uint8_t*);
    *rv = aim_zmalloc(18);
    AIM_SNPRINTF((char*)*rv, 18, "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x",
                 mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

static int
aim_datatype_fs__vlan__(aim_datatype_context_t* dtc, const char* arg,
                       aim_va_list_t* vargs)
{
    int* rv = va_arg(vargs->val, int*);
    if(aim_datatype_fs_int(arg, rv) != 0) {
        return AIM_STATUS_E_ARG;
    }
    if(*rv < 0 || *rv > 0xFFF) {
        return AIM_STATUS_E_ARG;
    }
    AIM_REFERENCE(dtc);
    return AIM_DATATYPE_OK;
}


static int
aim_datatype_ts__vlan__(aim_datatype_context_t* dtc, aim_va_list_t* vargs,
                       const char** rv)
{
    int vid = va_arg(vargs->val, int);
    *rv = aim_zmalloc(6);
    AIM_SNPRINTF((char*)rv, 6, "%d", vid);
    AIM_REFERENCE(dtc);
    return AIM_STATUS_OK;
}

int
aim_datatypes_init()
{
    aim_datatype_register('s', "string", "string", aim_datatype_fs__string__,
                           NULL, NULL);
    aim_datatype_register('i', "int", "integer", aim_datatype_fs__int__,
                           NULL, NULL);
    aim_datatype_register('r', "rint", NULL, aim_datatype_fs__rint__,
                           NULL, NULL);
    aim_datatype_register('m', "map", NULL, aim_datatype_fs__map__,
                           NULL, NULL);
    aim_datatype_register('c', "choice", NULL, aim_datatype_fs__choice__,
                          NULL, NULL);
    aim_datatype_register('b', "bool", "boolean",
                          aim_datatype_fs__bool__, aim_datatype_ts__bool__,
                          NULL);
    aim_datatype_register(0, "ipv4a", "IPv4 Address",
                           aim_datatype_fs__ipv4a__, aim_datatype_ts__ipv4a__,
                           NULL);
    aim_datatype_register(0, "data", "data string",
                           aim_datatype_fs__data__, aim_datatype_ts__data__,
                           NULL);
    aim_datatype_register(0, "idata", "data string",
                           aim_datatype_fs__idata__, aim_datatype_ts__data__,
                           NULL);
    aim_datatype_register(0, "ip4conn", "IPv4 Connection",
                           aim_datatype_fs__ip4conn__,
                           aim_datatype_ts__ip4conn__,
                           NULL);
    aim_datatype_register(0, "aim_log", "Log Module",
                           aim_datatype_fs__aim_log__,
                           NULL,
                           NULL);
    aim_datatype_register(0, "aim_error", "AIM Error",
                          NULL,
                          aim_datatype_ts__aim_error__,
                          NULL);
    aim_datatype_register(0, "aim_bitmap", "AIM Bitmap",
                          NULL,
                          aim_datatype_ts__aim_bitmap__,
                          NULL);
    aim_datatype_register(0, "mac", "MAC address",
                          aim_datatype_fs__mac__,
                          aim_datatype_ts__mac__,
                          NULL);
    aim_datatype_register(0, "vlan", "VLAN Id",
                          aim_datatype_fs__vlan__,
                          aim_datatype_ts__vlan__,
                          NULL);

   return 0;
}

void
aim_datatypes_denit()
{
    while(!list_empty(&aim_datatype_list__)) {
        aim_datatype_t* dt = DT_ENTRY(aim_datatype_list__.links.next);
        aim_datatype_unregister(dt->c, dt->type);
    }
}


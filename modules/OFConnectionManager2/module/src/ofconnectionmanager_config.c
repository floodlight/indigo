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
 *  /module/src/ofconnectionmanager_config.c
 *
 *  OFConnectionManager Config Information
 *
 * Most of the contents of this file are automatically generated
 *
 *****************************************************************************/


#include <OFConnectionManager/ofconnectionmanager_config.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <OFConnectionManager/ofconnectionmanager_porting.h>
#include "ofconnectionmanager_int.h"
#include "ofconnectionmanager_log.h"
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <Configuration/configuration.h>

/* <auto.start.cdefs(OFCONNECTIONMANAGER_CONFIG_HEADER).source> */
#define __ofconnectionmanager_config_STRINGIFY_NAME(_x) #_x
#define __ofconnectionmanager_config_STRINGIFY_VALUE(_x) __ofconnectionmanager_config_STRINGIFY_NAME(_x)
ofconnectionmanager_config_settings_t ofconnectionmanager_config_settings[] =
{
#ifdef OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING) },
#else
{ OFCONNECTIONMANAGER_CONFIG_INCLUDE_LOGGING(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT) },
#else
{ OFCONNECTIONMANAGER_CONFIG_LOG_OPTIONS_DEFAULT(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT) },
#else
{ OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT) },
#else
{ OFCONNECTIONMANAGER_CONFIG_LOG_CUSTOM_BITS_DEFAULT(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB) },
#else
{ OFCONNECTIONMANAGER_CONFIG_PORTING_STDLIB(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS) },
#else
{ OFCONNECTIONMANAGER_CONFIG_PORTING_INCLUDE_STDLIB_HEADERS(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI) },
#else
{ OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_ECHO_OPTIMIZATION
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_ECHO_OPTIMIZATION), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_ECHO_OPTIMIZATION) },
#else
{ OFCONNECTIONMANAGER_CONFIG_ECHO_OPTIMIZATION(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_OF_VERSION
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_OF_VERSION), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_OF_VERSION) },
#else
{ OFCONNECTIONMANAGER_CONFIG_OF_VERSION(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_MAX_MSGS_PER_TICK
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_MAX_MSGS_PER_TICK), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_MAX_MSGS_PER_TICK) },
#else
{ OFCONNECTIONMANAGER_CONFIG_MAX_MSGS_PER_TICK(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_ASYNC_MSG_OF_VERSION
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_ASYNC_MSG_OF_VERSION), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_ASYNC_MSG_OF_VERSION) },
#else
{ OFCONNECTIONMANAGER_CONFIG_ASYNC_MSG_OF_VERSION(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_MSGS
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_MSGS), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_MSGS) },
#else
{ OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_MSGS(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
#ifdef OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_BYTES
    { __ofconnectionmanager_config_STRINGIFY_NAME(OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_BYTES), __ofconnectionmanager_config_STRINGIFY_VALUE(OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_BYTES) },
#else
{ OFCONNECTIONMANAGER_CONFIG_MAX_BUNDLE_BYTES(__ofconnectionmanager_config_STRINGIFY_NAME), "__undefined__" },
#endif
    { NULL, NULL }
};
#undef __ofconnectionmanager_config_STRINGIFY_VALUE
#undef __ofconnectionmanager_config_STRINGIFY_NAME

const char*
ofconnectionmanager_config_lookup(const char* setting)
{
    int i;
    for(i = 0; ofconnectionmanager_config_settings[i].name; i++) {
        if(strcmp(ofconnectionmanager_config_settings[i].name, setting)) {
            return ofconnectionmanager_config_settings[i].value;
        }
    }
    return NULL;
}

int
ofconnectionmanager_config_show(struct aim_pvs_s* pvs)
{
    int i;
    for(i = 0; ofconnectionmanager_config_settings[i].name; i++) {
        aim_printf(pvs, "%s = %s\n", ofconnectionmanager_config_settings[i].name, ofconnectionmanager_config_settings[i].value);
    }
    return i;
}

/* <auto.end.cdefs(OFCONNECTIONMANAGER_CONFIG_HEADER).source> */

struct controller {
    indigo_cxn_protocol_params_t proto;
    indigo_cxn_config_params_t config;
    indigo_controller_id_t controller_id;
};

static struct config {
    uint32_t log_flags;
    int keepalive_period_ms;
    int num_controllers;
    struct controller controllers[MAX_CONTROLLERS];
    char cipher_list[INDIGO_TLS_CFG_PARAM_LEN];
    char ca_cert[INDIGO_TLS_CFG_PARAM_LEN];
    char switch_cert[INDIGO_TLS_CFG_PARAM_LEN];
    char switch_priv_key[INDIGO_TLS_CFG_PARAM_LEN];
    int valid;
} staged_config, current_config;

/* Parse a controller string like "tcp:127.0.0.1:6633". */
static indigo_error_t
parse_controller(struct controller *controller, cJSON *root)
{
    indigo_cxn_protocol_t proto;
    indigo_cxn_params_tcp_over_ipv4_t *params4;
    indigo_cxn_params_tcp_over_ipv6_t *params6;
    indigo_cxn_params_unix_t *params_unix;
    char *proto_str = NULL, *ip = NULL, *unix_path = NULL;
    int port;
    int listen;
    int prio;
    indigo_error_t err;

    err = ind_cfg_lookup_string(root, "protocol", &proto_str);
    if (err == INDIGO_ERROR_NOT_FOUND) {
        /* Allow default protocol value */
        proto_str = "tcp";
    } else if (err < 0) {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: 'protocol' must be a string");
        }
        return err;
    }

    if (strcmp(proto_str, "tcp") == 0) {
        proto = INDIGO_CXN_PROTO_TCP_OVER_IPV4;
    } else if (strcmp(proto_str, "tcp6") == 0) {
        proto = INDIGO_CXN_PROTO_TCP_OVER_IPV6;
    } else if (strcmp(proto_str, "tls") == 0) {
        proto = INDIGO_CXN_PROTO_TLS_OVER_IPV4;
    } else if (strcmp(proto_str, "tls6") == 0) {
        proto = INDIGO_CXN_PROTO_TLS_OVER_IPV6;
    } else if (strcmp(proto_str, "unix") == 0) {
        proto = INDIGO_CXN_PROTO_UNIX;
    } else {
        AIM_LOG_ERROR("Config: Invalid controller protocol: %s", proto_str);
        return INDIGO_ERROR_PARAM;
    }

    switch(proto) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:  /* fall-through */
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6:  /* fall-through */
    case INDIGO_CXN_PROTO_TLS_OVER_IPV4:  /* fall-through */
    case INDIGO_CXN_PROTO_TLS_OVER_IPV6:
        err = ind_cfg_lookup_string(root, "ip_addr", &ip);
        if (err < 0) {
            if (err == INDIGO_ERROR_PARAM) {
                AIM_LOG_ERROR("Config: 'ip_addr' must be a string");
            } else if (err == INDIGO_ERROR_NOT_FOUND) {
                AIM_LOG_ERROR("Config: Missing 'ip_addr' in controller spec");
            }
            return err;
        }
        /*
         * WARNING: no validity checks for IP address.
         * Instead, they are performed by the cli front-end.
         */

        err = ind_cfg_lookup_int(root, "port", &port);
        if (err == INDIGO_ERROR_NOT_FOUND) {
            /* Allow default protocol value */
            port = 6633;
        } else if (err < 0) {
            if (err == INDIGO_ERROR_PARAM) {
                AIM_LOG_ERROR("Config: 'port' must be an integer");
            }
            return err;
        }
        if (port < 0 || port >= 0xffff) {
            AIM_LOG_ERROR("Config: Invalid controller port: %d", port);
            return INDIGO_ERROR_PARAM;
        }

        break;

    case INDIGO_CXN_PROTO_UNIX:
        err = ind_cfg_lookup_string(root, "unix_path", &unix_path);
        if (err < 0) {
            if (err == INDIGO_ERROR_PARAM) {
                AIM_LOG_ERROR("Config: 'unix_path' must be a string");
            } else if (err == INDIGO_ERROR_NOT_FOUND) {
                AIM_LOG_ERROR("Config: Missing 'unix_path' in controller spec");
            }
            return err;
        }

    default:
        AIM_DIE("Config: No handling for protocol %d", proto);
    }

    err = ind_cfg_lookup_bool(root, "listen", &listen);
    if (err == INDIGO_ERROR_NOT_FOUND) {
        listen = 0;
    } else if (err < 0) {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: 'listen' must be a boolean");
        }
        return err;
    }

    err = ind_cfg_lookup_int(root, "priority", &prio);
    if (err == INDIGO_ERROR_NOT_FOUND) {
        prio = 0;
    } else if (err < 0) {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: 'priority' must be an integer");
        }
        return err;
    }

    /* populate 'controller' struct */
    switch (proto) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:  /* fall-through */
    case INDIGO_CXN_PROTO_TLS_OVER_IPV4:
        params4 = &controller->proto.tcp_over_ipv4;
        params4->protocol = proto;
        strncpy(params4->controller_ip, ip, sizeof(params4->controller_ip));
        params4->controller_port = port;
        break;
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6:  /* fall-through */
    case INDIGO_CXN_PROTO_TLS_OVER_IPV6:
        params6 = &controller->proto.tcp_over_ipv6;
        params6->protocol = proto;
        strncpy(params6->controller_ip, ip, sizeof(params6->controller_ip));
        params6->controller_port = port;
        break;
    case INDIGO_CXN_PROTO_UNIX:
        params_unix = &controller->proto.unx;
        strncpy(params_unix->unix_path, unix_path, INDIGO_CXN_UNIX_PATH_LEN);
        break;
    default:
        AIM_DIE("Config: No handling for protocol %d", proto);
    }

    controller->config.listen = listen;
    controller->config.cxn_priority = prio;
    controller->config.local = 0;
    controller->config.version = OFCONNECTIONMANAGER_CONFIG_OF_VERSION;

    return INDIGO_ERROR_NONE;
}

/* Parse a JSON array of controllers. */
static indigo_error_t
parse_controllers(cJSON *root)
{
    cJSON *node, *child;
    int count = 0;
    indigo_error_t err;

    node = cJSON_GetObjectItem(root, "controllers");
    if (node == NULL) {
        AIM_LOG_ERROR("Config: Missing 'controllers' array");
        return INDIGO_ERROR_NOT_FOUND;
    }

    if (node->type != cJSON_Array) {
        AIM_LOG_ERROR("Config: expected 'controllers' to be an array");
        return INDIGO_ERROR_PARAM;
    }

    for (count = 0, child = node->child; child; ++count, child = child->next) {
        if (count >= MAX_CONTROLLERS) {
            AIM_LOG_ERROR("Config: More than %d controllers configured",
                          MAX_CONTROLLERS);
            return INDIGO_ERROR_PARAM;
        }

        if (child->type != cJSON_Object) {
            AIM_LOG_ERROR("Config: expected controller spec to be an object");
            return INDIGO_ERROR_PARAM;
        }

        err = parse_controller(&staged_config.controllers[count], child);
        if (err) {
            AIM_LOG_ERROR("Config: Error parsing controller entry %d", count);
            return err;
        }
    }

    AIM_LOG_INFO("Config: Parsed %d controller entries", count);
    staged_config.num_controllers = count;

    return INDIGO_ERROR_NONE;
}

/* Match on the protocol params. */
static const struct controller *
find_controller(const struct config *config,
                const indigo_cxn_protocol_params_t *proto)
{
    int i;
    for (i = 0; i < config->num_controllers; i++) {
        const struct controller *c = &config->controllers[i];
        /* Assumes unused space is zeroed. */
        if (!memcmp(proto, &c->proto, sizeof(*proto))) {
            return c;
        }
    }
    return NULL;
}

static indigo_error_t
parse_tls_config(cJSON *root)
{
    indigo_error_t err;
    char *cipher_list;
    char *ca_cert;
    char *switch_cert;
    char *switch_priv_key;

    err = ind_cfg_lookup_string(root, "cipher_list", &cipher_list);
    if (err == INDIGO_ERROR_NOT_FOUND) {
        AIM_LOG_INFO("Config: No TLS cipher list, default to HIGH");
        cipher_list = "HIGH";
    } else if (err < 0) {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: cipher_list must be a string");
        } else {
            AIM_LOG_ERROR("Config: %s", indigo_strerror(err));
        }
        goto error;
    }

    err = ind_cfg_lookup_string(root, "ca_cert", &ca_cert);
    if (err == INDIGO_ERROR_NOT_FOUND ||
        (ca_cert && ca_cert[0] == '\0')) {
        AIM_LOG_INFO("Config: No ca_cert given, allowed self-signed certs");
        ca_cert = NULL;
    } else if (err < 0) {
        if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: ca_cert must be a string");
        } else {
            AIM_LOG_ERROR("Config: %s", indigo_strerror(err));
        }
        goto error;
    }

    err = ind_cfg_lookup_string(root, "switch_cert", &switch_cert);
    if (err < 0) {
        if (err == INDIGO_ERROR_NOT_FOUND) {
            AIM_LOG_ERROR("Config: Missing switch_cert");
        } else if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: switch_cert must be a string");
        } else {
            AIM_LOG_ERROR("Config: %s", indigo_strerror(err));
        }
        goto error;
    }

    err = ind_cfg_lookup_string(root, "switch_priv_key", &switch_priv_key);
    if (err < 0) {
        if (err == INDIGO_ERROR_NOT_FOUND) {
            AIM_LOG_ERROR("Config: Missing switch_priv_key");
        } else if (err == INDIGO_ERROR_PARAM) {
            AIM_LOG_ERROR("Config: switch_priv_key must be a string");
        } else {
            AIM_LOG_ERROR("Config: %s", indigo_strerror(err));
        }
        goto error;
    }

    if (ind_cxn_verify_tls(cipher_list, ca_cert,
                           switch_cert, switch_priv_key) !=
        INDIGO_ERROR_NONE) {
        AIM_LOG_ERROR("Config: TLS parameter verification failed");
        goto error;
    }

    OFCONNECTIONMANAGER_STRNCPY(staged_config.cipher_list, cipher_list,
                                INDIGO_TLS_CFG_PARAM_LEN);
    if (ca_cert) {
        OFCONNECTIONMANAGER_STRNCPY(staged_config.ca_cert, ca_cert,
                                    INDIGO_TLS_CFG_PARAM_LEN);
    } else {
        OFCONNECTIONMANAGER_MEMSET(staged_config.ca_cert, 0,
                                   INDIGO_TLS_CFG_PARAM_LEN);
    }
    OFCONNECTIONMANAGER_STRNCPY(staged_config.switch_cert, switch_cert,
                                INDIGO_TLS_CFG_PARAM_LEN);
    OFCONNECTIONMANAGER_STRNCPY(staged_config.switch_priv_key, switch_priv_key,
                                INDIGO_TLS_CFG_PARAM_LEN);

    AIM_LOG_INFO("Config: TLS cipher list %s, ca_cert %s, "
                 "switch_cert %s, switch_priv_key %s",
                 cipher_list, ca_cert? ca_cert: "NONE",
                 switch_cert, switch_priv_key);
    return INDIGO_ERROR_NONE;

 error:
    AIM_LOG_VERBOSE("Config: Clearing TLS params");
    OFCONNECTIONMANAGER_MEMSET(staged_config.cipher_list, 0,
                               INDIGO_TLS_CFG_PARAM_LEN);
    OFCONNECTIONMANAGER_MEMSET(staged_config.ca_cert, 0,
                               INDIGO_TLS_CFG_PARAM_LEN);
    OFCONNECTIONMANAGER_MEMSET(staged_config.switch_cert, 0,
                               INDIGO_TLS_CFG_PARAM_LEN);
    OFCONNECTIONMANAGER_MEMSET(staged_config.switch_priv_key, 0,
                               INDIGO_TLS_CFG_PARAM_LEN);
    return err;
}

indigo_error_t
ind_cxn_cfg_stage(cJSON *config)
{
    indigo_error_t err;
    int i;

    err = ind_cfg_parse_loglevel(config, "logging.connection",
                                 OFCONNECTIONMANAGER_CONFIG_LOG_BITS_DEFAULT,
                                 &staged_config.log_flags);
    if (err != INDIGO_ERROR_NONE) {
        return err;
    }

    /* Not supporting setting log options yet */

    err = ind_cfg_lookup_int(config, "keepalive_period_ms", &staged_config.keepalive_period_ms);
    if (err == INDIGO_ERROR_NONE) {
        if (staged_config.keepalive_period_ms <= 0) {
            AIM_LOG_ERROR("'keepalive_period_ms' must be greater than 0");
            return INDIGO_ERROR_PARAM;
        }
    } else if (err == INDIGO_ERROR_PARAM) {
        AIM_LOG_ERROR("Config: Could not parse 'keepalive_period_ms'");
        return err;
    } else if (err == INDIGO_ERROR_NOT_FOUND) {
        AIM_LOG_ERROR("Config: Missing required key 'keepalive_period_ms'");
        return err;
    }

    err = parse_controllers(config);
    if (err != INDIGO_ERROR_NONE) {
        return err;
    }

    for (i = 0; i < staged_config.num_controllers; i++) {
        /* @FIXME local? listen? priority? */
        staged_config.controllers[i].config.periodic_echo_ms = staged_config.keepalive_period_ms;
        staged_config.controllers[i].config.reset_echo_count = 3; /* @FIXME */
    }

    /* verify TLS parameters */
    /*
     * for now, we should be able to accept:
     * - TLS config with switch cert and key specified,
     *   cipher_list and CA cert optional
     * - if cipher_list is specified, it should be valid
     * - if CA cert is specified, it should be consistent with switch cert
     * - TLS config with parameters specified, but
     *   CA cert, switch cert and switch priv key files not present
     */
    {
        cJSON *node = cJSON_GetObjectItem(config, "tls");
        if (node) {
            if (node->type != cJSON_Object) {
                AIM_LOG_ERROR("Config: expected tls to be an object");
                return INDIGO_ERROR_PARAM;
            }
            err = parse_tls_config(node);
            if (err != INDIGO_ERROR_NONE) {
                AIM_LOG_ERROR("Config: error parsing TLS config: %s",
                              indigo_strerror(err));
                return err;
            }
        } else {
            AIM_LOG_VERBOSE("Config: TLS config not found, continuing");
        }
    }

    staged_config.valid = true;

    return INDIGO_ERROR_NONE;
}

static void
ind_cxn_cfg_commit(void)
{
    aim_log_t *lobj;
    int i, enable;

    if (staged_config.valid != true)
        return;

    /* Commit config only if connection manager is enabled. */
    (void) ind_cxn_enable_get(&enable);
    if (!enable)
        return;

    if ((lobj = aim_log_find("ofconnectionmanager")) == NULL) {
        AIM_LOG_WARN("Could not find log module");
    } else {
        lobj->common_flags = staged_config.log_flags;
    }

    /* configure TLS before parsing controller configs */
    (void) indigo_cxn_config_tls(staged_config.cipher_list,
                                 staged_config.ca_cert,
                                 staged_config.switch_cert,
                                 staged_config.switch_priv_key);

    for (i = 0; i < staged_config.num_controllers; i++) {
        struct controller *c = &staged_config.controllers[i];
        const struct controller *old_controller;
        int rv;
        char desc[256];

        ind_cxn_proto_ip_string(&c->proto, desc, sizeof(desc));
        AIM_LOG_INFO("controller %d: %s", i, desc);

        /* Keep existing connections to the same controller. */
        if ((old_controller = find_controller(&current_config, &c->proto))) {
            c->controller_id = old_controller->controller_id;
            /* TODO apply keepalive_period to existing connection. */
            continue;
        }

        rv = indigo_controller_add(&c->proto, &c->config, &c->controller_id);
        if (rv != 0) {
            AIM_LOG_ERROR("failed to add controller connection %d: %s",
                          i, desc);
        }
    }

    /* Remove controller's that don't exist in the new configuration. */
    for (i = 0; i < current_config.num_controllers; i++) {
        const struct controller *c = &current_config.controllers[i];
        if (!find_controller(&staged_config, &c->proto)) {
            (void) indigo_controller_remove(c->controller_id);
        }
    }

    /* Save config so we can diff the controllers next time */
    current_config = staged_config;
    staged_config.valid = false;
}

void
ofconnectionmanager_config_commit(void)
{
    ind_cxn_cfg_commit();
}

const struct ind_cfg_ops ind_cxn_cfg_ops = {
    .stage = ind_cxn_cfg_stage,
    .commit = ind_cxn_cfg_commit,
};

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
 * OFConnectionManager Generic uCli Interfaces.
 *
 * Available for Query, Status, and Debug.
 *
 *****************************************************************************/
#include <OFConnectionManager/ofconnectionmanager_config.h>


#if OFCONNECTIONMANAGER_CONFIG_INCLUDE_UCLI == 1

#include <uCli/ucli.h>
#include <uCli/ucli_argparse.h>
#include <uCli/ucli_handler_macros.h>

#include "ofconnectionmanager_int.h"


static ucli_status_t
ofconnectionmanager_ucli_ucli__config__(ucli_context_t* uc)
{
    UCLI_COMMAND_INFO(uc,
                      "config", 0,
                      "$summary#config command.");
    ucli_printf(uc, "todo: support config command\n");

    return UCLI_STATUS_OK;
}

static ucli_status_t
ofconnectionmanager_ucli_ucli__stats__(ucli_context_t *uc)
{
    char *str;
    int details = 0;

    UCLI_COMMAND_INFO(uc,
                      "stats", -1,
                      "$summary#Show connection stats.");
    if (uc->pargs->count == 1) {
        UCLI_ARGPARSE_OR_RETURN(uc, "s", &str);
        if (!strncmp(str, "detail", 6)) { /* Allow detail or details */
            details = 1;
        } else {
            return UCLI_STATUS_E_ARG;
        }
    } else if (uc->pargs->count > 1) {
        return UCLI_STATUS_E_ARG;
    }

    ind_cxn_stats_show(&uc->pvs, details);

    return UCLI_STATUS_OK;
}

static ucli_status_t
ofconnectionmanager_ucli_ucli__pending_stats__(ucli_context_t *uc)
{
    UCLI_COMMAND_INFO(uc,
                      "pending_stats", 0,
                      "$summary#Show accumulated cxns outstanding stats.");

    ind_cxn_accumulated_pending_op_stats_show(&uc->pvs);

    return UCLI_STATUS_OK;
}

static ucli_status_t
ofconnectionmanager_ucli_ucli__pending_stats_clear__(ucli_context_t *uc)
{
    UCLI_COMMAND_INFO(uc,
                      "pending_stats_clear", 0,
                      "$summary#Clear accumulated cxns outstanding stats.");

    ind_cxn_accumulated_pending_op_stats_clear(&uc->pvs);

    return UCLI_STATUS_OK;
}

static ucli_status_t
ofconnectionmanager_ucli_ucli__tls__(ucli_context_t *uc)
{
    UCLI_COMMAND_INFO(uc,
                      "tls", 0,
                      "$summary#Show TLS configuration.");

    ind_cxn_tls_config_show(&uc->pvs);

    return UCLI_STATUS_OK;
}

static char *
get_ip(indigo_cxn_protocol_params_t *params)
{
    switch(params->header.protocol) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:
        return params->tcp_over_ipv4.controller_ip;
        break;
    case INDIGO_CXN_PROTO_TLS_OVER_IPV4:
        return params->tls_over_ipv4.controller_ip;
        break;
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6:
        return params->tcp_over_ipv6.controller_ip;
        break;
    case INDIGO_CXN_PROTO_TLS_OVER_IPV6:
        return params->tls_over_ipv6.controller_ip;
        break;
    default:
        return NULL;
    }
}

static uint16_t
get_port(indigo_cxn_protocol_params_t *params)
{
    switch(params->header.protocol) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:
        return params->tcp_over_ipv4.controller_port;
        break;
    case INDIGO_CXN_PROTO_TLS_OVER_IPV4:
        return params->tls_over_ipv4.controller_port;
        break;
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6:
        return params->tcp_over_ipv6.controller_port;
        break;
    case INDIGO_CXN_PROTO_TLS_OVER_IPV6:
        return params->tls_over_ipv6.controller_port;
        break;
    default:
        return 0;
    }
}

static char *
get_protocol(indigo_cxn_protocol_params_t *params)
{
    switch(params->header.protocol) {
    case INDIGO_CXN_PROTO_TCP_OVER_IPV4:  /* fall-through */
    case INDIGO_CXN_PROTO_TCP_OVER_IPV6:
        return "TCP";
        break;
    case INDIGO_CXN_PROTO_TLS_OVER_IPV4:  /* fall-through */
    case INDIGO_CXN_PROTO_TLS_OVER_IPV6:
        return "TLS";
        break;
    default:
        return "UNK";
    }
}

static char *
get_role_name(indigo_cxn_role_t role)
{
    switch (role) {
    case INDIGO_CXN_R_MASTER:
        return "MASTER";
        break;
    case INDIGO_CXN_R_SLAVE:
        return "SLAVE";
        break;
    case INDIGO_CXN_R_EQUAL:
        return "EQUAL";
        break;
    default:
        return "UNKNOWN";
    }
}

static ucli_status_t
ofconnectionmanager_ucli_ucli__controller_list__(ucli_context_t *uc)
{
    indigo_controller_info_t* ctrl;
    indigo_controller_info_t* list = NULL;
    int count = 0;
    indigo_cxn_status_t status;
    indigo_error_t rv;
    const char* statename;
    const char* rolename;

    UCLI_COMMAND_INFO(uc,
                      "controller-list", 0,
                      "$summary#Show controller connections.");


    indigo_controller_list(&list);

    for(ctrl = list; ctrl; ctrl = ctrl->next) {
        if (ctrl->main_cxn_id == INDIGO_CXN_ID_UNSPECIFIED) {
            statename = "DISCONNECTED";
            rolename = "EQUAL";
        } else {
            rv = indigo_cxn_connection_status_get(ctrl->main_cxn_id,
                                                  &status);
            if (rv == INDIGO_ERROR_NONE) {
                statename = status.is_connected?
                    "CONNECTED": "DISCONNECTED";
                rolename = get_role_name(ctrl->role);
            } else {
                statename = "UNKNOWN";
                rolename = "UNKNOWN";
            }
        }

        char *ip = get_ip(&ctrl->protocol_params);
        uint16_t port = get_port(&ctrl->protocol_params);
        char *protocol = get_protocol(&ctrl->protocol_params);
        /* dump as yaml for cli to parse and reformat */
        ucli_printf(uc, "%d:\n  ip: %s\n  port: %u\n  protocol: %s\n"
                    "  state: %s\n  role: %s\n  naux: %u\n",
                    count++, ip? ip: "invalid", port, protocol,
                    statename, rolename, ctrl->num_aux);
    }

    indigo_controller_list_destroy(list);
    return UCLI_STATUS_OK;
}

/* <auto.ucli.handlers.start> */
/******************************************************************************
 *
 * These handler table(s) were autogenerated from the symbols in this
 * source file.
 *
 *****************************************************************************/
static ucli_command_handler_f ofconnectionmanager_ucli_ucli_handlers__[] =
{
    ofconnectionmanager_ucli_ucli__config__,
    ofconnectionmanager_ucli_ucli__stats__,
    ofconnectionmanager_ucli_ucli__pending_stats__,
    ofconnectionmanager_ucli_ucli__pending_stats_clear__,
    ofconnectionmanager_ucli_ucli__tls__,
    ofconnectionmanager_ucli_ucli__controller_list__,
    NULL
};
/******************************************************************************/
/* <auto.ucli.handlers.end> */

static ucli_module_t
ofconnectionmanager_ucli_module__ =
    {
        "ofconnectionmanager_ucli",
        NULL,
        ofconnectionmanager_ucli_ucli_handlers__,
        NULL,
        NULL,
    };


ucli_node_t*
ofconnectionmanager_ucli_node_create(void)
{
    ucli_node_t* n;
    ucli_module_init(&ofconnectionmanager_ucli_module__);
    n = ucli_node_create("ofconnectionmanager", NULL,
                         &ofconnectionmanager_ucli_module__);
    ucli_node_subnode_add(n,
                          ucli_module_log_node_create("ofconnectionmanager"));
    return n;
}

#else
void*
ofconnectionmanager_ucli_node_create(void)
{
    return NULL;
}
#endif

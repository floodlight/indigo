/****************************************************************
 *
 *        Copyright 2016, Big Switch Networks, Inc.
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

/**
 * @file
 * @brief OpenFlow message handlers for generic stats messages
 *
 * See detailed documentation in the Indigo architecture headers.
 */

#include "ofstatemanager_log.h"

#include <OFStateManager/ofstatemanager_config.h>
#include <indigo/indigo.h>
#include <loci/loci.h>
#include "ofstatemanager_decs.h"
#include "ofstatemanager_int.h"
#include "handlers.h"

static LIST_DEFINE(generic_stats_head);

struct generic_stats {
    list_links_t links;
    indigo_core_generic_stats_f handler;
    void *priv;
    of_str64_t name;
};

static struct generic_stats *find_generic_stats(const char *name);

void
indigo_core_generic_stats_register(
    const char *name,
    indigo_core_generic_stats_f handler,
    void *priv)
{
    AIM_ASSERT(strlen(name) < sizeof(of_str64_t));
    AIM_ASSERT(find_generic_stats(name) == NULL);
    struct generic_stats *generic_stats = aim_zmalloc(sizeof(*generic_stats));
    strncpy(generic_stats->name, name, sizeof(generic_stats->name));
    generic_stats->handler = handler;
    generic_stats->priv = priv;
    list_push(&generic_stats_head, &generic_stats->links);
}

void
indigo_core_generic_stats_unregister(const char *name)
{
    struct generic_stats *generic_stats = find_generic_stats(name);
    if (generic_stats == NULL) {
        return;
    }

    list_remove(&generic_stats->links);
    aim_free(generic_stats);
}

void
ind_core_bsn_generic_stats_request_handler(
    of_object_t *req,
    indigo_cxn_id_t cxn_id)
{
    of_str64_t name;
    of_bsn_generic_stats_request_name_get(req, &name);

    struct generic_stats *generic_stats = find_generic_stats(name);
    if (generic_stats == NULL) {
        char msg[128];
        snprintf(msg, sizeof(msg), "Unknown generic stats request '%.64s'", name);
        indigo_cxn_send_bsn_error(cxn_id, req, msg);
        return;
    }

    generic_stats->handler(cxn_id, req, generic_stats->priv);
}

static struct generic_stats *
find_generic_stats(const char *name)
{
    struct list_links *cur;
    LIST_FOREACH(&generic_stats_head, cur) {
        struct generic_stats *generic_stats = container_of(cur, links, struct generic_stats);
        if (!strncmp(generic_stats->name, name, sizeof(of_str64_t))) {
            return generic_stats;
        }
    }
    return NULL;
}

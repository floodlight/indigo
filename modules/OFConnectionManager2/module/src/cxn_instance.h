/****************************************************************
 *
 *        Copyright 2013-2015, Big Switch Networks, Inc.
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
 * @brief Reference implemenation interface for the a connection instance
 *
 * Based on the Indigo2 architecture, but specific to Linux Ref Implemenation
 */

#ifndef _CXN_INSTANCE_H_
#define _CXN_INSTANCE_H_

#include <loci/loci.h>
#include <OFConnectionManager/ofconnectionmanager.h>
#include <BigList/biglist.h>
#include <debug_counter/debug_counter.h>
#include <BigRing/bigring.h>

#define READ_BUFFER_SIZE (64 * 1024)

/**
 * The write buffer size is artificial in that the original data
 * is buffered rather than copying into a local buffer.  This value
 * is used to limit the amount of data queued.
 *
 * NOTE:  If you make this less than (or equal to) 64K, you will only
 * be able to enqueue one message.  In general, it is recommended that
 * you have this at least as the max size transation response (like
 * dumping the whole flow table).  Since this size depends on the
 * number of entries in the flow table, and that is platform dependent,
 * this should really be determined by the platform specific code and
 * made visible via the config.
 */
#define WRITE_BUFFER_SIZE (16 * 1024 * 1024)

/**
 * Maximum number of messages that can be waiting to be written to the socket
 */
#define WRITE_QUEUE_SIZE 1000

/**
 * Write queue length above which to drop noncritical messages
 */
#define NONCRITICAL_DROP_THRESHOLD 64

/**
 * Maximum number of controllers
 */
#define MAX_CONTROLLERS 16

/**
 * Maximum connections including remote and local across all controllers
 */
#define MAX_CONTROLLER_CONNECTIONS 32

/**
 * Maximum auxiliary connections possible per controller 
 */
#define MAX_AUX_CONNECTIONS 8       

/**
 * The connection ID is split into two fields. The lower 16 bits are the index
 * of the connection in the connection array. The upper 16 bits are a
 * generation ID. Each time the connection disconnects, the generation ID is
 * incremented. Because we compare the connection IDs when doing a lookup,
 * we will fail attempts to use a stale connection ID.
 */
#define CXN_ID_GENERATION_SHIFT 16
#define CXN_ID_TO_INDEX(cxn_id) ((cxn_id) & ((1<<CXN_ID_GENERATION_SHIFT)-1))
#define CXN_ID_TO_GENERATION(cxn_id) ((cxn_id) >> CXN_ID_GENERATION_SHIFT)

#define CXN_ID_VALID(cxn_id)                                            \
    (((cxn_id) >= 0) && (CXN_ID_TO_INDEX(cxn_id) < MAX_CONTROLLER_CONNECTIONS))
#define CXN_TO_CXN_ID(cxn) ((cxn)->cxn_id)


/* Format a connection id as index:generation */
#define CXN_ID_FMT "%u:%u"
#define CXN_ID_FMT_ARGS(cxn_id) \
    CXN_ID_TO_INDEX(cxn_id), CXN_ID_TO_GENERATION(cxn_id)

#define MAX_CONTROLLER_DESC_LEN (64)


/* Controller control block */
typedef struct controller_s {
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_cxn_role_t role;

    int active; /* Has this controller instance been configured? */
    int restartable; /* Should this controller be restarted when its main cxn 
                      * is disconnected? */
    uint32_t fail_count;  /* Increments each time a main cxn attempt fails;
                           * cleared when TCP connection is established */
    indigo_controller_id_t controller_id;

    uint32_t num_aux; /* Auxillary connection count */

    /* Pointers to all connections for this controller (main and aux) */
    struct connection_s *cxns[MAX_AUX_CONNECTIONS+1];

    char desc[MAX_CONTROLLER_DESC_LEN];  /* For logging */
} controller_t;


/**
 * Connection states:
 * CXN_S_INIT                Connecting
 * CXN_S_HANDSHAKING         TCP Connection established
 * CXN_S_HANDSHAKE_COMPLETE  OpenFlow handshake (features) complete
 * CXN_S_CLOSING             Connection broken, cleaning up
 *                           outstanding operations
 * CXN_S_CLOSED              Clean up complete;
 *                           connection_t can be released
 *
 * Timeouts are 5 seconds for all states except HANDSHAKE_COMPLETE and CLOSED.
 */

/*
 * each connection state is a tuple of
 *   (value, id, human-readable name, timeout).
 * the timeouts have units of milliseconds.
 * a timeout of zero indicates that there is no timeout.
 */
#define CXN_S_DESCS                                                     \
    cxn_s_desc(0, CXN_S_INIT, "Initialized", 5000)                      \
    cxn_s_desc(1, CXN_S_HANDSHAKING, "Handshaking", 5000)               \
    cxn_s_desc(2, CXN_S_HANDSHAKE_COMPLETE, "Handshake Complete", 0)    \
    cxn_s_desc(3, CXN_S_CLOSING, "Closing", 5000)                       \
    cxn_s_desc(4, CXN_S_CLOSED, "Closed", 0)                            \
    cxn_s_desc(5, CXN_S_COUNT, "COUNT", 0) /* last value */

typedef enum cxn_state_e {
#define cxn_s_desc(_val, _id, _name, _timeout) _id = _val,
    CXN_S_DESCS
#undef cxn_s_desc
} cxn_state_t;


#define MAX_BUNDLES 4
#define BUNDLE_ID_INVALID (-1)

typedef struct bundle_s {
    uint32_t id;    /* Supplied by controller when bundle is opened */
    uint32_t count; /* Number of messages in bundle */
    uint32_t allocated; /* Length of msgs array */
    uint32_t bytes; /* Sum of message sizes */
    uint16_t flags; /* Copied from flags field in bundle-open request */
    uint8_t **msgs; /* Array of pointers to raw message data */
} bundle_t;


#define MAX_AUX_ID_DESC_LEN (4)

/* Connection control block */
typedef struct connection_s {
    cxn_state_t state;
    indigo_cxn_status_t status;

    int active; /* Has this connection instance been configured? */
    indigo_cxn_id_t cxn_id; /* For back tracking */

    int sd; /* The socket descriptor */

    /*
     * The read buffer is used to buffer a single message.  There
     * are two steps to the operation: Read the header, then use that
     * to determine the number of bytes remaining in the message.
     * Once a message is read in, it is processed and the read buffer
     * is cleared.
     */
    uint8_t read_buffer[READ_BUFFER_SIZE];
    int read_bytes; /* Number of bytes currently in read buffer */
    int bytes_needed; /* Num bytes needed for next process step */

    /* Write queue */
    bigring_t *write_queue; /* Ringbuffer of pointers to message data */
    int write_queue_head_offset; /* Bytes already sent out from head of write_queue */
    int bytes_enqueued;     /* Total bytes queued */
    int pkts_enqueued;      /* Total pkts queued */

    /* Additional debug info */
    int has_debug_counters;
    debug_counter_t tx_drop_counter;
    debug_counter_t rx_counters[OF_MESSAGE_OBJECT_COUNT];
    debug_counter_t tx_counters[OF_MESSAGE_OBJECT_COUNT];

    /* Barrier */
    int outstanding_op_cnt; /* Number of outstanding operations */
    struct {
        unsigned char pendingf;           /* Barrier reply pending flag */
        uint32_t      xid;                /* XID of barrier request */
    } barrier;

    /* Echo */
    struct {
        uint32_t outstanding_echo_cnt;  /* number of unacknowledged echoes */
        uint32_t threshold;  /* value above which cxn is declared dead */
        uint32_t period_ms;  /* keepalive period in milliseconds */
    } keepalive;

    bundle_t bundles[MAX_BUNDLES];

    /* Message Tracing */
    aim_pvs_t* trace_pvs;

    /* Used by the bsn_time_request message handler */
    indigo_time_t hello_time;

    /* Zero for main connection and non-zero for other connections */
    uint8_t aux_id;

    /* Pointer to the controller to which this connection belongs */
    controller_t *controller;

    /* If set, don't read any messages for this connection */
    bool paused;

    char desc[MAX_CONTROLLER_DESC_LEN+MAX_AUX_ID_DESC_LEN];  /* For logging */
} connection_t;

/**
 * How many bytes in buffer are free
 * See notes above about WRITE_BUFFER_SIZE.
 */
#define CXN_WRITE_BYTES_AVAIL(cxn) \
    (WRITE_BUFFER_SIZE - ((cxn)->bytes_enqueued))

/**
 * Is a connection active (in any state)?
 */
#define CXN_ACTIVE(cxn) ((cxn)->active)

/**
 * Is connection marked local
 */
#define CXN_LOCAL(cxn) ((cxn)->controller->config_params.local)

/**
 * Is connection marked listen
 */
#define CXN_LISTEN(cxn) ((cxn)->controller->config_params.listen)

/**
 * Is a controller active?
 */
#define CONTROLLER_ACTIVE(controller) ((controller)->active)

/**
 * Is a connection TCP connected?
 */
#define CXN_TCP_CONNECTED(cxn)                                          \
    (CXN_ACTIVE(cxn) &&                                                 \
     ((cxn->state == CXN_S_HANDSHAKING) ||                              \
      (cxn->state == CXN_S_HANDSHAKE_COMPLETE)))


static inline indigo_cxn_config_params_t*
get_connection_config(connection_t *cxn)
{
    if (cxn && cxn->controller) {
        return (&cxn->controller->config_params);
    } else {
        return NULL;
    }
} 

static inline indigo_cxn_protocol_params_t*
get_connection_params(connection_t *cxn)
{
    if (cxn && cxn->controller) {
        return (&cxn->controller->protocol_params);
    } else {
        return NULL;
    }
}


extern void
cxn_init_instances(void);

extern connection_t *
cxn_id_to_connection(indigo_cxn_id_t cxn_id);

extern connection_t *
cxn_alloc(controller_t *controller, uint8_t aux_id, int sock_id);
extern void
cxn_start(connection_t *cxn);
extern void
cxn_stop(connection_t *cxn);
extern void
cxn_free(connection_t *cxn);

extern int
cxn_is_handshake_complete(const connection_t *cxn);
extern int
cxn_is_closed(const connection_t *cxn);

extern int
cxn_instance_enqueue(connection_t *cxn, uint8_t *data, int len);

extern indigo_error_t 
cxn_send_echo_request(connection_t *cxn);

void cxn_notify_features_reply_sent(connection_t *cxn);

void ind_cxn_block_barrier(connection_t *cxn);
void ind_cxn_unblock_barrier(connection_t *cxn);

void cxn_pause(connection_t *cxn);
void cxn_resume(connection_t *cxn);

void ind_cxn_process_message(connection_t *cxn, of_object_t *obj);

void
ind_cxn_populate_connection_list(of_list_bsn_controller_connection_t *list);

#endif /* _CXN_INSTANCE_H_ */

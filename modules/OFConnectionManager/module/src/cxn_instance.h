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
 * Connection flag, connection is to be removed pending op completion
 */
#define CXN_TO_BE_REMOVED 0x1

/* Connection control block */
typedef struct connection_s {
    indigo_cxn_protocol_params_t protocol_params;
    indigo_cxn_config_params_t config_params;
    indigo_cxn_status_t status;
    uint32_t flags;

    /* Internal configuration below */
    int active; /* Has this connection instance been configured? */
    int fail_count; /* How may failed connection tries */
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
    biglist_t *output_list; /* List of outgoing messages */
    int output_head_offset; /* Bytes already sent out from head of output_list */
    int bytes_enqueued;     /* Total bytes queued */
    int pkts_enqueued;      /* Total pkts queued */

    /* Additional debug info */
    uint64_t messages_in_by_type[OF_MESSAGE_OBJECT_COUNT];
    uint64_t messages_out_by_type[OF_MESSAGE_OBJECT_COUNT];
    uint64_t messages_in_unknown;
    uint64_t messages_out_unknown;

    uint64_t packet_ins;

    biglist_t *outstanding_ops; /* Used only if OF_OBJECT_TRACKING is on */
    int outstanding_op_cnt; /* Number of outstanding operations */
    struct {
        unsigned char pendingf;           /* Barrier reply pending flag */
        uint32_t      xid;                /* XID of barrier request */
    } barrier;

    /* @todo clean this up */
    struct {
        uint32_t outstanding_echo_cnt;  /* number of unacknowledged echoes */
        uint32_t threshold;  /* value above which connection is declared dead */
        uint32_t period_ms;     /* keepalive period in milliseconds */
        uint32_t xid;   /* xid of last outstanding echo reply */
    } keepalive;


    /* Message Tracing */
    aim_pvs_t* trace_pvs;

    /* To detect object staleness */
    uint32_t generation_id;
    
} connection_t;



/**
 * Should a packet in be dropped based on connection state?
 * @TODO This may need tuning
 */
#define PACKET_IN_DROP_QUEUE_MAX 64
#define CXN_DROP_PACKET_IN(cxn, obj)                    \
    ((cxn)->pkts_enqueued > PACKET_IN_DROP_QUEUE_MAX)

/**
 * Should a flow removed message be dropped based on connection state?
 * @TODO This may need tuning
 */
#define FLOW_REMOVED_DROP_QUEUE_MAX 64
#define CXN_DROP_FLOW_REMOVED(cxn, obj)                \
    ((cxn)->pkts_enqueued > FLOW_REMOVED_DROP_QUEUE_MAX)

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
#define CXN_LOCAL(cxn) ((cxn)->config_params.local)

/**
 * Is connection marked listen
 */
#define CXN_LISTEN(cxn) ((cxn)->config_params.listen)

/**
 * The connection state of connection
 *
 * @fixme Expose timeout for connecting and closing states
 *
 * NOTE Only connecting and closing states support timeouts
 */
typedef struct state_info_s {
    char name[32];
    int timeout;
} state_info_t;


extern state_info_t state_info[INDIGO_CXN_S_COUNT];
#define CXN_STATE_NAME(state) (state_info[state].name)
#define CXN_STATE_TIMEOUT(state) (state_info[state].timeout)
#define CONNECTION_STATE(cxn) ((cxn)->status.state)

/**
 * Is a connection connected?
 */
#define CXN_TCP_CONNECTED(cxn)                                          \
    (CXN_ACTIVE(cxn) &&                                                 \
     ((CONNECTION_STATE(cxn) == INDIGO_CXN_S_CONNECTING) ||             \
      (CONNECTION_STATE(cxn) == INDIGO_CXN_S_HANDSHAKE_COMPLETE)))

/**
 * Is a connection connected?
 */
#define CXN_HANDSHAKE_COMPLETE(cxn)                                     \
    (CXN_ACTIVE(cxn) &&                                                 \
     (CONNECTION_STATE(cxn) == INDIGO_CXN_S_HANDSHAKE_COMPLETE))

extern int ind_cxn_instance_enqueue(connection_t *cxn, uint8_t *data, int len);

extern int ind_cxn_send_hello(connection_t *cxn);

extern int ind_cxn_try_to_connect(connection_t *cxn);

extern void ind_cxn_connection_retry_timer(void *cookie);

extern indigo_error_t ind_cxn_send_echo_request(connection_t *cxn);

extern void ind_cxn_disconnect(connection_t *cxn);

extern void ind_cxn_disconnected_init(connection_t *cxn);

extern void ind_cxn_state_set(connection_t *cxn, indigo_cxn_state_t new_state);


/****************************************************************
 * Debug and logging routines
 ****************************************************************/

/* WARNING: single threaded; ipv4 specific */
/* Display the IP/port for a connection based on params */
static char ip_print_buf[64];
static inline char *
proto_ip_string(indigo_cxn_protocol_params_t *params)
{
    int port;

    port = params->tcp_over_ipv4.controller_port;

    sprintf(ip_print_buf, "%s:%d", params->tcp_over_ipv4.controller_ip, port);

    return ip_print_buf;
}

/* As above, but based on a connection ID */
static inline char *
cxn_ip_string(connection_t *cxn)
{
    return proto_ip_string(&cxn->protocol_params);
}

extern int ind_cxn_process_write_buffer(connection_t *cxn);
extern int ind_cxn_process_read_buffer(connection_t *cxn);

#if 0 /* TBD */
/**
 * Flags for a connection instance
 *
 * CXN_F_DO_ECHO_REPLIES Should the connection instance respond
 * to echo requests
 *
 * CXN_F_INITIATE_HELLO Immediately send a HELLO when connected
 *
 */

#define CXN_F_DO_ECHO_REPLIES (1 << 0)
#define CXN_F_INITIATE_HELLO (1 << 1)
#endif /* TBD */

#endif /* _CXN_INSTANCE_H_ */

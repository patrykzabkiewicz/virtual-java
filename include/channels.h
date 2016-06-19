/**
 *
 * channels.h
 *
 * channels implementation similar to QNX channels
 *
 *  Created on: 16 kwi 2016
 *      Author: zabkiewi
 *
 */
#ifndef CHANNELS_H
#define CHANNELS_H

#include "typedef.h"
#include "mmalloc.h"
#include "bool.h"


#define CHNL_SIZE 256

#define _flag_tbag 0x01
#define _flag_trex 0x02
#define _flag_tmux 0x03

struct _msg_info {        /* _msg_info    _server_info */
    uint32  nd;         /*  client      server */
    uint32  srcnd;      /*  server      n/a */
    uint32  pid;        /*  client      server */
    int32   tid;        /*  thread      n/a */
    int32   chid;       /*  server      server */
    int32   scoid;      /*  server      server */
    int32   coid;       /*  client      client */
    int32   msglen;     /*  msg         n/a */
    int32   srcmsglen;  /*  thread      n/a */
    int32   dstmsglen;  /*  thread      n/a */
    int16   priority;   /*  thread      n/a */
    int16   flags;      /*  n/a         client */
    uint32  reserved;
};

typedef struct _MSG {
        int type;
        int len;
        char body[0]; // null terminated
} MSG;


/* Channel describing structure */
typedef struct _channel {
	void * msg;					/* channel size */
	uint32 cur_bytes;
	uint8 chnl[0];			/* null byte */
} CHNL;

static CHNL * channels[10];

/* channel create */
uint32 createChnl(uint32 flags);

/* destroys channel */
uint32 destroyChnl(uint32 chid);

/* Reads date from the channel */
uint32 MsgReceive( uint32 chid,
                void * msg,
                uint32 bytes,
                struct _msg_info * info );


/* Writes date onto a channel */
uint32 MsgSend( uint32 coid,
             const void * smsg,
             uint32 sbytes,
             void * const rmsg,
             uint32 rbytes );

#endif // CHANNELS_H

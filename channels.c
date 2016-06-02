
#include "channels.h"

/* channel create */
uint32 createChnl(uint32 flags) 
{
    static uint32 cur_chnl = 0; // static variable

    channels[cur_chnl] = (CHNL *) malloc(sizeof(CHNL));
    return cur_chnl++; // no mistake here
}

/* destroys channel */
uint32 destroyChnl(uint32 chid)
{
    // free the memory
    free(channels[chid]->msg);
    free(channels[chid]);
    return true;
}

/* Reads date from the channel */
uint32 MsgReceive( uint32 chid,
                void * msg,
                uint32 bytes,
                struct _msg_info * info )
{
	if(bytes <= channels[chid]->cur_bytes) {
		memcpy(msg, channels[chid]->msg, bytes);
	}
    return true;
}


/* Writes date onto a channel */
uint32 MsgSend( uint32 coid,
             const void * const smsg,
             uint32 sbytes,
             void * const rmsg,
             uint32 rbytes )
{
    return true;
}

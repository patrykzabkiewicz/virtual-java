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

#define CHNL_SIZE 256

/* Channel describing structure */
typedef struct _channel {
	uint8 * D;
	uint8 msg_size;
	int32 count;
	int32 num_recivers;
	uint8 chnl_size[CHNL_SIZE];
	uint8 chnl[0] = { 0 };
} CHNL;


/* channel create */
void createChnl(uint8 * const CHNL, uint8 msg_size);


/* attache listener to a channel */
void attachChnl(uint8 * const CHNL, void * listener);


/* Reads date from the channel */
void * readChnl(uint8 * CHNL, uint8 size);


/* Writes date onto a channel */
void writeChnl(uint8 * CHNL, uint8 size);

#endif // CHANNELS_H

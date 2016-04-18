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
	int32 user_count;
	int32 current_readers;
} CHNL;


/* Reads date from the channel */
void readChnl(uint8 * CHNL, uint8 size);


/* Writes date onto a channel */
void writeChnl(uint8 * CHNL, uint8 size);

#endif // CHANNELS_H

/**
 *
 * event.h
 *
 *  Created on: 16 kwi 2016
 *      Author: zabkiewi
 *
 */

#ifndef EVENT_H
#define EVENT_H

#include "typedef.h"
#include "time.h"

typedef struct _event {
	uint32 id;
	uint32 date;
	uint32 type;
	uint32 data_lenght;
	time_t datetime;
	void * data;
	uint8 end[1];
} EVENT;

void event_init(EVENT * const e);

#endif // EVENT_H

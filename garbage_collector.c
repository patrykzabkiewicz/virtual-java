/*
 * garbage_collector.c
 *
 *  Created on: 20 kwi 2016
 *      Author: zabkiewp
 */

#include "garbage_collector.h"

/* garbage collector init */
void garbage_init(QUEUE * const gb) {
	pthread_t pth;	// this is our thread identifier

	/* Create worker thread */
	pthread_create(&pth,0,garbage_worker,0);

	/* wait for our thread to finish before continuing */
	pthread_join(pth, 0 /* void ** return value could go here */);

}

/* worker in thread to check if the garbage has to be collected */
void garbage_worker() {
	while(1) {
		if(garbage_collector->count > GARBAGE_COLLECTOR_LIMIT) {
			garbage_collect(garbage_collector);
		}
		sleep(1);
	}
}

/** 
 * garbage collector has three stages of collection
 *
 * 1. collects objects that has been created only once
 * 2. if it finds the objects that were here 
 *
 * collects garbage 
 */
void garbage_collect(QUEUE * const gb) {
	uint32 bytes;
	void * garbage;
	while(gb) {
		bytes = queue_pop(gb, garbage);
		free(garbage);
	}
}

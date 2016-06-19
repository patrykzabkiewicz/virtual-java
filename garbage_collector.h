/*
 * garbage_collector.h
 *
 *  Created on: 20 kwi 2016
 *      Author: zabkiewp
 */

#ifndef GARBAGE_COLLECTOR_H_
#define GARBAGE_COLLECTOR_H_

#include <pthread.h>
#include <unistd.h>

#include "queue.h"
#include "mmalloc.h"

#define GARBAGE_COLLECTOR_LIMIT 10

QUEUE * garbage_collector;

/* garbage collector init */
void garbage_init(QUEUE * const gb);

/* worker in thread to check if the garbage has to be collected */
void * garbage_worker(void *);

/* collect garbage */
void garbage_collect(QUEUE * const gb);

#endif /* GARBAGE_COLLECTOR_H_ */

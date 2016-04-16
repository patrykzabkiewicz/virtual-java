/*
 * priority_queue.h
 *
 *  Created on: 16 kwi 2016
 *      Author: zabkiewi
 */

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include "typedef.h"

/* priority queue basic element */
typedef struct _priority_queue_elem {
	uint32 priority;
	struct _priority_queue_elem * next;
} PRIO_QUEUE_ELEM;

/* priority queue structure */
typedef struct _priority_queue {
	PRIO_QUEUE_ELEM * first;
	PRIO_QUEUE_ELEM * last;
	uint8 * copy : 1;  /* copy-on-write idiom */
	uint32 count;
	uint32 elem_size;
	uint32 max_size;
	void * comparator;
} PRIO_QUEUE;

/* priority queue initialization */
void priority_queue_init(
		PRIO_QUEUE * pqueue,	/* queue pointer */
		uint32 elem_size, 		/* single element size */
		void * comparator 		/* comparator function pointer */
);

/* priority queue copy-on-write */
PRIO_QUEUE * priority_queue_copy(PRIO_QUEUE * pqueue);

/* hard copy of whole queue */
PRIO_QUEUE * priority_queue_hard_copy(PRIO_QUEUE * pqueue);

/* pop element from front */
void * pop_front(PRIO_QUEUE * pqueue);

/* push element back to queue */
void push_back(PRIO_QUEUE * pqueue, void * data);

#endif /* PRIORITY_QUEUE_H_ */

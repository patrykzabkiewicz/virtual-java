/*
 * priority_queue.c
 *
 *  Created on: 16 kwi 2016
 *      Author: zabkiewi
 */

#include "priority_queue.h"

/* priority queue initialization */
void priority_queue_init(
		PRIO_QUEUE * pqueue,	/* queue pointer */
		uint32 elem_size, 		/* single element size */
		void * comparator 		/* comparator function pointer */
		) {
	pqueue->copy 	= 0;
	pqueue->count 	= 0;
	pqueue->first 	= 0;
	pqueue->last	= 0;
}

/* priority queue copy-on-write */
PRIO_QUEUE * priority_queue_copy(PRIO_QUEUE * pqueue) {
	PRIO_QUEUE * tmp;
	return tmp;
}

/* hard copy of whole queue */
PRIO_QUEUE * priority_queue_hard_copy(PRIO_QUEUE * pqueue) {
	PRIO_QUEUE * tmp;
	return tmp;
}

/* pop element from front */
void * pop_front(PRIO_QUEUE * pqueue) {
	void * data;
	return data;
}

/* push element back to queue */
void push_back(PRIO_QUEUE * pqueue, void * data) {}


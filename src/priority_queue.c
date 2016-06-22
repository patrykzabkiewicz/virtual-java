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
		void (* comparator) 	/* comparator function pointer */
		) {
	pqueue->copy 	= 0;
	pqueue->count 	= 0;
	pqueue->first 	= 0;
	pqueue->last	= 0;
	pqueue->elem_size = elem_size;
	pqueue->comparator = comparator;
}

/* priority queue copy-on-write */
PRIO_QUEUE * priority_queue_copy(PRIO_QUEUE * pqueue) {
	PRIO_QUEUE * tmp;
	tmp = pqueue;
	tmp->copy = 1;
	return tmp;
}

/* hard copy of whole queue */
PRIO_QUEUE * priority_queue_hard_copy(PRIO_QUEUE * const pqueue) {
	PRIO_QUEUE * tmp = NULL;
	PRIO_QUEUE_ELEM * tmp_elem;

	tmp = (PRIO_QUEUE *) mmalloc(sizeof(PRIO_QUEUE));
	priority_queue_init(tmp, sizeof(PRIO_QUEUE_ELEM), pqueue->comparator);
	tmp_elem = pqueue->first;
	while(tmp_elem) {
		tmp->first = (PRIO_QUEUE_ELEM *)mmalloc(sizeof(PRIO_QUEUE_ELEM));
		mmemcpy(tmp->first, tmp_elem, sizeof(PRIO_QUEUE_ELEM));
		tmp_elem = tmp_elem->next;
	}
	return tmp;
}

/* pop element from front */
uint32 priority_queue_pop(PRIO_QUEUE * pqueue, PRIO_QUEUE_ELEM ** elem) {
	*elem = pqueue->first;
	pqueue->first = pqueue->first->next;
	return pqueue->elem_size;
}

/* push element back to queue */
void priority_queue_push(PRIO_QUEUE * pqueue, PRIO_QUEUE_ELEM * elem) {
	PRIO_QUEUE_ELEM * tmp;
	tmp = pqueue->first;
	while(tmp) {
		if( tmp->priority > elem->priority ) {
			elem->next = tmp;
			tmp = elem;
		}
		tmp = tmp->next;
	}
}


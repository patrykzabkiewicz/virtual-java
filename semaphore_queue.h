#ifndef SEMAPHORE_QUEUE_H
#define SEMAPHORE_QUEUE_H

#include "typedef.h"
#include "mmalloc.h"

/* Semaphore queue basic element */
typedef struct _semaphore_queue_elem {
	void * data;								/* the data the element contains */
	uint32 read_count;							/* how many reads this element already has */
	struct _semaphore_queue_elem * next;		/* next element on the queue */
} SEMAPHORE_QUEUE_ELEM;


typedef struct _semaphore_queue {
	SEMAPHORE_QUEUE_ELEM * first;
	SEMAPHORE_QUEUE_ELEM * last;
	uint32 elem_size;
	uint32 count;
	uint32 max_size;
	uint32 read_limit;					/* limit the amount of reads before removal from queue */
} SEMAPHORE_QUEUE;

/* initiates the semaphore queue */
void sem_q_init(SEMAPHORE_QUEUE * this, uint32 elem_size, uint32 read_limit);

/* takes element from the queue */
void * sem_q_pop(SEMAPHORE_QUEUE * this);

/* pushes element to the queue */
void sem_q_push(SEMAPHORE_QUEUE * this, SEMAPHORE_QUEUE_ELEM * elem);

#endif // SEMAPHORE_QUEUE_H

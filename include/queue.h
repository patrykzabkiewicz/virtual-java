#ifndef QUEUE_H
#define QUEUE_H

#include "typedef.h"

/* Single list element */
typedef struct _queue_elem {
  void * data;				/* Element data */
  struct _queue_elem * next;
} QUEUE_ELEM;


/* Double ended list */
typedef struct _queue {
  QUEUE_ELEM * first;
  QUEUE_ELEM * last;
  uint32 count;
  uint32 elem_size;
  uint8  copy : 1;			/* copy-on-write idiom */
} QUEUE;


/* Appends element to back from the queue */
void queue_append_back(QUEUE * const queue, QUEUE_ELEM * const elem);

/* Returns number of bytes popped from back of the list */
uint32 queue_pop_front(QUEUE * const queue, QUEUE_ELEM * const elem);

/* Initiates the list structure */
void queue_init(QUEUE * const queue, uint32 elem_size);

/* queue with max size 
   can be used as circular buffer */
void queue_init_max_size(QUEUE * const queue, uint32 elem_size, uint32 max_size);

/* finds element in queue and return it's possition */
int queue_find(
  QUEUE * const queue,
  QUEUE_ELEM * elem,
  int (*comparator)(QUEUE_ELEM * first, QUEUE_ELEM * sec)
  );

/* append to back of the queue unique element */
void queue_append_back_unique(
  QUEUE * const queue, 
  QUEUE_ELEM * elem,
  int (*comparator)(QUEUE_ELEM * first, QUEUE_ELEM * sec)
  );

#endif // QUEUE_H



#ifndef QUEUE_H
#define QUEUE_H

#include "typedef.h"

/* Single list element */
typedef struct _queue_elem {
  void * data;		/* Element data */
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
void queue_append_back(QUEUE * queue, QUEUE_ELEM * elem);

/* Returns number of bytes popped from back of the list */
uint32 queue_pop_front(QUEUE * queue, QUEUE_ELEM * elem);

/* Initiates the list structure */
void queue_init(QUEUE * queue, uint32 elem_size);

#endif // QUEUE_H

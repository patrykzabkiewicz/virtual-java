#ifndef QUEUE_H
#define QUEUE_H

#include "typedef.h"

/* Single list element */
typedef struct _list_elem {
  void * data;		/* Element data */
  struct _list_elem * next;
} QUEUE_ELEM;


/* Double ended list */
typedef struct _queue {
  QUEUE_ELEM * first;
  QUEUE_ELEM * last;
  uint32 count;
  uint32 elem_size;
  uint8  copy : 1;			/* copy-on-write idiom */

  void * (*queue_append_back)	(LIST * list, void * elem);		/* Function pointer */
  uint32 (*queue_pop_front)		(LIST * list, void * elem);		/* Function pointer */

} QUEUE;


/* Appends element to back from the queue */
void queue_append_back(QUEUE * queue, QUEUE_ELEM * elem);

/* Returns number of bytes popped from back of the list */
uint32 queue_pop_front(QUEUE * queue, QUEUE_ELEM * elem);

/* Initiates the list structure */
void queue_init(QUEUE * queue, uint32 elem_size);

/* check if there is next element */
uint8 queue_hasNext(QUEUE * queue);

#endif // QUEUE_H

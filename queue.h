#ifndef QUEUE_H
#define QUEUE_H

#include "typedef.h"

/* Single list element */
typedef struct _list_elem {
  void * data;		/* Element data */
  void * next;
} QUEUE_ELEM;


/* Double ended list */
typedef struct _queue {
  void * first;
  void * last;
  uint32 count;
  uint32 elem_size;

  void * (*list_append_back)	(LIST * list, void * elem);		/* Function pointer */
  uint32 (*list_pop_front)		(LIST * list, void * elem);		/* Function pointer */

} QUEUE;


/* Appends element to back from the queue */
void queue_append_back(LIST * list, void * elem);

/* Returns number of bytes popped from back of the list */
uint32 queue_pop_front(LIST * list, void * elem);

/* Initiates the list structure */
void queue_init(LIST * list, uint32 elem_size);



#endif // QUEUE_H

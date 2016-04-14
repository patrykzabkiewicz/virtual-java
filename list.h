#ifndef LIST_H
#define LIST_H

#include "typedef.h"

/* Single list element */
typedef struct _list_elem {
  void * data;		/* Element data */
  void * next;
  void * prev;
} LIST_ELEM;


/* Double ended list */
typedef struct _list {
  void * first;
  void * last;

  uint32 count;				/* count of elements in the list */
  uint32 elem_size;			/* element size in bytes */
  uint32 list_size;			/* list size in bytes */
  uint8  copy : 1;			/* copy-on-write idiom */
  
  void (*list_append_front)		(LIST * this, void * elem);		/* Function pointer */
  void (*list_append_back)		(LIST * this, void * elem);		/* Function pointer */
  uint32 (*list_pop_back)		(LIST * this, void * elem);		/* Function pointer */
  uint32 (*list_pop_front)		(LIST * this, void * elem);		/* Function pointer */

} LIST;

/* Appends element to front of the list */
void list_append_front(LIST * this, void * elem);

/* Appends element to back fo the list */
void list_append_back(LIST * this, void * elem);

/* Returns number of bytes popped from back of the list */
uint32 list_pop_back(LIST * this, void * elem);

/* Returns number of bytes popped from back of the list */
uint32 list_pop_front(LIST * this, void * elem);

/* Initiates the list structure */
void list_init(LIST * this, uint32 elem_size);

/* Copy constructor */
void list_init_copy(LIST * this, LIST * list);

#endif // LIST_H

#ifndef LIST_H
#define LIST_H

#include "typedef.h"

/* Single list element */
typedef struct _list_elem {
  void * data;		/* Element data */
  struct _list_elem * next;
  struct _list_elem * prev;
} LIST_ELEM;


/* Double ended list */
typedef struct _list {
	LIST_ELEM * first;
	LIST_ELEM * last;
	uint32 count;				/* count of elements in the list */
	size_t elem_size;			/* element size in bytes */
	size_t list_size;			/* list size in bytes */
	uint8  copy : 1;			/* copy-on-write idiom */
} LIST;

/* Appends element to front of the list */
void list_append_front(LIST * this, LIST_ELEM * elem);

/* Appends element to back from the list */
void list_append_back(LIST * this, LIST_ELEM * elem);

/* Returns number of bytes popped from back of the list */
uint32 list_pop_back(LIST * this, LIST_ELEM * elem);

/* Returns number of bytes popped from back of the list */
uint32 list_pop_front(LIST * this, LIST_ELEM * elem);

/* Initiates the list structure */
void list_init(LIST * this, uint32 elem_size);

/* Copy constructor */
void list_init_copy(LIST * this, LIST * list);

/* reverse elements of the list */
void list_reverse(LIST * this);

/* sort elements in the list */
void list_qsort(
		LIST * this,									/* pointer to structure */
		size_t elem_count,								/* element quantity */
		size_t elem_size,								/* single element size */
        int (*comparator)(const void *, const void *)	/* comparator function pointer */
		);

/* partitioner for quick sort */
LIST_ELEM * list_partition(LIST * this, LIST_ELEM * lo_ptr, LIST_ELEM * hi_ptr);

/* integer sorter */
int int_comparator( const void *first_arg, const void *second_arg );

#endif // LIST_H

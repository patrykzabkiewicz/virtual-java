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
void list_append_front(LIST * const this, LIST_ELEM * const elem);

/* Appends element to back from the list */
void list_append_back(LIST * const this, LIST_ELEM * const elem);

/* Returns number of bytes popped from back of the list */
uint32 list_pop_back(LIST * const this, LIST_ELEM * const elem);

/* Returns number of bytes popped from back of the list */
uint32 list_pop_front(LIST * const this, LIST_ELEM * const elem);

/* Initiates the list structure */
void list_init(LIST * const this, uint32 elem_size);

/* Copy constructor */
void list_init_copy(LIST * const this, LIST * list);

/* reverse elements of the list */
void list_reverse(LIST * const this);

/* inserts the element at specified index */
void list_insert_indx(
		LIST * const this,
		const uint32 indx,
		const LIST_ELEM * const elem
		);

/* inserts the element after the another element */
void list_insert_after(
		LIST * const this,
		const LIST_ELEM * const after,
		const LIST_ELEM * const elem,
		int (*comparator)(const void *, const void *)
		);

/* insert the element before another element on the list */
void list_insert_before(
		LIST * const this,
		const LIST_ELEM * const before,
		const LIST_ELEM * const elem,
		int (*comparator)(const void *, const void *)
		);

/* find element on the list and return indx position */
uint32 list_find_indx(
		const LIST * const this,
		const LIST_ELEM * const elem
		);

/* find element on the list and return pointer to the element */
const LIST_ELEM * const list_find_ptr(
		const LIST * const this,
		const LIST_ELEM * const elem
		);

/* remove element from the list */
void list_remove(
		LIST * const this,
		LIST_ELEM * const elem
		);

/* sort elements in the list */
void list_qsort(
		LIST * this,									/* pointer to structure */
		size_t elem_count,								/* element quantity */
		size_t elem_size,								/* single element size */
        int (*comparator)(const void *, const void *)	/* comparator function pointer */
		);

/* non repeatable append to list */
void list_append_norepeat(
	LIST * const list, 
	LIST_ELEM * const elem
	);


/* partitioner for quick sort */
LIST_ELEM * list_partition(LIST * this, LIST_ELEM * lo_ptr, LIST_ELEM * hi_ptr);

/* integer sorter */
int int_comparator( const void *first_arg, const void *second_arg );

#endif // LIST_H

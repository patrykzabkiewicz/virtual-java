/*
 * list.c
 *
 *  Created on: 13 kwi 2016
 *      Author: zabkiewp
 */

#include "list.h"

void list_init(LIST * this, uint32 elem_size) {
	this->elem_size = elem_size;
}

/* destructor of list */
void list_destroy(LIST * const this) {

}

void list_init_copy(LIST * this, LIST * list) {
	this->elem_size = list->elem_size;
	this->copy = 1;
}

/* Appends element to front of the list */
void list_append_front(LIST * this, LIST_ELEM * elem) {
	this->first->prev = elem;
	this->first = this->first->prev;
}

/* Appends element to back from the list */
void list_append_back(LIST * this, LIST_ELEM * elem) {
	this->last->next = elem;
	this->last = this->last->next;
}

/* Returns number of bytes popped from back of the list */
uint32 list_pop_back(LIST * this, LIST_ELEM * elem) {
	LIST_ELEM tmp;
	elem = this->last;
	mfree(this->last);
	this->last = elem->prev;
	return this->elem_size;
}

/* Returns number of bytes popped from back of the list */
uint32 list_pop_front(LIST * this, LIST_ELEM * elem) {
	LIST_ELEM tmp;
	elem = this->first;
	mfree(this->first);
	this->first = elem->next;
	return this->elem_size;
}

/* remove element from the list */
void list_remove(
		LIST * const this,
		LIST_ELEM * const elem
		) {}

/* reverse elements of the list */
void list_reverse(LIST * this) {
	LIST * tmp;
	LIST_ELEM * tmp_ptr;
	tmp_ptr = this->first;
	while(tmp_ptr) {
		tmp_ptr->next = tmp->first;
		tmp->first = tmp_ptr;
		tmp_ptr = tmp_ptr->next;
	}
}

/* sort elements in the list */
void list_qsort(
		LIST * this,									/* pointer to structure */
		LIST_ELEM * lo_ptr,
		LIST_ELEM * hi_ptr,
        int (*comparator)(const void *, const void *)	/* comparator function pointer */
		) {
	if(comparator(this->first, this->last))
	{
		LIST_ELEM * pivot_ptr = list_partition(this, lo_ptr, hi_ptr, comparator);
		// list_qsort(this, lo_ptr, pivot_ptr,comparator);
		// list_qsort(this, pivot_ptr+1, hi_ptr,comparator);
	}
}

/* find element on the list and return indx position */
uint32 list_find_indx(
		const LIST * const this,
		const LIST_ELEM * const elem
		) {
			uint32 indx = 0;
			LIST_ELEM * cur;
			cur = this->first;
			
			while(cur->next) {
				if( mmemcmp(cur->data, elem->data, this->elem_size) ) {
					return indx;
				}
				cur = cur->next;
				indx++;
			}
			
			return indx;
		}

/* find element on the list and return pointer to the element */
const LIST_ELEM * const list_find_ptr(
		const LIST * const this,
		const LIST_ELEM * const elem
		) {
			LIST_ELEM * cur;
			cur = this->first;
			
			while(cur->next) {
				if( mmemcmp(cur->data, elem->data, this->elem_size) ) {
					return cur;
				}
				cur = cur->next;
			}
			
			return cur;
		}

/* non repeatable append to list */
void list_append_norepeat(
	LIST * const list, 
	LIST_ELEM * const elem
	) {
		uint32 i;
		i = list_find_indx(list, elem);
		if(i == 0) {
			list_append_back(list,elem);
		}
	}

/* partitioner for quick sort */
LIST_ELEM * list_partition(
		LIST * this, 
		LIST_ELEM * lo_ptr, 
		LIST_ELEM * hi_ptr, 
		int (*comparator)(const void *, const void *)
	) {
	LIST_ELEM * pivot_ptr;
	LIST_ELEM * tmp;
	LIST_ELEM * i;
	LIST_ELEM * j;

	pivot_ptr = lo_ptr;
	i = lo_ptr--;
	j = hi_ptr++;

    while(1) {
        i++;
        while ( comparator(i, pivot_ptr) )
        {
            j--;
        }
        while ( comparator(pivot_ptr, j) )
        {
			if ( comparator(j, i) )
			{
				return j;
			}
        }

        // swap two pointers
		tmp = i;
        i = j;
        j = tmp;
    }
}

/* integer sorter */
int int_comparator( const void *first_arg, const void *second_arg )
{
    int first = *(int*)first_arg;
    int second = *(int*)second_arg;
    if ( first < second )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


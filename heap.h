/*
 * heap.h
 *
 *  Created on: 17 maj 2016
 *      Author: zabkiewp
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "typedef.h"

typedef struct _stack {
	STACK_ELEM * first;
	STACK_ELEM * last;
	uint32 elem_size;
	uint32 count;			/* number of elements on stack */
	uint8 copy : 1;			/* copy-on-write idiom */
	uint32 max_size;		/* max size in bytes */
	uint32 max_elem;		/* max number of elements on stack */
	uint32 current_size; 	/* current size in bytes */
	uint32 boundry;			/* last byte of stack */
} STACK;

#endif /* HEAP_H_ */

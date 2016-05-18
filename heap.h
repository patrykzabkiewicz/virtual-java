/*
 * heap.h
 *
 *  Created on: 17 maj 2016
 *      Author: zabkiewp
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "typedef.h"
#include "bool.h"

typedef struct _heap_elem {
	void * data;
	struct _heap_elem * left;
	struct _heap_elem * right;
	uint32 color_br; /* color flag for black-red tree implementation */
} HEAP_ELEM;


typedef struct _heap {
	HEAP_ELEM * root;
	uint32 elem_size;
	uint32 count;			/* number of elements on stack */
} HEAP;

void heap_init(HEAP * const h);
void heap_insert(HEAP * const h, HEAP_ELEM * const he);

/* returns heap element if exist */
HEAP_ELEM * heap_find(HEAP * const h, void * data, uint32 data_size);



#endif /* HEAP_H_ */

/*
 * heap.h
 *
 * this structure serves as both heap and tree
 *
 *  Created on: 17 maj 2016
 *      Author: zabkiewp
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "typedef.h"
#include "bool.h"

typedef struct _heap {
	uint32 elem_size;
	uint32 count;			/* number of elements on stack */
	void * root[0];	/* general hack for custom sized array */
} HEAP;

/* init general heap */
void heap_init(HEAP * const h, uint32 elem_size);

/* deallocate heap */
void heap_destroy(HEAP * const h);

/**
 * inserts element at the top of heap
 */
void heap_insert_head(HEAP * const h, void * const he);

/**
 * removes heap head
 */
void * heap_remove_head(HEAP * const h);

/**
 * inserts leaf to binary tree
 */
void heap_insert_binary(HEAP * const h, void * const he);

/**
 * inserts leaf to red black tree
 */
void heap_insert_rb(HEAP * const h, void * const he);

/* returns heap element if exist */
void * heap_find(
		HEAP * const h,
		void * data,
		uint32 data_size,
		int (*comparator)(const void * const a, const void * const b)
		);



#endif /* HEAP_H_ */

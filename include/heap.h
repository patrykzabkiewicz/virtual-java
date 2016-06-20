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
#include "nullptr.h"
#include "mmalloc.h"

typedef struct _heap {
	uint32 elem_size;
	uint32 count;			/* number of elements on stack */
	void * root;			/* general hack for custom sized array */
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
void heap_remove_head(HEAP * const h);

/**
 * inserts leaf to binary tree
 */
void heap_insert_binary(HEAP * const h, void * const item,int32 (*comparator)(void * const A, void * const B));

/* depth first search */
void heap_dfs(HEAP * const h, void * const item);

/* return number of elements in path 
 fills out pointer to list of verticies from given point to root */
uint32 heap_path(HEAP * const h, uint32 * vertex_list, uint32 A);

/* swap two elements in a heap/tree */
void heap_swap(HEAP * const h, uint32 A, uint32 B);

/* shift up the element in heap */
void heap_shift_up(HEAP * const h, void * const A);

/* shift down the element in heap */
void heap_shift_down(HEAP * const h, void * const B);

/* sort the whole binary heap */
void heap_sort(HEAP * const h);

/**
 * inserts leaf to red black tree
 */
void heap_insert_rb(HEAP * const h, void * const he);

/* returns heap element if exist */
void * heap_find(
		HEAP * const h,
		void * const data,
		uint32 data_size,
		int (*comparator)(const void * const a, const void * const b)
		);



#endif /* HEAP_H_ */

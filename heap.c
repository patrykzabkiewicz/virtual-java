
#include "heap.h"

void heap_init(HEAP * const h, uint32 elem_size) {
	h->root = nullptr;
	h->elem_size = elem_size;
	h->count = 0;
}


// n2+1 = L
// n2+2 = R

/**
 * inserts element at the top of heap
 */
void heap_insert_head(HEAP * const h, void * const he) {
	mmemcpy((HEAP *)h->root + h->count, he, h->elem_size);
	h->count++;
}

/**
 * removes heap head
 */
void heap_remove_head(HEAP * const h) {
	mfree((HEAP *)h->root + h->count);
	h->count--;
}


/**
 * inserts leaf to binary tree
 */
void heap_insert_binary(HEAP * const h, void * const he) {
	uint32 i;
	// while heap still has elements in branches
	for (i = 0; i < h->count; ) {
		// compare left and right
		if((HEAP *)h->root + i < he) {
			i = 2 * i + 1;
		}
		else {
			i = 2 * i + 2;
		}
	}
}

/**
 * inserts leaft to red black tree
 */
void heap_insert_rb(HEAP * const h, void * const he) {

}

/**
 *  returns heap element if exist
 *
 *  left-most search of a tree
 **/
void * heap_find(
		HEAP * const h,
		void * data,
		uint32 data_size,
		int (*comparator)(const void * const a, const void * const b)
		) {

}

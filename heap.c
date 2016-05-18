
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
	h->root[h->count] = he;
	h->count++;
}

/**
 * removes heap head
 */
void heap_remove_head(HEAP * const h) {
	free(h->root[h->count]);
	h->count--;
}


/**
 * inserts leaf to binary tree
 */
void heap_insert_binary(HEAP * const h, void * const he) {
	
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

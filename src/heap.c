
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
void heap_insert_binary(
	HEAP * const h, 
	void * const he, 
	int32 (*comparator)(void * const A, void * const B)
	) {
	uint32 i;
	// while heap still has elements in branches
	for (i = 0; i < h->count; ) {
		// compare left and right
		if( comparator((HEAP *)(h->root + i), he) ) {
			i = 2 * i + 1;
		}
		else {
			i = 2 * i + 2;
		}
	}
}


/* depth first search */
void heap_dfs(HEAP * const h, void * const item) {

}

/* return path from given point to root */
uint32 heap_path(HEAP * const h, uint32 * vertex_list, uint32 A) {
	uint32 i;
	uint32 count;
	vertex_list = mmalloc(sizeof(uint32) * 10);

	// while heap still has elements in branches
	for (i = 0; i < h->count; ) {
		// compare left and right
		// if((HEAP *)h->root + i < he) {
		// 	vertex_list[count++] = i;
		// 	i = 2 * i + 1;
		// }
		// else {
		// 	vertex_list[count++] = i;
		// 	i = 2 * i + 2;
		// }
	}

	return count;
}

/* swap two elements in a heap/tree */
void heap_swap(HEAP * const h, uint32 A, uint32 B) {
	void * C;
	C = mmalloc(sizeof(h->elem_size));

	/* copy memory as we dont know how big are elements */
	mmemcpy(C, h->root + (h->elem_size * A), h->elem_size);
	mmemcpy(h->root + (h->elem_size * A), h->root + (h->elem_size * B), h->elem_size);
	mmemcpy(h->root + (h->elem_size * B), C, h->elem_size);

	mfree(C);
}

/* shift up the element in heap */
void heap_shift_up(HEAP * const h, void * const A);

/* shift down the element in heap */
void heap_shift_down(HEAP * const h, void * const B);

/* sort the whole binary heap */
void heap_sort(HEAP * const h);


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
			return data;
}

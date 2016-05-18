
#include "heap.h"

void heap_init(HEAP * const h, uint32 elem_size) {
	h->root = nullptr;
	h->elem_size = elem_size;
	h->count = 0;
}

/**
 * inserts the leaf into a heap
 */
bool heap_leaf(HEAP_ELEM * const root, HEAP_ELEM * const leaf) {
	if(root->left == nullptr) {

	} else {
		if() {}
	}
	return false;
}

/**
 * inserts element at the right place
 * do left-most search of binary tree
 */
void heap_insert(HEAP * const h, HEAP_ELEM * const he) {
	HEAP_ELEM * tmp;
	tmp = h->root;
    while(tmp->left) {
    	if()
    }
	h->count++;
}

/**
 *
 */
void heap_insert_binary(HEAP * const h, HEAP_ELEM * const he) {}

/* returns heap element if exist */
HEAP_ELEM * heap_find(HEAP * const h, void * data, uint32 data_size) {
    
}

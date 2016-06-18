
#include "chain.h"

/* chain initializer */
void chain_init(CHAIN * const chain, uint32 elem_size) {
	chain->count = 0;
	chain->elem_size = elem_size;
	chain->first = 0;
	chain->last = 0;
	chain->max = 0;
}

/* chain append element in the back */
void chain_append(CHAIN * const chain, CHAIN_ELEM * elem) {
	chain->last->next = elem;
	elem->prev = chain->last;
	chain->last = elem;
	chain->count++;
}

/* chain pop element from the back */
uint32 chain_pop(CHAIN * const chain, void * data) {
	if(chain->last) {
		data = chain->last;
		chain->last = chain->last->prev;
		chain->last->next = 0;
		chain->count--;
		return chain->elem_size;
	} else {
		return 0;
	}
}


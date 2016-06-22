#ifndef CHAIN_H_
#define CHAIN_H_

#include "typedef.h"

/* chain element structure */
typedef struct _chain_elem {
	uint32 id;					/* identification number */
	uint32 timestamp;			/* time stamp */
	void * data;				/* pointer to data object */
	uint8 * hash;				/* hash value for data integration */
	struct _chain_elem * next;	/* pointer to next element */
	struct _chain_elem * prev;	/* pointer to previous element */
} CHAIN_ELEM;

/* chain structure */
typedef struct _chain {
	uint32 elem_size;			/* single element size */
	CHAIN_ELEM * first;			/* first element pointer */
	CHAIN_ELEM * last;			/* last element pointer */
	uint32 count;				/* quantity of elements */
	uint32 max;					/* max amount of elements */
} CHAIN;

/* chain initializer */
void chain_init(CHAIN * const chain, uint32 elem_size);

/* chain append element in the back */
void chain_append(CHAIN * const chain, CHAIN_ELEM * elem);

/* chain pop element from the back */
uint32 chain_pop(CHAIN * const chain, void ** data);

#endif /* CHAIN_H_ */

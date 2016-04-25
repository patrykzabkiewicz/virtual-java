/*
 * map.h
 *
 *  Created on: 24 kwi 2016
 *      Author: zabkiewi
 */

#ifndef MAP_H_
#define MAP_H_

#include "typedef.h"

typedef struct _map_elem {
	uint8 * key;							/* key value */
	void * data;							/* data */
	uint32 indx;							/* index */
	struct _map_elem * const parent;		/* parent of the tree */
	struct _map_elem * const left;			/* left branch */
	struct _map_elem * const right;			/* right branch */
} MAP_ELEM;

typedef struct _map_h {
	uint32 key_size;				/* key value size */
	uint32 data_size;				/* data element size */
	MAP_ELEM * const data;			/* pointer to data */
} MAP;

void * const map_init(
		MAP * const map,
		uint32 const key_size,
		uint32 const data_size
		);

/**
 * inserts the element into hash map tree
 * returns a pointer to the inserted element
 */
void * map_insert(MAP * const map, MAP_ELEM const * const elem);

/**
 * remove the element from the map tree
 */
void * map_remove(MAP * const map, uint8 * key);

#endif /* MAP_H_ */

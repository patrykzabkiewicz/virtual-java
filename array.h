/*
 * array.h
 *
 *  Created on: 16 kwi 2016
 *      Author: zabkiewi
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "typedef.h"

/* boundry checks array */

typedef struct _array_h {
	void * data;			/* array data */
	uint32 elem_size;		/* max jump */
	uint32 max_size;		/* max size of array */
} ARRAY;

/* array init */
void array_init(ARRAY * array, uint32 elem_size, uint32 max_size);

/* insert data into an array */
void array_insert(ARRAY * array, void * data, uint32 position);

/* get the data from the array */
void * array_get(ARRAY * array, uint32 position);

#endif /* ARRAY_H_ */

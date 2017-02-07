/*
 * vector.h
 *
 *  Created on: 16 kwi 2016
 *      Author: zabkiewi
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "typedef.h"
#include "mmalloc.h"

/* boundry checks array/vector */

typedef struct _vector_int {
	int * data;				/* array data */
	uint32 elem_size;		/* max jump */
	uint32 count;			/* elements count */
	uint32 capacity;		/* max size of vector */
	uint32 max_size;		/* whole data size, boundary checks */
} VECTOR;

/* vector init */
void vector_init(
		VECTOR * const v,
		uint32 elem_size,
		uint32 capacity
		);

/* insert data into an array */
void vector_insert(VECTOR * const v, void * const data, uint32 position);

/* get the data from the array */
uint32 vector_get(VECTOR * const v, uint32 position, void * elem);

/* append to the end of vector */
void vector_append(VECTOR * const v, void * const data);

/* remove from the end of the vector */
uint32 vector_pop(VECTOR * const v, void * data);


#endif /* VECTOR_H_ */

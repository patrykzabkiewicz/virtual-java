/*
 * matrix.h
 *
 *  Created on: 24 kwi 2016
 *      Author: zabkiewi
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "typedef.h"

typedef struct _matrix {
	uint32 dims;				/* dim size */
	uint32 * const dim_sizes;	/* dimensions sizes */
	uint32 elem_size;			/* single element size */

	void * const data;			/* data pointer */
} MATRIX;

void * const matrix_init(MATRIX * const matrix);


#endif /* MATRIX_H_ */

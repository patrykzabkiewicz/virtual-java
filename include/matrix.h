/*
 * matrix.h
 *
 *  Created on: 24 kwi 2016
 *      Author: zabkiewi
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "typedef.h"
#include "mmalloc.h"

typedef struct _matrix {
	uint32 dims;				/* dim size */
	uint32 * const dim_sizes;	/* dimensions sizes */
	uint32 elem_size;			/* single element size */

	void * const data;			/* data pointer */
} MATRIX;

/* initiaties the matrix and returns pointer to it */
void * matrix_init(
		MATRIX * const A,
		uint32 dims,
		uint32 * dim_sizes,
		uint32 elem_size
);

/* matrix add another matrix */
MATRIX * const matrix_add(MATRIX * const A, MATRIX * const B);

/* matrix add scalar */
MATRIX * const matrix_add_factor(MATRIX * const A, uint32 factor);

/* matrix subtract matrix */
MATRIX * const matrix_sub(MATRIX * const A, MATRIX * const B);

/* matrix subtract scalar */
MATRIX * const matrix_sub_factor(MATRIX * const A, uint32 factor);

/* multiply matrix by scalar */
MATRIX * const matrix_multiply_factor(MATRIX * const A, uint32 factor);

/* multiply two matrices */
MATRIX * const matrix_multiply(MATRIX * const A, MATRIX * const B);

/* transpose matrix */
MATRIX * const matrix_transpose(MATRIX * const A);

/* calculates determinant of given matrix */
uint32 matrix_determinant(MATRIX * const A);

/* calculates the matrix rank */
uint32 matrix_rank(MATRIX * const A);

#endif /* MATRIX_H_ */

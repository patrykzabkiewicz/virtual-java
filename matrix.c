/*
 * matrix.c
 *
 *  Created on: 24 kwi 2016
 *      Author: zabkiewi
 */

#include "matrix.h"

/* Initiates the matrix and returns pointer to it */
void * const matrix_init(
		MATRIX * const A,
		uint32 dims,
		uint32 * dim_sizes,
		uint32 elem_size
		) {
	uint32 i;
	A = malloc(sizeof(MATRIX));
	A->dims = dims;
	for(i=0; i < dims; i++) {
		A->dim_sizes[i] = dim_sizes[i];
	}
	A->elem_size = elem_size;

	return A;
}

MATRIX * const matrix_add(MATRIX * const A, MATRIX * const B) {
	if(A->dims == B->dims) {

	}
}

MATRIX * const matrix_add_factor(MATRIX * const A, uint32 factor);

MATRIX * const matrix_sub(MATRIX * const A, MATRIX * const B);

MATRIX * const matrix_sub_factor(MATRIX * const A, uint32 factor);

/* multiply matrix by scalar */
MATRIX * const matrix_multiply_factor(MATRIX * const A, uint32 factor);

/* multiply two matrices */
MATRIX * const matrix_multiply(MATRIX * const A, MATRIX * const B);

/* transpose matrix */
MATRIX * const matrix_transpose(MATRIX * const A);

/* calculates determinant of given matrix */
uint32 matrix_determinant();



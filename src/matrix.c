/*
 * matrix.c
 *
 *  Created on: 24 kwi 2016
 *      Author: zabkiewi
 */

#include "../include/matrix.h"

/* Initiates the matrix and returns pointer to it */
void * matrix_init(
		MATRIX * const A,
		uint32 dims,
		uint32 * dim_sizes
		) {
	uint32 i;
	A->dims = dims;
	for(i=0; i < dims; i++) {
		A->dim_sizes[i] = dim_sizes[i];
	}
	return A;
}

MATRIX * const matrix_add(MATRIX * const A, MATRIX * const B) {

	if(A->dims == B->dims) {
		int dim;
		int i;

		for (dim = 0; dim < A->dims; dim++) {
			if (A->dim_sizes[dim] != B->dim_sizes[dim]) {
				return NULL;
			}
			for (i = 0; i < A->dim_sizes[dim]; i++) {
				A->data[dim*A->dim_sizes[dim] + i] += B->data[dim*B->dim_sizes[dim]+i];
			}
		}
		return A;
	}

	return NULL;
}

MATRIX * const matrix_add_factor(MATRIX * const A, uint32 factor) {
	int dim;
	int i;
	for (dim = 0; dim < A->dims; dim++ ) {
		for (i = 0; i < A->dim_sizes[dim]; i++) {
			A->data[dim*A->dim_sizes[dim] + i] += factor;
		}
	}
	return A;
}

MATRIX * const matrix_sub(MATRIX * const A, MATRIX * const B) {
	if (A->dims == B->dims) {
		int dim;
		int i;

		for (dim = 0; dim < A->dims; dim++) {
			if (A->dim_sizes[dim] != B->dim_sizes[dim]) {
				return NULL;
			}
			for (i = 0; i < A->dim_sizes[dim]; i++) {
				A->data[dim*A->dim_sizes[dim] + i] -= B->data[dim*B->dim_sizes[dim] + i];
			}
		}
		return A;
	}

	return NULL;
}

MATRIX * const matrix_sub_factor(MATRIX * const A, uint32 factor) {
	int dim;
	int i;
	for (dim = 0; dim < A->dims; dim++) {
		for (i = 0; i < A->dim_sizes[dim]; i++) {
			A->data[dim*A->dim_sizes[dim] + i] -= factor;
		}
	}
	return A;
}

/* multiply matrix by scalar */
MATRIX * const matrix_multiply_factor(MATRIX * const A, uint32 factor) {
	int dim;
	int i;
	for (dim = 0; dim < A->dims; dim++) {
		for (i = 0; i < A->dim_sizes[dim]; i++) {
			A->data[dim*A->dim_sizes[dim] + i] *= factor;
		}
	}
	return A;
}

#define matrix_multiply(A,B)()

/* multiply two matrices */
MATRIX * const matrix_multiply(MATRIX * const A, MATRIX * const B) {
	int i;
	int j;

	/* new matrix sizes */
	int ABx = A->dim_size[0];
	int ABy = B->dim_size[1];

	// first check the sizes
	if(A->dims > 2) return NULL; 
	// number of colums must be equal number of rows
	if(A->dim_sizes[0] != B->dim_sizes[1]) return NULL;


	MATRIX * AB = (struct _matrix *) malloc(sizeof(struct _matrix));
	AB->data = (int *) malloc(sizeof(int) * A->);
	
	for(i=0; i<A->dims[0];i++) {
		for(j=0; j<A->dims[1]; j++) {

		}
		// AB[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
		// AB[0][1] = A[1][0] * B[0][1];
	}
}

/* transpose matrix */
MATRIX * const matrix_transpose(MATRIX * const A);

/* calculates determinant of given matrix */
uint32 matrix_determinant(MATRIX * const A) {
	uint32 det = 0;
	return det;
}

/* calculates the matrix rank */
uint32 matrix_rank(MATRIX * const A) {
	uint32 rank = 0;
	return rank;
}

/* append vector at the right of the matrix */
MATRIX * const matrix_append(MATRIX * const A, VECTOR * const V) {
	int i;

	/* check sizes */
	if(A->dim_sizes[0] != V->size) return NULL;

	for() {}

	return NULL;
}


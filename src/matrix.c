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

/* 
	multiply two matrices 
	to be honest this topic is so huge that in can be gathered in another file
*/
int * const matrix_multiply(int * const A, int * const B) {
	int N;
	int K;
	int M;
	int * C;

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<K; j++) {
			float tmp = 0;
			for (int l = 0; l<M; l++) {
				tmp += A[M*i + l] * B[K*l + j];
			}
			C[K*i + j] = tmp;
		}
	}

	/*

	transpose(B);
	for(int i=0; i<N; i++) {
		for(int j=0; j<K; j++) {
			float tmp = 0;
			for(int l=0; l<M; l++) {
				tmp += A[M*i+l]*B[K*j+l];
			}
			C[K*i + j] = tmp;
		}
	}
	transpose(B);
	
	*/

	return C;
}



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

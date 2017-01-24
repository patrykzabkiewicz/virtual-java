
//#include <stdlib.h>

#define NULL 0

/* transpose matrix the normal way */
int * const matrix_transpose(
	int * const src, 
	int * const dst, 
	const int N, 
	const int M
	) {
	for (int n = 0; n<N*M; n++) {
		int i = n / N;
		int j = n%N;
		dst[n] = src[M*j + i];
	}

	return NULL;
}


/* transpose matrix for scalar block */
inline void transpose_scalar_block(
	float * const A, 
	float * const B, 
	const int lda, 
	const int ldb, 
	const int block_size
	) {
	#pragma omp parallel for
	for (int i = 0; i<block_size; i++) {
		for (int j = 0; j<block_size; j++) {
			B[j*ldb + i] = A[i*lda + j];
		}
	}
}

/* transpose matrix block by block */
inline void transpose_block(
	float * const A, 
	float * const B, 
	const int n, 
	const int m, 
	const int lda, 
	const int ldb, 
	const int block_size
	) {
	#pragma omp parallel for
	for (int i = 0; i<n; i += block_size) {
		for (int j = 0; j<m; j += block_size) {
			transpose_scalar_block(&A[i*lda + j], &B[j*ldb + i], lda, ldb, block_size);
		}
	}
}


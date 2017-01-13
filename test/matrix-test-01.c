// matrix test 01

#include "matrix.h"
#include "CUnit/Basic.h"

#define MSIZE 3
int test_vec[MSIZE*MSIZE] = {8,1,5,3,4,7,9,12,44};


void testMatrix01(void) {
    int j;
    int i;

    MATRIX2D * A = (MATRIX2D *) malloc(sizeof(MATRIX2D));

    A->dims[0] = MSIZE;
    A->dims[1] = MSIZE;

    for(i=0; i<MSIZE; i++) {
        A->data[i] = (uint32 *) malloc(sizeof(uint32) * MSIZE);
    }
    
    for(i=0; i<MSIZE; i++) {
        for(j=0; j<MSIZE; j++) {
            A->data[j] = test_vec[i*MSIZE+j];
            
            // assert
            CU_ASSERT( A->data[j] > 0 );
            CU_ASSERT( A->data[j] = test_vec[i*MSIZE+j] );
        }
    }
}

void testMatrix02(void) {
    int j;
    int i;

    MATRIX2D * A = (MATRIX2D *) malloc(sizeof(MATRIX2D));

    A->dims[0] = MSIZE;
    A->dims[1] = MSIZE;

    for(i=0; i<MSIZE; i++) {
        A->data[i] = (uint32 *) malloc(sizeof(uint32) * MSIZE);
    }

    for(i=0; i<MSIZE; i++) {
        for(j=0; j<MSIZE; j++) {
            A->data[j] = test_vec[i*MSIZE+j];
        }
    }

    
}

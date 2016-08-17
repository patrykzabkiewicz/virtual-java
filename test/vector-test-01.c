// vector test 01

#include "vector.h"
#include "CUnit/Basic.h"

void testVector01(void) {
    int test;
    Vector vec1 = (Vector *) malloc(sizeof(Vector));
    vector_init(vec1 , sizeof(int));

    vector_append(vec1, 1);
    vector_append(vec1, 2);
    vector_append(vec1, 3);
    vector_append(vec1, 4);
    vector_append(vec1, 5);

    vector_pop(vec1, test);
    CU_ASSERT( 5 == test);
    vector_pop(vec1, test);
    CU_ASSERT( 4 == test);
    vector_pop(vec1, test);
    CU_ASSERT( 3 == test);
    vector_pop(vec1, test);
    CU_ASSERT( 2 == test);
    vector_pop(vec1, test);
    CU_ASSERT( 1 == test);

    CU_ASSERT( -1 == vector_pop(vec1, test));
} 
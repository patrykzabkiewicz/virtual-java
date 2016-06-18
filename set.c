#include "set.h"


/* initialize set structure */
void set_init(SET * s, uint32 elem_size) {
    s->elem_size = elem_size;
    s->count = 0;
}

void set_add_elem(SET * s, SET_ELEM * elem);
void set_add_set(SET * s, SET * set);
int32 set_dot_product(SET * s);
void set_sub_elem(SET * s, int32 elem);
void set_sub_set(SET * s, SET * sub);
void set_div_elem(SET * s, int32 divider);
void set_multiply_elem(SET * s, int32 multiply);

SET * set_subset(SET * s, int32 start, int32 count);

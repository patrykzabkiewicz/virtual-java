/*
 * set.h
 *
 *  Created on: 17 maj 2016
 *      Author: zabkiewp
 */

#ifndef SET_H_
#define SET_H_

#include "typedef.h"

typedef struct _set_elem {
	void * data;
	struct	_set_elem * next;
} SET_ELEM;

typedef struct _set {
	SET * first;
	uint32 elem_size;
	uint32 count;			/* number of elements in set */
} SET;

/* initialize set structure */
void set_init(SET * s, uint32 elem_size);
void set_destroy(SET * s);

void set_add_elem(SET * s, SET_ELEM * elem);
void set_add_set(SET * s, SET * set);
int32 set_dot_product(SET * s);
void set_sub_elem(SET * s, int32 elem);
void set_sub_set(SET * s, SET * sub);
void set_div_elem(SET * s, int32 divider);
void set_multiply_elem(SET * s, int32 multiply);

SET * set_subset(SET * s, int32 start, int32 count);

#endif /* SET_H_ */

/*
 * set.h
 *
 *  Created on: 17 maj 2016
 *      Author: zabkiewp
 */

#ifndef SET_H_
#define SET_H_

#include "typedef.h"

typedef struct _set {
	STACK_ELEM * first;
	uint32 elem_size;
	uint32 count;			/* number of elements on stack */
} SET;

#endif /* SET_H_ */

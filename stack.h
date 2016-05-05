/*
 * stack.h
 *
 *  Created on: 14 kwi 2016
 *      Author: zabkiewp
 */

#ifndef STACK_H_
#define STACK_H_

#include "typedef.h"
#include "nullptr.h"

typedef struct _stack_elem {
	void * data;
	struct _stack_elem * next;
} STACK_ELEM;

typedef struct _stack {
	STACK_ELEM * first;
	STACK_ELEM * last;
	uint32 elem_size;
	uint32 count;
	uint8 copy : 1;		/* copy-on-write idiom */
	uint32 max_size;
} STACK;

/* initiates the stack structure */
void stack_init(STACK * stack, uint32 elem_size);

void stack_init_maxsize(
		STACK * stack,
		uint32 elem_size,
		uint32 max_size
		);

/* copies the stack and returns the pointer to new structure */
STACK * stack_copy(STACK * stack);

/* makes a hard copy of the stack */
STACK * stack_hard_copy(STACK * stack);

/* push element to stack */
void push_stack(STACK * stack, STACK_ELEM * data);

/* pop element from stack */
void * pop_stack(STACK * stack);

#endif /* STACK_H_ */

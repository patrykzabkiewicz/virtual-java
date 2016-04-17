/*
 * stack.c
 *
 *  Created on: 16 kwi 2016
 *      Author: zabkiewi
 */

#include "stack.h"

/* initiates the stack structure */
void stack_init(STACK * stack, uint32 elem_size) {
	stack->copy = 0;
	stack->elem_size = elem_size;
	stack->first = 0;
	stack->count = 0;
}

/* copies the stack and returns the pointer to new structure */
STACK * stack_copy(STACK * stack) {
	STACK * tmp;
	tmp = stack;
	tmp->copy = 1;
	return tmp;
}

/* makes a hard copy of the stack */
STACK * stack_hard_copy(STACK * stack) {
	STACK * tmp;
	STACK_ELEM * org_tmp, * dest_tmp;

	tmp->copy = 0;
	tmp->count = stack->count;
	tmp->elem_size = stack->elem_size;
	tmp->first = stack->first;

	// copy all elements one by one
	org_tmp = stack->first;
	while(org_tmp) {
		memncpy(dest_tmp , org_tmp->data, stack->elem_size);
		tmp->first->next = dest_tmp;
		org_tmp = org_tmp->next;
	}

	return tmp;
}

/* push element to stack */
void push_stack(STACK * stack, void * data) {
	STACK_ELEM * elem;
	elem->data = data;
	stack->first->next = elem;
}

/* pop element from stack */
void * pop_stack(STACK * stack) {
	STACK_ELEM * tmp;
	tmp = stack->first;
	free(stack->first);
	stack->first = tmp->next;
	return tmp->data;
}



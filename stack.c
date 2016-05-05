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
	stack->first = nullptr;
	stack->last = nullptr;
	stack->count = 0;
	stack->max_size = 0;
}

void stack_init_maxsize(
		STACK * stack,
		uint32 elem_size,
		uint32 max_size
		) {
	stack->copy = 0;
	stack->elem_size = elem_size;
	stack->first = nullptr;
	stack->last = nullptr;
	stack->count = 0;
	stack->max_size = max_size;
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
	tmp = (STACK *) malloc(sizeof(STACK));
	stack_init(tmp);

	STACK_ELEM * org_tmp, * dest_tmp;
	org_tmp = (STACK_ELEM *) malloc(sizeof(STACK_ELEM));
	dest_tmp = (STACK_ELEM *) malloc(sizeof(STACK_ELEM));

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
void push_stack(STACK * stack, STACK_ELEM * data) {
	stack->first->next = data;
}

/* pop element from stack */
void * pop_stack(STACK * stack) {
	if(stack->first) {
		STACK_ELEM * tmp;
		tmp = stack->first;
		free(stack->first);
		stack->first = tmp->next;
		return tmp->data;
	}
	return nullptr;
}



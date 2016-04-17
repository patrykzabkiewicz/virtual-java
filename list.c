/*
 * list.c
 *
 *  Created on: 13 kwi 2016
 *      Author: zabkiewp
 */

#include "list.h"

void list_init(LIST * this, uint32 elem_size) {
	this->list_append_front = &list_append_front;
	this->list_append_back = &list_append_back;
	this->list_pop_back = &list_pop_back;
	this->list_pop_front = &list_pop_front;
	this->elem_size = elem_size;
}

void list_init_copy(LIST * this, LIST * list) {
	this->list_append_front = &list_append_front;
	this->list_append_back = &list_append_back;
	this->list_pop_back = &list_pop_back;
	this->list_pop_front = &list_pop_front;
	this->elem_size = list->elem_size;
	this->copy = 1;
}

/* Appends element to front of the list */
void list_append_front(LIST * this, LIST_ELEM * elem) {
	this->first->prev = elem;
	this->first = this->first->prev;
}

/* Appends element to back from the list */
void list_append_back(LIST * this, LIST_ELEM * elem) {
	this->last->next = elem;
	this->last = this->last->next;
}

/* Returns number of bytes popped from back of the list */
uint32 list_pop_back(LIST * this, LIST_ELEM * elem) {
	LIST_ELEM tmp;
	elem = this->last;
	free(this->last);
	this->last = elem->prev;
	return this->elem_size;
}

/* Returns number of bytes popped from back of the list */
uint32 list_pop_front(LIST * this, LIST_ELEM * elem) {
	LIST_ELEM tmp;
	elem = this->first;
	free(this->first);
	this->first = elem->next;
	return this->elem_size;
}

/* reverse elements of the list */
void list_reverse(LIST * this) {
	LIST * tmp;

}

/* sort elements in the list */
void list_sort(LIST * this, void (*comparator)) {

}

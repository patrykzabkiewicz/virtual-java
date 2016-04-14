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

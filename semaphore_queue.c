#include "semaphore_queue.h"

/* initiates the semaphore queue */
void sem_q_init(SEMAPHORE_QUEUE * this, uint32 elem_size, uint32 read_limit) {
	this->count = 0;
	this->elem_size = elem_size;
	this->first = 0;
	this->last = 0;
	this->max_size = 0;
	this->read_limit = read_limit;
}

/* takes element from the queue */
void * sem_q_pop(SEMAPHORE_QUEUE * this) {
	SEMAPHORE_QUEUE_ELEM * tmp;

	this->first->read_count++;
	tmp = this->first;
	if( this->first->read_count == this->read_limit) {
		this->count--;
	}
	if( this->first->next ) {
		free(this->first);
		this->first = tmp->next;
	}
	return tmp->data;
}

/* pushes element to the queue */
void sem_q_push(SEMAPHORE_QUEUE * this, SEMAPHORE_QUEUE_ELEM * elem) {
	if( this->max_size > 0 && this->count < this->max_size) {
		elem->read_count = 0;
		this->last->next = elem;
		this->count++;
	}
}

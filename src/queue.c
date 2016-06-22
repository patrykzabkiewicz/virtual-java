#include "queue.h"

/* Appends element to back from the queue */
void queue_append_back(QUEUE * queue, QUEUE_ELEM * elem) {
	queue->last->next = elem;
	queue->last = queue->last->next;
}

/* Returns number of bytes popped from back of the list */
uint32 queue_pop_front(QUEUE * const queue, QUEUE_ELEM ** elem) {
	*elem = queue->first;
	queue->first = queue->first->next;
	return queue->elem_size;
}

/* Initiates the list structure */
void queue_init(QUEUE * queue, uint32 elem_size) {
	queue->first = 0;
	queue->last = 0;
	queue->copy = 0;
	queue->elem_size = elem_size;
	queue->count = 0;
}

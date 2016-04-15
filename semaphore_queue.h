#ifndef SEMAPHORE_QUEUE_H
#define SEMAPHORE_QUEUE_H

#include "typedef.h"

/* Semaphore queue basic element */
typedef struct _semaphore_queue {
	void * data;						/* the data the element contains */
	uint32 read_count;					/* how many reads this element already has */
	uint32 read_limit;					/* limit the amount of reads before removal from queue */
	struct _semaphore_queue * next;		/* next element on the queue */
} SEMAPHORE_QUEUE;


class SemaphoreQueueElem(object):
    """ Basic element of semaphore queue """
    def __init__(self, data, read_limit=1):
        super(SemaphoreQueueElem, self).__init__()
        self.data = data                    # the data the element contains
        self.read_count = 0                 # how many reads this element already has
        self.read_limit = read_limit        # limit the amount of reads before removal from queue
        self.next = None                    # next element on the queue

class SemaphoreQueue(object):
    """ Data structure that deletes the element after several number of reads """
    def __init__(self, max_size=0):
        super(SemaphoreQueue, self).__init__()
        self.first = []                     # first element in queue
        self.last = []                      # last element in queue
        self.count = 0                      # how many element is there in the queue
        self.max_size = max_size            # what is the max size of the queue

    def pop(self):
        self.first.read_count += 1
        tmp = self.first
        if self.first.read_count == self.read_limit:
            self.count -= 1
        if self.first.next is not None:
            self.first = self.first.next
        return tmp.data

    def hasNext(self):
        if self.first.next is not None:
            return True

    def push(self, data, read_count=1):
        if self.max_size > 0 and self.count < self.max_size:
            self.last.next = SemaphoreQueueElem(data, read_count)
            self.count += 1

    def lenght(self):
        return self.count

#endif // SEMAPHORE_QUEUE_H

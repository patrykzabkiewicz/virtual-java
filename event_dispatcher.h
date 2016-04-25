#ifndef EVENT_DISPATCHER_H_
#define EVENT_DISPATCHER_H_

#include "typedef.h"
#include "queue.h"
#include "list.h"
#include "event.h"

#define EVENT_DISPATCH_INTERVAL 10

typedef struct _event_dispatcher {
	QUEUE 	* events;			/* events to be dispatched */
	LIST 	* list_recivers;	/* list of receivers */
	QUEUE 	* dumpster;			/* dumpster of events that can't be dispatched */
} EVENT_DISPATCHER;

/* constructor for event dispatcher */
void event_dispatcher_init(EVENT_DISPATCHER * const event_dispatcher);

/* adds event to be dispatched */
void event_dispatcher_event(EVENT_DISPATCHER * const event_dispatcher, EVENT * event);

/* adds customer to events loop */
void event_dispatcher_add_customer_event_loop(EVENT_DISPATCHER * const event_dispatcher);

/* worker thread for dispatching */
void event_dispatcher_worker();

/* dispatch all events from wait queue */
void event_dispatcher_dispatch(EVENT_DISPATCHER * const event_dispatcher);

#endif // EVENT_DISPATCHER_H_

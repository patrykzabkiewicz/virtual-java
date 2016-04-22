
#include "event_dispatcher.h"

/* constructor for event dispatcher */
void event_dispatcher_init(EVENT_DISPATCHER * const event_dispatcher) {
	queue_init(event_dispatcher->dumpster);
	list_init(event_dispatcher->events_lists);
	queue_init(event_dispatcher->events, sizeof(EVENT));
}

/* adds event to be dispatched */
void event_dispatcher_event(EVENT_DISPATCHER * const event_dispatcher, EVENT * event) {
	QUEUE_ELEM * qe;
	qe = malloc(sizeof(QUEUE_ELEM));
	qe->data = event;
	queue_append_back(event_dispatcher->events, qe);
}

/* adds customer to events loop */
void event_dispatcher_add_customer_event_loop(EVENT_DISPATCHER * const event_dispatcher) {

}

/* worker thread for dispatching */
void event_dispatcher_worker() {

}

/* dispatch all events from wait queue */
void event_dispatcher_dispatch(EVENT_DISPATCHER * const event_dispatcher) {

}


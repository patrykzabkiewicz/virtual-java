
#include "event_dispatcher.h"

/* constructor for event dispatcher */
void event_dispatcher_init(EVENT_DISPATCHER * const event_dispatcher) {
	event_dispatcher->dumpster = mmalloc(sizeof(QUEUE));
	queue_init(event_dispatcher->dumpster, sizeof(EVENT));

	event_dispatcher->list_recivers = mmalloc(sizeof(LIST));
	list_init(event_dispatcher->list_recivers, sizeof(LIST *));

	event_dispatcher->events = mmalloc(sizeof(QUEUE));
	queue_init(event_dispatcher->events, sizeof(EVENT));
}

/* adds event to be dispatched */
void event_dispatcher_event(EVENT_DISPATCHER * const event_dispatcher, EVENT * const event) {
	QUEUE_ELEM * qe;
	qe = mmalloc(sizeof(QUEUE_ELEM));
	qe->data = event;
	queue_append_back(event_dispatcher->events, qe);
}

/* adds customer to events loop */
void event_dispatcher_add_customer_event_loop(
		EVENT_DISPATCHER * const event_dispatcher,
		LIST * ptr
		) {
	LIST_ELEM * le;
	le = (LIST_ELEM *) mmalloc(sizeof(LIST_ELEM));
	le->data = (void *) ptr;
	list_append_back(event_dispatcher->list_recivers, le);
}

/* worker thread for dispatching */
void event_dispatcher_worker() {

}

/* dispatch all events from wait queue */
void event_dispatcher_dispatch(
		EVENT_DISPATCHER * const event_dispatcher,
		LIST * ptr
		) {
	LIST_ELEM * le;
	le = (LIST_ELEM *) mmalloc(sizeof(LIST_ELEM));
	le->data = (void *) ptr;
	list_remove(event_dispatcher->list_recivers, le);
}


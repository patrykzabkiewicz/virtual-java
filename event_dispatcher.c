
#include "event_dispatcher.h"

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


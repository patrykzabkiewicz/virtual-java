
#include "event.h"

void event_init(EVENT * this) {
	this->id = 0;
	this->data_lenght = 0;
	this->type = 0;
	this->date = 0;
	this->data = 0;
}

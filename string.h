/*
 * string.h
 *
 *  Created on: 19 kwi 2016
 *      Author: zabkiewi
 */

#ifndef STRING_H_
#define STRING_H_

#include "typedef.h"

typedef struct _string {
	uint8 * data;
	uint32 capacity;
	uint32 size;
} STRING;

/* string init */
void string_init(STRING * string);

#endif /* STRING_H_ */

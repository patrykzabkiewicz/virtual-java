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
void string_init_str(STRING * string);
void string_init_ch(int8 * string);
void string_init_int(int32 string);
void string_append_str(STRING * self, STRING * string);
void string_append_ch(STRING * self, int8 * string);
void string_append_int(STRING * self, int32 string);
void string_clear(STRING * string);
int8 * string_substr(STRING * string, uint32 start_pos, int32 amount);
int8 * string_split(STRING * string, int8 symbol);
void string_destroy(STRING * string);

#endif /* STRING_H_ */

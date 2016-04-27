/*
 * bool.h
 *
 *  Created on: 26 kwi 2016
 *      Author: zabkiewp
 */

#ifndef BOOL_H_
#define BOOL_H_

#define true 1
#define false 0

typedef struct _Bool {
	unsigned char val : 1;
} __bool;

#define stdbool __bool

#endif /* BOOL_H_ */

/*
 * smart_pointer.h
 *
 *  Created on: 13 kwi 2016
 *      Author: zabkiewp
 */

#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include "typedef.h"

typedef struct _smrt_ptr {
	void * __ptr;
	uint32 * __ref_count;
	uint32 * __elem_size; /* max jump */

	void (*smrt_ptr_refrence)(SMRT_PTR * ptr);
	void (*smrt_ptr_release)(SMRT_PTR * ptr);
} SMRT_PTR;

void smrt_ptr_init(SMRT_PTR * ptr, uint32 elem_size);

void smrt_ptr_refrence(SMRT_PTR * ptr);

void smrt_ptr_release(SMRT_PTR * ptr);

#endif /* SMART_POINTER_H_ */

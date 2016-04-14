/*
 * smart_pointer.h
 *
 *  Created on: 13 kwi 2016
 *      Author: zabkiewp
 */

#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include "typedef.h"

struct _smrt_ptr_p; /* Opaque type */

typedef struct _smrt_ptr {
	const void * __ptr;				/* valid pointer */
	struct _smrt_ptr_p * __private; /* private member */
	uint8 __copy : 1;

	void (*smrt_ptr_refrence)(SMRT_PTR * ptr);
	void (*smrt_ptr_release)(SMRT_PTR * ptr);
} SMRT_PTR;

void smrt_ptr_init(const SMRT_PTR * this, const SMRT_PTR * ptr, uint32 elem_size);

const SMRT_PTR * smrt_ptr_copy(const SMRT_PTR * this);

#endif /* SMART_POINTER_H_ */

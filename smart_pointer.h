/*
 * smart_pointer.h
 *
 *  Created on: 13 kwi 2016
 *      Author: zabkiewp
 */

#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include "typedef.h"
#include "mmalloc.h"

struct _smrt_ptr_p; /* Opaque type */

typedef struct _smrt_ptr {
	void * __ptr;					/* valid pointer */
	struct _smrt_ptr_p * __private; /* private member */
	uint8 __copy : 1;

	void (*smrt_ptr_refrence)(struct _smrt_ptr * ptr);
	void (*smrt_ptr_release)(struct _smrt_ptr * ptr);
} SMRT_PTR;

void smrt_ptr_init(SMRT_PTR * const this, SMRT_PTR * const ptr, uint32 elem_size);

const SMRT_PTR * smrt_ptr_copy(SMRT_PTR * const this);

#endif /* SMART_POINTER_H_ */

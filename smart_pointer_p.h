/*
 * smart_pointer_p.h
 *
 *  Created on: 14 kwi 2016
 *      Author: zabkiewp
 */

#ifndef SMART_POINTER_P_H_
#define SMART_POINTER_P_H_

#include "typedef.h"

typedef struct _smrt_ptr_p {
	uint32 * __ref_count; 	/* reference counter */
	uint32 * __elem_size; 	/* max jump */
	uint32 * __array_size; 	/* whole array size for boundry checks */
} SMRT_PTR_P;


void smrt_ptr_refrence(SMRT_PTR * ptr);

void smrt_ptr_release(SMRT_PTR * ptr);


#endif /* SMART_POINTER_P_H_ */

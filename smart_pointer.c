
#include "smart_pointer.h"
#include "smart_pointer_p.h"

void smrt_ptr_init(SMRT_PTR * const this, SMRT_PTR * const ptr, uint32 elem_size) {
	this->__ptr = ptr;
	this->__private->__ref_count = 1;
	this->__private->__elem_size = elem_size;
}

const SMRT_PTR * smrt_ptr_copy(SMRT_PTR * const this) {
	SMRT_PTR * ptr;
	ptr = this;
	ptr->__private->__ref_count++;
	ptr->__copy = 1;
	return ptr;
}

void smrt_ptr_refrence(SMRT_PTR * this) {
	this->__private->__ref_count++;
}

void smrt_ptr_release(SMRT_PTR * this) {
	this->__private->__ref_count--;
	if(this->__private->__ref_count == 0) {
		mfree(this->__ptr);
	}
}



#include "vector.h"

#define VECTOR_STEP_SIZE 4

/* vector init */
void vector_init(
		VECTOR * const v,
		uint32 elem_size,
		uint32 capacity
		) {
	v->capacity = capacity;
	v->count = 0;
	v->elem_size = elem_size;
	v->max_size = elem_size*capacity;
	v->data = calloc( v->max_size );
}

/* insert data into an array */
void vector_insert(VECTOR * const v, void * const data, uint32 position)
{
	memcpy(data ,(v->data)+position, v->elem_size);
}

/* get the data from the array */
size_t vector_get(VECTOR * const v, uint32 position, void * elem)
{
	elem = v->data[position];
	return v->elem_size;
}

/* append to the end of vector */
void vector_append(VECTOR * const v, void * const data)
{
	v->count++;
	if( v->capacity < v->count )
	{
		// move the vector and expand
		v->capacity += VECTOR_STEP_SIZE;
		void * tmp;
		size_t new_size = v->capacity * v->elem_size;
		tmp = calloc( new_size );
		memcpy(tmp, v->data, v->max_size);
		v->max_size = new_size;
	}

	memcpy(v->data[v->elem_size*v->count++], data, v->elem_size);
}

/* remove from the end of the vector */
size_t vector_pop(VECTOR * const v, void * const data) {
	v->count--;
	data = v->data[v->elem_size*v->count];
	return v->elem_size;
}

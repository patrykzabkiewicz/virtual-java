
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
	v->data = mcalloc( v->max_size );
}

/* insert data into an array */
void vector_insert(VECTOR * const v, void * const data, uint32 position)
{
	mmemcpy(((int8 *)v->data) + (v->elem_size * position), data, v->elem_size);
}

/* get the data from the array */
uint32 vector_get(VECTOR * const v, uint32 position, void * elem)
{
	mmemcpy(elem, (int8 *)v->data + (v->elem_size * position), v->elem_size );
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
		uint32 new_size = v->capacity * v->elem_size;
		tmp = mcalloc( new_size );
		mmemcpy(tmp, v->data, v->max_size);
		v->max_size = new_size;
	}

	mmemcpy((int8 *)v->data + (v->elem_size*v->count++), data, v->elem_size);
}

/* remove from the end of the vector */
uint32 vector_pop(VECTOR * const v, void * data) {
	v->count--;
	mmemcpy(data, (int8 *)v->data + (v->elem_size*v->count), v->elem_size);
	return v->elem_size;
}

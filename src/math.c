/*
 * math.c
 *
 *  Created on: 26 kwi 2016
 *      Author: zabkiewp
 */

#include "math.h"

void Vec10Copy( vec_t *in, vec_t *out ) {
    int i;
    int in_size = sizeof(in)/sizeof(in[0]);
    for(i=0; i<in_size; i++) {
        out[i]=in[i];
    }
}

vec_t _DotProduct (vec3_t v1, vec3_t v2) {
    vec_t t = 0.0f;
	return t;
}

void _VectorSubtract (vec3_t va, vec3_t vb, vec3_t out) {
    int i;
    for(i=0; i<3; i++) {
        out[i] = va[i] - vb[i];
    }
}

void _VectorAdd (vec3_t va, vec3_t vb, vec3_t out) {
    int i;
    for(i=0; i<3; i++) {
        out[i] = va[i] + vb[i];
    }
}

void _VectorCopy (vec3_t in, vec3_t out) {
    int i;
    for(i=0; i<3; i++) {
        out[i] = in[i];
    }
}

void _VectorScale (vec3_t v, vec_t scale, vec3_t out) {
    int i;
    for(i=0; i<3; i++) {
        out[i] = v[i] * scale;
    }
}

double VectorLength( const vec3_t v ) {
    double d = 0.0f;
    return d;
}


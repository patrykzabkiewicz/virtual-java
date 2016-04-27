/*
 * math.h
 *
 *  Created on: 26 kwi 2016
 *      Author: zabkiewp
 */

#ifndef MATH_H_
#define MATH_H_

#include "bool.h"
#include "typedef.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#ifdef DOUBLEVEC_T
typedef double vec_t;
#else
typedef float vec_t;
#endif
typedef vec_t vec2_t[3];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];


#define	Q_PI	3.14159265358979323846
#define DEG2RAD( a ) ( ( (a) * Q_PI ) / 180.0F )
#define RAD2DEG( a ) ( ( (a) * 180.0f ) / Q_PI )

#define	EQUAL_EPSILON	0.001

stdbool VectorCompare( const vec3_t v1, const vec3_t v2 );

#define DotProduct(x,y) (x[0]*y[0]+x[1]*y[1]+x[2]*y[2])
#define VectorSubtract(a,b,c) {c[0]=a[0]-b[0];c[1]=a[1]-b[1];c[2]=a[2]-b[2];}
#define VectorAdd(a,b,c) {c[0]=a[0]+b[0];c[1]=a[1]+b[1];c[2]=a[2]+b[2];}
#define VectorCopy(a,b) {b[0]=a[0];b[1]=a[1];b[2]=a[2];}
#define VectorScale(a,b,c) {c[0]=b*a[0];c[1]=b*a[1];c[2]=b*a[2];}
#define VectorClear(x) {x[0] = x[1] = x[2] = 0;}
#define	VectorNegate(x) {x[0]=-x[0];x[1]=-x[1];x[2]=-x[2];}
void Vec10Copy( vec_t *in, vec_t *out );


vec_t Q_rint (vec_t in);
vec_t _DotProduct (vec3_t v1, vec3_t v2);
void _VectorSubtract (vec3_t va, vec3_t vb, vec3_t out);
void _VectorAdd (vec3_t va, vec3_t vb, vec3_t out);
void _VectorCopy (vec3_t in, vec3_t out);
void _VectorScale (vec3_t v, vec_t scale, vec3_t out);

double VectorLength( const vec3_t v );

void VectorMA( const vec3_t va, double scale, const vec3_t vb, vec3_t vc );

void CrossProduct( const vec3_t v1, const vec3_t v2, vec3_t cross );
vec_t VectorNormalize( const vec3_t in, vec3_t out );
vec_t ColorNormalize( const vec3_t in, vec3_t out );
void VectorInverse (vec3_t v);

void ClearBounds (vec3_t mins, vec3_t maxs);
void AddPointToBounds( const vec3_t v, vec3_t mins, vec3_t maxs );

bool PlaneFromPoints( vec4_t plane, const vec3_t a, const vec3_t b, const vec3_t c );

void NormalToLatLong( const vec3_t normal, uint8 bytes[2] );

int	PlaneTypeForNormal (vec3_t normal);

void RotatePointAroundVector( vec3_t dst, const vec3_t dir, const vec3_t point,
							 float degrees );

#endif /* MATH_H_ */

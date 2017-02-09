
#include <stdlib.h>
#include <math.h>

#ifndef USE_FLOAT
#define vec_t int
#else
#define vec_t float
#endif

typedef struct _point {
	vec_t x;
	vec_t y;
} Point;

typedef struct _spatial {
	Point sp;
	Point * adj;	/* adjencity list */
} Spatial;

typedef struct _rtree {
	struct _rtree * left;
	Point sp;
	struct _rtree * right;
} Rtree;


/*
	calculate euclidan distance between two given points
*/
vec_t distance(Point * const A, Point * const B) {
	int X = abs(A->x - B->x);
	int Y = abs(A->y - B->y);
	return sqrt( X*X + Y*Y );
}

/*
	k-Nearest Neighbor Graph
	linear approach
*/
void kNNG(
	Point * const points,		/* spatial points */
	int spc,			/* spatial points count */
	/* output */
	Spatial * const graph
) {
	int i,j;
	int * dist_m;
	
	if(points == NULL) return;
	if(graph == NULL) return;
	if(spc < 1) return;

	dist_m = (int *) malloc(sizeof(int) * spc * spc);

	/* for every point check all other points */
	for (i = 0; i < spc; i++) {
		for (j = i; j < spc; j++) {
			dist_m[i*spc+j] = distance(&points[i], &points[j]);
		}
	}

	free(dist_m);
}


/*
	Nearest Neighbor Search
	using humming distance for discrete spatial space partitioning
*/
void NNS(Point * const spatial, int spc) {
	
}

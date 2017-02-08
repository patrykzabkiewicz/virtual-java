
#define NULL 0

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


int distance(Point * const A, Point * const B) {
	int X = abs(A->x - B->x);
	int Y = abs(A->y - B->y);
	return sqrt( X*X + Y*Y );
}

/*
	k-Nearest Neighbor Graph
	linear approach
*/
void kNNG(
	Point * points,		/* spatial points */
	int spc,			/* spatial points count */
	/* output */
	Spatial * graph
) {
	int i,j;
	int * dist_m = (int *) malloc(sizeof(int) * spc * spc);

	/* for every point check all other points */
	for (i = 0; i < spc; i++) {
		for (j = i; j < spc; j++) {
			dist_m[i*spc+j] = distance(&points[i], &points[j]);
		}
	}

}


/*
	Nearest Neighbor Search
*/
void NNS(Point * spatial, int spc) {}

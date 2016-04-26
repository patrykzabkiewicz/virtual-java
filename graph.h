/**
 *
 * Implementation of the graph
 *
 * Author: Patryk Zabkiewicz, April 2015
 *
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include "typedef.h"
#include "list.h"

static uint32 vrtx_id = 0;

typedef struct _vrtx {
	uint32 id;			/* number of the vertex */
	void * data;		/* data hold in the vertex */
	LIST * next; 		/* neighbors */
} VRTX;

typedef struct _graph {
	uint32 v_count;		/* amount of hold vertices */
	uint32 data_size;	/* size of the data in bytes */
	LIST * verticies;	/* list of verticies */
} GRAPH;

/* graph initialization */
GRAPH * const graph_init(GRAPH * g, uint32 elem_size);

/* remove vertex from the graph */
void graph_remove_vrtx(GRAPH * const g, VRTX * const v);

/* add new vertex to graph */
void graph_add_vrtx(GRAPH * const g, VRTX * const v);

/* add neighbor of vertex ve to vertex vi */
void graph_add_edge(VRTX * const vi, VRTX * const ve);

/* remove neighbor ve of vertex vi */
void graph_add_edge(VRTX * const vi, VRTX * const ve);


#endif // GRAPH_H_

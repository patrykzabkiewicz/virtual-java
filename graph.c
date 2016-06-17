
#include "graph.h"

/* graph initialization */
GRAPH * const graph_init(GRAPH * g, uint32 elem_size) {
	g = malloc(sizeof(GRAPH));
	g->v_count = 0;
	g->data_size = elem_size;
	list_init(g->verticies, sizeof(VRTX));
	return g;
}

/* remove vertex from the graph */
void graph_remove_vrtx(GRAPH * const g, VRTX * const v) {
	list_remove(g->verticies, v);
}

/* add new vertex to graph */
void graph_add_vrtx(GRAPH * const g, VRTX * const v) {
	list_append_back(g->verticies, v);
}

/* add neighbor of vertex ve to vertex vi */
void graph_add_edge(VRTX * const vi, VRTX * const ve) {
	list_append_back(vi->next, ve);
}

void graph_add_edge_capacity(VRTX * const va, VRTX * const vb, int32 capacity)
{
}

void graph_add_edge_flow(VRTX * const va, VRTX * const vb, int32 flow)
{
}



/* remove neighbor ve of vertex vi */
void graph_remove_edge(VRTX * const vi, VRTX * const ve) {
	list_remove(vi->next, ve);
}



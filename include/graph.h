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
#include "mmalloc.h"


typedef enum _field_type_enum {
	INTEGER = 1,
	CHARACTER,
	VARCHAR,
	FLOATING_POINT,
	DOUBLE_PRECISION
} FIELD_TYPE;

typedef struct _field {
	void * data;
	FIELD_TYPE type;		/* field type */
	uint32 lenght;			/* lenght of the field */
} FIELD;

#define DEFAULT_INT 11
int int_ptr[DEFAULT_INT];

#define DEFAULT_VARCHAR 255
char char_ptr[DEFAULT_INT];

FIELD table[] = {
	{ (void *)int_ptr, INTEGER, 11},
	{ (void *)char_ptr, CHARACTER, 11}
};

typedef struct _table {
	uint8 * name;
	LIST * fields;
	uint32 field_count;
} TABLE;

struct { FIELD_TYPE type; int byte_count; } field_types[] = {
	{INTEGER, 4},
	{CHARACTER, 1},
	{VARCHAR, 4},
	{FLOATING_POINT, 4},
	{DOUBLE_PRECISION, 4}
};

/* STRUCT holding the informations about calculated data */
typedef struct _vrtx_map {
	/* TODO describe vertex map in dense network */
	int a;
} VRTX_MAP;

/* STRUCT describes the gravity in network */
typedef struct _vrtx_gravity {
	int32 gravity;		/* how much flow it attracts, impact on space and neighbors */
	int32 weight;		/* weight of vertex,  */
} VRTX_GRAVITY;

/* STRUCT describes the road in navigation engine */
typedef struct _vrtx_road {
	uint32 distance;	/* distance to another vertex */
	int32 cost;			/* cost of getting throu vertex */
	int32 alpha;		/* angle of direction to next vertex */
	int32 taken;		/* is the road occupied */
} VRTX_ROAD;

/* SRTUCT describes flow in network */
typedef struct _vrtx_flow {
	int32 flow;			/* flow in the vertex */
	int32 capcity;		/* capcity of the vertex */
} VRTX_FLOW;

/* STRUCT describing the basic vertex in graph */
typedef struct _vrtx {
	uint32 id;			/* number of the vertex */
	void * data;		/* data hold in the vertex */
	LIST * next; 		/* neighbors */
} VRTX;

/* STRUCT holding the information about the graph */
typedef struct _graph {
	uint32 v_count;		/* amount of hold vertices */
	uint32 data_size;	/* size of the data in bytes */
	FIELD_TYPE data_type;	/* defined type of the field */
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

/* add or substract capacity to edge */
void graph_add_edge_capacity(VRTX * const va, VRTX * const vb, int32 capacity);

/* add or substract flow to edge */
void graph_add_edge_flow(VRTX * const va, VRTX * const vb, int32 flow);



#endif /* GRAPH_H_ */

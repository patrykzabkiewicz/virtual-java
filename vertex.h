/**
 *
 * Implementation of the vertex
 *
 * Autor: Patryk Zabkiewicz
 *
*/

/* Struct for traffic vertex */
typedef struct _trffc_v {
	uint8 hour;
	uint8 type;
	struct _trffc_v * next;
} TRAFFIC_VRTX;

/* Struct for vertex */
typedef struct _map_vertex {
	uint32 id;
	uint8 * street_name;
	TRAFFIC_VRTX * traffic;
	struct _map_vertex * next;
} VRTX;

VRTX * new_vrtx();
void * destroy_vrtx(VRTX * ptr_vrtx);

void * add_traffic_vrtx(VRTX * ptr_vrtx);
void * remove_traffic_vrtx(VRTX * ptr_vrtx);
TRAFFIC_VRTX * get_traffic_vrtx(int i);


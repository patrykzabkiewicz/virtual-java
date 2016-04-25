/**
 *
 * Implementation of the graph
 *
 * Author: Patryk Zabkiewicz, April 2015
 *
*/

namespace dfrm {

template <typename T>
struct graph {
	int v_count;
	int e_count;
	list<vertex<T>> *verticies;

	graph() {
		this->verticies = new list<vertex>(); 
	}

	~graph() {
		delete this->verticies;
	}

}


template <typename T>
void addVertex(graph<T> *g, vertex<T> *v) {
	push_back(g->verticies, v);
}


template <typename T>
void addEdge(vertex<T> *vs, vertex<T> *ve) {
	push_back(vs->edges,ve);
}

}

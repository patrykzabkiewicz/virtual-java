
/*
	Floyd-Warshall algorithm implementation with path reconstruction

	dist - distances initialized to infinity (or precalculated before)
	next - vertex indices initialized to null
*/

#include <stdlib.h>

void floyd_warshall(int * dist[], int * next[], int V) {
	int u;
	int v;
	int k, i, j;

	// for each edge (u,v)
	for ( /* no idea yet */ ) {
		dist[u][v] = w(u, v); /* weight of the edge */
		next[u][v] = v;
	}

	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])) {
					dist[i][j] = dist[i][k] + dist[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
}

/*
	Path reconstruction 
		from calculated previously matrix of next elements
*/
int * path_reconstruction(int * next[], int * path) {
	int u, v;
	int i = 0;

	if (next[u][v] == NULL) {
		return NULL;
	}
	path[i] = u;
	while (u != v) {
		u = next[u][v];
		path[++i] = u;
	}
	return path;
}

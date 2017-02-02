
#include <stdlib.h>

#define EPSILON 0.1

/*
square clustering
cluster graph by dividing verticies into square segments
*/
int * square_cluster(int * graph);

/*
nearest neighbor clustering
cluster graph by squeze nearest neighbors into one node

implementation details:
NN is implemented on basis of reduction of classes by merging two low distance classes together
at beginning we asume that every node in graph is a seperate class
for every node in graph we calculate distance to every class (note above statment)
if distance is less than epsilon than we do merge them

Can this algorithm be repeated recursivly?
Can we implement this as recursion?
Can we send the classes onto heap?

*/
void knn_cluster(int * const in[], /* adjencity matrix input */
	int * const out[], /* adjencity matrix output after nn clustering */
	int in_node_count);


int * square_cluster(int * graph) {

}

void knn_cluster(
	int * const in[],	/* adjencity matrix input */
	int * const out[],	/* adjencity matrix output after nn clustering */
	int in_node_count,
	int k				/* amount of cluster levels */
) {
	int i;
	int j;
	int m;
	const double eps = EPSILON;
	int * parent = (int *) malloc(sizeof(int) * in_node_count); // array of parent classes
	float * classes = (float *)malloc(sizeof(float) * in_node_count); // array of class means

	/* for every node */
	for (m = 0; m < k; m++) {
		for (i = 0; i < in_node_count; i++) {
			for (j = 0; j < in_node_count; j++) {
				if (distance(in[i][j], classes[i]) < EPSILON) {
					parent[j] = i;
				}
			}
		}
	}
}



/*
	square clustering
	cluster graph by dividing verticies into square segments
*/
void square_cluster(int * const in, int * const out);

/*
	nearest neighbor clustering
	cluster graph by squeze nearest neighbors into one node
*/
void nn_cluster(int * const in, int * const out);


void square_cluster(int * const in, int * const out) {
    /*  */

}

void nn_cluster(int * const in, int * const out) {
    int i;
    int j;
    HEAP * H;

    /* for every node push neighbors to the heap */
    for(i=0; i<in->count; i++) {
        for(j=0; j<in[i]->adj_count; j++) {
            heap_push(H,i);
        }
    }


}

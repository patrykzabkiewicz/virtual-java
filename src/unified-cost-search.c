
/* 
    unified cost search algorithm
    
    basic dijkstra algorithm expanded for inifinite graph

*/
int ucs(GRAPH * const g, int source, int sink) {
    int node = source;
    int cost = 0;
    PRIORITY_QUEUE * frontier;
    SET * explored;
    
    priority_queue_init(frontier);
    set_init(explored);

    while(1) {
        if(frontier->size == 0) return -1;
        node = priority_queue_pop(frontier);
        if(node == sink) return node;
        set_add(explored, node);

        /* for each */
        for(n->adj_count) {
            
        }
    }

}



/* maximum flow in network with  */
void edmonds_karp(
    int * const C[], /* capacity matrix */
    int * const T[], /* residual matrix, T = C at beginning */
    int s,          /* source */
    int t,          /* sink */
    /* outputs */
    int f,          /* maximum flow */ 
    int * const F[] /*  */
    ) {
        int m;
        int * P;
        int v,u;

        f = 0;
        F = (int *) malloc(sizeof(int) * n * n);

    while(1) {
        breadest_first_search(C,T,s,t,F,m,P);
        if(m = 0) break;
        f = f+m;
        v = t;
        while( v != s ) {
            u = P[v];
            F[u][v] = F[u][v] + m;
            F[v][u] = F[v][u] - m;
            T[u][v] = T[u][v] - m;
            T[v][u] = T[v][u] + m;
            v = u;
        }
    }
}

/* helping algorithm for finding shortest path with avaible capacity */
void breadest_first_search(
    int * const C[],
    int * const T[],
    int s,
    int t,
    int * const F[],
    /* outputs */
    int M, /* capacity of path found */
    int * P /* parent table */
) {
    int u;
    int n = 10;
    QUEUE * Q;

    P = malloc();
    
    for(u=0; u<n; u++) {
        P[u] = -1;
    }

    P[s] = -2; /* source cannot be rediscovered */
    M = (int *) malloc(sizeof(int) * n);
    M[s] = MAX_INT;

    queue_init(Q);

    queue_push(Q, s);

    while(Q->size > 0) {
        u = queue_pop(Q);
        for() {
            if(T[u][v] > 0 && P[v] = -1) {
                P[v] = u;
                M[v] = min(M[u], C[u][v] - F[u][v]);
                if ( v != t ) {
                    queue_append(Q,v);
                } else {
                    return;
                }
            }
        }
    }

}



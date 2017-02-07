
#include <stdio.h>
#define NULL 0

/*
    calculate some stuff
*/
int calculate(
    int * T,    /* input matrix */
    int Ti,     /* input count, scalar */
    int * P     /* output matrix */
    ) {
        int Pi;
        int j;
        
        for(int i=0; i < Ti; i++) {
            P[j] += T[i];
            if( i % 2 == 0 ) Pi++;
        }

        return Pi;
}

/*
    estimates how input variables influence the output
*/
int estimate(
    int ti,         /*  */
    int * Q         /* output matrix */
    ) {
        int Qi;     /* count of output variables */

        for() {}

        return Qi;
    }


int generate_inputs(int * T /* output */) {

}

/*
    main
*/
int main(int argc, char * argv[]) {

    int * T = (int *) malloc(sizeof(int));
    int * P = (int *) malloc(sizeof(int));
    
    int Ti,Pi;

    /* generate inputs for calculation based on  */
    Ti = generate_inputs(T);

    /*  */
    Pi = calculate(T,Ti,P);

    /*
        we consider two cases

        1. the program is the unknown, we know relation between input and output, 
        but we have to descibe the decision tree

        2. the output and program are known and input is unknown, we try to find
        inputs that fits all the possible results
    */

    /* estimate what inputs are influencing what outputs */
    estimate();

    /* build the decision tree, aka output program */
    build();

    /* test correctness with all inputs and outputs */
    test();

    /* print the generated program */
    printout();

}

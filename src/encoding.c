
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
    estimates how input variables
*/
int estimate(
    int * Q         /* output matrix */
    ) {
        int Qi;     /* count of output variables */

        

        return Qi;
    }


/*
    main
*/
int main(int argc, char * argv[]) {

}

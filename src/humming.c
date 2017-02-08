
#define NULL 0

/*
    bit-wise xor
*/
int xor(int x, int y) 
{
    int a = x & y;
    int b = ~x & ~y;
    int z = ~a & ~b;
    return z;
}     

/*
    humming distance
*/
int humming(int A, int B) 
{
    int i, tmp;
    int p = 0; /* returns amount of active bits  */
    tmp = xor(A,B);
    while(tmp > 0) {
        if(tmp & 1) p++;
        tmp = tmp << 1;
    }
    return p;
}


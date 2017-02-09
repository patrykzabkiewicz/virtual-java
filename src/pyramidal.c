
#define NULL 0

/*
	pyramid space scaling
*/
void pyramid(int * in[], int * out[], int in_size);

void scale_out(
	int * in[], 
	int * out[], 
	int * rel[] /* relation matrix */
	);

/*
	scale out and downsize sample
*/
void scale_out(
	int * in[], 
	int * out[], 
	int * rel[] /* relation matrix */
	) {

	}

void pyramid(int * in[], int * out[], int in_size) {
	int i;

	/* for every node calculate avrage of neighberhood */
	for(i=0; i<in_size; i++) {
		out[i] = /*calc()*/ in[i];
	}
}


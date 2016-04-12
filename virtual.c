/****************************************
 *
 *  Virtual machine in C
 *
 *  Author: 	Patryk Zabkiewicz
 *  Date:	06.01.2016
 *
*/

#include <stdio.h>

#define uint8 unsigned char
#define uint16 unsigned short
#define uint32 unsigned int
#define uint64 unsigned long long

#define int8 char
#define int16 short
#define int32 int
#define int64 long long

#define CHNL_SIZE 256


/* Structure for machine language instructions */
typedef struct _instr {
	int32 binary;
	uint8 * mnemonic;	
} INSTR;


/* CPU simulator structure */
typedef struct _cpu {
	uint8 AX;
	uint8 BX;
	uint8 CX; 
} PX_CPU;


/* Channel describing structure */
typedef struct _channel {
	uint8 * ASD;
	int32 user_count;
	int32 current_readers;
} CHNL;

/* Machine structure */
typedef struct _machine {
	
} MACHINE;

/* Reads date from the channel */
void * readChnl(uint8 * CHNL, uint8 size) {}


/* Writes date onto a channel */
void * writeChnl(uint8 * CHNL, uint8 size) {}


/* Main */
int main(int argc, char **argv) {
	MACHINE * list_machines;

	// initiate the machines
	int number_of_machines = create_machines(list_machines);

}


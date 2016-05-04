/****************************************
 *
 *  Virtual machine in C
 *
 *  Author: 	Patryk Zabkiewicz
 *  Date:	06.01.2016
 *
*/

#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include "typedef.h"
#include "queue.h"
#include "stack.h"
#include "nullptr.h"

/* Structure for machine language instructions */
typedef struct _instr {
	int32 binary;
	uint8 * mnemonic;
} INSTR;


/* CPU simulator structure */
typedef struct _cpu {
	// the registers could be queues of states that one can come to specific another
	// the whole cpu could be rabin-scott state machine
	STACK * AX;		/* 64-bit register */
	STACK * BX;		/* 64-bit register */
	STACK * CX;		/* 64-bit register */

	uint32 PC;		/* Program counter */

	uint8 CARRY : 1;		/* Carry flag */
	uint8 NILL : 1;			/* Result zero */
	uint8 PAIR : 1;			/* Result is even */
	uint8 MINUS : 1;		/* Result is negative */
} PX_CPU;

inline void px_cpu_init(PX_CPU * px);

/* Stack simulator structure */
typedef struct _stack {
	uint8 count;
	uint8 * data;
	uint8 * first;
} PX_STACK;

inline void px_stack_init(PX_STACK * sx);

/* Machine structure */
typedef struct _machine {
	PX_CPU * cpu;
	PX_CPU * cpu_cp; /* copy of the cpu state for try catch blocks */
	PX_STACK * stack;
	PX_STACK * stack_cp; /* copy of the stack state for try catch blocks */

	QUEUE * instr_queue; /* instruction queue */
} MACHINE;

/* Structure that holds all the virtual machines abstraction */
typedef struct _machines_struct {
  	MACHINE * machines_list;       /* List of the machines */
    uint32 count;                  /* How many machines are on the list */
} MACHINES_STRUCT;

/* initialization of virtual machines */
void virtual_machine_init(MACHINE * m);

#endif // VIRTUAL_MACHINE_H

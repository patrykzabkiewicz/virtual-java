/****************************************
 *
 *  Virtual machine in C
 *
 *  Author: 	Patryk Zabkiewicz
 *  Date:	06.01.2016
 *
*/


/* Structure for machine language instructions */
typedef struct _instr {
	int32 binary;
	uint8 * mnemonic;
} INSTR;


/* CPU simulator structure */
typedef struct _cpu {
	uint64 AX;		/* 64-bit register */
	uint64 BX;		/* 64-bit register */
	uint64 CX;		/* 64-bit register */

	uint32 PC;		/* Program counter */

	uint8 CARRY : 1;		/* Carry flag */
	uint8 NILL : 1;			/* Result zero */
	uint8 PAIR : 1;			/* Result is even */
	uint8 MINUS : 1;		/* Result is negative */
} PX_CPU;

typedef struct _stack {
	uint8 count;
	uint8 * data;
	uint8 * first;
} PX_STACK;

/* Machine structure */
typedef struct _machine {
	PX_CPU 		* cpu;		/* CPU of virtual machine */
	PX_STACK 	* stack;	/* Stack of the virtual machine */
	MEMORY		* mem;		/* Memory for the machine */
	//NETWORK * net;			/* Network connection for virtual machine */
	//DISK * io;				/* Disk storage for virtual machine */
} MACHINE;

typedef struct _machine_elem {
  MACHINE * data;
  MACHINE * next;
  MACHINE * prev;
} MACHINE_ELEM;


/* Double ended list of machines */
typedef struct _machine_list {
  MACHINE_ELEM * elem;
  MACHINE_ELEM * first;
  MACHINE_ELEM * last;
  uint32 count;

  (void *)(*append_front)();
  (void *)(*append_back)();
  (void *)(*pop_back)();
  (void *)(*pop_front)();

} MACHINE_LIST;

/* Structure that holds all the virtual machines abstraction */
typedef struct _machines_struct {
  	MACHINE * machines_list;       /* List of the machines */
    uint32 count;                  /* How many machines are on the list */
} MACHINES_STRUCT;

/* initialization of virtual machines */
int virtual_machine_init(int argc, char **argv);

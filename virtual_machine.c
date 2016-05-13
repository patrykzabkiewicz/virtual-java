
#include "virtual_machine.h"

/* initialization of virtual machines */
void virtual_machine_init(MACHINE * m) {
	m = (MACHINE *) malloc(sizeof(MACHINE));
	m->cpu = (PX_CPU *) malloc(sizeof(PX_CPU));
	px_cpu_init(m->cpu);

	m->stack = (PX_STACK *) malloc(sizeof(PX_STACK));
	px_stack_init(m->stack);

	m->instr_queue = (QUEUE *) malloc(sizeof(QUEUE));
	queue_init(m->instr_queue);

	m->cpu_cp = nullptr;
	m->stack_cp = nullptr;

}

inline void px_cpu_init(PX_CPU * px) {
	stack_init(px->AX);
	stack_init(px->BX);
	stack_init(px->CX);
	px->PC = 0;
	px->MINUS = 0x00;
	px->NILL = 0x00;
	px->PAIR = 0x00;
	px->CARRY = 0x00;
}

inline void px_stack_init(PX_STACK * sx) {

}

void virtual_machine_exec(MACHINE * m, CLASS * cl) {
	queue_append_back(m->instr_queue, cl);
}


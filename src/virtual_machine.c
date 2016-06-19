
#include "virtual_machine.h"

/* initialization of virtual machines */
void virtual_machine_init(MACHINE * m) {
	m = (MACHINE *) mmalloc(sizeof(MACHINE));
	m->cpu = (PX_CPU *) mmalloc(sizeof(PX_CPU));
	px_cpu_init(m->cpu);

	m->heap = (PX_STACK *) mmalloc(sizeof(PX_STACK));
	px_stack_init(m->heap);

	m->instr_queue = (QUEUE *) mmalloc(sizeof(QUEUE));
	queue_init(m->instr_queue, sizeof(INSTR));

}

void virtual_machine_exec(MACHINE * m, CLASS * cl) {
	QUEUE_ELEM * qe;
	qe = (QUEUE_ELEM *) mmalloc(sizeof(QUEUE_ELEM));
	qe->data = (void *) cl;
	queue_append_back(m->instr_queue, qe);
}

void virtual_machine_destroy(MACHINE * m) {

}

void px_cpu_init(PX_CPU * px) {
	px_stack_init(px->AX);
	px_stack_init(px->BX);
	px_stack_init(px->CX);
	px->PC = 0;
	px->MINUS = 0x00;
	px->NILL = 0x00;
	px->PAIR = 0x00;
	px->CARRY = 0x00;
}

void px_stack_init(PX_STACK * sx) {

}


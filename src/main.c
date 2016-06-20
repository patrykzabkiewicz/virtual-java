/**************************
 *
 *	Lightweigh Java VM
 *
 *	Project is intended to provide a lightweight java virtual machine
 *	Can run both Java and C++ programs on seperate enviroments from underneath platform
 *	Your program will execute always the same way on every platform
 *	No JIT compilation and no different behaviour for different data
 *	Enterprise level of security, ECC checks and bulletprof isolation from outside world
 *	Perfect for Banking, Finance and Enterprises
 * 	100% compatible with your current java code, but executes it faster and more safetly than JVM
 *
 *	Main features are:
 *		- register based, with stack
 *		- application isolation, run every app in seperate enviroment
 *		- no batch memory allocation from kernel
 *		- dynamic memory allocation outside machine
 *		- returning memory to kernel after object is destroyed
 *		- no garbage colletion
 *		- destroy object and deallocate resources after pointer is released
 *		- all pointers are smart pointers
 *		- all refrences are counted to data object
 *		- no lazy initialization, all resources are initialized
 *			at the start of the system or dynamicly during runtime
 *		- no data duplication in memory, copy-on-write, one data, multiple pointers
 *		- 100% compatible with current java language spec, but executes instructions diffrently
 *		- continue running after program closed
 *		- prefetch resources, allocate before it's needed
 *		- predict resource allocation (no lazy allocation like normal java)
 *		- resolve dependencies and load them once, use multiple times
 *		- no cached interpreter of class files (better security)
 *
 *		- thread safty tests
 *		- memory leaks tests
 *		- compatibility tests
 * 		- performance tests, how much time it takes the execute certain algorithm on certain data
 *		- security tests
 *		-
 *
 * 		Security enhancments:
 *		- boundy checks
 *		- bit ecc checks on data types
 *		-
 *
 *	Author: 	Patryk Zabkiewicz
 *	Date: 		2016-03-23
 *
 *	License:	GPL 3.0
 *
*/

#include <stdio.h>
#include "nullptr.h"
#include "parser.h"
#include "list.h"
#include "stack.h"
#include "linker.h"
#include "mmalloc.h"
#include "virtual_machine.h"

/*
# class file interpretation and loading
# instructions execution
# memory management
# interprocess communication
# multithreading, threads

*/

#define NCC 2

struct {
	char name[25];
	char filename[255];
	char path[25];
} ncs[] = {
	{ "int" , "int" , "int"},
	{ "string", "string", "string" }
};

/* ******** */
int main(int argc, char *argv[]) {
/* ******** */
	int32 i;

	if(argc < 2) {
		printf("no class file name given");
		return -1;
	}

	// bootstrap class loader

	// should be threaded
	// NCC = native class count
	STACK * ncl_list;
	ncl_list = (STACK *) mmalloc(sizeof(STACK));
	stack_init(ncl_list, sizeof(CLASS));

	for(i = 0; i < NCC; i++) {
		CLASS * clc = load_class(ncs[i].name);
		STACK_ELEM * stack_elem;
		stack_elem = (STACK_ELEM *) mmalloc(sizeof(STACK_ELEM));
		stack_elem->data = clc;
		stack_push(ncl_list,stack_elem);
	}

	// user defined class loader
	CLASS * cl = load_class(argv[1]);

	// link class file
	/**
	 *	Verification: ensures the correctness of the imported type
	 *	Preparation: allocates memory for class variables and initializing the memory to default values
	 *	Resolution: transforms symbolic references from the type into direct references.
	 */
	linker(cl);
	
	/* cache the result of parsing and linking */
	//cache();

	// starting the main interprer process
	MACHINE * vm = nullptr;
	virtual_machine_init(vm);
	stack_init(vm->native_ms, sizeof(CLASS));

	virtual_machine_exec(vm,cl);

	/* memory cleanup */
	virtual_machine_destroy(vm);
	stack_destroy(ncl_list);
	class_destroy(cl);

	/* always return zero at the end */
	return 0;
}

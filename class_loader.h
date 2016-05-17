#ifndef CLASS_LOADER_H_
#define CLASS_LOADER_H_

#define "typedef.h"
#define "heap.h"
#define "class.h"

HEAP * bootstrap_classes;
HEAP * extenstion_classes;
HEAP * system_classes;
HEAP * user_classes;

void loader_init();
void load_class(CLASS * const cl);
void optimize_bytecode(CLASS * const cl);

#endif // CLASS_LOADER_H_
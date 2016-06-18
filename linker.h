#ifndef CLASS_LOADER_H_
#define CLASS_LOADER_H_

#include "typedef.h"
#include "class_loader.h"
#include "heap.h"
#include "parser.h"

extern HEAP * bootstrap_classes;
extern HEAP * extenstion_classes;
extern HEAP * system_classes;
extern HEAP * user_classes;

void linker(CLASS * const cl);

#endif // CLASS_LOADER_H_
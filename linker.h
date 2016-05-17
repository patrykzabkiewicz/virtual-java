#ifndef CLASS_LOADER_H_
#define CLASS_LOADER_H_

#define "typedef.h"
#define "class_loader.h"
#define "heap.h"
#define "class.h"

extern HEAP * bootstrap_classes;
extern HEAP * extenstion_classes;
extern HEAP * system_classes;
extern HEAP * user_classes;

void link(CLASS * const cl);

#endif // CLASS_LOADER_H_
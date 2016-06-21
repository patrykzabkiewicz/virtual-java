#ifndef NULLPTR_H_
#define NULLPTR_H_

typedef void * const nullptr;
#define nullptr (nullptr) 0

#ifdef _WIN32
#define NULL nullptr
#endif

#endif /* NULLPTR_H_ */

#ifndef MMALLOC_H
#define MMALLOC_H

#include <unistd.h>

#ifdef _WIN32
#include <Windows.h>
#define alloc(X) VirtualAlloc(NULL, X, MEM_COMMIT, PAGE_EXECUTE_READWRITE)
#else
#define alloc(X) sbrk(X)
#endif

typedef struct free_block {
    size_t size;
    struct free_block* next;
} free_block;

void * mmalloc(size_t size);
void * mcalloc(size_t size);
void mmemcpy(void * target, void * source, int bytecount);
int mmemcmp(void * const source, void * const end, int elem_size);

void mfree(void* ptr);

#endif /* MMALLOC_H */

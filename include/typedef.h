#ifndef TYPEDEF_H
#define TYPEDEF_H

#define WINDOWS

#ifndef WINDOWS
#include <unistd.h>
#endif

#define uint8 unsigned char
#define uint16 unsigned short
#define uint32 unsigned int
#define uint64 unsigned long long

#define int8 char
#define int16 short
#define int32 int
#define int64 long long

#define bool int
#define true 1
#define false 0

#endif // TYPEDEF_H

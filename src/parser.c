/*
 * parser.c
 *
 *  Created on: 9 maj 2016
 *      Author: zabkiewp
 */

#include <stdio.h>

#include "parser.h"
#include "logger.h"
#include "mmalloc.h"

extern QUEUE * lglog;

#define MAX_FILE_SIZE 4096
#define CANT_READ_FILE "Cannot read class file:"

CLASS * load_class(int8 * name) {
    // read file to memory
    FILE * fd;
    uint8 buffer[MAX_FILE_SIZE];
    uint32 n;

    fd = fopen(name, "rb");
    if (fd)
    {
        n = fread(buffer, MAX_FILE_SIZE, 1, fd);
	if(n) 
	{
		// print buffer
		printf("%s",buffer);
	}
    }
    else
    {
        // error opening file
        int8 msg[] = CANT_READ_FILE;
        putlog(lglog, WARRNING, msg );
    }
    
    // parse the file and create structures
    CLASS * c = (CLASS *) mmalloc (sizeof(CLASS));
    // c->magic_number = ;
    // c->
    return c;
}

void class_destroy(CLASS * const cl) {}


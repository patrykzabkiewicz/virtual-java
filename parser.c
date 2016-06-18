/*
 * parser.c
 *
 *  Created on: 9 maj 2016
 *      Author: zabkiewp
 */

#include "parser.h"
#include <stdio.h>

#define MAX_FILE_SIZE 4096

CLASS * load_class(int8 * name) {
    // read file to memory
    FILE * fd;
    uint8 buffer[MAX_FILE_SIZE];
    uint32 n;

    f = fopen(name, "rb");
    if (f)
    {
        n = fread(buffer, MAX_FILE_SIZE, 1, f);
    }
    else
    {
        // error opening file
        Log(WARRNING,"Cannot read class file: " + name );
    }
    
    // parse the file and create structures
    CLASS * c = (CLASS *) malloc (sizeof(CLASS));
    c->magic_number = ;
    c->
}

void class_destroy(CLASS * const cl) {}


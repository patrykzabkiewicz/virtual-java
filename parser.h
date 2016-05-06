#ifndef PARSER_H_
#define PARSER_H_


#include "typedef.h"

#define java_class_magic 0xCAFEBABE

typedef struct _cp_info {
    uint32 cos;
} cp_info;

typedef struct _field_info {
    uint32 cos;
} field_info;

typedef struct _method_info {
    uint32 cos;
} method_info;

typedef struct _attribute_info {
    uint32 cos;
} attribute_info;


typedef struct Class_File_Format {
   uint32 magic_number;

   uint16 minor_version;   
   uint16 major_version;

   uint16 constant_pool_count;   // n+2 constans
  
   cp_info constant_pool[constant_pool_count - 1];

   uint16 access_flags;

   uint16 this_class;
   uint16 super_class;

   uint16 interfaces_count;   
   
   uint16 interfaces[interfaces_count];

   uint16 fields_count;   
   field_info fields[fields_count];

   uint16 methods_count;
   method_info methods[methods_count];

   uint16 attributes_count;   
   attribute_info attributes[attributes_count];
} CLASS;

#endif // PARSER_H_


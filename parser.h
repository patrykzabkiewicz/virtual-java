#ifndef PARSER_H_
#define PARSER_H_


#include "typedef.h"

#define java_class_magic 0xCAFEBABE

struct Class_File_Format {
   u4 magic_number;

   u2 minor_version;   
   u2 major_version;

   u2 constant_pool_count;   
  
   cp_info constant_pool[constant_pool_count - 1];

   u2 access_flags;

   u2 this_class;
   u2 super_class;

   u2 interfaces_count;   
   
   u2 interfaces[interfaces_count];

   u2 fields_count;   
   field_info fields[fields_count];

   u2 methods_count;
   method_info methods[methods_count];

   u2 attributes_count;   
   attribute_info attributes[attributes_count];
}

#endif // PARSER_H_


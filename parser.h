#ifndef PARSER_H_
#define PARSER_H_


#include "typedef.h"

#define java_class_magic 0xCAFEBABE

#define ACC_PUBLIC 	0x0001
#define ACC_FINAL 	0x0010
#define ACC_SUPER	0x0020
#define ACC_INTERFACE 0x0200
#define ACC_ABSTRACT 0x0400
#define ACC_SYNTHETIC 0x1000
#define ACC_ANNOTATION 0x2000
#define ACC_ENUM 0x4000


#define CONSTANT_Class 7
#define CONSTANT_Fieldref 9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_String 8
#define CONSTANT_Integer 3
#define CONSTANT_Float 4
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_NameAndType 12
#define CONSTANT_Utf8 1

typedef struct _cp_info {
    uint8 tag;
    uint8 info[];
} cp_info;

typedef struct CONSTANT_Class_info {
	uint8 tag;
	uint16 name_index;
} const_class_info;

typedef struct CONSTANT_Fieldref_info {
	uint8 tag;
	uint16 class_index;
	uint16 name_and_type_index;
} const_fieldref_info;

typedef struct CONSTANT_Methodref_info {
	uint8 tag;
	uint16 class_index;
	uint16 name_and_type_index;
} const_methodref_info;

typedef struct CONSTANT_InterfaceMethodref_info {
	uint8 tag;
	uint16 class_index;
	uint16 name_and_type_index;
} const_interface_info;

typedef struct CONSTANT_String_info {
	uint8 tag;
	uint16 string_index;
} const_string_info;

typedef struct CONSTANT_Long_info {
	uint8 tag;
	uint32 high_bytes;
	uint32 low_bytes;
} const_long_info;

typedef struct CONSTANT_Double_info {
	uint8 tag;
	uint32 high_bytes;
	uint32 low_bytes;
} const_double_info;

typedef struct CONSTANT_Integer_info {
	uint8 tag;
	uint32 bytes;
} const_int_info;

typedef struct CONSTANT_Float_info {
	uint8 tag;
	uint32 bytes;
} const_float_info;

typedef struct CONSTANT_NameAndType_info {
	uint8 tag;
	uint16 name_index;
	uint16 descriptor_index;
} const_nametype_info;

typedef struct CONSTANT_Utf8_info {
	uint8 tag;
	uint16 length;
	uint8 * bytes; /* table */
} const_utf8_info;

typedef struct _field_info {
	uint16 access_flags;
	uint16 name_index;
	uint16 descriptor_index;
	uint16 attributes_count;
	attribute_info * attributes; /* table */
} field_info;


#define ACC_PUBLIC 0x0001 // Declared public; may be accessed from outside its package.
#define ACC_PRIVATE 0x0002 // Declared private; usable only within the defining class.
#define ACC_PROTECTED 0x0004 // Declared protected; may be accessed within subclasses.
#define ACC_STATIC 0x0008 // Declared static.
#define ACC_FINAL 0x0010 // Declared final; no further assignment after initialization.
#define ACC_VOLATILE 0x0040 // Declared volatile; cannot be cached.
#define ACC_TRANSIENT 0x0080 // Declared transient; not written or read by a persistent object manager.
#define ACC_SYNTHETIC 0x1000 // Declared synthetic; Not present in the source code.
#define ACC_ENUM 0x4000 // Declared as an element of an enum

typedef struct _method_info {
	uint16 access_flags;
	uint16 name_index;
	uint16 descriptor_index;
	uint16 attributes_count;
	attribute_info * attributes; /* table */
} method_info;


#define ACC_PUBLIC 0x0001
#define ACC_PRIVATE 0x0002
#define ACC_PROTECTED 0x0004
#define ACC_STATIC 0x0008
#define ACC_FINAL 0x0010
#define ACC_SYNCHRONIZED 0x0020
#define ACC_BRIDGE 0x0040
#define ACC_VARARGS 0x0080
#define ACC_NATIVE 0x0100
#define ACC_ABSTRACT 0x0400
#define ACC_STRICT 0x0800
#define ACC_SYNTHETIC 0x1000

typedef struct _attribute_info {
	uint16 attribute_name_index;
	uint32 attribute_length;
	uint8 * info; /* table */
} attribute_info;

typedef struct _ConstantValue_attribute {
	uint16 attribute_name_index;
	uint32 attribute_length;
	uint16 constantvalue_index;
} const_attribute_info;

typedef struct Code_attribute {
	uint16 attribute_name_index;
	uint32 attribute_length;
	uint16 max_stack;
	uint16 max_locals;
	uint32 code_length;
	uint8 code; /* table */
	uint16 exception_table_length;
	struct {
		uint16 start_pc;
		uint16 end_pc;
		uint16 handler_pc;
		uint16 catch_type;
	} * exception_table; /* table */
	uint16 attributes_count;
	attribute_info * attributes; /* table */
} code_attribute;


typedef struct Class_File_Format {
   uint32 magic_number;

   uint16 minor_version;   
   uint16 major_version;

   uint16 constant_pool_count;   // n+2 constans
  
   cp_info * constant_pool; /* table */

   uint16 access_flags;

   uint16 this_class;
   uint16 super_class;

   uint16 interfaces_count;   
   
   uint16 * interfaces; /* table */

   uint16 fields_count;   
   field_info * fields; /* table */

   uint16 methods_count;
   method_info * methods; /* table */

   uint16 attributes_count;   
   attribute_info attributes; /* table */
} CLASS;


CLASS * load_class(int8 * name);


#endif // PARSER_H_


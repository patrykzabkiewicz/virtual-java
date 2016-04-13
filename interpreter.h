
typedef struct nodeTypeTag nodeType, *nodeTypePtr;

typedef enum {
	typeCon,
	typeId,
	typeOpr
} nodeEnum;

typedef struct {
	int	value;
} conNodeType;

typedef struct {
	int	i;
} idNodeType;

typedef struct {
	int		oper;
	int		nops;
	nodeType	*op[1];
} oprNodeType;

struct nodeTypeTag {
	nodeEnum	type;

	union {
		conNodeType	con;
		idNodeType	id;
		oprNodeType	opr;
	} value;
};


extern int	sym['z'-'a'+1];

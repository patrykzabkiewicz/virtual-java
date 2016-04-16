%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "includes.h"

nodeType	*opr( int, int, ... );
nodeType	*id( int );
nodeType	*con( int );
void		freeNode( nodeType* );
int		ex( nodeType* );

int		sym['z'-'a'+1];
%}

%union {
	int		iValue;
	char		sIndex;
	nodeType	*nPtr;
};

%token<iValue>	INTEGER
%token<sIndex>	VARIABLE
%token WHILE IF PRINT
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' 
%left '^'
%nonassoc UMINUS

%type<nPtr> stmt expr stmt_list

%%

function:
	function stmt	{ ex($2); freeNode($2); }
	|
	;

stmt:
    	';'				{ $$= opr( ';', 2, NULL, NULL); }
	|
	expr ';'			{ $$= $1; }
	|
	PRINT expr ';'			{ $$= opr( PRINT, 1, $2 ); }
	|
	VARIABLE '=' expr ';'		{ $$= opr( '=', 2, id($1), $3 ); }
	|
	WHILE '(' expr ')' stmt		{ $$= opr( WHILE, 2, $3, $5 ); }
	|
	IF '(' expr ')' stmt %prec IFX  { $$= opr( IF, 2, $3, $5 ); }
	|
	IF '(' expr ')' stmt ELSE stmt  { $$= opr( IF, 3, $3, $5, $7 ); }
	|
	'{' stmt_list '}'		{ $$= $2; }
	;

stmt_list:
	 stmt				{ $$= $1; }
	 |
	 stmt_list stmt			{ $$= opr( ';', 2, $1, $2 ); }
	 ;

expr:
    	INTEGER				{ $$= con( $1 ); }
	|
	VARIABLE			{ $$= id( $1 ); }
	|
	'-' expr %prec UMINUS		{ $$= opr( UMINUS, 1, $2 ); }
	|
	expr '+' expr			{ $$= opr( '+', 2, $1, $3 ); }
	|
	expr '-' expr			{ $$= opr( '-', 2, $1, $3 ); }
	|
	expr '*' expr			{ $$= opr( '*', 2, $1, $3 ); }
	|
	expr '^' expr			{ $$= opr( '^', 2, $1, $3 ); }
	|
	expr '/' expr			{ $$= opr( '/', 2, $1, $3 ); }
	|
	expr '<' expr			{ $$= opr( '<', 2, $1, $3 ); }
	|
	expr '>' expr			{ $$= opr( '>', 2, $1, $3 ); }
	|
	expr GE expr			{ $$= opr( GE, 2, $1, $3 ); }
	|
	expr LE expr			{ $$= opr( LE, 2, $1, $3 ); }
	|
	expr NE expr			{ $$= opr( NE, 2, $1, $3 ); }
	|
	expr EQ expr			{ $$= opr( EQ, 2, $1, $3 ); }
	|
	'(' expr ')'			{ $$= $2; }
	;

%%

#define SZND ( (char*)&((nodeType*)0)->value - (char*)0 )

nodeType	*con( int value ) {
	nodeType	*p;
	size_t		nodeSize;

nodeSize= SZND + sizeof( conNodeType );

if( !( p= malloc( nodeSize ) ) )
	yyerror( "out of memory" );

p->type= typeCon;
p->value.con.value= value;


return p;
}


nodeType	*id( int value ) {
	nodeType	*p;
	size_t		nodeSize;

nodeSize= SZND + sizeof( idNodeType );

if( !( p= malloc( nodeSize ) ) )
	yyerror( "out of memory" );

p->type= typeId;
p->value.id.i= value;


return p;
}
	

nodeType	*opr( int oper, int nops, ... ) {
	va_list		ap;
	nodeType	*p;
	size_t		nodeSize;
	int		i;

nodeSize= SZND + sizeof( oprNodeType ) + (nops-1)*sizeof( nodeType* );

if( !( p= malloc( nodeSize ) ) )
	yyerror( "out of memory" );

p->type= typeOpr;
p->value.opr.oper= oper;
p->value.opr.nops= nops;

va_start( ap, nops );

for( i=0; i<nops; ++i ) 
	p->value.opr.op[i]= va_arg( ap, nodeType* );
	
va_end( ap );	


return p;
}

void	freeNode( nodeType *p ) {
	int	i;

	if( !p ) 
		return;

	if( p->type == typeOpr ) 
		for( i=0; i<p->value.opr.nops; ++i )
			freeNode( p->value.opr.op[i] );

	free( p );
}

int	yyerror( char *s ) {
	fprintf( stderr, "error: \"%s\"\n", s );

	return 0;
}

main() {
	yyparse();

	return 0;
}

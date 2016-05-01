%{
#include <stdlib.h>
#include "includes.h"
#include "y.tab.h"
%}

%%

[a-z]			{
				yylval.sIndex= yytext[0] - 'a';

				return VARIABLE;
			}

[0-9]+			{
				yylval.iValue= atoi( yytext );

				return INTEGER;
			}

[!~-()<>=+*^/;{}.%&?:\[\]]	{
				return yytext[0];
				}


">="			{ return GE; }
"<="			{ return LE; }
"=="			{ return EQ; }
"!="			{ return NE; }
"+="			{ return PLUSEQ; }
"-="			{ return MINUSEQ; }
"*="			{ return MULTIPLYEQ; }
"/="			{ return DIVEQ; }
"%="			{ return PERCENTEQ; }
"&="			{ return AMPEQ; }
"^="			{ return POWEQ; }
"|="			{ return DASHEQ; }
"<<="			{ return SHIFTLEFTEQ; }
">>="			{ return SHIFTRIGHTEQ; }
">>>="			{ return UNSIGNSHIFTRIGHTEQ; }
"++"			{ return PLUSPLUS; }
"--"			{ return MINUSMINUS; }
">>"			{ return SHIFTRIGHT; }
"<<"			{ return SHIFTLEFT; }
">>>"			{ return UNSIGNEDSHIFTRIGHT; }
"&&"			{ return LOGICAND; }
"||"			{ return LOGICOR; }

"/*"			{ return COMMENTSTART; }
"*/"			{ return COMMENTSTOP; }
"//"			{ return INLINECOMMENT; }

"true"			{ return TRUE; }
"false"			{ return FALSE; }
"null"			{ return NILL; }

"bstract"		{ return BSTRACT; }
"continue"		{ return CONTINUE; }
"for"			{ return FOR; }
"new"			{ return NEW; }
"switch"		{ return SWITCH; }
"assert" 		{ return ASSERT; }
"default"		{ return DEFAULT; }
"goto"			{ return GOTO; }
"package"		{ return PACKAGE; }
"synchronized"		{ return SYNCH;}
"boolean"		{ return BOOL; }
"do"			{ return DO; }
"if"			{ return IF; }
"private"		{ return PRIVATE; }
"this"			{ return THIS; }
"break" 		{ return BREAK; }
"double" 		{ return DOUBLE; }
"implements" 		{ return IMPLEMENTS; }
"protected"		{ return PROTECTED; }
"throw"			{ return THROW; }
"byte"			{ return BYTE; }
"else"			{ return ELSE; }
"import"		{ return IMPORT; }
"public"		{ return PUBLIC; }
"throws"		{ return THROWS; }
"case"			{ return CASE; }
"enum"			{ return ENUM; }
"instanceof"		{ return INSTNACEOF; }
"return"		{ return RETURN; }
"transient"		{ return TRANSIENT; }
"catch"			{ return CATCH; }
"extends" 		{ return EXTENDS; }
"int"			{ return INT; }
"short" 		{ return SHORT; }
"try"			{ return TRY; }
"char"			{ return CHAR; }
"final"			{ return FINAL; }
"interface" 		{ return INTERFACE; }
"static" 		{ return STATIC; }
"void"			{ return VOID; }
"class"			{ return CLASS; }
"finally" 		{ return FINALLY; }
"long"			{ return LONG; }
"strictfp" 		{ return STRICTFP; }
"volatile"		{ return VOLATILE; }
"const" 		{ return CONST; }
"float"			{ return FLOAT; }
"native"		{ return NATIVE; }
"super"			{ return SUPER; }
"while"			{ return WHILE; }


[ \t\n]			{ ; }
.			{ yyerror( "bledny znak" ); }

%%

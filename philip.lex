%{
typedef char* string;
#define YYSTYPE string
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
//extern char* yylval;
%}

digit  [0-9]
nonzero [1-9]
octal [0-7]
hexa [0-9a-f]

deci_const {nonzero}{digit}*
octal_const 0{octal}*
hexa_const 0[xX]{hexa}+

int_const {deci_const}|{octal_const}|{hexa_const}

char [A-Za-z_]
id   [A-Za-z_][A-Za-z_0-9]*

%%

"if" {return IF;}

"else" {return ELSE;}

"while" {return WHILE;}

"continue" {return CONTINUE;}

"break" {return BREAK;}

"var" {printf("LEX : var\n");return VAR;}

"const" {printf("LEX : const\n");return CONST;}

"int" {printf("LEX : int\n");return INT;}

"void" {return VOID; }

"return" {return RETURN;}

"<=" {return LREQ;}

">=" {return GREQ;}

"==" {return EQEQ;}

"!=" {return NOEQ;}

"&&" {return ANDAND;}

"||" {return OROR;}

"=" { printf("LEX : eq\n"); return EQ; }
"(" { printf("LEX : (\n"); return BRA; }
")" { printf("LEX : )\n"); return KET; }
"[" { printf("LEX : [\n"); return BRAA; }
"]" { printf("LEX : ]\n"); return KETT; }
"{" { printf("LEX : {\n"); return BRAAA; }
"}" { printf("LEX : }\n"); return KETTT; }
"+" { printf("LEX : +\n"); return ADD;}
"-" { printf("LEX : -\n"); return SUB;}
"*" { printf("LEX : *\n"); return MUL;}
"/" { printf("LEX : /\n"); return DIV;}
"%" { printf("LEX : MOD\n"); return MOD;}
"!" { printf("LEX : !\n"); return NO;}
"," { printf("LEX : ,\n"); return COMMA;}
";" { printf("LEX : ;\n"); return SEMI;}
">" { printf("LEX : >\n"); return GR;}
"<" { printf("LEX : <\n"); return LR;}
{id} { printf("LEX : id\n");
	yylval = strdup(yytext); return IDENT;
	}
{nonzero} { printf("LEX : int_const\n"); 
	yylval = strdup(yytext); return INT_CONST;
	 }

%%

//int main(){ yylex(); return 0; }

int yywrap(){ return 1;  }

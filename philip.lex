%{
#include "philip.hpp"
#define YYSTYPE treeNode *
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
//extern char* yylval;
int lexdbg = 0;
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

"if" { if(lexdbg) printf("LEX : if\n"); return IF;}
"else" { if(lexdbg) printf("LEX : else\n"); return ELSE;}
"while" { if(lexdbg) printf("LEX : while\n"); return WHILE;}
"continue" { if(lexdbg) printf("LEX : continue\n"); return CONTINUE;}
"break" { if(lexdbg) printf("LEX : break\n"); return BREAK;}
"const" { if(lexdbg) printf("LEX : const\n");return CONST;}
"int" { if(lexdbg) printf("LEX : int\n");return INT;}
"void" { if(lexdbg) printf("LEX : void\n"); return VOID; }
"return" { if(lexdbg) printf("LEX : return\n"); return RETURN;}
"<=" { if(lexdbg) printf("LEX : <=\n"); return LREQ;}
">=" { if(lexdbg) printf("LEX : >=\n"); return GREQ;}
"==" { if(lexdbg) printf("LEX : ==\n"); return EQEQ;}
"!=" { if(lexdbg) printf("LEX : !=\n"); return NOEQ;}
"&&" { if(lexdbg) printf("LEX : &&\n"); return ANDAND;}
"||" { if(lexdbg) printf("LEX : ||\n"); return OROR;}
"="  { if(lexdbg) printf("LEX : eq\n"); return EQ; }
"("  { if(lexdbg) printf("LEX : (\n"); return BRA; }
")"  { if(lexdbg) printf("LEX : )\n"); return KET; }
"["  { if(lexdbg) printf("LEX : [\n"); return BRAA; }
"]"  { if(lexdbg) printf("LEX : ]\n"); return KETT; }
"{"  { if(lexdbg) printf("LEX : {\n"); return BRAAA; }
"}"  { if(lexdbg) printf("LEX : }\n"); return KETTT; }
"+"  { if(lexdbg) printf("LEX : +\n"); return ADD;}
"-"  { if(lexdbg) printf("LEX : -\n"); return SUB;}
"*"  { if(lexdbg) printf("LEX : *\n"); return MUL;}
"/"  { if(lexdbg) printf("LEX : /\n"); return DIV;}
"%"  { if(lexdbg) printf("LEX : MOD\n"); return MOD;}
"!"  { if(lexdbg) printf("LEX : !\n"); return NO;}
","  { if(lexdbg) printf("LEX : ,\n"); return COMMA;}
";"  { if(lexdbg) printf("LEX : ;\n"); return SEMI;}
">"  { if(lexdbg) printf("LEX : >\n"); return GR;}
"<"  { if(lexdbg) printf("LEX : <\n"); return LR;}
{id} { if(lexdbg) printf("LEX : id\n");
	yylval = new treeNode(Object);
	yylval->attr.n = strdup(yytext);
		//store the name first and use the symtabid later(not now)
	return IDENT; 
	}
{int_const} { if(lexdbg) printf("LEX : int_const\n");
	yylval = new treeNode(Expression);
	yylval->op = EMPTY_;
	int v = 0;
	if(yytext[0] == '0'){
		if(yytext[1] == 'x') sscanf(yytext, "%x", &v);
		else sscanf(yytext, "%o", &v);
	}
	else sscanf(yytext, "%d", &v);
	yylval->val = v; //put the value in yylval->val decimal;
	
	return INT_CONST;
	}

%%
//int main(){ yylex(); return 0; }
int yywrap(){ return 1;  }

%{
#include <stdio.h>
typedef char* string;
#define YYSTYPE string
#define YYSTYPE_IS_DECLARED
extern int yylex(void);
extern int yyparse(void);
FILE *fp = NULL;
%}
%token INT_CONST IDENT IF ELSE WHILE CONTINUE BREAK CONST VAR INT VOID RETURN LREQ GREQ EQEQ NOEQ ANDAND OROR EQ
%token BRA KET BRAA KETT BRAAA KETTT COMMA SEMI
%token ADD SUB MUL DIV MOD NO GR LR
%start CompUnits
%%
CompUnits     : CompUnit CompUnits | CompUnit;
CompUnit      : Decl | FuncDef | FuncDeff;

Decl          : ConstDecl | VarDecl;
ConstDecl     : CONST BType ConstDefs SEMI;
BType         : INT;
ConstDefs     : ConstDef | ConstDef COMMA ConstDefs;
ConstDef      : IDENT ConstExpAs EQ ConstInitVal | IDENT EQ ConstInitVal;
ConstInitVals : ConstInitVal | ConstInitVal COMMA ConstInitVals;
ConstInitVal  : ConstExp | BRAAA ConstInitVals KETTT | BRAAA KETTT;
VarDecl       : BType VarDefs SEMI;
VarDefs       : VarDef | VarDef COMMA VarDefs;
VarDef        : IDENT ConstExpAs EQ InitVal | IDENT EQ InitVal
              | IDENT ConstExpAs | IDENT;
InitVals      : InitVal | InitVal COMMA InitVals;
InitVal       : Exp | BRAAA InitVals KETTT | BRAAA KETTT;

FuncDef       : FuncType IDENT BRA KET Block;
FuncDeff      : FuncType IDENT BRA FuncFParams KET Block;
FuncType      : VOID | INT; //rules useless due to conflict
FuncFParams   : FuncFParam | FuncFParam COMMA FuncFParams;
FuncFParam    : BType IDENT | BType IDENT BRAA KETT ConstExpAs
              | BType IDENT BRAA KETT;

Block         : BRAAA BlockItems KETTT | BRAAA KETTT;
BlockItems    : BlockItem BlockItems | BlockItem;
BlockItem     : Decl | Stmt;
Stmt          : LVal EQ Exp SEMI
                | Exp SEMI
                | SEMI // [Exp] ';'
                | Block
                | IF BRA Cond KET Stmt ELSE Stmt
                | IF BRA Cond KET Stmt
                | WHILE BRA Cond KET Stmt
                | BREAK SEMI
                | CONTINUE SEMI
                | RETURN SEMI
                | RETURN Exp SEMI;

ExpAs         : ExpA | ExpA ExpAs;
ExpA          : BRAA Exp KETT;
Exp           : AddExp;
Cond          : LOrExp;
LVal          : IDENT ExpAs | IDENT;
PrimaryExp    : BRA Exp KET | LVal | Number;
Number        : INT_CONST;
UnaryExp      : PrimaryExp | IDENT BRA FuncRParams KET 
              | IDENT BRA KET | UnaryOp PrimaryExp;
UnaryOp       : ADD | SUB | NO;
FuncRParams   : Exp | Exp COMMA FuncRParams;
MulExp        : UnaryExp | UnaryExp MUL MulExp | UnaryExp DIV MulExp | UnaryExp MOD MulExp;
AddExp        : MulExp | MulExp ADD AddExp | MulExp SUB AddExp;
RelExp        : AddExp | AddExp LR RelExp | AddExp GR RelExp 
              | AddExp LREQ RelExp | AddExp GREQ RelExp;
EqExp         : RelExp | RelExp EQEQ EqExp | RelExp NOEQ EqExp;
LAndExp       : EqExp | EqExp ANDAND LAndExp;
LOrExp        : LAndExp | LAndExp OROR LOrExp;
ConstExpAs    : ConstExpA | ConstExpA ConstExpAs;
ConstExpA     : BRAA ConstExp KETT;
ConstExp      : AddExp;

%%
int main()
{
  fp = fopen("./output.txt","w+"); fprintf(fp,"testing\n");
  yyparse();
  fclose(fp);
  return 0;
}

int yyerror(char *msg)
{
  printf("Error encountered: %s \n", msg);
}


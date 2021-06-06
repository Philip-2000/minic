%{
#include <stdio.h>
typedef char* string;
#define YYSTYPE string
#define YYSTYPE_IS_DECLARED
extern int yylex(void);
extern int yyparse(void);
FILE *fp = NULL;
%}
%token INT_CONST IDENT IF ELSE WHILE CONTINUE BREAK CONST INT VOID RETURN LREQ GREQ EQEQ NOEQ ANDAND OROR EQ
%token BRA KET BRAA KETT BRAAA KETTT COMMA SEMI
%token ADD SUB MUL DIV MOD NO GR LR
%start CompUnits
%%
CompUnits     : CompUnit CompUnitx;
CompUnitx     : Empty | CompUnit CompUnitx;
CompUnit      : Decl | FuncDef;

Decl          : ConstDecl | VarDecl;
ConstDecl     : CONST BType ConstDefs SEMI;
BType         : INT;
ConstDefs     : ConstDef ConstDefx;
ConstDefx     : Empty | COMMA ConstDef ConstDefx;
ConstDef      : IDENT ConstExpAx EQ ConstInitVal;
ConstInitValss: ConstInitVals | Empty;
ConstInitVals : ConstInitVal ConstInitValx;
ConstInitValx : Empty | COMMA ConstInitVal ConstInitValx;
ConstInitVal  : ConstExp | BRAAA ConstInitValss KETTT;
VarDecl       : BType {printf("testing\n");} VarDefs SEMI;
VarDefs       : VarDef VarDefx;
VarDefx       : Empty | COMMA VarDef VarDefx;
VarDef        : IDENT ConstExpAx VarDe;
VarDe         : Empty | EQ InitVal;
InitValss     : InitVals | Empty;
InitVals      : InitVal InitValx;
InitValx      : Empty | COMMA InitVal InitValx;
InitVal       : Exp | BRAAA InitValss KETTT;

FuncDef       : VOID IDENT BRA FuncFParamss KET Block | INT IDENT BRA FuncFParamss KET Block ;
//FuncType      : VOID | INT;
FuncFParamss  : FuncFParams | Empty ;
FuncFParams   : FuncFParam FuncFParamx;
FuncFParamx   : Empty | COMMA FuncFParam FuncFParamx;
FuncFParam    : BType IDENT FuncFP;
FuncFP        : BRAA KETT ConstExpAx | Empty;

Block         : BRAAA BlockItemx KETTT;
//BlockItems    : BlockItem BlockItemx;
BlockItemx    : Empty | BlockItem BlockItemx;
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

//ExpAss        : ExpAs | Empty;
//ExpAs         : ExpA | ExpA ExpAs;
ExpAx         : Empty | ExpA ExpAx;
ExpA          : BRAA Exp KETT;
Exp           : AddExp;
Cond          : LOrExp;
LVal          : IDENT ExpAx;
PrimaryExp    : BRA Exp KET | LVal | Number;
Number        : INT_CONST;
UnaryExp      : PrimaryExp | IDENT BRA FuncRParamss KET | UnaryOp PrimaryExp;
UnaryOp       : ADD | SUB | NO;
FuncRParamss  : FuncRParams | Empty;
FuncRParams   : Exp FuncRParamx;
FuncRParamx   : Empty | COMMA Exp FuncRParamx;
MulExp        : UnaryExp MulExpp;
MulExpp       : Empty | MUL MulExp | DIV MulExp | MOD MulExp;
AddExp        : MulExp AddExpp;
AddExpp       : Empty | ADD AddExp | SUB AddExp;
RelExp        : AddExp RelExpp;
RelExpp       : Empty | LR RelExp | GR RelExp | LREQ RelExp | GREQ RelExp;
EqExp         : RelExp EqExpp;
EqExpp        : Empty | EQEQ EqExp | NOEQ EqExp;
LAndExp       : EqExp LAndExpp;
LAndExpp      : Empty | ANDAND LAndExpp;
LOrExp        : LAndExp LOrExpp;
LOrExpp       : Empty | OROR LOrExp;
//ConstExpAss   : ConstExpAs | Empty;
//ConstExpAs    : ConstExpA ConstExpAx;
ConstExpAx    : Empty | ConstExpA ConstExpAx;
ConstExpA     : BRAA ConstExp KETT;
ConstExp      : AddExp;
Empty         : ;

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


%{
#include <iostream>
#include "philip.hpp"
#include <string>
#include <stdlib.h>
using namespace std;
#define YYSTYPE treeNode*
#define YYSTYPE_IS_DECLARED 1
extern int yylex(void); 
extern int yyparse(treeNode*);
void yyerror(treeNode*, string);
void yyerror(string);
extern FILE *yyin;
extern FILE *yyout;
%}

%token INT_CONST IDENT IF ELSE WHILE CONTINUE BREAK CONST
%token INT VOID RETURN LREQ GREQ EQEQ NOEQ ANDAND OROR EQ
%token BRA KET BRAA KETT BRAAA KETTT COMMA SEMI
%token ADD SUB MUL DIV MOD NO GR LR

%start CompUnits
%parse-param{treeNode *root}
%%
CompUnits     : CompUnit CompUnits {
			$$ = new treeNode();
			$$->first = $1;
			$1->last = $2->first;

			root->first = $1;
		}
              | CompUnit {
              		$$ = new treeNode();
              		$$->first = $1;
              		$$->last = NULL;
			root->first = $1;
		};
CompUnit      : Decl {
			$$ = new treeNode(CompilUnit);
			$$->first = $1->first; delete $1;
		}
              | FuncDef{
			$$ = new treeNode(CompilUnit);
			$$->first = $1;
		};

Decl          : ConstDecl {
			$$ = new treeNode();
			$$->first = $1;
		}
              | VarDecl {
			$$ = new treeNode();
			$$->first = $1;
		};
ConstDecl     : CONST INT ConstDefs SEMI{
			$$ = new treeNode(Declarate);
			$$->is_const = 1;
			$$->first = $3;
		};
ConstDefs     : ConstDef COMMA ConstDefs{
			$$ = new treeNode(Definition);
			$$->first = $1; $$->last = $3;
		}
              | ConstDef {
              		$$ = new treeNode(Definition);
              		$$->first = $1; $$->last = NULL;
              	};
ConstDef      : IDENT ConstExpAs EQ ConstInitVal{
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = $2->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,1, !R , sszCnt, ssz);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
			
			//error if the size is wrong
			
			
						
			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->is_const = 1;
			$$->first = $2;  $$->last = $4;
		}
              | IDENT EQ ConstInitVal{
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,1,!R);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
			
              		//error if the size is wrong
              		if(($3->first)->Type != Expression ||
              			$3->last != NULL)
              			yyerror("vector on scaler");
              		
     			$$ = new treeNode(Define);
			$$->is_const = 1;
			$$->first = $1;  $$->last = $3;
              	};
ConstInitVals : ConstInitVal COMMA ConstInitVals{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1; delete $3;
		}
              | ConstInitVal{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
ConstInitVal  : ConstExp{
			$$ = new treeNode(Values);
			$$->first = $1;
		}
              | BRAAA ConstInitVals KETTT{
			$$ = new treeNode(Values);
			$$->first = $2->first; delete $2;
              	}
              | BRAAA KETTT{
			$$ = new treeNode(Values);
			$$->first = NULL;
              	};
VarDecl       : INT VarDefs SEMI{
			$$ = new treeNode(Declarate);
			$$->is_const = 0;
			$$->first = $2;
		};
VarDefs       : VarDef COMMA VarDefs{
			$$ = new treeNode(Definition);
			$$->first = $1; $$->last = $3;
		}
              | VarDef {
              		$$ = new treeNode(Definition);
              		$$->first = $1; $$->last = NULL;
              	};
VarDef        : IDENT ConstExpAs EQ InitVal{
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = $2->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R, sszCnt, ssz);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
			
			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = $4;
		}
              | IDENT EQ InitVal{
              		//define this IDENT
              			//first check if it is defined
              		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
              		//error if the size is wrong
              		if(($3->first)->Type != Expression ||
              			$3->last != NULL)
              			yyerror("vector on scaler");
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = $3;
		}
              | IDENT ConstExpAs{
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = $2->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R, sszCnt, ssz);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
              
 			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = NULL;
		}
              | IDENT{
              		//define this IDENT
              		//printf("FLAG!");
              			//first check if it is defined
              		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
			
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = NULL;
		};
InitVals      : InitVal COMMA InitVals{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1; delete $3;
		}
              | InitVal{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
InitVal       : Exp{
			$$ = new treeNode(Values);
			$$->first = $1;
		}
              | BRAAA InitVals KETTT{
			$$ = new treeNode(Values);
			$$->first = $2->first; delete $2;
              	}
              | BRAAA KETTT{
			$$ = new treeNode(Values);
			$$->first = NULL;
              	};
              	
FuncDef_pre   : VOID IDENT{
			//define IDENT
				//check if I'm at the root
			if(step_out() != 0)
				yyerror("Function Defined not at root");
				
				//check if name defined lookup(N,1,1)
	      		char *N = strdup($2->attr.n);
              		if(lookup(N,1,1) != -1) yyerror("Func re-defined");
				
				//define it and modify flags about r
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,voidFunc,0,!R);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
			++currentSymStack; SymStack[currentSymStack] = 0;
			
			$$ = new treeNode();
			$$->attr.idx = currentSym;
			delete $2;
		}
              | INT IDENT{
              		//define IDENT
				//check if I'm at the root
			if(step_out() != 0)
				yyerror("Function Defined not at root");
				
				//check if name defined lookup(N,1,1)
	      		char *N = strdup($2->attr.n);
              		if(lookup(N,1,1) != -1) yyerror("Func re-defined");
				
				//define it and modify flags about r
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,intFunc,0,!R);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
			++currentSymStack; SymStack[currentSymStack] = 0;
			
			$$ = new treeNode();
			$$->attr.idx = currentSym;
			delete $2;
              	};

FuncDef       : FuncDef_pre BRA KET Block {
			$$ = new treeNode(FuncDef);
			$$->first = NULL;
			$$->last = $4;
			$$->attr.idx = $1->attr.idx;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;

			delete $1;
		}
              | FuncDef_pre BRA FuncFParams KET {
              		//check how many parameters are there for me
              		int paraCnt = 0;
              		treeNode * pointer = $3->first;
              		while(pointer != NULL){
              			++paraCnt;
              			pointer = pointer->last;
              		}
              		SymTab[$1->attr.idx].szCnt = paraCnt;
              		
              	} Block {
			
              		$$ = new treeNode(FuncDef);
			$$->first = $3;
			$$->last = $6;
			$$->attr.idx = $1->attr.idx;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
			
			delete $1;
              	};
              	
FuncFParams   : FuncFParam COMMA FuncFParams{
			printf("FuncFParam FuncFParam Flag!\n");
			//$1->last = $3->first;
			$$ = new treeNode(Parameter);
			$$->first = $1;
			$$->last = $3;
		}
              | FuncFParam{
              		printf("FuncFParam Flag!\n");
              		$$ = new treeNode(Parameter);
              		$$->first = $1;
              		$$->last = NULL;
              	};
FuncFParam    : INT IDENT BRAA KETT ConstExpAs{
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup($2->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = $5->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R,sszCnt,ssz,1);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
			$$ = new treeNode(ParaDefine);
			$$->is_ptr = 1;
			$$->first = $5;
			$$->attr.idx = currentSym;
		}
              | INT IDENT BRAA KETT{
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup($2->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R,0,NULL,1);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
              		$$ = new treeNode(ParaDefine);
              		$$->is_ptr = 1;
              		$$->first = NULL;
              		$$->attr.idx = currentSym;
              	}
              | INT IDENT{
              		printf("INT IDENT\n");
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup($2->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
              		$$ = new treeNode(ParaDefine);
              		$$->is_ptr = 0;
              		$$->first = NULL;
              		$$->attr.idx = currentSym;
              	};

Block         : BRAAA { ++currentSymStack;  SymStack[currentSymStack] = 0;
		} BlockItems KETTT {
			$$ = new treeNode(StmtBlock);
			$$->first = $3->first;
			delete $3;

			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
		}
              | BRAAA { ++currentSymStack; SymStack[currentSymStack] = 0;
              	} KETTT {
              		$$ = new treeNode(StmtBlock);
              		$$->first = NULL; //same as above to avoid conflict
              		if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
              	};
BlockItems    : BlockItem BlockItems{
			$1->last = $2->first;
			$$ = new treeNode();
			$$->first = $1; delete $2;
		}
              | BlockItem{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->attr.idx = 1024;
              		$$->first = $1;
              	};
BlockItem     : Decl{
			$$ = new treeNode(BlockIt);
			$$->first = $1->first; delete $1;
		}
	      | Stmt{
	      		$$ = new treeNode(BlockIt);
	      		$$->first = $1;
	      	};
Stmt          : LVal EQ Exp SEMI{
			$$ = new treeNode(Assignment);
			$$->first = $1;
			$$->last = $3;
		}
              | Exp SEMI{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = EMPTY_;
              	}
              | SEMI{
              		$$ = new treeNode();
              		$$->first = NULL; $$->last = NULL;
              	} // [Exp] ';'
              | Block{
              		$$ = new treeNode(StmtBlock);
              		$$->first = $1->first; delete $1;
              	}
              | IF BRA Cond KET Stmt{
              		$$ = new treeNode(If);
              		$$->first = $3;
              		$$->last = $5;
              		$$->end_if = labelCnt++;
              		$$->begin_true = labelCnt++; 
              	}
              | IF BRA Cond KET Stmt ELSE Stmt{
              		$$ = new treeNode(If);
              		$$->first = $3;
              		$6 = new treeNode(Else);
              		$$->last = $6;
              		$6->first = $5;
              		$6->last = $7;
              		$$->end_if = labelCnt++;
              		$$->begin_true = labelCnt++;
              	}
              | WHILE BRA Cond KET Stmt{
              		$$ = new treeNode(Loop);
              		$$->first = $3;
              		$$->last = $5;
              		$$->end_loop = labelCnt++;
              		$$->begin_loop = labelCnt++;
		}
              | BREAK SEMI{
              		$$ = new treeNode(Branch);
              		$$->b_type = b_break;
              	}
              | CONTINUE SEMI{
              		$$ = new treeNode(Branch);
              		$$->b_type = b_contin;
              	}
              | RETURN SEMI{
              		$$ = new treeNode(Branch);
              		$$->b_type = b_return;
              	}
              | RETURN Exp SEMI{
              		$$ = new treeNode(Branch);
              		$$->b_type = b_return;
              		$$->last = $2;
              	};

ExpAs         : ExpA ExpAs{
			$1->last = $2->first;
			$$ = new treeNode();
			$$->first = $1; delete $2;
		}
              | ExpA{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
ExpA          : BRAA Exp KETT{
			$$ = new treeNode(Index);
			$$->first = $2;
		};
Exp           : AddExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
Cond          : LOrExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
              	};
LVal          : IDENT ExpAs{
              		$$ = new treeNode(Object);
              		char *N = strdup($1->attr.n);
              		int res = lookup(N);
              		if( res == -1 ) yyerror("no such id");
              		
              		int sszCnt = 0;
			treeNode *ptr = $2->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
              		if( SymTab[res].szCnt != sszCnt)
              			yyerror("dimension fault");
              		
              		$$->attr.idx = res;
              		$$->first = $2->first;
              		$$->is_const = 0;
              	}
              | IDENT{
              		$$ = new treeNode(Object);
              		char *N = strdup($1->attr.n);
              		int res = lookup(N);
              		if( res == -1 ) yyerror("no such id");
              		if( SymTab[res].szCnt != 0) yyerror("dim fault");
              		
              		$$->attr.idx = res;
              		$$->first = NULL;
              		$$->is_const = 0;
              	};
PrimaryExp    : BRA Exp KET{
			$$ = new treeNode(Expression);
			$$->first = $2;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $2->is_const;
		}
              | LVal{
              		$$ = new treeNode(Expression);
			$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	}
              | INT_CONST{
              		$$ = new treeNode(Expression);
			$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = 1;
              	};
UnaryExp      : PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
		}
              | IDENT BRA FuncRParams KET{
              		$$ = new treeNode(FuncCall);
              		char *N = strdup($1->attr.n);
              		int res = lookup(N,0,1);
              		if( res == -1 ) yyerror("no such function");
              		
              		int paraCnt = 0;
              		treeNode * pointer = $3->first;
              		while(pointer != NULL){
              			++paraCnt;
              			pointer = pointer->last;
              		}
              		if( SymTab[res].szCnt != paraCnt) 
              			yyerror("para fault");
              		
              		$$->first = $3;
			$$->is_const = 0;
			$$->attr.idx = res;
              	}
              | IDENT BRA KET{
              
              		$$ = new treeNode(FuncCall);
              		char *N = strdup($1->attr.n);
              		int res = lookup(N,0,1);
              		if( res == -1 ) yyerror("no such function");
              		if( SymTab[res].szCnt != 0) yyerror("para fault");
              		
              		$$->first = NULL;
              		$$->is_const = 0;
              		$$->attr.idx = res;
              	}
              | ADD PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->op = ADD_;
			$$->last = $2;
			$$->is_const = $2->is_const;
		}
              | SUB PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->op = SUB_;
			$$->last = $2;
			$$->is_const = $2->is_const;
		}
              | NO PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->op = NO_;
			$$->last = $2;
			$$->is_const = $2->is_const;
		};
FuncRParams   : Exp COMMA FuncRParams{
			$1->last = $3->first;
			$$ = new treeNode(Argument);
			$$->first = $1; delete $3;
		}
              | Exp{
              		$1->last = NULL;
              		$$ = new treeNode(Argument);
              		$$->first = $1;
              	};
MulExp        : UnaryExp MOD MulExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = MOD_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | UnaryExp MUL MulExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = MUL_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | UnaryExp DIV MulExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = DIV_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | UnaryExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
AddExp        : MulExp SUB AddExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = SUB_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | MulExp ADD AddExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = ADD_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | MulExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
RelExp        : AddExp GR RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = GR_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		} 
              | AddExp LR RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = LR_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | AddExp GREQ RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = GREQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		} 
              | AddExp LREQ RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = LREQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | AddExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
EqExp         : RelExp NOEQ EqExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = NOEQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | RelExp EQEQ EqExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = EQEQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | RelExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
LAndExp       : EqExp ANDAND LAndExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = ANDAN_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | EqExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
LOrExp        : LAndExp OROR LOrExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->op = OROR_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | LAndExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
ConstExpAs    : ConstExpA ConstExpAs{
			$1->last = $2->first;
			$$ = new treeNode();
			$$->first = $1; delete $2;
		}
              | ConstExpA{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
ConstExpA     : BRAA ConstExp KETT{
			$$ = new treeNode(Index);
			$$->first = $2;
			$$->is_const = 1;
		};
ConstExp      : AddExp{
			$$ = new treeNode(Expression);
			$$->first = $1;
			$$->op = EMPTY_;
			$$->last = NULL;
			$$->is_const = 1;
			if($1->is_const == 0)
				yyerror("variable in const place");
		};

%%

int main(){
  fp = fopen("./input.txt", "r" ); yyin = fp;
  fp = fopen("./output.txt","w+"); 
  if(yaccdbg) fp = stdout;
  
  treeNode root(CompilUnit);
  initSymTab();
  printf("yyparse start\n");
  yyparse(&root);
  printf("yyparse over\n");
  scanSymTab();
  dbgprt(root.first);
  if(mainIdx == -1) yyerror("main function undefined");
  yyout = stdout;
  generate(root.first);
  
  fclose(fp);
  return 0;
}

void yyerror(string msg){
  printf("Error encountered: ");
  cout << msg << endl; exit(-1);
}

void yyerror(treeNode *ptr, string msg){
  printf("Error encountered: ");
  cout << msg << endl; exit(-1);
}


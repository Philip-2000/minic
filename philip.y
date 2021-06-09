%{
#include <stdio.h>
#include "philip.hpp"
#define YYSTYPE treeNode *
#define YYSTYPE_IS_DECLARED
extern int yylex(void);
extern int yyparse(void);
FILE *fp = NULL;
int yaccdbg = 1;
%}
%token INT_CONST IDENT IF ELSE WHILE CONTINUE BREAK CONST
%token INT VOID RETURN LREQ GREQ EQEQ NOEQ ANDAND OROR EQ
%token BRA KET BRAA KETT BRAAA KETTT COMMA SEMI
%token ADD SUB MUL DIV MOD NO GR LR
%start CompUnits
%%
CompUnits     : CompUnit CompUnits {
			$1->last = $2->first;
			$$ = new treeNode();
			$$->first = $1; delete $2;
			root = $$; //?????will it work?
		}
              | CompUnit {
			$1->last = NULL;
			$$ = new treeNode();
			$$->first = $1;
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
ConstDecl     : CONST BType ConstDefs SEMI{
			$$ = new treeNode(Declarate);
			$$->is_const = 1;
			$$->first = $2;
		};
BType         : INT;
ConstDefs     : ConstDef COMMA ConstDefs{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1; delete $3;
		}
              | ConstDef{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
ConstDef      : IDENT ConstExpAs{
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
			
		} EQ ConstInitVal{
			//error if the size is wrong
			
			
						
			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->is_const = 1;
			$$->first = $2;  $$->last = $4;
		}
              | IDENT {
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,1,!R);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
			
              	} EQ ConstInitVal{
              		//error if the size is wrong
              		if($4->first->type != Expression ||
              			$4->last != NULL)
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
			$$->first = $2;
              	}
              | BRAAA KETTT{
			$$ = new treeNode(Values);
			$$->first = NULL;
              	};
VarDecl       : BType VarDefs SEMI{
			$$ = new treeNode(Declarate);
			$$->is_const = 0;
			$$->first = $2;
		};
VarDefs       : VarDef COMMA VarDefs{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1;
			delete $3;
		}
              | VarDef{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
VarDef        : IDENT ConstExpAs {
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
			
		}EQ InitVal{
			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = $4;
		}
              | IDENT {
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			$1->attr.idx = currentSym;
			
              	} EQ InitVal{
              		//error if the size is wrong
              		if($4->first->type != Expression ||
              			$4->last != NULL)
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
			$$->first = $2;
              	}
              | BRAAA KETTT{
			$$ = new treeNode(Values);
			$$->first = NULL;
              	};

FuncDef       : FuncType IDENT {
			//define IDENT
				//check if I'm at the root
			if(step_out() != 0)
				yyerror("Function Defined not at root");
				
				//check if name defined lookup(N,1,1)
	      		char *N = strdup($2->attr.n);
              		if(lookup(N,1,1) != -1) yyerror("Func re-defined");
				
				//define it and modify flags about r
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,1,0,!R);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
			++currentSymStack;
			
		} BRA KET Block {
			
			$$ = new treeNode(FuncDef);
			$$->first = NULL;
			$$->last = $5;
			$$->attr.idx = currentSym;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;

		}
              | FuncType IDENT {
			//define IDENT
				//check if I'm at the root
			if(step_out() != 0)
				yyerror("Function Defined not at root");
				
				//check if name defined lookup(N,1,1)
	      		char *N = strdup($2->attr.n);
              		if(lookup(N,1,1) != -1) yyerror("Func re-defined");
				
				//define it and modify flags about r
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,1,0,!R);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
			++currentSymStack;
			
              	} BRA FuncFParams KET {
              		//check how many parameters are there for me
              		int paraCnt = 0;
              		treeNode * pointer = $4->first;
              		while(pointer != NULL){
              			++paraCnt;
              			pointer = pointer->last;
              		}
              		SymTab.[$2->attr.idx].szCnt = paraCnt;
              		
              	} Block {
			
              		$$ = new treeNode(FuncDef);
			$$->first = $4->first; delete $4;
			$$->last = $6;
			$$->attr.idx = currentSym;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
              	};
FuncType      : VOID | INT; //rules useless due to conflict
FuncFParams   : FuncFParam COMMA FuncFParams{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1; delete $3;
		}
              | FuncFParam{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
FuncFParam    : BType IDENT BRAA KETT ConstExpAs{
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup($1->attr.n);
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
			SymTab[SymCnt].modify(N,0,0,!R0,sszCnt,ssz,1);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
			$$ = new treeNode(ParaDefine);
			$$->attr.is_ptr = 1;
			$$->first = $5;
			$$->attr.idx = currentSym;
		}
              | BType IDENT BRAA KETT{
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R,0,NULL,1);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
              		$$ = new treeNode(ParaDefine);
              		$$->attr.is_ptr = 1;
              		$$->first = NULL;
              		$$->attr.idx = currentSym;
              	}
              | BType IDENT{
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup($1->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			$2->attr.idx = currentSym;
			
              		$$ = new treeNode(ParaDefine);
              		$$->attr.is_ptr = 0;
              		$$->first = NULL;
              		$$->attr.idx = currentSym;
              	};

Block         : BRAAA { ++currentSymStack; } BlockItems KETTT{
			$$ = new treeNode();
			$$->first = $2->first;
			delete $2;
			
			
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
		}
              | BRAAA { ++currentSymStack; } KETTT{
              		$$ = new treeNode();
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
              		$$->first = $1;
              	};
BlockItem     : Decl{
			$$ = new treeNode();
			$$->first = $1->first; delete $1;
		}
	      | Stmt{
	      		$$ = new treeNode();
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
              		$$->attr.op = EMPTY_;
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
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
Cond          : LOrExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
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
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $2->is_const;
		}
              | LVal{
              		$$ = new treeNode(Expression);
			$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	}
              | INT_CONST{
              		$$ = new treeNode(Expression);
			$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = 1;
              	};
UnaryExp      : PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = $1;
			$$->attr.op = EMPTY_;
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
              	}
              | IDENT BRA KET{
              
              		$$ = new treeNode(FuncCall);
              		char *N = strdup($1->attr.n);
              		int res = lookup(N,0,1);
              		if( res == -1 ) yyerror("no such function");
              		if( SymTab[res].szCnt != 0) yyerror("para fault");
              		
              		$$->first = NULL;
              		$$->is_const = 0;
              	}
              | ADD PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->attr.op = ADD_;
			$$->last = $2;
			$$->is_const = $2->is_const;
		}
              | SUB PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->attr.op = SUB_;
			$$->last = $2;
			$$->is_const = $2->is_const;
		}
              |  NO PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->attr.op = NO_;
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
              		$$->attr.op = MOD_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | UnaryExp MUL MulExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = MUL_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | UnaryExp DIV MulExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = DIV_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | UnaryExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
AddExp        : MulExp SUB AddExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = SUB_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | MulExp ADD AddExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = ADD_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | MulExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
RelExp        : AddExp GR RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = GR_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		} 
              | AddExp LR RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = LR_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | AddExp GREQ RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = GREQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		} 
              | AddExp LREQ RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = LREQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | AddExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
EqExp         : RelExp NOEQ EqExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = NOEQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | RelExp EQEQ EqExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = EQEQ_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | RelExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL
			$$->is_const = $1->is_const;
              	};
LAndExp       : EqExp ANDAND LAndExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = ANDAN_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | EqExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
			$$->is_const = $1->is_const;
              	};
LOrExp        : LAndExp OROR LOrExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = OROR_;
              		$$->last = $3;
              		$$->is_const = $1->is_const && $3->is_const;
		}
              | LAndExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
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
			$$->attr.op = EMPTY_;
			$$->is_const = 1;
			if($1->is_const == 0)
				yyerror("variable in const place");
		};

%%



int main(){
  fp = fopen("./output.txt","w+"); fprintf(fp,"testing\n");
  treeNode *root = NULL;
  yyparse(&root);
  if(root == NULL) yyerror("yyparse error: didn't return a root");
  if(yaccdbg) dbgprt(root);
  generate(root);
  
  fclose(fp);
  return 0;
}

int yyerror(char *msg)
{
  printf("Error encountered: %s \n", msg);
}


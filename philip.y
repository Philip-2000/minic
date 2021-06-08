%{
#include <stdio.h>
#include "philip.hpp"
//typedef char* string;
#define YYSTYPE treeNode *
#define YYSTYPE_IS_DECLARED
extern int yylex(void);
extern int yyparse(void);
FILE *fp = NULL;
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
			$$->first = $1; deledte $2;
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
              		if(lookup(N,1) != -1) return -1;
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			
			treeNode *ptr = $1->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			SymTab[SymCnt].modify(N,0,1,/*?*/, sszCnt, ssz);
			
		} EQ ConstInitVal{			
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
              		if(lookup(N,1) != -1) return -1;
              		
              			//define it
			SymTab[SymCnt].modify(N,0,1,/*?*/);
              	} EQ ConstInitVal{
     			$$ = new treeNode(Define);
			$$->is_const = 1;
			$$->first = $1;  $$->last = $3;
              	};
ConstInitVals : ConstInitVal COMMA ConstInitVals{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1;
			delete $3;
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
VarDef        : IDENT ConstExpAs EQ InitVal{
			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = $4;
		}
              | IDENT EQ InitVal{
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = $3;
		}
              | IDENT ConstExpAs{
 			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = NULL;
		}
              | IDENT{
			$$ = new treeNode(Define);
			$$->is_const = 0;
			$$->first = $1;  $$->last = NULL;
		};
InitVals      : InitVal COMMA InitVals{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1;
			delete $3;
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

FuncDef       : FuncType IDENT BRA KET Block{
			$$ = new treeNode(FuncDef);
			$$->first = NULL;
			$$->last = $5;
			
		}
              | FuncType IDENT BRA FuncFParams KET Block{
              		$$ = new treeNode(FuncDef);
			$$->first = $4;
			$$->last = $6;
			if( $6->is_ret == notRetu ){
				yyerror("function didn't return");
			}else if( /*???*/ && $6->is_ret == Retu){
				yyerror("function return nothing");
			}else if( /*???*/ && $6->is_ret == RetuExp){
				yyerror("function return something");
			}
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
			$$ = new treeNode(ParaDefine);
			$$->attr.is_ptr = 1;
			$$->first = $5;
		}
              | BType IDENT BRAA KETT{
              		$$ = new treeNode(ParaDefine);
              		$$->attr.is_ptr = 1;
              		$$->first = NULL;
              	}
              | BType IDENT{
              		$$ = new treeNode(ParaDefine);
              		$$->attr.is_ptr = 0;
              		$$->first = NULL;
              	};

Block         : BRAAA BlockItems KETTT{
			$$ = new treeNode();
			$$->first = $2->first;
			delete $2;
		}
              | BRAAA KETTT{
              		$$ = new treeNode();
              		$$->first = NULL;
              	};
BlockItems    : BlockItem BlockItems{
			$1->last = $2->first;
			
			if($1->is_ret != $2->is_ret){
              			yyerror("return situation is different");
              		}
			$$ = new treeNode();
			$$->first = $1; delete $2;
		}
              | BlockItem{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              		$$->is_ret = $1->is_ret;
              	};
BlockItem     : Decl{
			$$ = new treeNode();
			$$->first = $1->first; delete $1;
			$$->is_ret = notRetu;
		}
	      | Stmt{
	      		$$ = new treeNode();
	      		$$->first = $1;
	      		$$->is_ret = $1->is_ret;
	      	};
Stmt          : LVal EQ Exp SEMI{
			$$ = new treeNode(Assignment);
			$$->first = $1;
			$$->last = $3;
			$$->is_ret = notRetu;
		}
              | Exp SEMI{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = EMPTY_;
              		$$->is_ret = notRetu;
              	}
              | SEMI{
              		$$ = new treeNode();
              		$$->first = NULL; $$->last = NULL;
              		$$->is_ret = notRetu;
              	} // [Exp] ';'
              | Block{
              		$$ = new treeNode(StmtBlock);
              		$$->is_ret = $1->first->is_ret;
              		$$->first = $1->first; delete $1;
              	}
              | IF BRA Cond KET Stmt{
              		$$ = new treeNode(If);
              		$$->first = $3;
              		$$->last = $5;
              		$$->is_ret = $5->is_ret;
              	}
              | IF BRA Cond KET Stmt ELSE Stmt{
              		$$ = new treeNode(If);
              		$$->first = $3;
              		$6 = new treeNode(Else);
              		$$->last = $6;
              		$6->first = $5;
              		$6->last = $7;
              		
              		if($5->is_ret != $7->is_ret){
              			yyerror("return situation is different");
              		}
              	}
              | WHILE BRA Cond KET Stmt{
              		$$ = new treeNode(Loop);
              		$$->first = $3;
              		$$->last = $5;
              		$$->is_ret = $5->is_ret;
		}
              | BREAK SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
              		$$->is_ret = notRetu;
              	}
              | CONTINUE SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
              		$$->is_ret = notRetu;
              	}
              | RETURN SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
              		$$->is_ret = Retu;
              	}
              | RETURN Exp SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
              		$$->is_ret = RetuExp;
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
              		$$->first = $2;
              		$$->is_const = 0;
              	}
              | IDENT{
              		$$ = new treeNode(Object);
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
              		$$->first = $3;
			$$->is_const = 0;
              	}
              | IDENT BRA KET{
              		$$ = new treeNode(FuncCall);
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
			$$ = new treeNode();
			$$->first = $1; delete $3;
		}
              | Exp{
              		$1->last = NULL;
              		$$ = new treeNode();
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


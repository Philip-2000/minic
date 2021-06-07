%{
#include <stdio.h>
#include <philip.hpp>
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
			$$->first = $1;
			delete $2;
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
			$$->attr.is_const = 1;
			$$->first = $2;
		};
BType         : INT;
ConstDefs     : ConstDef COMMA ConstDefs{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1;
			delete $3;
		}
              | ConstDef{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
ConstDef      : IDENT ConstExpAs EQ ConstInitVal{ //hang IDENT under CEAs
			$$ = new treeNode(Define);
			$$->attr.is_const = 1;
			$$->first = $2;  $$->last = $4;
		}
              | IDENT EQ ConstInitVal{
     			$$ = new treeNode(Define);
			$$->attr.is_const = 1;
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
ConstInitVal  : ConstExp
              | BRAAA ConstInitVals KETTT
              | BRAAA KETTT;
VarDecl       : BType VarDefs SEMI{
			$$ = new treeNode(Declarate);
			$$->attr.is_const = 0;
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
			$$->attr.is_const = 0;
			$$->first = $1;  $$->last = $4;
		}
              | IDENT EQ InitVal{
			$$ = new treeNode(Define);
			$$->attr.is_const = 0;
			$$->first = $1;  $$->last = $3;
		}
              | IDENT ConstExpAs{
 			//hang CEAs under IDENT as obj
			$1->first = $2->first; //index linked table head
			delete $2;
			
			$$ = new treeNode(Define);
			$$->attr.is_const = 0;
			$$->first = $1;  $$->last = NULL;
		}
              | IDENT{
			$$ = new treeNode(Define);
			$$->attr.is_const = 0;
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
			//?????
		}
              | BRAAA InitVals KETTT{
              		//?????
              	}
              | BRAAA KETTT;

FuncDef       : FuncType IDENT BRA KET Block{
			$$ = new treeNode(FuncDef);
			$$->first = NULL;
			$$->last = $5;
		}
              | FuncType IDENT BRA FuncFParams KET Block{
              		$$ = new treeNode(FuncDef);
			$$->first = $4;
			$$->last = $6;
              	};
FuncType      : VOID | INT; //rules useless due to conflict
FuncFParams   : FuncFParam COMMA FuncFParams{
			$1->last = $3->first;
			$$ = new treeNode();
			$$->first = $1;
			delete $3;
		}
              | FuncFParam{
              		$1->last = NULL;
              		$$ = new treeNode();
              		$$->first = $1;
              	};
FuncFParam    : BType IDENT
              | BType IDENT BRAA KETT ConstExpAs
              | BType IDENT BRAA KETT; //bugs here! what is parameter def

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
              	}
              | IF BRA Cond KET Stmt ELSE Stmt{
              		$$ = new treeNode(If);
              		$$->first = $3;
              		$6 = new treeNode(Else);
              		$$->last = $6;
              		$6->first = $5;
              		$6->last = $7;
              	}
              | WHILE BRA Cond KET Stmt{
              		$$ = new treeNode(Loop);
              		$$->first = $3;
              		$$->last = $5;
		}
              | BREAK SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
              	}
              | CONTINUE SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
              	}
              | RETURN SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
              	}
              | RETURN Exp SEMI{
              		$$ = new treeNode(Branch);
              		//unfinished
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
              	}
              | IDENT{
              		$$ = new treeNode(Object);
              		$$->first = NULL;
              	};
PrimaryExp    : BRA Exp KET{
			$$ = new treeNode(Expression);
			$$->first = $2;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
		}
              | LVal{
              		$$ = new treeNode(Expression);
			$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
              	}
              | INT_CONST{
              		$$ = new treeNode(Expression);
			$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
              	};
UnaryExp      : PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
		}
              | IDENT BRA FuncRParams KET{
              		$$ = new treeNode(FuncCall);
              		$$->first = $3;
              	}
              | IDENT BRA KET{
              		$$ = new treeNode(FuncCall);
              		$$->first = NULL;
              	}
              | ADD PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->attr.op = ADD_;
			$$->last = $2;
		}
              | SUB PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->attr.op = SUB_;
			$$->last = $2;
		}
              |  NO PrimaryExp{
			$$ = new treeNode(Expression);
			$$->first = NULL;
			$$->attr.op = NO_;
			$$->last = $2;
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
		}
              | UnaryExp MUL MulExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = MUL_;
              		$$->last = $3;
		}
              | UnaryExp DIV MulExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = DIV_;
              		$$->last = $3;
		}
              | UnaryExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
              	};
AddExp        : MulExp SUB AddExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = SUB_;
              		$$->last = $3;
		}
              | MulExp ADD AddExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = ADD_;
              		$$->last = $3;
		}
              | MulExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
              	};
RelExp        : AddExp GR RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = GR_;
              		$$->last = $3;
		} 
              | AddExp LR RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = LR_;
              		$$->last = $3;
		}
              | AddExp GREQ RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = GREQ_;
              		$$->last = $3;
		} 
              | AddExp LREQ RelExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = LREQ_;
              		$$->last = $3;
		}
              | AddExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
              	};
EqExp         : RelExp NOEQ EqExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = NOEQ_;
              		$$->last = $3;
		}
              | RelExp EQEQ EqExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = EQEQ_;
              		$$->last = $3;
		}
              | RelExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
              	};
LAndExp       : EqExp ANDAND LAndExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = ANDAN_;
              		$$->last = $3;
		}
              | EqExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
              	};
LOrExp        : LAndExp OROR LOrExp{
			$$ = new treeNode(Expression);
              		$$->first = $1;
              		$$->attr.op = OROR_;
              		$$->last = $3;
		}
              | LAndExp{
              		$$ = new treeNode(Expression);
              		$$->first = $1;
			$$->attr.op = EMPTY_;
			$$->last = NULL;
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
		};
ConstExp      : AddExp{
			$$ = new treeNode(Expression);
			$$->first = $1;
			$$->attr.op = EMPTY_;
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


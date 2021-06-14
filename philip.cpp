#include "philip.hpp"

FILE* fp = NULL;

int yaccdbg = 1;

int labelCnt;
int loop_begin, lb_valid = 0;
int loop_end, le_valid = 0;
int currentFuncType, cft_valid = 0; //for func type examination
int currentFuncIdx = -1, currentBlockIdx = -1; //for func var define

char *Names[MAXSYMBOL];
int SymCnt = 0;
int currentSym = 0;
int *currentSz = NULL;

int SymStack[MAXSTACK] = {0};
int currentSymStack = 0;
int mainIdx = -1;
SymTabEntry SymTab[MAXSYMBOL];

bool TempSym[32] = {0};
int maxTmpSym = -1;
int getTmpSym(){
	int ret = 0;
	while(TempSym[ret] || ret < 32) ++ret;
	if(ret == 32) return -1;
	TempSym[ret] = 1; if(ret > maxTmpSym) maxTmpSym = ret;
	return ret;
}

void STEdbgprt(SymTabEntry *ptr){
	if(ptr->real == 1) printf("   ");
	printf("%d %s prefix:%d",ptr->idx, Names[ptr->idx],ptr->prefix);
	if(ptr->is_func > 0) printf(" is function");
	if(ptr->is_const == 1) printf(" is const");
	if(ptr->is_ptr == 1) printf(" is pointer");
	if(ptr->szCnt > 0) printf(" is array with dim %d", ptr->szCnt);
	printf("\n");
}

void initSymTab(){
	labelCnt = 0;
	
	SymTab[0].idx = 0;
	SymTab[0].prefix = -1;
	SymTab[0].real = 1;
	
	SymCnt = 1;
	currentSym = 0;
	currentSymStack = 1;
	
	//add lib function in
	SymTab[SymCnt].modify("getint",intFunc,0,1); SymStack[1] = 1;
	SymTab[SymCnt].modify("getch",intFunc);
	
	SymTab[SymCnt].modify("getarray",intFunc);
	SymTab[SymCnt].modify("arr",0,0,1,0,NULL,1);
	currentSym = 3; SymTab[3].szCnt = 1;
	
	SymTab[SymCnt].modify("putint",voidFunc);
	SymTab[SymCnt].modify("n",0,0,1);
	currentSym = 5; SymTab[5].szCnt = 1;
	
	SymTab[SymCnt].modify("putch",voidFunc);
	SymTab[SymCnt].modify("n",0,0,1);
	currentSym = 7; SymTab[7].szCnt = 1;
	
	SymTab[SymCnt].modify("putarray",voidFunc);
	SymTab[SymCnt].modify("n",0,0,1);
	SymTab[SymCnt].modify("arr",0,0,0,0,NULL,1);
	currentSym = 9; SymTab[9].szCnt = 2;
	SymTab[SymCnt].modify("starttime",voidFunc);
	SymTab[SymCnt].modify("stoptime",voidFunc);
	
	for(int i = 0; i < SymCnt; ++i) STEdbgprt(SymTab+i);
}

void scanSymTab(){
	int lastFunc = 0, inFunc = 0;
	for(int i = 14; i < SymCnt; ++i){
		if(inFunc){
			if(SymTab[i].prefix == lastFunc
			&& SymTab[i].real == 0){
				SymTab[lastFunc].is_const =
					i-1-lastFunc-SymTab[lastFunc].szCnt;
				if(SymTab[i].is_func) lastFunc = i;
				else inFunc = 0;
			}
		}
		else{
			if(SymTab[i].is_func > 0){
				inFunc = 1;
				lastFunc = i;
			}
		}
	}
	if(inFunc)
	SymTab[lastFunc].is_const=SymCnt-1-lastFunc-SymTab[lastFunc].szCnt;
}

int step_out(){
	int P = currentSym;
	while(SymTab[P].real == 0) P = SymTab[P].prefix;
	return SymTab[P].prefix;
}

int lookup(const char *n, int limited, int func){
	int P = currentSym;
	if(P == 0) return -1;
	if(limited){
		while(SymTab[P].real == 0){
			if(strcmp(Names[P], n) == 0 && 
			SymTab[P].is_func == func) return P;
			P = SymTab[P].prefix;
		}
	}
	else{
		while(P > 0){
			if(strcmp(Names[P], n) == 0 && 
			SymTab[P].is_func >= func) return P;
			P = SymTab[P].prefix;
		}
	}
	return -1;
}

void opTable(int op){
	switch(op){
		case LREQ_:	printf("<="); return;
		case LR_:	printf("<"); return;
		case GREQ_:	printf(">="); return;
		case GR_:	printf(">"); return;
		case EQEQ_:	printf("=="); return;
		case NOEQ_:	printf("!="); return;
		case ANDAN_:	printf("&&"); return;
		case OROR_:	printf("||"); return;
		case NO_:	printf("!"); return;
		case EQ_:	printf("="); return;
		case ADD_:	printf("+"); return;
		case SUB_:	printf("-"); return;
		case MUL_:	printf("*"); return;
		case DIV_:	printf("/"); return;
		case MOD_:	printf("mod"); return;
		default:	printf("undefined operator"); return;
	}
}

void typeTable(int type){
	switch(type){
		case Assignment: 	printf("Assignment"); return;
		case Declarate: 	printf("Declarate"); return;
		case Define: 		printf("Define"); return;
		case ParaDefine: 	printf("ParaDefine"); return;
		case Expression: 	printf("Expression"); return;
		case Condition: 	printf("Condition"); return;
		case Object: 		printf("Object"); return;
		case FuncDef: 		printf("FuncDef"); return;
		case FuncCall: 	printf("FuncCall"); return;
		case StmtBlock:	printf("StmtBlock"); return;
		case If: 		printf("If"); return;
		case Else: 		printf("Else"); return;
		case Loop: 		printf("Loop"); return;
		case Branch: 		printf("Branch"); return;
		case Definition: 	printf("Definition"); return;
		case Parameter: 	printf("Parameter"); return;
		case Argument: 	printf("Argument"); return;
		case BlockIt: 		printf("BlockIt"); return;
		case Values: 		printf("Values"); return;
		case Index: 		printf("Index"); return;
		case CompilUnit: 	printf("CompilUnit"); return;
		default:		printf("Unknown node type"); return;
	}
}

void blanks(int level){ for(int i = 0; i < level; ++i) printf("  "); }

void dbgprt(treeNode *node, int level, int *var){
	int T = node->Type;
	int *varFirst = NULL, *varLast = NULL;
	if(T & LinkedNode){
		treeNode *pointer = node;
		if(T == Index){
			node->attr.idx = getTmpSym(); //for final result
			//then final = final * size; final = final + i;
		}
		while(pointer != NULL){
			if( !(pointer->Type & 0x10) )
				printf("dbgprt:BinaryNode in Linked Tab");
			
			blanks(level); typeTable(pointer->Type);
			printf("\n");
			while(pointer->first->Type == Expression){
				if(pointer->first->val == -1
				&& pointer->first->op == 0){
				treeNode *tmp = pointer->first;
				pointer->first = pointer->first->first;
				delete tmp;
				}
				else break;
			}
			dbgprt(pointer->first, level+1, varFirst);
			if(T == Index){ TempSym[*varFirst] = 0; }
			printf("\n");
			pointer = pointer->last;
		}
		return;
	}
	
	blanks(level); typeTable(T);
	//information about this node
	if(T == Define || T == Declarate){
		if(node->is_const == 1) printf(" is const");
	}
	if(T > 6 && T < 10){ //Object, FuncDef & FuncCall
		printf(" idx: %d", node->attr.idx);
		if(strcmp(Names[node->attr.idx],"main") == 0)
			mainIdx = node->attr.idx;
	}
	if(T == ParaDefine){
		printf(" idx: %d", node->attr.idx);
		if(node->is_ptr == 1) printf(" is pointer");
	}
	if(T == If){
	printf(" end_if: %d begin_true: %d",node->end_if,node->begin_true);
	}
	if(T == Loop){
		printf(" end_loop: %d begin_loop: %d",
		node->end_loop, node->begin_loop);
	}
	if(T == Expression){
		if(node->val != -1) printf(" value %d", node->val);
		else if( node->op != EMPTY_ ) {
			printf(" op: "); opTable(node->op);
			varFirst = new int; varLast = new int;
		}
		else printf(" no value and no operator");
	}
	
	//recursive
	if(node->first != NULL){
		while(node->first->Type == Expression){
			if(node->first->val == -1 && node->first->op == 0){
				treeNode *tmp = node->first;
				node->first = node->first->first;
				delete tmp;
			}
			else break;
		}
		printf("\n");
		dbgprt(node->first, level+1, varFirst);
	}
	if(node->last  != NULL){
		while(node->last->Type == Expression){
			if(node->last->val == -1 && node->last->op == 0){
				treeNode *tmp = node->last;
				node->last = node->last->first;
				delete tmp;
			}
			else break;
		}
		printf("\n");
		dbgprt(node->last, level+1, varLast);
	}
	
	//distribute a temperal Symbol for expression
	if(T == Expression && node->op != EMPTY_){
		node->attr.idx = getTmpSym();
		TempSym[*varFirst] = 0; TempSym[*varLast] = 0;
		*var = node->attr.idx;
	}
	if(T == Assignment){
		if(varFirst != NULL) TempSym[*varFirst] = 0;
		if(varLast  != NULL) TempSym[*varLast]  = 0;
	}
	if(T == FuncDef){
		node->is_ptr = maxTmpSym;
		for(int i = 0; i <= maxTmpSym; ++i) TempSym[i] = 0;
		maxTmpSym = -1;
	}
	if(T == Object && node->first != NULL) *var = *varFirst;
}

void generate(treeNode *node, char *var){
	//printf("generate function hasn't been finished yet\n"); return;
	
	int T = node->Type;
	int IDX = node->attr.idx;
	//deal with linked table heads
	if(T & LinkedNode){
		treeNode *pointer = node;
		int pos = 0;
		int *sz = currentSz;
		char posVar[10];
		while(pointer != NULL){
			if( !(pointer->Type & 0x10) )
				printf("generate:BinaryNode in Linked Tab");
			generate(pointer->first, posVar); printf("\n");
			if(T == Index){
				//Address Translation
			fprintf(fp,"t%d = t%d * %d",IDX,IDX,sz[pos]);
				//gen: t? = t? * sz[pos];
				fprintf(fp,"t%d = t%d + %s",IDX,IDX,posVar);
				//gen: t? = t? + posVar;
			}
			pointer = pointer->last;
			pos++;
		}
		if(T == Index) sprintf(var, "t%d", node->attr.idx);
		return;
	}
	
	//deal with binary nodes
	if(T == Assignment){
		char Ovar[10] = "";
		char Evar[10] = "";
		generate(node->first, Ovar);
		if(strcmp(Ovar,"") == 0) printf("invalid left value");
		generate(node->last, Evar);
		if(strcmp(Evar,"") == 0) printf("invalid right value");
		fprintf(fp,"%s = %s\n",Ovar,Evar);//assignment statement
		return;
	}
	
	if(T == Declarate){ generate(node->first); return; }
	
	if(T == Define){
		fprintf(fp,"var ");
		IDX = node->first->attr.idx;
		int tmp = SymTab[IDX].szCnt, res = 4;
		if(tmp > 0){
			for(int i = 0; i < tmp; ++i)
				res *= SymTab[IDX].sz[i];
			fprintf(fp,"%d ",res);
		}
		fprintf(fp,"T%d\n",IDX);
		return;
	}
	
	if(T == ParaDefine){ printf("ParaDefine shouldn't call"); return; }
	
	if(T == Expression){
		char LVar[10] = "";
		char RVar[10] = "";
		if(node->val == 0){
			sprintf(var, "%d", node->val);
			return;
		}
		if(node->op != EMPTY_){
			if(node->first == NULL){
				//unary operator
				generate(node->last, RVar);
				
				fprintf(fp, "t%d = ", IDX);
				opTable(node->op);
				fprintf(fp, " %s\n", RVar);
				
				sprintf(var, "t%d", IDX);
			}
			else{
				//both
				generate(node->first, LVar);
				generate(node->last,  RVar);
				
				fprintf(fp, "t%d = %s ", IDX, LVar);
				opTable(node->op);
				fprintf(fp, " %s\n", RVar);
				
				sprintf(var, "t%d", IDX);
			}
			return;
		}	
		printf("invalid Exp with no val, op & son\n");
		return;
	}
	
	if(T == Condition){ printf("Cond hasn't appear in .y"); return; }
	
	if(T == Object){
		//is variable
		int is_param = 0;
		int cnt = -1;
		int offset = 0;
		if(IDX > currentFuncIdx && IDX < currentBlockIdx){
			is_param = 1;
			cnt = IDX - currentFuncIdx - 1;
		}
		if(is_param) offset = sprintf(var, "p%d", cnt);
		else offset = sprintf(var, "T%d", IDX);

		if(node->first != NULL){
			//is array element
			//send your sz array in through currentSz
			char iVar[10] = "";
			currentSz = SymTab[IDX].sz;
			generate(node->first, iVar);
			sprintf(var+offset, "[%s]", iVar);
		}
		return;
	}
	
	if(T == FuncDef){
		fprintf(fp,"f_%s [%d]\n", Names[IDX], SymTab[IDX].szCnt);
		currentFuncType = SymTab[IDX].is_func; cft_valid = 1;
		currentFuncIdx = IDX + 1;
		currentBlockIdx = IDX + 1 + SymTab[IDX].szCnt;
		//initialization
		if(IDX == mainIdx){
			//initialization
		}
		//var def
		int tmp = SymTab[IDX].is_const;//bug here!
		for(int i = 0; i < tmp; ++i) fprintf(fp,"var T%d\n",i);
		tmp = SymTab[IDX].is_func;
		for(int i = 0; i < tmp; ++i) fprintf(fp,"var t%d\n",i);
		
		//deal with the block
		generate(node->last);
		fprintf(fp,"end f_%s\n", Names[IDX]);
		cft_valid = 0;
		return;
	}
	
	if(T == FuncCall){
		for(int i = 0; i < SymTab[IDX].szCnt; ++i){
			fprintf(fp,"param ");
			//parameter
			fprintf(fp,"\n");
		}
		fprintf(fp,"call f_%s", Names[IDX]);
		return;
	}
	
	if(T == StmtBlock){ generate(node->first); return; }
	
	if(T == 0xB){ printf("undefined binary node type: 0xB"); return; }
	
	if(T == If){
		//deal with the condition first : node->first
		printf("if ");
		//display the condition : node->first
		printf(" goto l%d",node->begin_true);
		if(node->last->Type == Else){
			generate(node->last->last); // cond == false
			fprintf(fp,"\n goto l%d",node->end_if);
			fprintf(fp,"\nl%d:",node->begin_true);
			generate(node->last->first); // cond == true
		}
		else{
			fprintf(fp,"\n goto l%d",node->end_if);
			fprintf(fp,"\nl%d:",node->begin_true);
			generate(node->last); // cond == true
		}
		return;
	}
	
	if(T == Else){ printf("Else shouldn't call generate\n"); return; }
	
	if(T == Loop){
		int begin_stmt = labelCnt++;
		
		lb_valid = 1; le_valid = 1;
		loop_begin = node->begin_loop;
		loop_end = node->end_loop;
		fprintf(fp,"l%d:\n",node->begin_loop);
		/*if cond == true*/ fprintf(fp,"goto l%d\n",begin_stmt);
		fprintf(fp,"goto l%d\n",node->end_loop);
		fprintf(fp,"l%d:\n",begin_stmt);
		generate(node->last);//deal with the stmt
		
		lb_valid = 0; le_valid = 0;
		return;
	}
	
	if(T == Branch){
		int bT = node->b_type;
		if(bT == b_return){
			if(cft_valid == 0 || currentFuncType == 0){
				printf("return appears out of func\n");
				return;
			}
			fprintf(fp,"return ");
			if(node->last && currentFuncType == voidFunc)
				printf("void func tries to return sth");
			if(node->last && currentFuncType == voidFunc)
				printf("int func returns nothing");
			if(node->last) generate(node->last); //retval
		}else if(bT == b_break){
			if(lb_valid == 0 || le_valid == 0){
				printf("break appears out of loop\n");
				return;
			}
			fprintf(fp,"goto l%d",loop_end);
		}else if(bT == b_contin){
			if(lb_valid == 0 || le_valid == 0){
				printf("continue appears out of loop\n");
				return;
			}
			fprintf(fp,"goto l%d",loop_begin);
		}else printf("unknown branch type\n");
		return;
	}
	
	printf("Unknown node type\n");
}

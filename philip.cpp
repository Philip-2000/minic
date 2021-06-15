#include "philip.hpp"

FILE* fp = NULL;
treeNode *ROOT = NULL;
int yaccdbg = 0;

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
	while(TempSym[ret] && ret < 32) ++ret;
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
		case LREQ_:	fprintf(fp,"<="); return;
		case LR_:	fprintf(fp,"<"); return;
		case GREQ_:	fprintf(fp,">="); return;
		case GR_:	fprintf(fp,">"); return;
		case EQEQ_:	fprintf(fp,"=="); return;
		case NOEQ_:	fprintf(fp,"!="); return;
		case ANDAN_:	fprintf(fp,"&&"); return;
		case OROR_:	fprintf(fp,"||"); return;
		case NO_:	fprintf(fp,"!"); return;
		case EQ_:	fprintf(fp,"="); return;
		case ADD_:	fprintf(fp,"+"); return;
		case SUB_:	fprintf(fp,"-"); return;
		case MUL_:	fprintf(fp,"*"); return;
		case DIV_:	fprintf(fp,"/"); return;
		case MOD_:	fprintf(fp,"\%"); return;
		default:	printf("undefined operator"); return;
	}
}

void typeTable(int type){
	switch(type){
		case Assignment: 	fprintf(fp,"Assignment"); return;
		case Declarate: 	fprintf(fp,"Declarate"); return;
		case Define: 		fprintf(fp,"Define"); return;
		case ParaDefine: 	fprintf(fp,"ParaDefine"); return;
		case Expression: 	fprintf(fp,"Expression"); return;
		case Condition: 	fprintf(fp,"Condition"); return;
		case Object: 		fprintf(fp,"Object"); return;
		case FuncDef: 		fprintf(fp,"FuncDef"); return;
		case FuncCall: 	fprintf(fp,"FuncCall"); return;
		case StmtBlock:	fprintf(fp,"StmtBlock"); return;
		case If: 		fprintf(fp,"If"); return;
		case Else: 		fprintf(fp,"Else"); return;
		case Loop: 		fprintf(fp,"Loop"); return;
		case Branch: 		fprintf(fp,"Branch"); return;
		case Definition: 	fprintf(fp,"Definition"); return;
		case Parameter: 	fprintf(fp,"Parameter"); return;
		case Argument: 	fprintf(fp,"Argument"); return;
		case BlockIt: 		fprintf(fp,"BlockIt"); return;
		case Values: 		fprintf(fp,"Values"); return;
		case Index: 		fprintf(fp,"Index"); return;
		case CompilUnit: 	fprintf(fp,"CompilUnit"); return;
		default:		printf("Unknown node type"); return;
	}
}

void blanks(int level){ for(int i = 0; i < level; ++i) printf("  "); }

int bound = -1;
char arrSym[10] = "";
void fill_in(treeNode *node, int *sz, int level, int length, int base){
	int pos = base;
	int step = length / sz[level];
	treeNode *pointer = node;
	char var[10] = "";
	while(pointer != NULL){
		if(pointer->first->Type != Values){
			//one object or expression
			generate(pointer->first, var);
			fprintf(fp,"%s[%d] = %s\n", arrSym, pos*4, var);
			++pos;
		}else{
			//still linked table
			if(level+1 >= bound){
				printf("too many dimensions\n"); return;}
			pos = (pos+step)/step - 1;//ceil(pos)
			fill_in(pointer->first, sz, level+1, step, pos);
			pos += step;
		}
		if(pos > base+length){printf("out of bound\n"); return;}
		pointer = pointer->last;
	}
}

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
			if(T == Index && varFirst != NULL)
				TempSym[*varFirst] = 0;
			printf("\n");
			pointer = pointer->last;
		}
		return;
	}
	
	
	if(T == Define){
		if(cft_valid == 1){
			if(node->last != NULL){
				node->Type = Assignment; T = Assignment;
				node->is_ptr = 1; //to initialize
			}
			else{
				delete node;
				return;
			}
		}
	}
	
	blanks(level); typeTable(T);
	//information about this node
	if(T == Declarate){
		if(node->is_const == 1) printf(" is const");
	}
	if(T == Define){
		if(node->is_const == 1) printf(" is const");
	}
	if(T > 6 && T < 10){ //Object, FuncDef & FuncCall
		printf(" idx: %d", node->attr.idx);
		if(strcmp(Names[node->attr.idx],"main") == 0)
			mainIdx = node->attr.idx;
		if(T == FuncDef){
			currentFuncIdx = node->attr.idx;
			currentFuncType = SymTab[currentFuncIdx].is_func;
			cft_valid = 1;
		}
	}
	if(T == ParaDefine){
		printf(" idx: %d", node->attr.idx);
		if(node->is_ptr == 1) printf(" is pointer");
	}
	if(T == If){
	printf(" end_if: %d begin_true: %d",node->end_if,node->begin_true);
		varFirst = new int;
	}
	if(T == Loop){
		printf(" end_loop: %d begin_loop: %d",
		node->end_loop, node->begin_loop);
		varFirst = new int;
	}
	if(T == Expression){
		if(node->val != -1) {
			printf(" value %d", node->val);
		}
		else if( node->op != EMPTY_ ) {
			printf(" op: "); opTable(node->op);
			varFirst = new int; varLast = new int;
		}
		else printf(" no value and no operator");
	}
	if(T == Branch){
		if(node->b_type == b_return) printf(" return");
		else if(node->b_type = b_contin) printf(" continue");
		else printf(" break");
		if(node->b_type == b_return && node->last != NULL){
			varLast = new int;
		}
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
		if(var != NULL) {
			node->attr.idx = getTmpSym();
			*var = node->attr.idx;
		}
		if(varFirst != NULL) TempSym[*varFirst] = 0;
		if(varLast  != NULL) TempSym[*varLast]  = 0;
	}
	if(T == Assignment){
		if(varFirst != NULL) TempSym[*varFirst] = 0;
		if(varLast  != NULL) TempSym[*varLast]  = 0;
	}
	if(T == If || T == Loop){
		node->attr.idx = *varFirst;
	}
	if(T == FuncDef){
		node->is_ptr = maxTmpSym;
		for(int i = 0; i <= maxTmpSym; ++i) TempSym[i] = 0;
		maxTmpSym = -1;
		cft_valid = 0;
	}
	if(T == Object && node->first != NULL){
		if(varFirst!=NULL){*var= *varFirst; TempSym[*varFirst]=0;}
		else var = NULL;
	}
	if(T == Branch){
		if(node->b_type == b_return && node->last != NULL){
			TempSym[*varLast] = 0;
		}
	}
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
			generate(pointer->first, posVar); 
			if(T == Index){
				//Address Translation
				if(pos == 0)
					fprintf(fp,"t%d = 0\n",IDX);
				else
					fprintf(fp,"t%d = t%d * %d\n",
						IDX, IDX, sz[pos]);
				//gen: t? = t? * sz[pos];
				fprintf(fp,"t%d = t%d + %s\n",
					IDX, IDX, posVar);
				//gen: t? = t? + posVar;
			}
			pointer = pointer->last; pos++;
		}
		if(T == Index) {
			fprintf(fp, "t%d = t%d * 4\n", IDX, IDX);
			sprintf(var, "t%d", node->attr.idx);
		}
		return;
	}
	
	//deal with binary nodes
	if(T == Assignment){
		if(node->is_ptr){ //initialization
			int IIDX = node->first->attr.idx;
			sprintf(arrSym,"T%d",IIDX);
			bound = SymTab[IIDX].szCnt;
			if(bound == 0){
				char var[10] = "";
				generate(node->last->first, var);
				fprintf(fp,"%s = %s\n", arrSym, var);
				return;
			}
			int len = 1;
			for(int i=0; i<bound; ++i)len *= SymTab[IIDX].sz[i];
			fill_in(node->last->first,SymTab[IIDX].sz,0,len,0);
			return;
		}
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
		if(node->val > -1){sprintf(var, "%d", node->val);return;}
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
		//global initialization
		if(IDX == mainIdx){
			treeNode *cUnit = ROOT->first;
			treeNode *decla, *defi;
			while(cUnit != NULL){
				if(cUnit->first->Type == FuncDef){
					if(cUnit->first->attr.idx
						== mainIdx) break;
					cUnit = cUnit->last;
					continue; //skip functions
				}
				decla = cUnit->first->first;
				while(decla != NULL){
					defi = decla->first;
					if(defi->last == NULL) {
						decla=decla->last; continue;
					}
			
		int IIDX = defi->first->attr.idx;
		sprintf(arrSym,"T%d",IIDX);
		bound = SymTab[IIDX].szCnt;
		if(bound == 0){
			char var[10] = "";
			generate(defi->last->first, var);
			fprintf(fp,"%s = %s\n", arrSym, var);
		}else{
			int len = 1;
			for(int i=0; i<bound; ++i)len *= SymTab[IIDX].sz[i];
			fill_in(defi->last->first,SymTab[IIDX].sz,0,len,0);
		}
		
					decla = decla->last;
				}
				cUnit = cUnit->last;
			}
		}
		//var def
		int tmp = SymTab[IDX].is_const;
		for(int i = 0; i < tmp; ++i){
			fprintf(fp,"var ");
			int ttmp = SymTab[i+currentBlockIdx].szCnt,res = 4;
			if(ttmp > 0){
				for(int j = 0; j < ttmp; ++j)
				res *= SymTab[i+currentBlockIdx].sz[j];
				fprintf(fp,"%d ",res);
			}
			fprintf(fp,"T%d\n",i+currentBlockIdx);
		}
		tmp = node->is_ptr;
		for(int i = 0; i <= tmp; ++i) fprintf(fp,"var t%d\n",i);
		
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
		fprintf(fp,"call f_%s\n", Names[IDX]);
		return;
	}
	
	if(T == StmtBlock){ generate(node->first); return; }
	
	if(T == 0xB){ printf("undefined binary node type: 0xB"); return; }
	
	if(T == If){
		char condVar[10] = "";
		generate(node->first,condVar);
		fprintf(fp,"if %s > 0 goto l%d\n",
			condVar,node->begin_true);
		if(node->last->Type == Else){
			generate(node->last->last); // cond == false
			fprintf(fp,"goto l%d\n",node->end_if);
			fprintf(fp,"l%d:\n",node->begin_true);
			generate(node->last->first); // cond == true
			fprintf(fp,"l%d:\n",node->end_if);
		}
		else{
			fprintf(fp,"goto l%d\n",node->end_if);
			fprintf(fp,"l%d:\n",node->begin_true);
			generate(node->last); // cond == true
			fprintf(fp,"l%d:\n",node->end_if);
		}
		return;
	}
	
	if(T == Else){ printf("Else shouldn't call generate\n"); return; }
	
	if(T == Loop){
		char condVar[10] = "";
		int begin_stmt = labelCnt++;
		
		lb_valid = 1; le_valid = 1;
		loop_begin = node->begin_loop;
		loop_end = node->end_loop;
		fprintf(fp,"l%d:\n",node->begin_loop);
		generate(node->first, condVar);
		fprintf(fp,"if %s > 0 goto l%d\n",condVar,begin_stmt);
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
			if(node->last && currentFuncType == voidFunc)
				printf("void func tries to return sth");
			if(!(node->last) && currentFuncType == intFunc)
				printf("int func returns nothing");
			if(node->last) {//retval
				char var[10] = "";
				generate(node->last, var);
				fprintf(fp, "return %s\n", var);
			}else{
				fprintf(fp, "return\n");
			}
		}else if(bT == b_break){
			if(lb_valid == 0 || le_valid == 0){
				printf("break appears out of loop\n");
				return;
			}
			fprintf(fp,"goto l%d\n",loop_end);
		}else if(bT == b_contin){
			if(lb_valid == 0 || le_valid == 0){
				printf("continue appears out of loop\n");
				return;
			}
			fprintf(fp,"goto l%d\n",loop_begin);
		}else printf("unknown branch type\n");
		return;
	}
	
	printf("Unknown node type\n");
}

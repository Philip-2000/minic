#include "philip.hpp"

int labelCnt;

char *Names[MAXSYMBOL];
int SymCnt = 0;
int currentSym = 0;

int SymStack[MAXSTACK] = {0};
int currentSymStack = 0;

SymTabEntry SymTab[MAXSYMBOL];

void initSymTab(){
	labelCnt = 0;
	
	SymTab[0].idx = 0;
	SymTab[0].prefix = -1;
	
	SymCnt = 1;
	currentSym = 0;
	currentSymStack = 1;
}

int step_out(){
	int P = currentSym;
	while(SymTab[P].real == 0) P = SymTab[P].prefix;
	return SymTab[P].prefix;
}

int lookup(const char *n, int limited, int func){
	int P = currentSym;
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
			SymTab[P].is_func == func) return P;
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

void dbgprt(treeNode *node, int level){
	int T = node->Type;
	if(T & LinkedNode){
		treeNode *pointer = node;
		while(pointer != NULL){
			if( !(pointer->Type & 0x10) )
				printf("generate:BinaryNode in Linked Tab");
			
			blanks(level); typeTable(pointer->Type);
			printf("\n"); dbgprt(pointer->first, level+1);
			printf("\n");
			pointer = pointer->last;
		}
		return;
	}
	
	blanks(level); typeTable(T);
	//information about this node
	if(T == 2 || T == 3){	//define or declarate
		if(node->is_const == 1) printf(" is const");
	}
	if(T > 6 && T < 10){ //object, funcDef & funcCall
		printf(" idx: %d", node->attr.idx);
	}
	if(T == 4){	//paraDef
		printf(" idx: %d", node->attr.idx);
		if(node->is_ptr == 1) printf(" is pointer");
	}
	if(T == 12){	//if
	printf(" end_if: %d begin_true: %d",node->end_if,node->begin_true);
	}
	if(T == 14){	//loop
		printf(" end_loop: %d begin_loop: %d",
		node->end_loop, node->begin_loop);
	}
	if(T == 5){	//Expression
		if(node->val != -1) printf(" value %d", node->val);
		else if( node->op != 0 ) {
			printf(" op: "); opTable(node->op);
		}
		else printf(" no value and no operator");
	}
	
	//recursive
	printf("\n"); if(node->first != NULL) dbgprt(node->first, level+1);
	printf("\n"); if(node->last  != NULL) dbgprt(node->last,  level+1);
}

void generate(treeNode *node){
	printf("generate function hasn't been finished yet\n"); return;
	
	int T = node->Type;
	//deal with linked table heads
	if(T & LinkedNode){
		treeNode *pointer = node;
		while(pointer != NULL){
			if( !(pointer->Type & 0x10) )
				printf("generate:BinaryNode in Linked Tab");
			generate(pointer->first);
			pointer = pointer->last;
		}
		return;
	}
	
	//deal with binary nodes
		//1. recursively	2. set bounds
	if(T == Assignment){
		
		return;
	}
	
	if(T == Declarate){
		return;
	}
	
	if(T == Define){ 
		return;
	}
	
	if(T == ParaDefine){
		return;
	}
	
	if(T == Expression){
		return;
	}
	
	if(T == Condition){
		return;
	}
	
	if(T == Object){
		return;
	}
	
	if(T == FuncDef){
		return;
	}
	
	if(T == FuncCall){
		return;
	}
	
	if(T == StmtBlock){
		return;
	}
	
	if(T == 0xB){ //Nothing Here
		printf("undefined binary node type: 0xB"); return;
	}
	
	if(T == If){
		return;
	}
	
	if(T == Else){
		return;
	}
	
	if(T == Loop){
		return;
	}
	
	if(T == Branch){
		return;
	}
	
}

#include "philip.hpp"

void initSymTab(){
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

int lookup(const char *n, int limited = 0, int func = 0){
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

void generate(treeNode *node){
	//deal with linked table heads
	if(node->type & LinkedNode){
		treeNode *pointer = node;
		while(pointer != NULL){
			if( !(pointer->type & 0x10) )
				printf("generate:BinaryNode in Linked Tab");
			generate(pointer->first);
			pointer = pointer->last;
		}
		return;
	}
	
	//deal with binary nodes
		//1. recursively	2. set bounds
	if(node->type == Assignment){
		return;
	}
	
	if(node->type == Declarate){
		return;
	}
	
	if(node->type == Define){ 
		return;
	}
	
	if(node->type == ParaDefine){
		return;
	}
	
	if(node->type == Expression){
		return;
	}
	
	if(node->type == Condition){
		return;
	}
	
	if(node->type == Object){
		return;
	}
	
	if(node->type == FuncDef){
		return;
	}
	
	if(node->type == FuncCall){
		return;
	}
	
	if(node->type == StmtBlock){
		return;
	}
	
	if(node->type == 0xB){ //Nothing Here
		printf("undefined binary node type: 0xB"); return;
	}
	
	if(node->type == If){
		return;
	}
	
	if(node->type == Else){
		return;
	}
	
	if(node->type == Loop){
		return;
	}
	
	if(node->type == Branch){
		return;
	}
	
}

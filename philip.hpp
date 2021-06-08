#define EMPTY_	0x00
#define LREQ_	0x01
#define LR_	0x02
#define GREQ_	0x03
#define GR_	0x04
#define EQEQ_	0x05
#define NOEQ_	0x06
#define ANDAN_	0x07
#define OROR_	0x08
#define NO_	0x09
#define EQ_	0x10
#define ADD_	0x11
#define SUB_	0x12
#define MUL_	0x13
#define DIV_	0x14
#define MOD_	0x15

#define BinaryNode 0x00	//attr	first = left, last = right
#define Assignment 0x01	//	first = obj, last = exp
#define Declarate  0x02	//cst	first = definitions. last = NULL
#define Define     0x03	//cst	first = obj, last = exp or NULL
#define ParaDefine 0x04	//ptr?	first = indices or NULL
#define Expression 0x05	//op	
#define Condition  0x06	//op	
#define Object     0x07	//name	first = indices, last = NULL
#define FuncDef    0x08	//name	first = list, last = body
#define FuncCall   0x09	//name	first = list, last = NULL
#define StmtBlock  0x0A	//	first = blockIt, last = NULL
#define If         0x0C	//	first = cond, last = stmts/else
#define Else       0x0D	//	first = stmts,last = stmts
#define Loop       0x0E	//	first = cond, last = stmts
#define Branch     0x0F	//dest	(last = exp for ret)

#define LinkedNode 0x10	//attr	first = self, last = next
#define Definition 0x11	//	first = define
#define Parameter  0x12	//	first = paraDefine
#define Argument   0x13	//	first = exp
#define BlockIt    0x14	//	first = stmt
#define Values     0x15	//	first = exp
#define Index      0x16	//	first = constexp
#define CompilUnit 0x17	//	first = decl/funcdef

#define notRetu 0x0
#define Retu    0x1
#define RetuExp 0x3

#include <string.h>
#define MAXSYMBOL 128
#define MAXDIM    10

class treeNode{
	treeNode *first;
	treeNode *last;
	int is_const = 0;
	int is_ptr = 0;
	int is_ret = 0;
	int op;
	int val = -1;
	union Attr{
		int idx;
		char *n;
		//destination : though I don't know how to code now
	}attr;
	char Type = '\0';
	treeNode(int type = 0){ Type = (char)type; }
	int calc(){
		if(val > -1) return val;
		
		if(op == 0){
			if(first != NULL){
				return first->calc();
			}else if(last != NULL){
				return last->calc();
			}else{
				printf("treeNode:calc:No son no op\n");
			}
		}
		if(first == NULL or last == NULL){
			printf("treeNode:calc:with op but no 2 sons\n");
		}
		switch(attr.op){
			case ADD_ : return first->calc() + last->calc();
			case SUB_ : return first->calc() - last->calc();
			case MUL_ : return first->calc() * last->calc();
			case DIV_ : return first->calc() / last->calc();
			case MOD_ : return first->calc() % last->calc();
			default: printf("treeNode:calc:unrecognized op\n");
		}
	}
};

char *Names[MAXSYMBOL];
int SymCnt = 0;
int currentSym = 0;

class SymTabEntry{
	int idx, prefix, is_func, real, is_const, szCnt, sz[MAXDIM]={0};
	void modify(const char *n, int f=0, int c=0, int r=0,
		int SZCnt = 0, int SZ[] = NULL){
		idx = SymCnt; ++SymCnt; Names[idx] = strdup(n);
		prefix = currentSym; currentSym = idx;
		is_func = f; is_const = c; real = r; szCnt = SZCnt;
		for(int i = 0; i < SZCnt; ++i) sz[i]=SZ[i];
	}
} SymTab[MAXSYMBOL];

void step_out(){
	int P = currentSym;
	while(SymTab[P].real == 0) P = SymTab[P].prefix;
	currentSym = SymTab[P].prefix;
}

int lookup(const char *n, int limited = 0){
	int P = currentSym;
	if(limited){
		while(SymTab[P].real == 0){
			if(strcmp(Names[P], n) == 0) return P;
			P = SymTab[P].prefix;
		}
	}
	else{
		while(P > 0){
			if(strcmp(Names[P], n) == 0) return P;
			P = SymTab[P].prefix;
		}
	}
	return -1;
}

// if(lookup(n,1) != -1) return -1;
// SymTab[SymCnt].modify(n,f,c,r,......); 

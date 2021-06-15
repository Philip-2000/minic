//for op
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

//for type
#define BinaryNode 0x00	//attr	first = left, last = right
#define Assignment 0x01	//	first = obj, last = exp
#define Declarate  0x02	//cst	first = definitions. last = NULL
#define Define     0x03	//cst	first = obj, last = exp or NULL
#define ParaDefine 0x04	//name	first = indices or NULL
#define Expression 0x05	//op	
#define Condition  0x06	//op	
#define Object     0x07	//name	first = indices, last = NULL
#define FuncDef    0x08	//name	first = listIt, last = StmtBlock
#define FuncCall   0x09	//name	first = listIt, last = NULL
#define StmtBlock  0x0A	//	first = blockIt, last = NULL
#define If         0x0C	//	first = cond, last = stmts/else
#define Else       0x0D	//	first = stmts,last = stmts
#define Loop       0x0E	// 	first = cond, last = stmts
#define Branch     0x0F	//dest	(last = exp for ret)

#define LinkedNode 0x10	//attr	first = self, last = next
#define Definition 0x11	//	first = define
#define Parameter  0x12	//	first = paraDefine
#define Argument   0x13	//	first = exp
#define BlockIt    0x14	//	first = stmt
#define Values     0x15	//	first = exp/values
#define Index      0x16	//	first = constexp
#define CompilUnit 0x17	//	first = decl/funcdef

//for is_func
#define notFunc  0x0
#define voidFunc 0x1
#define intFunc  0x3

//for b_type
#define b_return 0x1
#define b_contin 0x2
#define b_break  0x3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSYMBOL 128
#define MAXSTACK  32
#define MAXDIM    10

//about label:
	//if labelOne:end of if, labelTwo:beginning of cond = true,
	//loop labelOne:end of loop, labelTwo: beginning of loop

extern FILE* fp;

extern int yaccdbg;

extern int labelCnt;
extern int loop_begin, lb_valid;
extern int loop_end, le_valid;
extern int currentFuncType, cft_valid;
extern int currentFuncIdx, currentBlockIdx;
class treeNode{
public:
	treeNode *first;
	treeNode *last;
	int is_const = 0;
	int is_ptr = 0;
	int op;
	int b_type;
	int val = -1;
	int end_if = -1, begin_true= -1, end_loop = -1, begin_loop = -1;
	union Attr{
		int idx;
		char *n;
	}attr;
	int Type = 0;
	treeNode(int type = 0){ Type = type; }
	int calc(){ //for ConstExpA to calculate its size : all const
		if(val > -1) return val;
		if(op == EMPTY_){
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
		switch(op){
			case ADD_ : return first->calc() + last->calc();
			case SUB_ : return first->calc() - last->calc();
			case MUL_ : return first->calc() * last->calc();
			case DIV_ : return first->calc() / last->calc();
			case MOD_ : return first->calc() % last->calc();
			default: printf("treeNode:calc:unrecognized op\n");
				return -1;
		}
	}
};
extern treeNode* ROOT;

extern char *Names[MAXSYMBOL];
extern int SymCnt;
extern int currentSym;

extern int SymStack[MAXSTACK];
extern int currentSymStack;

extern int mainIdx;

	//blocks or funcs will push this stack
	//the end of blocks will pop this stack and step out if defined
	//if the stack is 0, and I define, I will change it to 1 and real
	// parameter is lower than FuncIDENT for 1 degree, but is higher than its block for 1 degree. It's easier to code.

class SymTabEntry{
public:
	int idx, prefix, real;
	int is_func, is_const, is_ptr, szCnt, sz[MAXDIM]={0};
	void modify(const char *n, int f=0, int c=0, int r=0,
		int SZCnt = 0, int SZ[] = NULL, int ptr=0){
		idx = SymCnt; ++SymCnt; Names[idx] = strdup(n);
		prefix = currentSym; currentSym = idx; is_ptr = ptr;
		is_func = f; is_const = c; real = r; szCnt = SZCnt;
		for(int i = 0; i < SZCnt; ++i) sz[i]=SZ[i];
	}
};

extern SymTabEntry SymTab[MAXSYMBOL];

extern bool tempSym[32];
int getTmpSym();

//first SymTabEntry is 0, without name, indicating the head of SymTab
void STEdbgprt(SymTabEntry *ptr);

void initSymTab();

void scanSymTab();

int step_out();

int lookup(const char *n, int limited = 0, int func = 0);

// if(lookup(n,1) != -1) return -1;
// SymTab[SymCnt].modify(n,f,c,r,......);

void dbgprt(treeNode *node, int level = 0, int *var = NULL);

void generate(treeNode *node, char *var = NULL);

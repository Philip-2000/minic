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
#define Expression 0x04	//op	
#define Condition  0x05	//op	
#define Object     0x06	//name	first = indices, last = NULL
#define FuncDef    0x07	//name	first = list, last = body
#define FuncCall   0x08	//name	first = list, last = NULL
#define StmtBlock  0x09	//	first = blockIt, last = NULL
#define If         0x0C	//	first = cond, last = stmts/else
#define Else       0x0D	//	first = stmts,last = stmts
#define Loop       0x0E	//	first = cond, last = stmts
#define Branch     0x0F	//dest	(last = exp for ret)

#define LinkedNode 0x10	//attr	first = self, last = next
#define Definition 0x11	//	first = define
#define Parameter  0x12	//	first = parameterDef ?????????
#define Argument   0x13	//	first = exp
#define BlockIt    0x14	//	first = stmt
#define Index      0x15	//	first = constexp
#define CompilUnit 0x16	//	first = decl/funcdef

class treeNode{
	treeNode *first;
	treeNode *last;
	union Attr{
		int is_const;
		int op;
		char *name;
		//destination : though I don't know how to code now
	}attr;
	char Type = '\0';
	treeNode(int type = 0){ Type = (char)type; }
};

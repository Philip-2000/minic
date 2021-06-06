#define LREQ	0x01
#define LR	0x02
#define GREQ	0x03
#define GR	0x04
#define EQEQ	0x05
#define NOEQ	0x06
#define ANDAND	0x07
#define OROR	0x08
#define NO	0x09
#define EQ	0x10
#define ADD	0x11
#define SUB	0x12
#define MUL	0x13
#define DIV	0x14
#define MOD	0x15

#define BinaryNode 0x00	//attr	first = left, last = right
#define Assignment 0x01	//	first = obj, last = exp
#define Declarate  0x02	//	same as above but do sth more
#define Explain    0x03	//op	
#define Condition  0x04	//op	
#define Object     0x05	//name	first = indices, last = NULL
#define FuncDef    0x06	//name	first = list, last = body
#define FuncCall   0x07	//name	first = list, last = NULL
#define If         0x08	//	first = cond, last = else
#define Else       0x09	//	first = stmts,last = stmts
#define Loop       0x0A	//	first = cond, last = stmts
#define Branch     0x0B	//dest	(last = exp for ret)

#define LinkedNode 0x10	//attr	first = self, last = next
#define Definition 0x11	//	first = constdef/vardef
#define Parameter  0x12	//	first = parameterDef ?????????
#define Argument   0x13	//	first = exp
#define Statement  0x14	//	first = stmt
#define Index      0x15	//	first = constexp
#define CompilUnit 0x16	//	first = decl/funcdef

class treeNode{
	treeNode *first;
	treeNode *last;
	union Attr{
		int op;
		char *name;
		//destination : though I don't know how to code now
	}attr;
	char Type;
	//treeNode(){}
};

/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "philip.y"

#include <stdio.h>
#include "philip.hpp"
//typedef char* string;
#define YYSTYPE treeNode *
#define YYSTYPE_IS_DECLARED
extern int yylex(void);
extern int yyparse(void);
FILE *fp = NULL;

#line 81 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_CONST = 258,
    IDENT = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    CONTINUE = 263,
    BREAK = 264,
    CONST = 265,
    INT = 266,
    VOID = 267,
    RETURN = 268,
    LREQ = 269,
    GREQ = 270,
    EQEQ = 271,
    NOEQ = 272,
    ANDAND = 273,
    OROR = 274,
    EQ = 275,
    BRA = 276,
    KET = 277,
    BRAA = 278,
    KETT = 279,
    BRAAA = 280,
    KETTT = 281,
    COMMA = 282,
    SEMI = 283,
    ADD = 284,
    SUB = 285,
    MUL = 286,
    DIV = 287,
    MOD = 288,
    NO = 289,
    GR = 290,
    LR = 291
  };
#endif
/* Tokens.  */
#define INT_CONST 258
#define IDENT 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define CONTINUE 263
#define BREAK 264
#define CONST 265
#define INT 266
#define VOID 267
#define RETURN 268
#define LREQ 269
#define GREQ 270
#define EQEQ 271
#define NOEQ 272
#define ANDAND 273
#define OROR 274
#define EQ 275
#define BRA 276
#define KET 277
#define BRAA 278
#define KETT 279
#define BRAAA 280
#define KETTT 281
#define COMMA 282
#define SEMI 283
#define ADD 284
#define SUB 285
#define MUL 286
#define DIV 287
#define MOD 288
#define NO 289
#define GR 290
#define LR 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    17,    17,    22,    27,    31,    36,    40,    44,    49,
      50,    55,    60,    60,    96,    96,   119,   124,   129,   133,
     137,   141,   146,   152,   157,   157,   189,   189,   212,   243,
     260,   265,   270,   274,   278,   283,   283,   313,   331,   313,
     352,   352,   353,   358,   363,   391,   409,   428,   428,   439,
     439,   446,   451,   456,   460,   464,   469,   474,   478,   482,
     489,   499,   506,   510,   514,   518,   524,   529,   534,   538,
     545,   551,   571,   582,   589,   596,   603,   610,   628,   639,
     646,   653,   660,   665,   670,   677,   684,   691,   698,   705,
     712,   719,   726,   733,   740,   747,   754,   761,   768,   775,
     782,   789,   796,   803,   808,   813,   818
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_CONST", "IDENT", "IF", "ELSE",
  "WHILE", "CONTINUE", "BREAK", "CONST", "INT", "VOID", "RETURN", "LREQ",
  "GREQ", "EQEQ", "NOEQ", "ANDAND", "OROR", "EQ", "BRA", "KET", "BRAA",
  "KETT", "BRAAA", "KETTT", "COMMA", "SEMI", "ADD", "SUB", "MUL", "DIV",
  "MOD", "NO", "GR", "LR", "$accept", "CompUnits", "CompUnit", "Decl",
  "ConstDecl", "BType", "ConstDefs", "ConstDef", "$@1", "$@2",
  "ConstInitVals", "ConstInitVal", "VarDecl", "VarDefs", "VarDef", "$@3",
  "$@4", "InitVals", "InitVal", "FuncDef", "$@5", "$@6", "$@7", "FuncType",
  "FuncFParams", "FuncFParam", "Block", "@8", "$@9", "BlockItems",
  "BlockItem", "Stmt", "ExpAs", "ExpA", "Exp", "Cond", "LVal",
  "PrimaryExp", "UnaryExp", "FuncRParams", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "ConstExpAs", "ConstExpA", "ConstExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,    20,  -146,  -146,    38,    75,  -146,  -146,    54,  -146,
    -146,    61,  -146,    64,  -146,  -146,    -8,    14,    55,  -146,
      71,    78,    99,   162,    83,   109,    71,  -146,    54,   112,
     113,   115,  -146,  -146,    64,  -146,    32,   162,    13,    13,
      13,  -146,  -146,    76,   -11,  -146,   129,    98,   116,  -146,
    -146,   132,    20,   127,   138,  -146,    22,   162,  -146,   139,
     146,  -146,   139,  -146,  -146,  -146,   162,   162,   162,   162,
     162,  -146,     3,  -146,  -146,    98,   144,   160,   151,   147,
      63,  -146,  -146,   127,  -146,   148,   157,   154,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,   155,   153,  -146,   161,
    -146,   159,  -146,    20,  -146,   163,   166,  -146,   162,  -146,
    -146,  -146,    98,    70,   168,   164,   144,  -146,  -146,   127,
    -146,  -146,   174,   176,   170,   171,   156,  -146,  -146,  -146,
     175,    70,  -146,   172,   182,  -146,    71,  -146,  -146,   162,
     162,  -146,  -146,  -146,   177,  -146,  -146,  -146,   162,  -146,
     181,    34,    94,   186,   187,  -146,   185,  -146,   180,   142,
     162,   162,   162,   162,   162,   162,   162,   162,   142,  -146,
     203,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
     142,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     9,    40,     0,     3,     4,     6,     0,     7,
       5,     0,     9,     0,     1,     2,    29,     0,    23,    35,
      14,     0,    11,     0,     0,    28,   104,    21,     0,     0,
       0,     0,    12,     8,     0,    75,    72,     0,     0,     0,
       0,    74,    76,    87,    90,   106,     0,     0,     0,   103,
      22,     0,     0,     0,     0,    10,     0,     0,    71,    67,
       0,    69,    72,    79,    80,    81,     0,     0,     0,     0,
       0,   105,     0,    27,    32,     0,     0,     0,     0,    43,
       0,    15,    18,     0,    78,    83,     0,     0,    66,    73,
      85,    86,    84,    89,    88,    34,     0,    31,    25,    47,
      36,    46,    38,     0,    20,     0,    17,    13,     0,    77,
      68,    33,     0,     0,     0,     0,     0,    42,    19,     0,
      82,    30,     0,     0,     0,     0,     0,    57,    53,    58,
       0,    52,    54,     0,    74,    50,    45,    39,    16,     0,
       0,    63,    62,    64,     0,    48,    51,    56,     0,    44,
       0,    95,    98,   100,   102,    70,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      59,    94,    93,    91,    92,    97,    96,    99,   101,    61,
       0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,   205,  -146,  -104,  -146,     2,   178,  -146,  -146,  -146,
      92,   -43,  -146,   188,  -146,  -146,  -146,   101,   -34,  -146,
    -146,  -146,  -146,  -146,   111,  -146,   -71,  -146,  -146,    84,
    -146,  -145,   158,  -146,   -36,    79,  -109,    82,  -146,   110,
      47,   -23,   -99,   -40,    56,    53,   -18,  -146,   198
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    21,    22,    54,    31,
     105,   106,     9,    17,    18,    48,    24,    96,    97,    10,
      29,    30,   116,    11,    78,    79,   129,   113,   114,   130,
     131,   132,    58,    59,   133,   150,    41,    42,    43,    86,
      44,    61,   152,   153,   154,   155,    25,    26,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    60,    32,    13,   134,   100,    35,    36,    49,   128,
      81,    74,   -26,    73,   170,    23,    35,    62,    69,    70,
      85,    87,   134,   179,    37,    35,    36,   128,    72,    95,
      45,    12,    38,    39,    37,   181,    74,    40,    14,    74,
     107,    98,    27,    37,    84,   137,    93,    94,   160,   161,
     134,    38,    39,    56,    77,    57,    40,    45,    16,   134,
      45,   171,   172,   173,   174,    19,    35,    36,    20,   162,
     163,   134,    85,    35,    36,   122,    74,   123,   124,   125,
       1,    12,    28,   126,    37,     1,     2,     3,    80,   104,
     144,    37,    38,    39,    23,    99,    45,    40,   127,    38,
      39,    35,    36,    47,    40,    77,    33,    66,    67,    68,
     164,   165,   158,    90,    91,    92,   151,   151,   149,    37,
      63,    64,    65,    72,   175,   176,    34,    38,    39,   -24,
      35,    36,    40,    51,    52,    53,    75,   151,   151,   151,
     151,   151,   151,   151,   151,    35,    36,   122,    37,   123,
     124,   125,    80,    71,    76,   126,    38,    39,    83,    35,
      36,    40,    57,    37,   101,    35,    36,    99,    89,    99,
     127,    38,    39,   102,   103,   108,    40,    37,   110,   109,
     112,   111,   115,    37,   143,    38,    39,   -49,   136,   118,
      40,    38,    39,   119,   135,   139,    40,   140,   141,   142,
     147,   145,   148,   159,   166,   157,   167,   168,   169,   180,
      15,   138,    55,   121,   117,   146,    50,    88,   120,   156,
     178,    46,   177
};

static const yytype_uint8 yycheck[] =
{
      23,    37,    20,     1,   113,    76,     3,     4,    26,   113,
      53,    47,    20,    47,   159,    23,     3,     4,    29,    30,
      56,    57,   131,   168,    21,     3,     4,   131,    25,    26,
      53,    11,    29,    30,    21,   180,    72,    34,     0,    75,
      83,    75,    28,    21,    22,   116,    69,    70,    14,    15,
     159,    29,    30,    21,    52,    23,    34,    80,     4,   168,
      83,   160,   161,   162,   163,     4,     3,     4,     4,    35,
      36,   180,   108,     3,     4,     5,   112,     7,     8,     9,
      10,    11,    27,    13,    21,    10,    11,    12,    25,    26,
     126,    21,    29,    30,    23,    25,   119,    34,    28,    29,
      30,     3,     4,    20,    34,   103,    28,    31,    32,    33,
      16,    17,   148,    66,    67,    68,   139,   140,   136,    21,
      38,    39,    40,    25,   164,   165,    27,    29,    30,    20,
       3,     4,    34,    21,    21,    20,    20,   160,   161,   162,
     163,   164,   165,   166,   167,     3,     4,     5,    21,     7,
       8,     9,    25,    24,    22,    13,    29,    30,    20,     3,
       4,    34,    23,    21,     4,     3,     4,    25,    22,    25,
      28,    29,    30,    22,    27,    27,    34,    21,    24,    22,
      27,    26,    23,    21,    28,    29,    30,    26,    24,    26,
      34,    29,    30,    27,    26,    21,    34,    21,    28,    28,
      28,    26,    20,    22,    18,    28,    19,    22,    28,     6,
       5,   119,    34,   112,   103,   131,    28,    59,   108,   140,
     167,    23,   166
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    12,    38,    39,    40,    41,    42,    49,
      56,    60,    11,    42,     0,    38,     4,    50,    51,     4,
       4,    43,    44,    23,    53,    83,    84,    28,    27,    57,
      58,    46,    83,    28,    27,     3,     4,    21,    29,    30,
      34,    73,    74,    75,    77,    78,    85,    20,    52,    83,
      50,    21,    21,    20,    45,    43,    21,    23,    69,    70,
      71,    78,     4,    74,    74,    74,    31,    32,    33,    29,
      30,    24,    25,    55,    71,    20,    22,    42,    61,    62,
      25,    48,    85,    20,    22,    71,    76,    71,    69,    22,
      77,    77,    77,    78,    78,    26,    54,    55,    55,    25,
      63,     4,    22,    27,    26,    47,    48,    48,    27,    22,
      24,    26,    27,    64,    65,    23,    59,    61,    26,    27,
      76,    54,     5,     7,     8,     9,    13,    28,    40,    63,
      66,    67,    68,    71,    73,    26,    24,    63,    47,    21,
      21,    28,    28,    28,    71,    26,    66,    28,    20,    83,
      72,    78,    79,    80,    81,    82,    72,    28,    71,    22,
      14,    15,    35,    36,    16,    17,    18,    19,    22,    28,
      68,    79,    79,    79,    79,    80,    80,    81,    82,    68,
       6,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      43,    43,    45,    44,    46,    44,    47,    47,    48,    48,
      48,    49,    50,    50,    52,    51,    53,    51,    51,    51,
      54,    54,    55,    55,    55,    57,    56,    58,    59,    56,
      60,    60,    61,    61,    62,    62,    62,    64,    63,    65,
      63,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    71,
      72,    73,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     0,     5,     0,     4,     3,     1,     1,     3,
       2,     3,     3,     1,     0,     5,     0,     4,     2,     1,
       3,     1,     1,     3,     2,     0,     6,     0,     0,     8,
       1,     1,     3,     1,     5,     4,     2,     0,     4,     0,
       3,     2,     1,     1,     1,     4,     2,     1,     1,     5,
       7,     5,     2,     2,     2,     3,     2,     1,     3,     1,
       1,     2,     1,     3,     1,     1,     1,     4,     3,     2,
       2,     2,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     2,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 17 "philip.y"
                                   {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; deledte yyvsp[0];
		}
#line 1519 "y.tab.c"
    break;

  case 3:
#line 22 "philip.y"
                         {
			yyvsp[0]->last = NULL;
			yyval = new treeNode();
			yyval->first = yyvsp[0];
		}
#line 1529 "y.tab.c"
    break;

  case 4:
#line 27 "philip.y"
                     {
			yyval = new treeNode(CompilUnit);
			yyval->first = yyvsp[0]->first; delete yyvsp[0];
		}
#line 1538 "y.tab.c"
    break;

  case 5:
#line 31 "philip.y"
                       {
			yyval = new treeNode(CompilUnit);
			yyval->first = yyvsp[0];
		}
#line 1547 "y.tab.c"
    break;

  case 6:
#line 36 "philip.y"
                          {
			yyval = new treeNode();
			yyval->first = yyvsp[0];
		}
#line 1556 "y.tab.c"
    break;

  case 7:
#line 40 "philip.y"
                        {
			yyval = new treeNode();
			yyval->first = yyvsp[0];
		}
#line 1565 "y.tab.c"
    break;

  case 8:
#line 44 "philip.y"
                                          {
			yyval = new treeNode(Declarate);
			yyval->is_const = 1;
			yyval->first = yyvsp[-2];
		}
#line 1575 "y.tab.c"
    break;

  case 10:
#line 50 "philip.y"
                                        {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 1585 "y.tab.c"
    break;

  case 11:
#line 55 "philip.y"
                        {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1595 "y.tab.c"
    break;

  case 12:
#line 60 "philip.y"
                                {
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup(yyvsp[-1]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = yyvsp[0]->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,1, !R , sszCnt, ssz);
			SymStack[currentSymStack] = 1;
			yyvsp[-1]->attr.idx = currentSym;
			
		}
#line 1624 "y.tab.c"
    break;

  case 13:
#line 83 "philip.y"
                                 {
			//error if the size is wrong
			
			
						
			//hang CEAs under IDENT as obj
			yyvsp[-4]->first = yyvsp[-3]->first; //index linked table head
			delete yyvsp[-3];
			
			yyval = new treeNode(Define);
			yyval->is_const = 1;
			yyval->first = yyvsp[-3];  yyval->last = yyvsp[-1];
		}
#line 1642 "y.tab.c"
    break;

  case 14:
#line 96 "philip.y"
                      {
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup(yyvsp[0]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,1,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
              	}
#line 1661 "y.tab.c"
    break;

  case 15:
#line 109 "philip.y"
                                 {
              		//error if the size is wrong
              		if(yyvsp[0]->first->type != Expression ||
              			yyvsp[0]->last != NULL)
              			yyerror("vector on scaler");
              		
     			yyval = new treeNode(Define);
			yyval->is_const = 1;
			yyval->first = yyvsp[-3];  yyval->last = yyvsp[-1];
              	}
#line 1676 "y.tab.c"
    break;

  case 16:
#line 119 "philip.y"
                                                {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 1686 "y.tab.c"
    break;

  case 17:
#line 124 "philip.y"
                            {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1696 "y.tab.c"
    break;

  case 18:
#line 129 "philip.y"
                        {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[0];
		}
#line 1705 "y.tab.c"
    break;

  case 19:
#line 133 "philip.y"
                                         {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[-1];
              	}
#line 1714 "y.tab.c"
    break;

  case 20:
#line 137 "philip.y"
                           {
			yyval = new treeNode(Values);
			yyval->first = NULL;
              	}
#line 1723 "y.tab.c"
    break;

  case 21:
#line 141 "philip.y"
                                  {
			yyval = new treeNode(Declarate);
			yyval->is_const = 0;
			yyval->first = yyvsp[-1];
		}
#line 1733 "y.tab.c"
    break;

  case 22:
#line 146 "philip.y"
                                    {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2];
			delete yyvsp[0];
		}
#line 1744 "y.tab.c"
    break;

  case 23:
#line 152 "philip.y"
                      {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1754 "y.tab.c"
    break;

  case 24:
#line 157 "philip.y"
                                 {
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup(yyvsp[-1]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = yyvsp[0]->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R, sszCnt, ssz);
			SymStack[currentSymStack] = 1;
			yyvsp[-1]->attr.idx = currentSym;
			
		}
#line 1783 "y.tab.c"
    break;

  case 25:
#line 180 "philip.y"
                           {
			//hang CEAs under IDENT as obj
			yyvsp[-4]->first = yyvsp[-3]->first; //index linked table head
			delete yyvsp[-3];
			
			yyval = new treeNode(Define);
			yyval->is_const = 0;
			yyval->first = yyvsp[-4];  yyval->last = yyvsp[-1];
		}
#line 1797 "y.tab.c"
    break;

  case 26:
#line 189 "philip.y"
                      {
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup(yyvsp[0]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
              	}
#line 1816 "y.tab.c"
    break;

  case 27:
#line 202 "philip.y"
                            {
              		//error if the size is wrong
              		if(yyvsp[0]->first->type != Expression ||
              			yyvsp[0]->last != NULL)
              			yyerror("vector on scaler");
              
			yyval = new treeNode(Define);
			yyval->is_const = 0;
			yyval->first = yyvsp[-3];  yyval->last = yyvsp[-1];
		}
#line 1831 "y.tab.c"
    break;

  case 28:
#line 212 "philip.y"
                                {
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup(yyvsp[-1]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = yyvsp[0]->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R, sszCnt, ssz);
			SymStack[currentSymStack] = 1;
			yyvsp[-1]->attr.idx = currentSym;
              
 			//hang CEAs under IDENT as obj
			yyvsp[-1]->first = yyvsp[0]->first; //index linked table head
			delete yyvsp[0];
			
			yyval = new treeNode(Define);
			yyval->is_const = 0;
			yyval->first = yyvsp[-1];  yyval->last = NULL;
		}
#line 1867 "y.tab.c"
    break;

  case 29:
#line 243 "philip.y"
                     {
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup(yyvsp[0]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
			yyval = new treeNode(Define);
			yyval->is_const = 0;
			yyval->first = yyvsp[0];  yyval->last = NULL;
		}
#line 1889 "y.tab.c"
    break;

  case 30:
#line 260 "philip.y"
                                      {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 1899 "y.tab.c"
    break;

  case 31:
#line 265 "philip.y"
                       {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1909 "y.tab.c"
    break;

  case 32:
#line 270 "philip.y"
                   {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[0];
		}
#line 1918 "y.tab.c"
    break;

  case 33:
#line 274 "philip.y"
                                    {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[-1];
              	}
#line 1927 "y.tab.c"
    break;

  case 34:
#line 278 "philip.y"
                           {
			yyval = new treeNode(Values);
			yyval->first = NULL;
              	}
#line 1936 "y.tab.c"
    break;

  case 35:
#line 283 "philip.y"
                               {
			//define IDENT
				//check if I'm at the root
			if(step_out() != 0)
				yyerror("Function Defined not at root");
				
				//check if name defined lookup(N,1,1)
	      		char *N = strdup(yyvsp[0]->attr.n);
              		if(lookup(N,1,1) != -1) yyerror("Func re-defined");
				
				//define it and modify flags about r
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,1,0,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
			++currentSymStack;
			
		}
#line 1960 "y.tab.c"
    break;

  case 36:
#line 301 "philip.y"
                                {
			
			yyval = new treeNode(FuncDef);
			yyval->first = NULL;
			yyval->last = yyvsp[-1];
			yyval->attr.idx = currentSym;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;

		}
#line 1977 "y.tab.c"
    break;

  case 37:
#line 313 "philip.y"
                               {
			//define IDENT
				//check if I'm at the root
			if(step_out() != 0)
				yyerror("Function Defined not at root");
				
				//check if name defined lookup(N,1,1)
	      		char *N = strdup(yyvsp[0]->attr.n);
              		if(lookup(N,1,1) != -1) yyerror("Func re-defined");
				
				//define it and modify flags about r
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,1,0,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
			++currentSymStack;
			
              	}
#line 2001 "y.tab.c"
    break;

  case 38:
#line 331 "philip.y"
                                      {
              		//check how many parameters are there for me
              		int paraCnt = 0;
              		treeNode * pointer = yyvsp[-2]->first;
              		while(pointer != NULL){
              			++paraCnt;
              			pointer = pointer->last;
              		}
              		SymTab.[yyvsp[-4]->attr.idx].szCnt = paraCnt;
              		
              	}
#line 2017 "y.tab.c"
    break;

  case 39:
#line 341 "philip.y"
                        {
			
              		yyval = new treeNode(FuncDef);
			yyval->first = yyvsp[-4]->first; delete yyvsp[-4];
			yyval->last = yyvsp[-2];
			yyval->attr.idx = currentSym;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
              	}
#line 2033 "y.tab.c"
    break;

  case 42:
#line 353 "philip.y"
                                            {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 2043 "y.tab.c"
    break;

  case 43:
#line 358 "philip.y"
                          {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2053 "y.tab.c"
    break;

  case 44:
#line 363 "philip.y"
                                                {
			//define this IDENT;
			
				//first check if it is defined
	      		char *N = strdup(yyvsp[-4]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//recursively get those parameters
			int sszCnt = 0, ssz[MAXDIM] = {0};
			treeNode *ptr = yyvsp[0]->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ssz[sszCnt] = ptr->first->calc();
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
			
				//define it
			int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R0,sszCnt,ssz,1);
			SymStack[currentSymStack] = 1;
			yyvsp[-3]->attr.idx = currentSym;
			
			yyval = new treeNode(ParaDefine);
			yyval->attr.is_ptr = 1;
			yyval->first = yyvsp[0];
			yyval->attr.idx = currentSym;
		}
#line 2086 "y.tab.c"
    break;

  case 45:
#line 391 "philip.y"
                                     {
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup(yyvsp[-3]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R,0,NULL,1);
			SymStack[currentSymStack] = 1;
			yyvsp[-2]->attr.idx = currentSym;
			
              		yyval = new treeNode(ParaDefine);
              		yyval->attr.is_ptr = 1;
              		yyval->first = NULL;
              		yyval->attr.idx = currentSym;
              	}
#line 2109 "y.tab.c"
    break;

  case 46:
#line 409 "philip.y"
                           {
              		//define this IDENT
              		
              			//first check if it is defined
              		char *N = strdup(yyvsp[-1]->attr.n);
              		if(lookup(N,1) != -1) yyerror("symbol re-defined");
              		
              			//define it
              		int R = SymStack[currentSymStack];
			SymTab[SymCnt].modify(N,0,0,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
              		yyval = new treeNode(ParaDefine);
              		yyval->attr.is_ptr = 0;
              		yyval->first = NULL;
              		yyval->attr.idx = currentSym;
              	}
#line 2132 "y.tab.c"
    break;

  case 47:
#line 428 "philip.y"
                      { ++currentSymStack; }
#line 2138 "y.tab.c"
    break;

  case 48:
#line 428 "philip.y"
                                                             {
			yyval = new treeNode();
			yyval->first = yyvsp[-2]->first;
			delete yyvsp[-2];
			
			
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
		}
#line 2154 "y.tab.c"
    break;

  case 49:
#line 439 "philip.y"
                      { ++currentSymStack; }
#line 2160 "y.tab.c"
    break;

  case 50:
#line 439 "philip.y"
                                                  {
              		yyval = new treeNode();
              		yyval->first = NULL; //same as above to avoid conflict
              		if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
              	}
#line 2172 "y.tab.c"
    break;

  case 51:
#line 446 "philip.y"
                                    {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; delete yyvsp[0];
		}
#line 2182 "y.tab.c"
    break;

  case 52:
#line 451 "philip.y"
                         {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2192 "y.tab.c"
    break;

  case 53:
#line 456 "philip.y"
                    {
			yyval = new treeNode();
			yyval->first = yyvsp[0]->first; delete yyvsp[0];
		}
#line 2201 "y.tab.c"
    break;

  case 54:
#line 460 "philip.y"
                    {
	      		yyval = new treeNode();
	      		yyval->first = yyvsp[0];
	      	}
#line 2210 "y.tab.c"
    break;

  case 55:
#line 464 "philip.y"
                                {
			yyval = new treeNode(Assignment);
			yyval->first = yyvsp[-3];
			yyval->last = yyvsp[-1];
		}
#line 2220 "y.tab.c"
    break;

  case 56:
#line 469 "philip.y"
                        {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-1];
              		yyval->attr.op = EMPTY_;
              	}
#line 2230 "y.tab.c"
    break;

  case 57:
#line 474 "philip.y"
                    {
              		yyval = new treeNode();
              		yyval->first = NULL; yyval->last = NULL;
              	}
#line 2239 "y.tab.c"
    break;

  case 58:
#line 478 "philip.y"
                     {
              		yyval = new treeNode(StmtBlock);
              		yyval->first = yyvsp[0]->first; delete yyvsp[0];
              	}
#line 2248 "y.tab.c"
    break;

  case 59:
#line 482 "philip.y"
                                    {
              		yyval = new treeNode(If);
              		yyval->first = yyvsp[-2];
              		yyval->last = yyvsp[0];
              		yyval->end_if = labelCnt++;
              		yyval->begin_true = labelCnt++; 
              	}
#line 2260 "y.tab.c"
    break;

  case 60:
#line 489 "philip.y"
                                              {
              		yyval = new treeNode(If);
              		yyval->first = yyvsp[-4];
              		yyvsp[-1] = new treeNode(Else);
              		yyval->last = yyvsp[-1];
              		yyvsp[-1]->first = yyvsp[-2];
              		yyvsp[-1]->last = yyvsp[0];
              		yyval->end_if = labelCnt++;
              		yyval->begin_true = labelCnt++;
              	}
#line 2275 "y.tab.c"
    break;

  case 61:
#line 499 "philip.y"
                                       {
              		yyval = new treeNode(Loop);
              		yyval->first = yyvsp[-2];
              		yyval->last = yyvsp[0];
              		yyval->end_loop = labelCnt++;
              		yyval->begin_loop = labelCnt++;
		}
#line 2287 "y.tab.c"
    break;

  case 62:
#line 506 "philip.y"
                          {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_break;
              	}
#line 2296 "y.tab.c"
    break;

  case 63:
#line 510 "philip.y"
                             {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_contin;
              	}
#line 2305 "y.tab.c"
    break;

  case 64:
#line 514 "philip.y"
                           {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_return;
              	}
#line 2314 "y.tab.c"
    break;

  case 65:
#line 518 "philip.y"
                               {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_return;
              		yyval->last = yyvsp[-1];
              	}
#line 2324 "y.tab.c"
    break;

  case 66:
#line 524 "philip.y"
                          {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; delete yyvsp[0];
		}
#line 2334 "y.tab.c"
    break;

  case 67:
#line 529 "philip.y"
                    {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2344 "y.tab.c"
    break;

  case 68:
#line 534 "philip.y"
                             {
			yyval = new treeNode(Index);
			yyval->first = yyvsp[-1];
		}
#line 2353 "y.tab.c"
    break;

  case 69:
#line 538 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2365 "y.tab.c"
    break;

  case 70:
#line 545 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
              	}
#line 2376 "y.tab.c"
    break;

  case 71:
#line 551 "philip.y"
                           {
              		yyval = new treeNode(Object);
              		char *N = strdup(yyvsp[-1]->attr.n);
              		int res = lookup(N);
              		if( res == -1 ) yyerror("no such id");
              		
              		int sszCnt = 0;
			treeNode *ptr = yyvsp[0]->first;
			for(;sszCnt < MAXDIM; ++sszCnt){
				if(ptr == NULL) break;
				ptr = ptr->last;
			}
			if(sszCnt >= MAXDIM) yyerror("too many dimension");
              		if( SymTab[res].szCnt != sszCnt)
              			yyerror("dimension fault");
              		
              		yyval->attr.idx = res;
              		yyval->first = yyvsp[0]->first;
              		yyval->is_const = 0;
              	}
#line 2401 "y.tab.c"
    break;

  case 72:
#line 571 "philip.y"
                     {
              		yyval = new treeNode(Object);
              		char *N = strdup(yyvsp[0]->attr.n);
              		int res = lookup(N);
              		if( res == -1 ) yyerror("no such id");
              		if( SymTab[res].szCnt != 0) yyerror("dim fault");
              		
              		yyval->attr.idx = res;
              		yyval->first = NULL;
              		yyval->is_const = 0;
              	}
#line 2417 "y.tab.c"
    break;

  case 73:
#line 582 "philip.y"
                           {
			yyval = new treeNode(Expression);
			yyval->first = yyvsp[-1];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[-1]->is_const;
		}
#line 2429 "y.tab.c"
    break;

  case 74:
#line 589 "philip.y"
                    {
              		yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2441 "y.tab.c"
    break;

  case 75:
#line 596 "philip.y"
                         {
              		yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = 1;
              	}
#line 2453 "y.tab.c"
    break;

  case 76:
#line 603 "philip.y"
                          {
			yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2465 "y.tab.c"
    break;

  case 77:
#line 610 "philip.y"
                                         {
              		yyval = new treeNode(FuncCall);
              		char *N = strdup(yyvsp[-3]->attr.n);
              		int res = lookup(N,0,1);
              		if( res == -1 ) yyerror("no such function");
              		
              		int paraCnt = 0;
              		treeNode * pointer = yyvsp[-1]->first;
              		while(pointer != NULL){
              			++paraCnt;
              			pointer = pointer->last;
              		}
              		if( SymTab[res].szCnt != paraCnt) 
              			yyerror("para fault");
              		
              		yyval->first = yyvsp[-1];
			yyval->is_const = 0;
              	}
#line 2488 "y.tab.c"
    break;

  case 78:
#line 628 "philip.y"
                             {
              
              		yyval = new treeNode(FuncCall);
              		char *N = strdup(yyvsp[-2]->attr.n);
              		int res = lookup(N,0,1);
              		if( res == -1 ) yyerror("no such function");
              		if( SymTab[res].szCnt != 0) yyerror("para fault");
              		
              		yyval->first = NULL;
              		yyval->is_const = 0;
              	}
#line 2504 "y.tab.c"
    break;

  case 79:
#line 639 "philip.y"
                              {
			yyval = new treeNode(Expression);
			yyval->first = NULL;
			yyval->attr.op = ADD_;
			yyval->last = yyvsp[0];
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2516 "y.tab.c"
    break;

  case 80:
#line 646 "philip.y"
                              {
			yyval = new treeNode(Expression);
			yyval->first = NULL;
			yyval->attr.op = SUB_;
			yyval->last = yyvsp[0];
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2528 "y.tab.c"
    break;

  case 81:
#line 653 "philip.y"
                              {
			yyval = new treeNode(Expression);
			yyval->first = NULL;
			yyval->attr.op = NO_;
			yyval->last = yyvsp[0];
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2540 "y.tab.c"
    break;

  case 82:
#line 660 "philip.y"
                                     {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 2550 "y.tab.c"
    break;

  case 83:
#line 665 "philip.y"
                   {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2560 "y.tab.c"
    break;

  case 84:
#line 670 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = MOD_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2572 "y.tab.c"
    break;

  case 85:
#line 677 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = MUL_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2584 "y.tab.c"
    break;

  case 86:
#line 684 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = DIV_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2596 "y.tab.c"
    break;

  case 87:
#line 691 "philip.y"
                        {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2608 "y.tab.c"
    break;

  case 88:
#line 698 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = SUB_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2620 "y.tab.c"
    break;

  case 89:
#line 705 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = ADD_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2632 "y.tab.c"
    break;

  case 90:
#line 712 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2644 "y.tab.c"
    break;

  case 91:
#line 719 "philip.y"
                                {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = GR_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2656 "y.tab.c"
    break;

  case 92:
#line 726 "philip.y"
                                {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = LR_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2668 "y.tab.c"
    break;

  case 93:
#line 733 "philip.y"
                                  {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = GREQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2680 "y.tab.c"
    break;

  case 94:
#line 740 "philip.y"
                                  {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = LREQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2692 "y.tab.c"
    break;

  case 95:
#line 747 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2704 "y.tab.c"
    break;

  case 96:
#line 754 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = NOEQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2716 "y.tab.c"
    break;

  case 97:
#line 761 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = EQEQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2728 "y.tab.c"
    break;

  case 98:
#line 768 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2740 "y.tab.c"
    break;

  case 99:
#line 775 "philip.y"
                                    {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = ANDAN_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2752 "y.tab.c"
    break;

  case 100:
#line 782 "philip.y"
                     {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2764 "y.tab.c"
    break;

  case 101:
#line 789 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->attr.op = OROR_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2776 "y.tab.c"
    break;

  case 102:
#line 796 "philip.y"
                       {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2788 "y.tab.c"
    break;

  case 103:
#line 803 "philip.y"
                                    {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; delete yyvsp[0];
		}
#line 2798 "y.tab.c"
    break;

  case 104:
#line 808 "philip.y"
                         {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2808 "y.tab.c"
    break;

  case 105:
#line 813 "philip.y"
                                  {
			yyval = new treeNode(Index);
			yyval->first = yyvsp[-1];
			yyval->is_const = 1;
		}
#line 2818 "y.tab.c"
    break;

  case 106:
#line 818 "philip.y"
                      {
			yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->attr.op = EMPTY_;
			yyval->is_const = 1;
			if(yyvsp[0]->is_const == 0)
				yyerror("variable in const place");
		}
#line 2831 "y.tab.c"
    break;


#line 2835 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 827 "philip.y"




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


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

#include <iostream>
#include "philip.hpp"
#include <string>
using namespace std;
#define YYSTYPE treeNode *
#define YYSTYPE_IS_DECLARED
extern int yylex(void);
extern int yyparse(void);
extern int yyerror(string);
FILE *fp = NULL;
int yaccdbg = 1;

#line 84 "philip.tab.cpp"

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
#ifndef YY_YY_PHILIP_TAB_HPP_INCLUDED
# define YY_YY_PHILIP_TAB_HPP_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PHILIP_TAB_HPP_INCLUDED  */



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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

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
       0,    20,    20,    26,    31,    35,    40,    44,    48,    53,
      54,    59,    64,    64,   100,   100,   123,   128,   133,   137,
     141,   145,   150,   156,   161,   161,   193,   193,   216,   247,
     264,   269,   274,   278,   282,   287,   309,   332,   345,   345,
     369,   374,   379,   407,   425,   444,   444,   455,   455,   462,
     467,   472,   476,   480,   485,   490,   494,   498,   505,   515,
     522,   526,   530,   534,   540,   545,   550,   554,   561,   567,
     587,   598,   605,   612,   619,   626,   644,   655,   662,   669,
     676,   681,   686,   693,   700,   707,   714,   721,   728,   735,
     742,   749,   756,   763,   770,   777,   784,   791,   798,   805,
     812,   819,   824,   829,   834
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
  "$@4", "InitVals", "InitVal", "FuncDef_pre", "FuncDef", "@5",
  "FuncFParams", "FuncFParam", "Block", "@6", "$@7", "BlockItems",
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

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      70,     5,    22,    40,    47,    70,  -150,  -150,    63,  -150,
      44,  -150,  -150,    73,  -150,  -150,  -150,  -150,    23,    64,
      62,    14,    91,    68,    79,   172,   102,   105,    91,  -150,
      63,   104,   126,   109,   127,   112,  -150,  -150,    73,  -150,
      41,   172,    11,    11,    11,  -150,  -150,    52,    83,  -150,
     134,   152,   130,  -150,  -150,   139,  -150,   137,  -150,     5,
     158,   144,  -150,    94,   172,  -150,   146,   148,  -150,   146,
    -150,  -150,  -150,   172,   172,   172,   172,   172,  -150,    24,
    -150,  -150,   152,    65,   145,   150,   104,  -150,   123,  -150,
    -150,   158,  -150,   151,   162,   156,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,   159,   163,  -150,   168,   170,   166,
     167,    27,  -150,  -150,  -150,   171,    65,  -150,   175,   176,
    -150,    91,  -150,  -150,   173,   177,  -150,   172,  -150,  -150,
    -150,   152,   172,   172,  -150,  -150,  -150,   179,  -150,  -150,
    -150,   172,  -150,  -150,   158,  -150,  -150,   178,    -2,   101,
     180,   186,  -150,   187,  -150,   182,  -150,   138,   172,   172,
     172,   172,   172,   172,   172,   172,   138,  -150,   202,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   138,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     4,     6,     0,     7,
       0,     5,     9,     0,    36,    35,     1,     2,    29,     0,
      23,     0,    14,     0,    11,     0,     0,    28,   102,    21,
       0,     0,     0,     0,    41,     0,    12,     8,     0,    73,
      70,     0,     0,     0,     0,    72,    74,    85,    88,   104,
       0,     0,     0,   101,    22,    45,    37,    44,    38,     0,
       0,     0,    10,     0,     0,    69,    65,     0,    67,    70,
      77,    78,    79,     0,     0,     0,     0,     0,   103,     0,
      27,    32,     0,     0,     0,     0,     0,    40,     0,    15,
      18,     0,    76,    81,     0,     0,    64,    71,    83,    84,
      82,    87,    86,    34,     0,    31,    25,     0,     0,     0,
       0,     0,    55,    51,    56,     0,    50,    52,     0,    72,
      48,    43,    39,    20,     0,    17,    13,     0,    75,    66,
      33,     0,     0,     0,    61,    60,    62,     0,    46,    49,
      54,     0,    42,    19,     0,    80,    30,     0,    93,    96,
      98,   100,    68,     0,    63,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    57,    92,
      91,    89,    90,    95,    94,    97,    99,    59,     0,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,   206,  -150,   -76,  -150,     1,   174,  -150,  -150,  -150,
      69,   -54,  -150,   184,  -150,  -150,  -150,    84,   -41,  -150,
    -150,  -150,   157,  -150,   -27,  -150,  -150,   103,  -150,  -149,
     154,  -150,   -40,    85,   -78,    61,  -150,    90,    36,   -25,
    -140,   -42,    57,    58,   -19,  -150,   197
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    23,    24,    61,    35,
     124,   125,     9,    19,    20,    52,    26,   104,   105,    10,
      11,    86,    33,    34,   114,    83,    84,   115,   116,   117,
      65,    66,   118,   147,    45,    46,    47,    94,    48,    68,
     149,   150,   151,   152,    27,    28,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    67,    13,    36,    56,   119,    89,   113,   168,    53,
      80,    81,   158,   159,    39,    69,    12,   177,   169,   170,
     171,   172,    32,    93,    95,    12,    14,    39,    40,   179,
      39,    40,    41,   160,   161,    49,    31,   126,   119,    81,
     113,   106,    81,   -26,    15,    41,    25,    16,    41,    79,
     103,   101,   102,    42,    43,   136,    42,    43,    44,   122,
      32,    44,    63,    49,    64,    21,    49,    18,    39,    40,
     107,   137,   108,   109,   110,     1,    12,    22,   111,   119,
       1,     2,     3,    73,    74,    75,    41,    93,   119,    30,
      55,    81,    29,   112,    42,    43,    37,    39,    40,    44,
     119,   155,   142,    70,    71,    72,    38,   148,   148,    98,
      99,   100,    76,    77,    25,    41,    92,   162,   163,    49,
     173,   174,    51,    42,    43,   -24,    39,    40,    44,    55,
      57,    58,    60,   148,   148,   148,   148,   148,   148,   148,
     148,    39,    40,   107,    41,   108,   109,   110,    88,   123,
      82,   111,    42,    43,    59,    39,    40,    44,    78,    41,
      85,    39,    40,    55,    91,   -47,   112,    42,    43,    64,
      97,   120,    44,    41,   121,    39,    40,    79,   127,    41,
     129,    42,    43,    88,   128,   130,    44,    42,    43,   132,
     131,   133,    44,    41,   134,   135,   141,   138,   164,   143,
     157,    42,    43,   140,   144,   165,    44,   154,   178,   166,
     167,    17,    62,   156,    54,   146,    87,   145,   153,   139,
      96,   175,    50,   176
};

static const yytype_uint8 yycheck[] =
{
      25,    41,     1,    22,    31,    83,    60,    83,   157,    28,
      51,    51,    14,    15,     3,     4,    11,   166,   158,   159,
     160,   161,    21,    63,    64,    11,     4,     3,     4,   178,
       3,     4,    21,    35,    36,    60,    22,    91,   116,    79,
     116,    82,    82,    20,     4,    21,    23,     0,    21,    25,
      26,    76,    77,    29,    30,    28,    29,    30,    34,    86,
      59,    34,    21,    88,    23,    21,    91,     4,     3,     4,
       5,   111,     7,     8,     9,    10,    11,     4,    13,   157,
      10,    11,    12,    31,    32,    33,    21,   127,   166,    27,
      25,   131,    28,    28,    29,    30,    28,     3,     4,    34,
     178,   141,   121,    42,    43,    44,    27,   132,   133,    73,
      74,    75,    29,    30,    23,    21,    22,    16,    17,   144,
     162,   163,    20,    29,    30,    20,     3,     4,    34,    25,
       4,    22,    20,   158,   159,   160,   161,   162,   163,   164,
     165,     3,     4,     5,    21,     7,     8,     9,    25,    26,
      20,    13,    29,    30,    27,     3,     4,    34,    24,    21,
      23,     3,     4,    25,    20,    26,    28,    29,    30,    23,
      22,    26,    34,    21,    24,     3,     4,    25,    27,    21,
      24,    29,    30,    25,    22,    26,    34,    29,    30,    21,
      27,    21,    34,    21,    28,    28,    20,    26,    18,    26,
      22,    29,    30,    28,    27,    19,    34,    28,     6,    22,
      28,     5,    38,   144,    30,   131,    59,   127,   133,   116,
      66,   164,    25,   165
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    11,    12,    38,    39,    40,    41,    42,    49,
      56,    57,    11,    42,     4,     4,     0,    38,     4,    50,
      51,    21,     4,    43,    44,    23,    53,    81,    82,    28,
      27,    22,    42,    59,    60,    46,    81,    28,    27,     3,
       4,    21,    29,    30,    34,    71,    72,    73,    75,    76,
      83,    20,    52,    81,    50,    25,    61,     4,    22,    27,
      20,    45,    43,    21,    23,    67,    68,    69,    76,     4,
      72,    72,    72,    31,    32,    33,    29,    30,    24,    25,
      55,    69,    20,    62,    63,    23,    58,    59,    25,    48,
      83,    20,    22,    69,    74,    69,    67,    22,    75,    75,
      75,    76,    76,    26,    54,    55,    55,     5,     7,     8,
       9,    13,    28,    40,    61,    64,    65,    66,    69,    71,
      26,    24,    61,    26,    47,    48,    48,    27,    22,    24,
      26,    27,    21,    21,    28,    28,    28,    69,    26,    64,
      28,    20,    81,    26,    27,    74,    54,    70,    76,    77,
      78,    79,    80,    70,    28,    69,    47,    22,    14,    15,
      35,    36,    16,    17,    18,    19,    22,    28,    66,    77,
      77,    77,    77,    78,    78,    79,    80,    66,     6,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      43,    43,    45,    44,    46,    44,    47,    47,    48,    48,
      48,    49,    50,    50,    52,    51,    53,    51,    51,    51,
      54,    54,    55,    55,    55,    56,    56,    57,    58,    57,
      59,    59,    60,    60,    60,    62,    61,    63,    61,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    69,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     0,     5,     0,     4,     3,     1,     1,     3,
       2,     3,     3,     1,     0,     5,     0,     4,     2,     1,
       3,     1,     1,     3,     2,     2,     2,     4,     0,     6,
       3,     1,     5,     4,     2,     0,     4,     0,     3,     2,
       1,     1,     1,     4,     2,     1,     1,     5,     7,     5,
       2,     2,     2,     3,     2,     1,     3,     1,     1,     2,
       1,     3,     1,     1,     1,     4,     3,     2,     2,     2,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     2,     1,     3,     1
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
#line 20 "philip.y"
                                   {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; delete yyvsp[0];
			root = yyval; //?????will it work?
		}
#line 1485 "philip.tab.cpp"
    break;

  case 3:
#line 26 "philip.y"
                         {
			yyvsp[0]->last = NULL;
			yyval = new treeNode();
			yyval->first = yyvsp[0];
		}
#line 1495 "philip.tab.cpp"
    break;

  case 4:
#line 31 "philip.y"
                     {
			yyval = new treeNode(CompilUnit);
			yyval->first = yyvsp[0]->first; delete yyvsp[0];
		}
#line 1504 "philip.tab.cpp"
    break;

  case 5:
#line 35 "philip.y"
                       {
			yyval = new treeNode(CompilUnit);
			yyval->first = yyvsp[0];
		}
#line 1513 "philip.tab.cpp"
    break;

  case 6:
#line 40 "philip.y"
                          {
			yyval = new treeNode();
			yyval->first = yyvsp[0];
		}
#line 1522 "philip.tab.cpp"
    break;

  case 7:
#line 44 "philip.y"
                        {
			yyval = new treeNode();
			yyval->first = yyvsp[0];
		}
#line 1531 "philip.tab.cpp"
    break;

  case 8:
#line 48 "philip.y"
                                          {
			yyval = new treeNode(Declarate);
			yyval->is_const = 1;
			yyval->first = yyvsp[-2];
		}
#line 1541 "philip.tab.cpp"
    break;

  case 10:
#line 54 "philip.y"
                                        {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 1551 "philip.tab.cpp"
    break;

  case 11:
#line 59 "philip.y"
                        {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1561 "philip.tab.cpp"
    break;

  case 12:
#line 64 "philip.y"
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
#line 1590 "philip.tab.cpp"
    break;

  case 13:
#line 87 "philip.y"
                                 {
			//error if the size is wrong
			
			
						
			//hang CEAs under IDENT as obj
			yyvsp[-4]->first = yyvsp[-3]->first; //index linked table head
			delete yyvsp[-3];
			
			yyval = new treeNode(Define);
			yyval->is_const = 1;
			yyval->first = yyvsp[-3];  yyval->last = yyvsp[-1];
		}
#line 1608 "philip.tab.cpp"
    break;

  case 14:
#line 100 "philip.y"
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
#line 1627 "philip.tab.cpp"
    break;

  case 15:
#line 113 "philip.y"
                                 {
              		//error if the size is wrong
              		if((yyvsp[0]->first)->Type != Expression ||
              			yyvsp[0]->last != NULL)
              			yyerror("vector on scaler");
              		
     			yyval = new treeNode(Define);
			yyval->is_const = 1;
			yyval->first = yyvsp[-3];  yyval->last = yyvsp[-1];
              	}
#line 1642 "philip.tab.cpp"
    break;

  case 16:
#line 123 "philip.y"
                                                {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 1652 "philip.tab.cpp"
    break;

  case 17:
#line 128 "philip.y"
                            {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1662 "philip.tab.cpp"
    break;

  case 18:
#line 133 "philip.y"
                        {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[0];
		}
#line 1671 "philip.tab.cpp"
    break;

  case 19:
#line 137 "philip.y"
                                         {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[-1];
              	}
#line 1680 "philip.tab.cpp"
    break;

  case 20:
#line 141 "philip.y"
                           {
			yyval = new treeNode(Values);
			yyval->first = NULL;
              	}
#line 1689 "philip.tab.cpp"
    break;

  case 21:
#line 145 "philip.y"
                                  {
			yyval = new treeNode(Declarate);
			yyval->is_const = 0;
			yyval->first = yyvsp[-1];
		}
#line 1699 "philip.tab.cpp"
    break;

  case 22:
#line 150 "philip.y"
                                    {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2];
			delete yyvsp[0];
		}
#line 1710 "philip.tab.cpp"
    break;

  case 23:
#line 156 "philip.y"
                      {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1720 "philip.tab.cpp"
    break;

  case 24:
#line 161 "philip.y"
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
#line 1749 "philip.tab.cpp"
    break;

  case 25:
#line 184 "philip.y"
                           {
			//hang CEAs under IDENT as obj
			yyvsp[-4]->first = yyvsp[-3]->first; //index linked table head
			delete yyvsp[-3];
			
			yyval = new treeNode(Define);
			yyval->is_const = 0;
			yyval->first = yyvsp[-4];  yyval->last = yyvsp[-1];
		}
#line 1763 "philip.tab.cpp"
    break;

  case 26:
#line 193 "philip.y"
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
#line 1782 "philip.tab.cpp"
    break;

  case 27:
#line 206 "philip.y"
                            {
              		//error if the size is wrong
              		if((yyvsp[0]->first)->Type != Expression ||
              			yyvsp[0]->last != NULL)
              			yyerror("vector on scaler");
              
			yyval = new treeNode(Define);
			yyval->is_const = 0;
			yyval->first = yyvsp[-3];  yyval->last = yyvsp[-1];
		}
#line 1797 "philip.tab.cpp"
    break;

  case 28:
#line 216 "philip.y"
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
#line 1833 "philip.tab.cpp"
    break;

  case 29:
#line 247 "philip.y"
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
#line 1855 "philip.tab.cpp"
    break;

  case 30:
#line 264 "philip.y"
                                      {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 1865 "philip.tab.cpp"
    break;

  case 31:
#line 269 "philip.y"
                       {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 1875 "philip.tab.cpp"
    break;

  case 32:
#line 274 "philip.y"
                   {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[0];
		}
#line 1884 "philip.tab.cpp"
    break;

  case 33:
#line 278 "philip.y"
                                    {
			yyval = new treeNode(Values);
			yyval->first = yyvsp[-1];
              	}
#line 1893 "philip.tab.cpp"
    break;

  case 34:
#line 282 "philip.y"
                           {
			yyval = new treeNode(Values);
			yyval->first = NULL;
              	}
#line 1902 "philip.tab.cpp"
    break;

  case 35:
#line 287 "philip.y"
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
			SymTab[SymCnt].modify(N,voidFunc,0,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
			++currentSymStack;
			
			yyval = new treeNode();
			yyval->attr.idx = currentSym;
			delete yyvsp[0];
		}
#line 1929 "philip.tab.cpp"
    break;

  case 36:
#line 309 "philip.y"
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
			SymTab[SymCnt].modify(N,intFunc,0,!R);
			SymStack[currentSymStack] = 1;
			yyvsp[0]->attr.idx = currentSym;
			
			++currentSymStack;
			
			yyval = new treeNode();
			yyval->attr.idx = currentSym;
			delete yyvsp[0];
              	}
#line 1956 "philip.tab.cpp"
    break;

  case 37:
#line 332 "philip.y"
                                          {
			
			yyval = new treeNode(FuncDef);
			yyval->first = NULL;
			yyval->last = yyvsp[0];
			yyval->attr.idx = currentSym;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;

			delete yyvsp[-3];
		}
#line 1974 "philip.tab.cpp"
    break;

  case 38:
#line 345 "philip.y"
                                                {
              		//check how many parameters are there for me
              		int paraCnt = 0;
              		treeNode * pointer = yyvsp[-1]->first;
              		while(pointer != NULL){
              			++paraCnt;
              			pointer = pointer->last;
              		}
              		SymTab[yyvsp[-3]->attr.idx].szCnt = paraCnt;
              		
              	}
#line 1990 "philip.tab.cpp"
    break;

  case 39:
#line 355 "philip.y"
                        {
			
              		yyval = new treeNode(FuncDef);
			yyval->first = yyvsp[-3]->first; delete yyvsp[-3];
			yyval->last = yyvsp[-1];
			yyval->attr.idx = currentSym;
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
			
			delete yyvsp[-5];
              	}
#line 2008 "philip.tab.cpp"
    break;

  case 40:
#line 369 "philip.y"
                                            {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 2018 "philip.tab.cpp"
    break;

  case 41:
#line 374 "philip.y"
                          {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2028 "philip.tab.cpp"
    break;

  case 42:
#line 379 "philip.y"
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
			SymTab[SymCnt].modify(N,0,0,!R,sszCnt,ssz,1);
			SymStack[currentSymStack] = 1;
			yyvsp[-3]->attr.idx = currentSym;
			
			yyval = new treeNode(ParaDefine);
			yyval->is_ptr = 1;
			yyval->first = yyvsp[0];
			yyval->attr.idx = currentSym;
		}
#line 2061 "philip.tab.cpp"
    break;

  case 43:
#line 407 "philip.y"
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
              		yyval->is_ptr = 1;
              		yyval->first = NULL;
              		yyval->attr.idx = currentSym;
              	}
#line 2084 "philip.tab.cpp"
    break;

  case 44:
#line 425 "philip.y"
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
              		yyval->is_ptr = 0;
              		yyval->first = NULL;
              		yyval->attr.idx = currentSym;
              	}
#line 2107 "philip.tab.cpp"
    break;

  case 45:
#line 444 "philip.y"
                      { ++currentSymStack; }
#line 2113 "philip.tab.cpp"
    break;

  case 46:
#line 444 "philip.y"
                                                             {
			yyval = new treeNode();
			yyval->first = yyvsp[-2]->first;
			delete yyvsp[-2];
			
			
			
			if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
		}
#line 2129 "philip.tab.cpp"
    break;

  case 47:
#line 455 "philip.y"
                      { ++currentSymStack; }
#line 2135 "philip.tab.cpp"
    break;

  case 48:
#line 455 "philip.y"
                                                  {
              		yyval = new treeNode();
              		yyval->first = NULL; //same as above to avoid conflict
              		if(SymStack[currentSymStack] == 1)
				currentSym = step_out();
			--currentSymStack;
              	}
#line 2147 "philip.tab.cpp"
    break;

  case 49:
#line 462 "philip.y"
                                    {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; delete yyvsp[0];
		}
#line 2157 "philip.tab.cpp"
    break;

  case 50:
#line 467 "philip.y"
                         {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2167 "philip.tab.cpp"
    break;

  case 51:
#line 472 "philip.y"
                    {
			yyval = new treeNode();
			yyval->first = yyvsp[0]->first; delete yyvsp[0];
		}
#line 2176 "philip.tab.cpp"
    break;

  case 52:
#line 476 "philip.y"
                    {
	      		yyval = new treeNode();
	      		yyval->first = yyvsp[0];
	      	}
#line 2185 "philip.tab.cpp"
    break;

  case 53:
#line 480 "philip.y"
                                {
			yyval = new treeNode(Assignment);
			yyval->first = yyvsp[-3];
			yyval->last = yyvsp[-1];
		}
#line 2195 "philip.tab.cpp"
    break;

  case 54:
#line 485 "philip.y"
                        {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-1];
              		yyval->op = EMPTY_;
              	}
#line 2205 "philip.tab.cpp"
    break;

  case 55:
#line 490 "philip.y"
                    {
              		yyval = new treeNode();
              		yyval->first = NULL; yyval->last = NULL;
              	}
#line 2214 "philip.tab.cpp"
    break;

  case 56:
#line 494 "philip.y"
                     {
              		yyval = new treeNode(StmtBlock);
              		yyval->first = yyvsp[0]->first; delete yyvsp[0];
              	}
#line 2223 "philip.tab.cpp"
    break;

  case 57:
#line 498 "philip.y"
                                    {
              		yyval = new treeNode(If);
              		yyval->first = yyvsp[-2];
              		yyval->last = yyvsp[0];
              		yyval->end_if = labelCnt++;
              		yyval->begin_true = labelCnt++; 
              	}
#line 2235 "philip.tab.cpp"
    break;

  case 58:
#line 505 "philip.y"
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
#line 2250 "philip.tab.cpp"
    break;

  case 59:
#line 515 "philip.y"
                                       {
              		yyval = new treeNode(Loop);
              		yyval->first = yyvsp[-2];
              		yyval->last = yyvsp[0];
              		yyval->end_loop = labelCnt++;
              		yyval->begin_loop = labelCnt++;
		}
#line 2262 "philip.tab.cpp"
    break;

  case 60:
#line 522 "philip.y"
                          {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_break;
              	}
#line 2271 "philip.tab.cpp"
    break;

  case 61:
#line 526 "philip.y"
                             {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_contin;
              	}
#line 2280 "philip.tab.cpp"
    break;

  case 62:
#line 530 "philip.y"
                           {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_return;
              	}
#line 2289 "philip.tab.cpp"
    break;

  case 63:
#line 534 "philip.y"
                               {
              		yyval = new treeNode(Branch);
              		yyval->b_type = b_return;
              		yyval->last = yyvsp[-1];
              	}
#line 2299 "philip.tab.cpp"
    break;

  case 64:
#line 540 "philip.y"
                          {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; delete yyvsp[0];
		}
#line 2309 "philip.tab.cpp"
    break;

  case 65:
#line 545 "philip.y"
                    {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2319 "philip.tab.cpp"
    break;

  case 66:
#line 550 "philip.y"
                             {
			yyval = new treeNode(Index);
			yyval->first = yyvsp[-1];
		}
#line 2328 "philip.tab.cpp"
    break;

  case 67:
#line 554 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2340 "philip.tab.cpp"
    break;

  case 68:
#line 561 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
              	}
#line 2351 "philip.tab.cpp"
    break;

  case 69:
#line 567 "philip.y"
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
#line 2376 "philip.tab.cpp"
    break;

  case 70:
#line 587 "philip.y"
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
#line 2392 "philip.tab.cpp"
    break;

  case 71:
#line 598 "philip.y"
                           {
			yyval = new treeNode(Expression);
			yyval->first = yyvsp[-1];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[-1]->is_const;
		}
#line 2404 "philip.tab.cpp"
    break;

  case 72:
#line 605 "philip.y"
                    {
              		yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2416 "philip.tab.cpp"
    break;

  case 73:
#line 612 "philip.y"
                         {
              		yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = 1;
              	}
#line 2428 "philip.tab.cpp"
    break;

  case 74:
#line 619 "philip.y"
                          {
			yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2440 "philip.tab.cpp"
    break;

  case 75:
#line 626 "philip.y"
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
#line 2463 "philip.tab.cpp"
    break;

  case 76:
#line 644 "philip.y"
                             {
              
              		yyval = new treeNode(FuncCall);
              		char *N = strdup(yyvsp[-2]->attr.n);
              		int res = lookup(N,0,1);
              		if( res == -1 ) yyerror("no such function");
              		if( SymTab[res].szCnt != 0) yyerror("para fault");
              		
              		yyval->first = NULL;
              		yyval->is_const = 0;
              	}
#line 2479 "philip.tab.cpp"
    break;

  case 77:
#line 655 "philip.y"
                              {
			yyval = new treeNode(Expression);
			yyval->first = NULL;
			yyval->op = ADD_;
			yyval->last = yyvsp[0];
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2491 "philip.tab.cpp"
    break;

  case 78:
#line 662 "philip.y"
                              {
			yyval = new treeNode(Expression);
			yyval->first = NULL;
			yyval->op = SUB_;
			yyval->last = yyvsp[0];
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2503 "philip.tab.cpp"
    break;

  case 79:
#line 669 "philip.y"
                              {
			yyval = new treeNode(Expression);
			yyval->first = NULL;
			yyval->op = NO_;
			yyval->last = yyvsp[0];
			yyval->is_const = yyvsp[0]->is_const;
		}
#line 2515 "philip.tab.cpp"
    break;

  case 80:
#line 676 "philip.y"
                                     {
			yyvsp[-2]->last = yyvsp[0]->first;
			yyval = new treeNode(Argument);
			yyval->first = yyvsp[-2]; delete yyvsp[0];
		}
#line 2525 "philip.tab.cpp"
    break;

  case 81:
#line 681 "philip.y"
                   {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode(Argument);
              		yyval->first = yyvsp[0];
              	}
#line 2535 "philip.tab.cpp"
    break;

  case 82:
#line 686 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = MOD_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2547 "philip.tab.cpp"
    break;

  case 83:
#line 693 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = MUL_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2559 "philip.tab.cpp"
    break;

  case 84:
#line 700 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = DIV_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2571 "philip.tab.cpp"
    break;

  case 85:
#line 707 "philip.y"
                        {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2583 "philip.tab.cpp"
    break;

  case 86:
#line 714 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = SUB_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2595 "philip.tab.cpp"
    break;

  case 87:
#line 721 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = ADD_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2607 "philip.tab.cpp"
    break;

  case 88:
#line 728 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2619 "philip.tab.cpp"
    break;

  case 89:
#line 735 "philip.y"
                                {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = GR_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2631 "philip.tab.cpp"
    break;

  case 90:
#line 742 "philip.y"
                                {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = LR_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2643 "philip.tab.cpp"
    break;

  case 91:
#line 749 "philip.y"
                                  {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = GREQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2655 "philip.tab.cpp"
    break;

  case 92:
#line 756 "philip.y"
                                  {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = LREQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2667 "philip.tab.cpp"
    break;

  case 93:
#line 763 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2679 "philip.tab.cpp"
    break;

  case 94:
#line 770 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = NOEQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2691 "philip.tab.cpp"
    break;

  case 95:
#line 777 "philip.y"
                                 {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = EQEQ_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2703 "philip.tab.cpp"
    break;

  case 96:
#line 784 "philip.y"
                      {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2715 "philip.tab.cpp"
    break;

  case 97:
#line 791 "philip.y"
                                    {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = ANDAN_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2727 "philip.tab.cpp"
    break;

  case 98:
#line 798 "philip.y"
                     {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2739 "philip.tab.cpp"
    break;

  case 99:
#line 805 "philip.y"
                                   {
			yyval = new treeNode(Expression);
              		yyval->first = yyvsp[-2];
              		yyval->op = OROR_;
              		yyval->last = yyvsp[0];
              		yyval->is_const = yyvsp[-2]->is_const && yyvsp[0]->is_const;
		}
#line 2751 "philip.tab.cpp"
    break;

  case 100:
#line 812 "philip.y"
                       {
              		yyval = new treeNode(Expression);
              		yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->last = NULL;
			yyval->is_const = yyvsp[0]->is_const;
              	}
#line 2763 "philip.tab.cpp"
    break;

  case 101:
#line 819 "philip.y"
                                    {
			yyvsp[-1]->last = yyvsp[0]->first;
			yyval = new treeNode();
			yyval->first = yyvsp[-1]; delete yyvsp[0];
		}
#line 2773 "philip.tab.cpp"
    break;

  case 102:
#line 824 "philip.y"
                         {
              		yyvsp[0]->last = NULL;
              		yyval = new treeNode();
              		yyval->first = yyvsp[0];
              	}
#line 2783 "philip.tab.cpp"
    break;

  case 103:
#line 829 "philip.y"
                                  {
			yyval = new treeNode(Index);
			yyval->first = yyvsp[-1];
			yyval->is_const = 1;
		}
#line 2793 "philip.tab.cpp"
    break;

  case 104:
#line 834 "philip.y"
                      {
			yyval = new treeNode(Expression);
			yyval->first = yyvsp[0];
			yyval->op = EMPTY_;
			yyval->is_const = 1;
			if(yyvsp[0]->is_const == 0)
				yyerror("variable in const place");
		}
#line 2806 "philip.tab.cpp"
    break;


#line 2810 "philip.tab.cpp"

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
#line 843 "philip.y"


int main(){
  fp = fopen("./output.txt","w+"); fprintf(fp,"testing\n");
  treeNode *root = NULL;
  initSymTab();
  yyparse(&root);
  if(root == NULL) yyerror("yyparse error: didn't return a root");
  if(yaccdbg) dbgprt(root,0);
  generate(root);
  
  fclose(fp);
  return 0;
}

int yyerror(string msg){
  printf("Error encountered:");
  cout << msg << endl; return 0;
}


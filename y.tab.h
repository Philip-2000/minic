/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    VAR = 266,
    INT = 267,
    VOID = 268,
    RETURN = 269,
    LREQ = 270,
    GREQ = 271,
    EQEQ = 272,
    NOEQ = 273,
    ANDAND = 274,
    OROR = 275,
    EQ = 276,
    BRA = 277,
    KET = 278,
    BRAA = 279,
    KETT = 280,
    BRAAA = 281,
    KETTT = 282,
    COMMA = 283,
    SEMI = 284,
    ADD = 285,
    SUB = 286,
    MUL = 287,
    DIV = 288,
    MOD = 289,
    NO = 290,
    GR = 291,
    LR = 292
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
#define VAR 266
#define INT 267
#define VOID 268
#define RETURN 269
#define LREQ 270
#define GREQ 271
#define EQEQ 272
#define NOEQ 273
#define ANDAND 274
#define OROR 275
#define EQ 276
#define BRA 277
#define KET 278
#define BRAA 279
#define KETT 280
#define BRAAA 281
#define KETTT 282
#define COMMA 283
#define SEMI 284
#define ADD 285
#define SUB 286
#define MUL 287
#define DIV 288
#define MOD 289
#define NO 290
#define GR 291
#define LR 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

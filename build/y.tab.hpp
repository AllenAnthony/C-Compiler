/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IVAL = 258,
     CVAL = 259,
     FVAL = 260,
     SVAL = 261,
     INT = 262,
     FLOAT = 263,
     CHAR = 264,
     ID = 265,
     LP = 266,
     RP = 267,
     LCB = 268,
     RCB = 269,
     LSB = 270,
     RSB = 271,
     SEMI = 272,
     COMMA = 273,
     COLON = 274,
     PRINT = 275,
     IF = 276,
     ELSE = 277,
     WHILE = 278,
     FOR = 279,
     BREAK = 280,
     RETURN = 281,
     ASSIGN = 282,
     SWITCH = 283,
     CONTINUE = 284,
     CASE = 285,
     DEFAULT = 286,
     SIZEOF = 287,
     PLUS = 288,
     MINUS = 289,
     MUL = 290,
     DIV = 291,
     MOD = 292,
     AND = 293,
     OR = 294,
     NOT = 295,
     NE = 296,
     EQ = 297,
     GE = 298,
     LE = 299,
     GT = 300,
     LT = 301
   };
#endif
/* Tokens.  */
#define IVAL 258
#define CVAL 259
#define FVAL 260
#define SVAL 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define ID 265
#define LP 266
#define RP 267
#define LCB 268
#define RCB 269
#define LSB 270
#define RSB 271
#define SEMI 272
#define COMMA 273
#define COLON 274
#define PRINT 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define FOR 279
#define BREAK 280
#define RETURN 281
#define ASSIGN 282
#define SWITCH 283
#define CONTINUE 284
#define CASE 285
#define DEFAULT 286
#define SIZEOF 287
#define PLUS 288
#define MINUS 289
#define MUL 290
#define DIV 291
#define MOD 292
#define AND 293
#define OR 294
#define NOT 295
#define NE 296
#define EQ 297
#define GE 298
#define LE 299
#define GT 300
#define LT 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 5 "c.y"
{
    char cval;
    int ival;
    float fval;
    char* sval;
}
/* Line 1529 of yacc.c.  */
#line 148 "/Users/yanhaopeng/ClionProjects/C-compiler/build/y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


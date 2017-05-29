
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     ID_D = 265,
     ID_E = 266,
     LP = 267,
     RP = 268,
     LCB = 269,
     RCB = 270,
     LSB = 271,
     RSB = 272,
     SEMI = 273,
     COMMA = 274,
     COLON = 275,
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
     GE = 296,
     LE = 297,
     NE = 298,
     EQ = 299,
     GT = 300,
     LT = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 7 "c.y"

    char cval;
    int ival;
    float fval;
    char *sval;
    ABS_Exp exp;
    ABS_Dec dec;
    ABS_Type type;
    ABS_Init_Dec init_dec;
    ABS_Init_Dec_List init_dec_list;
    ABS_Stmt stmt;
    ABS_Block_Item_List block_item_list_func;
    ABS_Block_Item block_item_func;
    ABS_Unit unit; 
    ABS_Ex_Dec ex_dec;
    ABS_Func_Def func_def;
    ABS_Param_List param_list;
    ABS_Param_Dec param_dec;
    ABS_Dec_List dec_list;
    _ABS_ID id;



/* Line 1676 of yacc.c  */
#line 122 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



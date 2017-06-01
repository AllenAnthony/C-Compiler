
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
     ID = 261,
     INT = 262,
     FLOAT = 263,
     CHAR = 264,
     LP = 265,
     RP = 266,
     LCB = 267,
     RCB = 268,
     LSB = 269,
     RSB = 270,
     SEMI = 271,
     COMMA = 272,
     COLON = 273,
     PRINT = 274,
     IF = 275,
     ELSE = 276,
     WHILE = 277,
     FOR = 278,
     BREAK = 279,
     RETURN = 280,
     ASSIGN = 281,
     SWITCH = 282,
     CONTINUE = 283,
     CASE = 284,
     DEFAULT = 285,
     SIZEOF = 286,
     PLUS = 287,
     MINUS = 288,
     MUL = 289,
     DIV = 290,
     MOD = 291,
     AND = 292,
     OR = 293,
     NOT = 294,
     NE = 295,
     EQ = 296,
     GE = 297,
     LE = 298,
     GT = 299,
     LT = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 9 "c.y"

    char cval;
    int ival;
    float fval;
    char* sval;
    ABS_expression_list expression_list;
    ABS_expression expression;
    ABS_assignment_expression assignment_expression;
    ABS_primary_expression primary_expression;
    ABS_constant constant;
    ABS_function_invoking function_invoking;
    ABS_argue_list argue_list;
    ABS_compound_expression compound_expression;
    ABS_declaration_list declaration_list;
    ABS_declaration declaration;
    ABS_specifier specifier;
    ABS_init_declarator_list init_declarator_list;
    ABS_init_declarator init_declarator;
    ABS_statement_list statement_list;
    ABS_statement statement;
    ABS_block_statement block_statement;
    ABS_expression_statement expression_statement;
    ABS_selection_statement selection_statement;
    ABS_iteration_statement iteration_statement;
    ABS_jump_statement jump_statement;
    ABS_program program;
    ABS_function_definition_list function_definition_list;
    ABS_function_definition function_definition;
    ABS_parameter_list parameter_list;
    ABS_parameter parameter;



/* Line 1676 of yacc.c  */
#line 131 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



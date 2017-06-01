
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "c.y"

#include "util.hpp"
#include "abs.hpp"
#include "symbol.hpp"
#include "sement.hpp"
ABS_program ABS_root;


/* Line 189 of yacc.c  */
#line 82 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 197 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 209 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    13,    17,    24,    26,
      28,    32,    34,    36,    38,    40,    45,    48,    52,    54,
      58,    62,    66,    70,    74,    78,    82,    86,    90,    94,
      98,   102,   106,   108,   111,   114,   116,   118,   120,   123,
     127,   129,   133,   135,   138,   140,   142,   144,   146,   148,
     153,   156,   161,   165,   169,   171,   174,   182,   188,   196,
     199,   202,   205,   207,   209,   212,   214,   217,   223,   229,
     232,   236
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      67,     0,    -1,    48,    -1,    47,    17,    48,    -1,    49,
      -1,    54,    -1,     6,    26,    54,    -1,     6,    14,    54,
      15,    26,    54,    -1,     6,    -1,    51,    -1,    10,    54,
      11,    -1,    52,    -1,     3,    -1,     5,    -1,     4,    -1,
       6,    53,    11,    16,    -1,    10,     6,    -1,    53,    17,
       6,    -1,    50,    -1,    54,    34,    50,    -1,    54,    35,
      50,    -1,    54,    36,    50,    -1,    54,    32,    50,    -1,
      54,    33,    50,    -1,    54,    45,    50,    -1,    54,    44,
      50,    -1,    54,    43,    50,    -1,    54,    42,    50,    -1,
      54,    41,    50,    -1,    54,    40,    50,    -1,    54,    37,
      50,    -1,    54,    38,    50,    -1,    56,    -1,    55,    56,
      -1,    57,    58,    -1,     7,    -1,     8,    -1,     9,    -1,
      59,    16,    -1,    59,    17,    58,    -1,     6,    -1,     6,
      26,    51,    -1,    61,    -1,    60,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    19,    10,
      54,    11,    -1,    12,    13,    -1,    12,    55,    60,    13,
      -1,    12,    55,    13,    -1,    12,    60,    13,    -1,    16,
      -1,    47,    16,    -1,    20,    10,    47,    11,    61,    21,
      61,    -1,    22,    10,    47,    11,    61,    -1,    23,    10,
      63,    63,    47,    11,    61,    -1,    28,    16,    -1,    24,
      16,    -1,    25,    63,    -1,    68,    -1,    69,    -1,    55,
      69,    -1,    70,    -1,    69,    70,    -1,    57,     6,    10,
      11,    62,    -1,    57,     6,    71,    11,    62,    -1,    10,
      72,    -1,    71,    17,    72,    -1,    57,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    89,    93,    94,    98,    99,   103,   104,
     105,   106,   110,   111,   112,   116,   120,   121,   125,   127,
     128,   129,   131,   132,   134,   135,   136,   137,   139,   140,
     142,   144,   148,   149,   153,   157,   158,   159,   163,   164,
     168,   169,   173,   174,   178,   179,   180,   181,   182,   183,
     187,   188,   189,   190,   194,   195,   199,   203,   204,   208,
     209,   210,   214,   218,   219,   223,   224,   228,   229,   233,
     234,   237
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IVAL", "CVAL", "FVAL", "ID", "INT",
  "FLOAT", "CHAR", "LP", "RP", "LCB", "RCB", "LSB", "RSB", "SEMI", "COMMA",
  "COLON", "PRINT", "IF", "ELSE", "WHILE", "FOR", "BREAK", "RETURN",
  "ASSIGN", "SWITCH", "CONTINUE", "CASE", "DEFAULT", "SIZEOF", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "AND", "OR", "NOT", "NE", "EQ", "GE", "LE",
  "GT", "LT", "$accept", "expression_list", "expression",
  "assignment_expression", "primary_expression", "constant",
  "function_invoking", "argue_list", "compound_expression",
  "declaration_list", "declaration", "type_specifier",
  "init_declarator_list", "init_declarator", "statement_list", "statement",
  "block_statement", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "compiler", "program",
  "function_definition_list", "function_definition", "parameter_list",
  "parameter", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    51,    51,    51,    52,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    63,    63,    64,    65,    65,    66,
      66,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     3,     6,     1,     1,
       3,     1,     1,     1,     1,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     2,     1,     1,     1,     2,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     4,
       2,     4,     3,     3,     1,     2,     7,     5,     7,     2,
       2,     2,     1,     1,     2,     1,     2,     5,     5,     2,
       3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,    36,    37,     0,    32,     0,     0,    62,    63,
      65,    33,    64,    40,    34,     0,     1,     0,    66,     0,
       0,     0,    38,     0,     0,     0,     0,    69,    12,    14,
      13,    41,     0,     0,    40,    39,     0,    67,    71,    68,
      70,     8,     0,    50,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     4,    18,     9,    11,     5,     0,
       0,     0,    42,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     8,     0,     0,     0,     0,     0,    60,    61,
      59,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,    53,    43,
      16,     0,     6,     0,     0,    10,     0,     0,     0,     0,
       3,    22,    23,    19,    20,    21,    30,    31,    29,    28,
      27,    26,    25,    24,    51,     0,    15,    17,    49,     0,
       0,     0,     0,     0,    57,     0,     7,     0,     0,    56,
      58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    52,    53,    54,    55,    56,    57,    71,    58,     4,
       5,     6,    14,    15,    61,    62,    63,    64,    65,    66,
      67,     7,     8,     9,    10,    21,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
      27,   -73,   -73,   -73,    27,   -73,     5,    13,   -73,    27,
     -73,   -73,    27,     0,   -73,   109,   -73,     9,   -73,   218,
      50,    41,   -73,    16,    35,    11,    62,   -73,   -73,   -73,
     -73,   -73,    11,    27,    55,   -73,   108,   -73,   -73,   -73,
     -73,    -2,    61,   -73,   -73,    66,    72,    94,   135,   132,
      15,   136,   118,   -73,   -73,   -73,   -73,   -73,   209,   134,
      16,   160,   -73,   -73,   -73,   -73,   -73,   -73,   145,    61,
      61,    46,   158,     6,    61,    69,    69,    15,   -73,   -73,
     -73,   -73,    69,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,   -73,   186,   -73,   -73,
     -73,    65,   209,   144,   163,   -73,    51,   112,   138,    15,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   148,   -73,   -73,   -73,   212,
     212,    69,    61,   154,   -73,   150,   209,   212,   212,   -73,
     -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -72,    89,   -73,   172,   157,   -73,   -73,   -42,   142,
       1,    -3,   164,   -73,   122,   -60,   -18,   -48,   -73,   -73,
     -73,   -73,   -73,   182,   110,   -73,   161
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      73,    99,    79,   107,   108,    11,    17,    37,    68,    17,
      19,    13,    69,    16,    39,    24,    26,   105,    28,    29,
      30,    41,    34,    36,    70,    42,    20,   101,   102,   109,
      26,    44,   106,    60,     1,     2,     3,    99,    83,    84,
      85,    86,    87,    88,    89,    19,    90,    91,    92,    93,
      94,    95,    32,    28,    29,    30,    60,   103,    33,   135,
      11,   131,   128,   104,    28,    29,    30,    72,    38,   133,
     134,    42,    28,    29,    30,    41,    74,   139,   140,    42,
     125,    20,    75,    83,    84,    85,    86,    87,    88,    89,
     136,    90,    91,    92,    93,    94,    95,    83,    84,    85,
      86,    87,    88,    89,    76,    90,    91,    92,    93,    94,
      95,    28,    29,    30,    41,     1,     2,     3,    42,    18,
      36,    43,    18,   129,    44,    22,    23,    45,    46,    82,
      47,    48,    49,    50,    81,    82,    51,    28,    29,    30,
      41,     1,     2,     3,    42,    77,    36,    96,    78,   130,
      44,   100,    80,    45,    46,    82,    47,    48,    49,    50,
     126,   138,    51,    28,    29,    30,    41,    82,    68,   127,
      42,   110,    36,    98,   132,   137,    44,    31,    59,    45,
      46,    97,    47,    48,    49,    50,    12,    35,    51,    28,
      29,    30,    41,     0,    40,     0,    42,     0,    36,   124,
       0,     0,    44,     0,     0,    45,    46,     0,    47,    48,
      49,    50,     0,     0,    51,    28,    29,    30,    41,     0,
       0,     0,    42,     0,    36,     1,     2,     3,    44,    25,
       0,    45,    46,     0,    47,    48,    49,    50,     0,     0,
      51,    83,    84,    85,    86,    87,    88,    89,     0,    90,
      91,    92,    93,    94,    95,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123
};

static const yytype_int16 yycheck[] =
{
      42,    61,    50,    75,    76,     4,     9,    25,    10,    12,
      10,     6,    14,     0,    32,     6,    19,    11,     3,     4,
       5,     6,     6,    12,    26,    10,    26,    69,    70,    77,
      33,    16,    74,    36,     7,     8,     9,    97,    32,    33,
      34,    35,    36,    37,    38,    10,    40,    41,    42,    43,
      44,    45,    11,     3,     4,     5,    59,    11,    17,   131,
      59,   109,    11,    17,     3,     4,     5,     6,     6,   129,
     130,    10,     3,     4,     5,     6,    10,   137,   138,    10,
      15,    26,    10,    32,    33,    34,    35,    36,    37,    38,
     132,    40,    41,    42,    43,    44,    45,    32,    33,    34,
      35,    36,    37,    38,    10,    40,    41,    42,    43,    44,
      45,     3,     4,     5,     6,     7,     8,     9,    10,     9,
      12,    13,    12,    11,    16,    16,    17,    19,    20,    17,
      22,    23,    24,    25,    16,    17,    28,     3,     4,     5,
       6,     7,     8,     9,    10,    10,    12,    13,    16,    11,
      16,     6,    16,    19,    20,    17,    22,    23,    24,    25,
      16,    11,    28,     3,     4,     5,     6,    17,    10,     6,
      10,    82,    12,    13,    26,    21,    16,    20,    36,    19,
      20,    59,    22,    23,    24,    25,     4,    23,    28,     3,
       4,     5,     6,    -1,    33,    -1,    10,    -1,    12,    13,
      -1,    -1,    16,    -1,    -1,    19,    20,    -1,    22,    23,
      24,    25,    -1,    -1,    28,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    12,     7,     8,     9,    16,    11,
      -1,    19,    20,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    55,    56,    57,    67,    68,    69,
      70,    56,    69,     6,    58,    59,     0,    57,    70,    10,
      26,    71,    16,    17,     6,    11,    57,    72,     3,     4,
       5,    51,    11,    17,     6,    58,    12,    62,     6,    62,
      72,     6,    10,    13,    16,    19,    20,    22,    23,    24,
      25,    28,    47,    48,    49,    50,    51,    52,    54,    55,
      57,    60,    61,    62,    63,    64,    65,    66,    10,    14,
      26,    53,     6,    54,    10,    10,    10,    10,    16,    63,
      16,    16,    17,    32,    33,    34,    35,    36,    37,    38,
      40,    41,    42,    43,    44,    45,    13,    60,    13,    61,
       6,    54,    54,    11,    17,    11,    54,    47,    47,    63,
      48,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    13,    15,    16,     6,    11,    11,
      11,    63,    26,    61,    61,    47,    54,    21,    11,    61,
      61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 88 "c.y"
    {(yyval.expression_list) = F_ABS_expression_list(NULL, (yyvsp[(1) - (1)].expression));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 89 "c.y"
    {(yyval.expression_list) = F_ABS_expression_list((yyvsp[(1) - (3)].expression_list), (yyvsp[(3) - (3)].expression));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 93 "c.y"
    {(yyval.expression) = F_ABS_expression(ENUM_assignment_expression, (yyvsp[(1) - (1)].assignment_expression), NULL);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 94 "c.y"
    {(yyval.expression) = F_ABS_expression(ENUM_compound_expression, NULL, (yyvsp[(1) - (1)].compound_expression));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 98 "c.y"
    {(yyval.assignment_expression) = F_ABS_assignment_expression(F_ABS_ID((yyvsp[(1) - (3)].sval)), NULL, (yyvsp[(3) - (3)].compound_expression));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 99 "c.y"
    {(yyval.assignment_expression) = F_ABS_assignment_expression(F_ABS_ID((yyvsp[(1) - (6)].sval)), (yyvsp[(3) - (6)].compound_expression), (yyvsp[(6) - (6)].compound_expression));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 103 "c.y"
    {(yyval.primary_expression) = F_ABS_primary_expression(ENUM_ID, F_ABS_ID((yyvsp[(1) - (1)].sval)), NULL, NULL, NULL);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 104 "c.y"
    {(yyval.primary_expression) = F_ABS_primary_expression(ENUM_constant, NULL, (yyvsp[(1) - (1)].constant), NULL, NULL);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 105 "c.y"
    {(yyval.primary_expression) = F_ABS_primary_expression(ENUM_compound_expression, NULL, NULL, (yyvsp[(2) - (3)].compound_expression), NULL);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 106 "c.y"
    {(yyval.primary_expression) = F_ABS_primary_expression(ENUM_function_invoking, NULL, NULL, NULL, (yyvsp[(1) - (1)].function_invoking));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 110 "c.y"
    {(yyval.constant) =F_ABS_constant(ENUM_IVAL, F_ABS_IVAL((yyvsp[(1) - (1)].ival)), NULL, NULL);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 111 "c.y"
    {(yyval.constant) =F_ABS_constant(ENUM_FVAL, NULL, F_ABS_FVAL((yyvsp[(1) - (1)].fval)), NULL);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 112 "c.y"
    {(yyval.constant) =F_ABS_constant(ENUM_CVAL, NULL, NULL, F_ABS_CVAL((yyvsp[(1) - (1)].cval)));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 116 "c.y"
    {(yyval.function_invoking) = F_ABS_function_invoking(F_ABS_ID((yyvsp[(1) - (4)].sval)), (yyvsp[(2) - (4)].argue_list));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 120 "c.y"
    {(yyval.argue_list) = F_ABS_argue_list(NULL, F_ABS_ID((yyvsp[(2) - (2)].sval)));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 121 "c.y"
    {(yyval.argue_list) = F_ABS_argue_list((yyvsp[(1) - (3)].argue_list), F_ABS_ID((yyvsp[(3) - (3)].sval)));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 125 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_NONE, (yyvsp[(1) - (1)].primary_expression), NULL);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 127 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_MUL, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 128 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_DIV, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 129 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_MOD, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 131 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_PLUS, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 132 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_MINUS, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 134 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_LT, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 135 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_GT, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 136 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_LE, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 137 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_GE, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 139 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_EQ, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 140 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_NE, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 142 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_AND, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 144 "c.y"
    {(yyval.compound_expression) = F_ABS_compound_expression(ENUM_OR, (yyvsp[(3) - (3)].primary_expression), (yyvsp[(1) - (3)].compound_expression));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 148 "c.y"
    {(yyval.declaration_list) = F_ABS_declaration_list(NULL, (yyvsp[(1) - (1)].declaration));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 149 "c.y"
    {(yyval.declaration_list) = F_ABS_declaration_list((yyvsp[(1) - (2)].declaration_list), (yyvsp[(2) - (2)].declaration));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 153 "c.y"
    {(yyval.declaration) = F_ABS_declaration((yyvsp[(1) - (2)].specifier), (yyvsp[(2) - (2)].init_declarator_list));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 157 "c.y"
    {(yyval.specifier) = F_ABS_specifier(ENUM_INT);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 158 "c.y"
    {(yyval.specifier) = F_ABS_specifier(ENUM_FLOAT);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 159 "c.y"
    {(yyval.specifier) = F_ABS_specifier(ENUM_CHAR);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 163 "c.y"
    {(yyval.init_declarator_list) = F_ABS_init_declarator_list(NULL, (yyvsp[(1) - (2)].init_declarator));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 164 "c.y"
    {(yyval.init_declarator_list) = F_ABS_init_declarator_list((yyvsp[(3) - (3)].init_declarator_list), (yyvsp[(1) - (3)].init_declarator));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 168 "c.y"
    {(yyval.init_declarator) = F_ABS_init_declarator(F_ABS_ID((yyvsp[(1) - (1)].sval)), NULL);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 169 "c.y"
    {(yyval.init_declarator) = F_ABS_init_declarator(F_ABS_ID((yyvsp[(1) - (3)].sval)), (yyvsp[(3) - (3)].constant));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 173 "c.y"
    {(yyval.statement_list) = F_ABS_statement_list(NULL, (yyvsp[(1) - (1)].statement));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 174 "c.y"
    {(yyval.statement_list) = F_ABS_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 178 "c.y"
    {(yyval.statement) = F_ABS_statement(ENUM_block_statement, (yyvsp[(1) - (1)].block_statement), NULL, NULL, NULL, NULL, NULL);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 179 "c.y"
    {(yyval.statement) = F_ABS_statement(ENUM_expression_statement, NULL, (yyvsp[(1) - (1)].expression_statement), NULL, NULL, NULL, NULL);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 180 "c.y"
    {(yyval.statement) = F_ABS_statement(ENUM_selection_statement, NULL, NULL, (yyvsp[(1) - (1)].selection_statement), NULL, NULL, NULL);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 181 "c.y"
    {(yyval.statement) = F_ABS_statement(ENUM_iteration_statement, NULL, NULL, NULL, (yyvsp[(1) - (1)].iteration_statement), NULL, NULL);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 182 "c.y"
    {(yyval.statement) = F_ABS_statement(ENUM_jump_statement, NULL, NULL, NULL, NULL, (yyvsp[(1) - (1)].jump_statement), NULL);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 183 "c.y"
    {(yyval.statement) = F_ABS_statement(ENUM_compound_expression, NULL, NULL, NULL, NULL, NULL, (yyvsp[(3) - (4)].compound_expression));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 187 "c.y"
    {(yyval.block_statement) = F_ABS_block_statement(NULL, NULL);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 188 "c.y"
    {(yyval.block_statement) = F_ABS_block_statement((yyvsp[(2) - (4)].declaration_list), (yyvsp[(3) - (4)].statement_list));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 189 "c.y"
    {(yyval.block_statement) = F_ABS_block_statement((yyvsp[(2) - (3)].declaration_list), NULL);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 190 "c.y"
    {(yyval.block_statement) = F_ABS_block_statement(NULL, (yyvsp[(2) - (3)].statement_list));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 194 "c.y"
    {(yyval.expression_statement) = F_ABS_expression_statement(NULL);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 195 "c.y"
    {(yyval.expression_statement) = F_ABS_expression_statement((yyvsp[(1) - (2)].expression_list));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 199 "c.y"
    {(yyval.selection_statement) = F_ABS_selection_statement((yyvsp[(3) - (7)].expression_list), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 203 "c.y"
    {(yyval.iteration_statement) = F_ABS_iteration_statement((yyvsp[(3) - (5)].expression_list), NULL, NULL, NULL, (yyvsp[(5) - (5)].statement));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 204 "c.y"
    {(yyval.iteration_statement) = F_ABS_iteration_statement(NULL, (yyvsp[(3) - (7)].expression_statement), (yyvsp[(4) - (7)].expression_statement), (yyvsp[(5) - (7)].expression_list), (yyvsp[(7) - (7)].statement));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 208 "c.y"
    {(yyval.jump_statement)=F_ABS_jump_statement(ENUM_CONTINUE, NULL);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 209 "c.y"
    {(yyval.jump_statement)=F_ABS_jump_statement(ENUM_BREAK, NULL);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 210 "c.y"
    {(yyval.jump_statement)=F_ABS_jump_statement(ENUM_RETURN, (yyvsp[(2) - (2)].expression_statement));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 214 "c.y"
    {ABS_root=(yyvsp[(1) - (1)].program); cout<<2333<<endl;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 218 "c.y"
    {(yyval.program)=F_ABS_program(NULL, (yyvsp[(1) - (1)].function_definition_list));}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 219 "c.y"
    {(yyval.program)=F_ABS_program((yyvsp[(1) - (2)].declaration_list), (yyvsp[(2) - (2)].function_definition_list));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 223 "c.y"
    {(yyval.function_definition_list)=F_ABS_function_definition_list(NULL, (yyvsp[(1) - (1)].function_definition));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 224 "c.y"
    {(yyval.function_definition_list)=F_ABS_function_definition_list((yyvsp[(1) - (2)].function_definition_list), (yyvsp[(2) - (2)].function_definition));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 228 "c.y"
    {(yyval.function_definition)=F_ABS_function_definition((yyvsp[(1) - (5)].specifier), F_ABS_ID((yyvsp[(2) - (5)].sval)), NULL, (yyvsp[(5) - (5)].block_statement));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 229 "c.y"
    {(yyval.function_definition)=F_ABS_function_definition((yyvsp[(1) - (5)].specifier), F_ABS_ID((yyvsp[(2) - (5)].sval)), (yyvsp[(3) - (5)].parameter_list), (yyvsp[(5) - (5)].block_statement));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 233 "c.y"
    {(yyval.parameter_list)=F_ABS_parameter_list(NULL, (yyvsp[(2) - (2)].parameter));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 234 "c.y"
    {(yyval.parameter_list)=F_ABS_parameter_list((yyvsp[(1) - (3)].parameter_list), (yyvsp[(3) - (3)].parameter));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 237 "c.y"
    {(yyval.parameter)=F_ABS_parameter((yyvsp[(1) - (2)].specifier), F_ABS_ID((yyvsp[(2) - (2)].sval)));;}
    break;



/* Line 1455 of yacc.c  */
#line 2046 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 240 "c.y"


int main(){
    yyparse();
    SEM_program(ABS_root);
    return 0;
}


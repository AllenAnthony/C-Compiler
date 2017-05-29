
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

#include "util.h"
#include "abs.h"
ABS_Root root;


/* Line 189 of yacc.c  */
#line 80 "y.tab.c"

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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 186 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 198 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    15,    19,    23,    30,
      37,    39,    41,    43,    45,    49,    54,    56,    60,    64,
      68,    70,    74,    78,    80,    84,    88,    92,    96,    98,
     102,   106,   108,   112,   114,   118,   122,   124,   126,   128,
     130,   134,   136,   138,   140,   142,   144,   146,   149,   153,
     155,   158,   160,   162,   164,   167,   175,   181,   189,   192,
     195,   198,   202,   204,   206,   209,   211,   213,   221,   228,
     230,   234,   237,   239
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    49,    -1,    56,    -1,    48,    19,    49,
      -1,    48,    19,    56,    -1,    11,    27,    56,    -1,    11,
      27,    49,    -1,    11,    16,    48,    17,    27,    56,    -1,
      11,    16,    48,    17,    27,    49,    -1,    11,    -1,     3,
      -1,     5,    -1,     4,    -1,    12,    48,    13,    -1,    32,
      12,    58,    13,    -1,    50,    -1,    51,    35,    50,    -1,
      51,    36,    50,    -1,    51,    37,    50,    -1,    51,    -1,
      52,    33,    51,    -1,    52,    34,    51,    -1,    52,    -1,
      53,    46,    52,    -1,    53,    45,    52,    -1,    53,    42,
      52,    -1,    53,    41,    52,    -1,    53,    -1,    54,    44,
      53,    -1,    54,    43,    53,    -1,    54,    -1,    55,    38,
      54,    -1,    55,    -1,    56,    39,    55,    -1,    58,    59,
      18,    -1,     7,    -1,     8,    -1,     9,    -1,    60,    -1,
      59,    19,    60,    -1,    10,    -1,    62,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,    14,    15,    -1,    14,
      63,    15,    -1,    64,    -1,    63,    64,    -1,    57,    -1,
      61,    -1,    18,    -1,    48,    18,    -1,    21,    12,    48,
      13,    61,    22,    61,    -1,    23,    12,    48,    13,    61,
      -1,    24,    12,    65,    65,    48,    13,    61,    -1,    29,
      18,    -1,    25,    18,    -1,    26,    18,    -1,    26,    48,
      18,    -1,    70,    -1,    71,    -1,    70,    71,    -1,    72,
      -1,    57,    -1,    58,    10,    12,    73,    13,    75,    62,
      -1,    58,    10,    12,    73,    13,    62,    -1,    74,    -1,
      73,    19,    74,    -1,    58,    10,    -1,    57,    -1,    75,
      57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    63,    64,    65,    69,    70,    71,    72,
      76,    77,    78,    79,    80,    81,    85,    86,    87,    88,
      92,    93,    94,    98,    99,   100,   101,   102,   106,   107,
     108,   112,   113,   117,   118,   122,   127,   128,   129,   133,
     134,   138,   142,   143,   144,   145,   146,   150,   151,   155,
     156,   160,   161,   165,   166,   170,   174,   175,   179,   180,
     181,   182,   186,   190,   191,   195,   196,   200,   201,   205,
     206,   210,   214,   215
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IVAL", "CVAL", "FVAL", "SVAL", "INT",
  "FLOAT", "CHAR", "ID_D", "ID_E", "LP", "RP", "LCB", "RCB", "LSB", "RSB",
  "SEMI", "COMMA", "COLON", "IF", "ELSE", "WHILE", "FOR", "BREAK",
  "RETURN", "ASSIGN", "SWITCH", "CONTINUE", "CASE", "DEFAULT", "SIZEOF",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "AND", "OR", "NOT", "GE", "LE",
  "NE", "EQ", "GT", "LT", "$accept", "expression", "assignment_expression",
  "primary_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "declaration", "type_specifier",
  "init_declarator_list", "init_declarator", "statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "translation_unit", "external_declaration",
  "function_definition", "parameter_list", "parameter_declaration",
  "declaration_list", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    49,    49,    49,    49,
      50,    50,    50,    50,    50,    50,    51,    51,    51,    51,
      52,    52,    52,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    56,    56,    57,    58,    58,    58,    59,
      59,    60,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     3,     3,     3,     6,     6,
       1,     1,     1,     1,     3,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       2,     1,     1,     1,     2,     7,     5,     7,     2,     2,
       2,     3,     1,     1,     2,     1,     1,     7,     6,     1,
       3,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    36,    37,    38,    66,     0,     0,    62,    63,    65,
      41,     0,    39,     1,    64,     0,    35,     0,     0,     0,
      69,    41,    40,    71,     0,     0,     0,    72,     0,    68,
       0,    70,    11,    13,    12,    10,     0,    47,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     2,    16,    20,
      23,    28,    31,    33,     3,    51,    52,    42,     0,    49,
      43,    44,    45,    46,    73,    67,     0,     0,     0,     0,
       0,     0,    59,    60,     0,    58,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    50,     0,     7,     6,    14,     0,     0,
       0,    61,     0,     4,     5,    10,    17,    18,    19,    21,
      22,    27,    26,    25,    24,    30,    29,    32,    34,     0,
       0,     0,     0,    15,     0,     0,    56,     0,     9,     8,
       0,     0,    55,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       4,    28,    11,    12,    56,    57,    58,    59,    60,    61,
      62,    63,     6,     7,     8,     9,    19,    20,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int16 yypact[] =
{
     150,   -66,   -66,   -66,   -66,     7,    12,   150,   -66,   -66,
      30,    65,   -66,   -66,   -66,   150,   -66,    35,    39,    -8,
     -66,   -66,   -66,   -66,   131,   150,    32,   -66,    35,   -66,
     131,   -66,   -66,   -66,   -66,     2,    16,   -66,   -66,    42,
      50,    54,    52,    98,    63,    92,    73,   -66,   -66,   125,
      88,   105,   123,    57,    72,   -66,   -66,   -66,    64,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    16,    16,    -4,    16,
      16,   124,   -66,   -66,   130,   -66,   150,   -66,    16,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,   -66,   -66,    46,   -66,    72,   -66,    61,    81,
     124,   -66,   101,   -66,    72,   -66,   -66,   -66,   -66,   125,
     125,    88,    88,    88,    88,   105,   105,   123,    57,    97,
      94,    94,    16,   -66,    16,   110,   -66,   112,   -66,    72,
      94,    94,   -66,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -36,   -65,    84,    86,    68,    82,    47,    85,   -64,
     -20,     1,   -66,   155,    13,    83,   -66,   115,   -49,   -66,
     -66,   -66,   -66,   -66,   134,   -66,   -66,   149,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      68,     5,    95,    96,    27,    24,    55,    74,     5,    97,
      64,    25,    13,   103,   104,    78,    18,    10,    66,    32,
      33,    34,   100,    32,    33,    34,    18,    35,    36,    67,
      94,   105,    36,    98,    99,    32,    33,    34,    55,     1,
       2,     3,    15,    35,    36,    21,    26,    37,    45,    23,
      38,   122,    45,    39,    69,    40,    41,    42,    43,   128,
     129,    44,    70,   119,    45,    78,    71,    32,    33,    34,
      72,     1,     2,     3,   120,    35,    36,   102,    26,    92,
      78,    75,    38,    16,    17,    39,   127,    40,    41,    42,
      43,    77,    78,    44,   121,    90,    45,    32,    33,    34,
      78,    32,    33,    34,    76,    35,    36,    29,    26,    35,
      36,    91,    38,    65,   123,    39,    73,    40,    41,    42,
      43,    82,    83,    44,   124,   131,    45,    32,    33,    34,
      45,    78,   130,   125,   126,    35,    36,   117,     1,     2,
       3,    14,    38,   132,   133,    26,    84,    85,   101,    78,
      86,    87,   111,   112,   113,   114,    45,     1,     2,     3,
      79,    80,    81,   106,   107,   108,    88,    89,   109,   110,
     115,   116,    22,    93,    31,     0,   118
};

static const yytype_int16 yycheck[] =
{
      36,     0,    67,    67,    24,    13,    26,    43,     7,    13,
      30,    19,     0,    78,    78,    19,    15,    10,    16,     3,
       4,     5,    71,     3,     4,     5,    25,    11,    12,    27,
      66,    11,    12,    69,    70,     3,     4,     5,    58,     7,
       8,     9,    12,    11,    12,    10,    14,    15,    32,    10,
      18,   100,    32,    21,    12,    23,    24,    25,    26,   124,
     124,    29,    12,    17,    32,    19,    12,     3,     4,     5,
      18,     7,     8,     9,    13,    11,    12,    76,    14,    15,
      19,    18,    18,    18,    19,    21,   122,    23,    24,    25,
      26,    18,    19,    29,    13,    38,    32,     3,     4,     5,
      19,     3,     4,     5,    12,    11,    12,    24,    14,    11,
      12,    39,    18,    30,    13,    21,    18,    23,    24,    25,
      26,    33,    34,    29,    27,    13,    32,     3,     4,     5,
      32,    19,    22,   120,   121,    11,    12,    90,     7,     8,
       9,     7,    18,   130,   131,    14,    41,    42,    18,    19,
      45,    46,    84,    85,    86,    87,    32,     7,     8,     9,
      35,    36,    37,    79,    80,    81,    43,    44,    82,    83,
      88,    89,    17,    58,    25,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    57,    58,    69,    70,    71,    72,
      10,    59,    60,     0,    71,    12,    18,    19,    58,    73,
      74,    10,    60,    10,    13,    19,    14,    57,    58,    62,
      75,    74,     3,     4,     5,    11,    12,    15,    18,    21,
      23,    24,    25,    26,    29,    32,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    61,    62,    63,    64,
      65,    66,    67,    68,    57,    62,    16,    27,    48,    12,
      12,    12,    18,    18,    48,    18,    12,    18,    19,    35,
      36,    37,    33,    34,    41,    42,    45,    46,    43,    44,
      38,    39,    15,    64,    48,    49,    56,    13,    48,    48,
      65,    18,    58,    49,    56,    11,    50,    50,    50,    51,
      51,    52,    52,    52,    52,    53,    53,    54,    55,    17,
      13,    13,    65,    13,    27,    61,    61,    48,    49,    56,
      22,    13,    61,    61
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
#line 62 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_expression, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 63 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_expression, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 64 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_expression, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 65 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_expression, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 69 "c.y"
    {(yyval.exp) = ABS_Assignment_Expression(ABS_assignment, 1, (yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp), NULL);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 70 "c.y"
    {(yyval.exp) = ABS_Assignment_Expression(ABS_assignment, 1, (yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].exp), NULL);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 71 "c.y"
    {(yyval.exp) = ABS_Assignment_Expression(ABS_assignment, 2, (yyvsp[(1) - (6)].id), (yyvsp[(3) - (6)].exp), (yyvsp[(6) - (6)].exp));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 72 "c.y"
    {(yyval.exp) = ABS_Assignment_Expression(ABS_assignment, 2, (yyvsp[(1) - (6)].id), (yyvsp[(3) - (6)].exp), (yyvsp[(6) - (6)].exp));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 76 "c.y"
    {(yyval.exp) = ABS_Primary_Expression(ABS_primary, 1, (int)(yyvsp[(1) - (1)].id));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 77 "c.y"
    {(yyval.exp) = ABS_Primary_Expression(ABS_primary, 2, (yyvsp[(1) - (1)].ival));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 78 "c.y"
    {(yyval.exp) = ABS_Primary_Expression(ABS_primary, 3, (int)(yyvsp[(1) - (1)].fval));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 79 "c.y"
    {(yyval.exp) = ABS_Primary_Expression(ABS_primary, 4, (int)(yyvsp[(1) - (1)].cval));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 80 "c.y"
    {(yyval.exp) = ABS_Primary_Expression(ABS_primary, 5, (int)(yyvsp[(2) - (3)].exp));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 81 "c.y"
    {(yyval.exp) = ABS_Primary_Expression(ABS_primary, 6, (int)(yyvsp[(3) - (4)].type));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 85 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_multiplicative, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 86 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_multiplicative, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 87 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_multiplicative, 3, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 88 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_multiplicative, 4, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 92 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_additive, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 93 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_additive, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 94 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_additive, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 98 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_relational, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 99 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_relational, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 100 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_relational, 3, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 101 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_relational, 4, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 102 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_relational, 5, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 106 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_equality, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 107 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_equality, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 108 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_equality, 3, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 112 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_logical_and, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 113 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_logical_and, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 117 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_logical_or, 1, (yyvsp[(1) - (1)].exp), NULL);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 118 "c.y"
    {(yyval.exp) = ABS_Expression(ABS_logical_or, 2, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 122 "c.y"
    {(yyval.dec) = ABS_Declaration((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].init_dec_list));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 127 "c.y"
    {(yyval.type) = ABS_Type_Specifier(ABS_INT);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 128 "c.y"
    {(yyval.type) = ABS_Type_Specifier(ABS_FLOAT);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 129 "c.y"
    {(yyval.type) = ABS_Type_Specifier(ABS_CHAR);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 133 "c.y"
    {(yyval.init_dec_list) = ABS_Init_Declarator_List(1, (yyvsp[(1) - (1)].init_dec), NULL);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 134 "c.y"
    {(yyval.init_dec_list) = ABS_Init_Declarator_List(2, (yyvsp[(3) - (3)].init_dec), (yyvsp[(1) - (3)].init_dec_list));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 138 "c.y"
    {(yyval.init_dec) = ABS_Init_Declarator((yyvsp[(1) - (1)].id));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 142 "c.y"
    {(yyval.stmt) = ABS_Statement(ABS_statement, (yyvsp[(1) - (1)].stmt));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 143 "c.y"
    {(yyval.stmt) = ABS_Statement(ABS_statement, (yyvsp[(1) - (1)].stmt));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 144 "c.y"
    {(yyval.stmt) = ABS_Statement(ABS_statement, (yyvsp[(1) - (1)].stmt));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 145 "c.y"
    {(yyval.stmt) = ABS_Statement(ABS_statement, (yyvsp[(1) - (1)].stmt));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 146 "c.y"
    {(yyval.stmt) = ABS_Statement(ABS_statement, (yyvsp[(1) - (1)].stmt));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 150 "c.y"
    {(yyval.stmt) = ABS_Compound(ABS_compound, 1, NULL);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 151 "c.y"
    {(yyval.stmt) = ABS_Compound(ABS_compound, 2, (yyvsp[(2) - (3)].block_item_list_func));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 155 "c.y"
    {(yyval.block_item_list_func) = ABS_Block_Item_List_Func(1, NULL, (yyvsp[(1) - (1)].block_item_func));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 156 "c.y"
    {(yyval.block_item_list_func) = ABS_Block_Item_List_Func(2, (yyvsp[(1) - (2)].block_item_list_func), (yyvsp[(2) - (2)].block_item_func));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 160 "c.y"
    {(yyval.block_item_func) = ABS_Block_Item_Func(1, (yyvsp[(1) - (1)].dec), NULL);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 161 "c.y"
    {(yyval.block_item_func) = ABS_Block_Item_Func(2, NULL, (yyvsp[(1) - (1)].stmt));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 165 "c.y"
    {(yyval.stmt) = ABS_Expression_Statement(ABS_expression_statement, 1, NULL);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 166 "c.y"
    {(yyval.stmt) = ABS_Expression_Statement(ABS_expression_statement, 2, (yyvsp[(1) - (2)].exp));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 170 "c.y"
    {(yyval.stmt) = ABS_Selection(ABS_selection, (yyvsp[(3) - (7)].exp), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 174 "c.y"
    {(yyval.stmt) = ABS_Iteration(ABS_iteration, 1, (yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].stmt), NULL, NULL);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 175 "c.y"
    {(yyval.stmt) = ABS_Iteration(ABS_iteration, 2, (yyvsp[(5) - (7)].exp), (yyvsp[(3) - (7)].stmt), (yyvsp[(4) - (7)].stmt), (yyvsp[(7) - (7)].stmt));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 179 "c.y"
    {(yyval.stmt) = ABS_Jump(ABS_jump, 1, NULL);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 180 "c.y"
    {(yyval.stmt) = ABS_Jump(ABS_jump, 2, NULL);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 181 "c.y"
    {(yyval.stmt) = ABS_Jump(ABS_jump, 3, NULL);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 182 "c.y"
    {(yyval.stmt) = ABS_Jump(ABS_jump, 4, (yyvsp[(2) - (3)].exp));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 186 "c.y"
    {root = (yyvsp[(1) - (1)].unit);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 190 "c.y"
    {(yyval.unit) = ABS_Translation_Unit(1, (yyvsp[(1) - (1)].ex_dec), NULL);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 191 "c.y"
    {(yyval.unit) = ABS_Translation_Unit(2, (yyvsp[(2) - (2)].ex_dec), (yyvsp[(1) - (2)].unit));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 195 "c.y"
    {(yyval.ex_dec) = ABS_External_Declaration(1, (yyvsp[(1) - (1)].func_def), NULL);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 196 "c.y"
    {(yyval.ex_dec) = ABS_External_Declaration(2, NULL, (yyvsp[(1) - (1)].dec));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 200 "c.y"
    {(yyval.func_def) = ABS_Function_Definition(1, (yyvsp[(1) - (7)].type), (yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].param_list), (yyvsp[(6) - (7)].dec_list), (yyvsp[(7) - (7)].stmt));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 201 "c.y"
    {(yyval.func_def) = ABS_Function_Definition(2, (yyvsp[(1) - (6)].type), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].param_list), NULL, (yyvsp[(6) - (6)].stmt));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 205 "c.y"
    {(yyval.param_list) = ABS_Parameter_List(1, NULL, (yyvsp[(1) - (1)].param_dec));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 206 "c.y"
    {(yyval.param_list) = ABS_Parameter_List(2, (yyvsp[(3) - (3)].param_dec), (yyvsp[(1) - (3)].param_list));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 210 "c.y"
    {(yyval.param_dec) = ABS_Parameter_Declaration((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].id));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 214 "c.y"
    {(yyval.dec_list) = ABS_Declaration_List(1, (yyvsp[(1) - (1)].dec), NULL);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 215 "c.y"
    {(yyval.dec_list) = ABS_Declaration_List(1, (yyvsp[(2) - (2)].dec), (yyvsp[(1) - (2)].dec_list));;}
    break;



/* Line 1455 of yacc.c  */
#line 2030 "y.tab.c"
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
#line 218 "c.y"


int main(){
    yyparse();

    return 0;
}


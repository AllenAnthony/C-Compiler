%{
#include <cstdlib>
#include <cstdio>
#include "util.hpp"
#include "abs.hpp"
#include "semant.hpp"
#include "function.hpp"

ABS_program ABS_root;


SymbolTable* curr_env;
FuncTable* curr_func;
int func_depth;
extern FILE* yyin;

vector<int> iter_label_head;
vector<int> iter_label_tail;

int curr_iter_label_head = 0;
int curr_iter_label_tail = 0;
int curr_iter_label_count = 0;

%}

%union{
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
}

%token <ival> IVAL
%token <cval> CVAL
%token <fval> FVAL
%token <sval> ID
%type <expression_list> expression_list
%type <expression> expression
%type <assignment_expression> assignment_expression
%type <primary_expression> primary_expression
%type <constant> constant
%type <function_invoking> function_invoking
%type <argue_list> argue_list
%type <compound_expression> compound_expression
%type <declaration_list> declaration_list
%type <declaration> declaration
%type <specifier> type_specifier
%type <init_declarator_list> init_declarator_list
%type <init_declarator> init_declarator
%type <statement_list> statement_list
%type <statement> statement
%type <block_statement> block_statement
%type <expression_statement> expression_statement
%type <selection_statement> selection_statement
%type <iteration_statement> iteration_statement
%type <jump_statement> jump_statement
%type <program> program
%type <function_definition_list> function_definition_list
%type <function_definition> function_definition
%type <parameter_list> parameter_list
%type <parameter> parameter

%token INT FLOAT CHAR

%token LP RP LCB RCB LSB RSB SEMI COMMA COLON PRINT
%token IF ELSE WHILE FOR BREAK RETURN ASSIGN SWITCH CONTINUE CASE DEFAULT SIZEOF
%token PLUS MINUS MUL DIV MOD AND OR NOT

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left MUL DIV MOD

%start compiler
%%

expression_list
    : expression {$$ = F_ABS_expression_list(NULL, $1);}
    | expression_list COMMA expression {$$ = F_ABS_expression_list($1, $3);}
;

expression
    : assignment_expression {$$ = F_ABS_expression(ENUM_assignment_expression, $1, NULL);}
    | compound_expression {$$ = F_ABS_expression(ENUM_compound_expression, NULL, $1);}
;

assignment_expression
    : ID ASSIGN compound_expression {$$ = F_ABS_assignment_expression(F_ABS_ID($1), NULL, $3);}
    | ID LSB compound_expression RSB ASSIGN compound_expression {$$ = F_ABS_assignment_expression(F_ABS_ID($1), $3, $6);}
;

primary_expression
    : ID {$$ = F_ABS_primary_expression(ENUM_ID, F_ABS_ID($1), NULL, NULL, NULL);}
    | constant {$$ = F_ABS_primary_expression(ENUM_constant, NULL, $1, NULL, NULL);}
    | LP compound_expression RP {$$ = F_ABS_primary_expression(ENUM_compound_expression, NULL, NULL, $2, NULL);}
    | function_invoking {$$ = F_ABS_primary_expression(ENUM_function_invoking, NULL, NULL, NULL, $1);}
;

constant
    : IVAL {$$ =F_ABS_constant(ENUM_IVAL, F_ABS_IVAL($1), NULL, NULL);}
    | FVAL {$$ =F_ABS_constant(ENUM_FVAL, NULL, F_ABS_FVAL($1), NULL);}
    | CVAL {$$ =F_ABS_constant(ENUM_CVAL, NULL, NULL, F_ABS_CVAL($1));}
;

function_invoking
    : ID argue_list RP SEMI {$$ = F_ABS_function_invoking(F_ABS_ID($1), $2);}
;

argue_list
    : LP ID {$$ = F_ABS_argue_list(NULL, F_ABS_ID($2));}
    | argue_list COMMA ID {$$ = F_ABS_argue_list($1, F_ABS_ID($3));}
;

compound_expression
    : primary_expression {$$ = F_ABS_compound_expression(ENUM_NONE, $1, NULL); if($1 == NULL) cout << "tag2"<<endl;}

    | compound_expression MUL primary_expression {$$ = F_ABS_compound_expression(ENUM_MUL, $3, $1);}
    | compound_expression DIV primary_expression {$$ = F_ABS_compound_expression(ENUM_DIV, $3, $1);}
    | compound_expression MOD primary_expression {$$ = F_ABS_compound_expression(ENUM_MOD, $3, $1);}

    | compound_expression PLUS primary_expression {$$ = F_ABS_compound_expression(ENUM_PLUS, $3, $1);}
    | compound_expression MINUS primary_expression {$$ = F_ABS_compound_expression(ENUM_MINUS, $3, $1);}

    | compound_expression LT primary_expression {$$ = F_ABS_compound_expression(ENUM_LT, $3, $1);}
    | compound_expression GT primary_expression {$$ = F_ABS_compound_expression(ENUM_GT, $3, $1);}
    | compound_expression LE primary_expression {$$ = F_ABS_compound_expression(ENUM_LE, $3, $1);}
    | compound_expression GE primary_expression {$$ = F_ABS_compound_expression(ENUM_GE, $3, $1);}

    | compound_expression EQ primary_expression {$$ = F_ABS_compound_expression(ENUM_EQ, $3, $1);}
    | compound_expression NE primary_expression {$$ = F_ABS_compound_expression(ENUM_NE, $3, $1);}

    | compound_expression AND primary_expression {$$ = F_ABS_compound_expression(ENUM_AND, $3, $1);}

    | compound_expression OR primary_expression {$$ = F_ABS_compound_expression(ENUM_OR, $3, $1);}
;

declaration_list
    : declaration {$$ = F_ABS_declaration_list(NULL, $1);}
    | declaration_list declaration {$$ = F_ABS_declaration_list($1, $2);}
;

declaration
    : type_specifier init_declarator_list {$$ = F_ABS_declaration($1, $2);}
;

type_specifier
    : INT {$$ = F_ABS_specifier(ENUM_INT);}
    | FLOAT {$$ = F_ABS_specifier(ENUM_FLOAT);}
    | CHAR {$$ = F_ABS_specifier(ENUM_CHAR);}
;

init_declarator_list
    : init_declarator SEMI {$$ = F_ABS_init_declarator_list(NULL, $1);}
    | init_declarator COMMA init_declarator_list {$$ = F_ABS_init_declarator_list($3, $1);}
;

init_declarator
    : ID {$$ = F_ABS_init_declarator(F_ABS_ID($1), NULL);}
    | ID ASSIGN constant {$$ = F_ABS_init_declarator(F_ABS_ID($1), $3);}
;

statement_list
    : statement {$$ = F_ABS_statement_list(NULL, $1);}
    | statement_list statement {$$ = F_ABS_statement_list($1, $2);}
;

statement
    : block_statement {$$ = F_ABS_statement(ENUM_block_statement, $1, NULL, NULL, NULL, NULL, NULL);}
    | expression_statement {$$ = F_ABS_statement(ENUM_expression_statement, NULL, $1, NULL, NULL, NULL, NULL);}
    | selection_statement {$$ = F_ABS_statement(ENUM_selection_statement, NULL, NULL, $1, NULL, NULL, NULL);}
    | iteration_statement {$$ = F_ABS_statement(ENUM_iteration_statement, NULL, NULL, NULL, $1, NULL, NULL);}
    | jump_statement {$$ = F_ABS_statement(ENUM_jump_statement, NULL, NULL, NULL, NULL, $1, NULL);}
    | PRINT LP compound_expression RP {$$ = F_ABS_statement(ENUM_compound_expression, NULL, NULL, NULL, NULL, NULL, $3);}
;

block_statement
    : LCB RCB {$$ = F_ABS_block_statement(NULL, NULL);}
    | LCB declaration_list statement_list RCB {$$ = F_ABS_block_statement($2, $3);}
    | LCB declaration_list RCB {$$ = F_ABS_block_statement($2, NULL);}
    | LCB statement_list RCB {$$ = F_ABS_block_statement(NULL, $2);}
;

expression_statement
    : SEMI {$$ = F_ABS_expression_statement(NULL);}
    | expression_list SEMI {$$ = F_ABS_expression_statement($1);}
;

selection_statement
    : IF LP expression_list RP statement ELSE statement {$$ = F_ABS_selection_statement($3, $5, $7);}
;

iteration_statement
    : WHILE LP expression_list RP statement {$$ = F_ABS_iteration_statement($3, NULL, NULL, NULL, $5);}
    | FOR LP expression_statement expression_statement expression_list RP statement{$$ = F_ABS_iteration_statement(NULL, $3, $4, $5, $7);}
;

jump_statement
    : CONTINUE SEMI{$$=F_ABS_jump_statement(ENUM_CONTINUE, NULL);}
    | BREAK SEMI{$$=F_ABS_jump_statement(ENUM_BREAK, NULL);}
    | RETURN expression_statement{$$=F_ABS_jump_statement(ENUM_RETURN, $2);}
;

compiler
    :program {ABS_root=$1;}
;

program
    : function_definition_list{$$=F_ABS_program(NULL, $1)}
    | declaration_list function_definition_list{$$=F_ABS_program($1, $2);}
;

function_definition_list
    : function_definition{$$=F_ABS_function_definition_list(NULL, $1);}
    | function_definition_list function_definition{$$=F_ABS_function_definition_list($1, $2);}
;

function_definition
    : type_specifier ID LP RP block_statement{$$=F_ABS_function_definition($1, F_ABS_ID($2), NULL, $5);}
    | type_specifier ID parameter_list RP block_statement{$$=F_ABS_function_definition($1, F_ABS_ID($2), $3, $5);}
;

parameter_list
    : LP parameter{$$=F_ABS_parameter_list(NULL, $2);}
    | parameter_list COMMA parameter{$$=F_ABS_parameter_list($1, $3);}
;
parameter
    : type_specifier ID{$$=F_ABS_parameter($1, F_ABS_ID($2));}
;

%%

int main(int argc, char** argv){
    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        cout << "File " << argv[1] << " open error!" << endl;
    } else {
        cout << "File: " << argv[1] << endl;
        yyin = fp;
    }

    cout << endl << "------------Parse begin-------------" << endl;
    yyparse();
    cout << endl << "------------Parse finish-------------" << endl;

    cout << endl << "------------Semant check begin-------------" << endl;
    curr_env = new SymbolTable(10);
    curr_func= new FuncTable();
    IR_NODE IR_root = SEM_program(ABS_root);

    cout << endl << "------------Semant check finish-------------" << endl;

    return 0;
}

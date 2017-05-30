%{
#include "util.hpp"
%}

%union{
    char cval;
    int ival;
    float fval;
    char* sval;
    ABS_ID abs_id;
    ABS_IVAL abs_ival;
    ABS_FVAL abs_fval;
    ABS_CVAL abs_cval;
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
%token <sval> SVAL
%token <abs_id>
%token <abs_ival>
%token <abs_fval>
%token <abs_cval>
%token <expression_list> expression_list
%token <expression> expression
%token <assignment_expression> assignment_expression
%token <primary_expression> primary_expression
%token <constant> constant
%token <function_invoking> function_invoking
%token <argue_list> argue_list
%token <compound_expression> compound_expression
%token <declaration_list> declaration_list
%token <declaration> declaration
%token <specifier> type_specifier
%token <init_declarator_list> init_declarator_list
%token <init_declarator> init_declarator
%token <statement_list> statement_list
%token <statement> statement
%token <block_statement> block_statement
%token <expression_statement> expression_statement
%token <selection_statement> selection_statement
%token <iteration_statement> iteration_statement
%token <jump_statement> jump_statement
%token <program> program
%token <function_definition_list> function_definition_list
%token <function_definition> function_definition
%token <parameter_list> parameter_list
%token <parameter> parameter

%token INT FLOAT CHAR ID

%token LP RP LCB RCB LSB RSB SEMI COMMA COLON PRINT
%token IF ELSE WHILE FOR BREAK RETURN ASSIGN SWITCH CONTINUE CASE DEFAULT SIZEOF
%token PLUS MINUS MUL DIV MOD AND OR NOT

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left MUL DIV MOD

%start program
%%

expression_list
    : expression
    | expression_list COMMA expression
;

expression
    : assignment_expression
    | compound_expression
;

assignment_expression
    : ID ASSIGN compound_expression
    | ID LSB compound_expression RSB ASSIGN compound_expression
;

primary_expression
    : ID
    | constant
    | LP compound_expression RP
    | function_invoking
;

constant
    : IVAL
    | FVAL
    | CVAL
;

function_invoking
    : ID argue_list RP SEMI
;

argue_list
    : LP ID
    | argue_list COMMA ID
;

compound_expression
    : primary_expression

    | compound_expression MUL primary_expression
    | compound_expression DIV primary_expression
    | compound_expression MOD primary_expression

    | compound_expression PLUS primary_expression
    | compound_expression MINUS primary_expression

    | compound_expression LT primary_expression
    | compound_expression GT primary_expression
    | compound_expression LE primary_expression
    | compound_expression GE primary_expression

    | compound_expression EQ primary_expression
    | compound_expression NE primary_expression

    | compound_expression AND primary_expression

    | compound_expression OR primary_expression
;

declaration_list
    : declaration
    | declaration_list declaration
;

declaration
    : type_specifier init_declarator_list
;

type_specifier
    : INT
    | FLOAT
    | CHAR
;

init_declarator_list
    : init_declarator SEMI
    | init_declarator COMMA init_declarator_list
;

init_declarator
    : ID
    | ID ASSIGN constant
;

statement_list
    : statement
    | statement_list statement
;

statement
    : block_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | PRINT LP compound_expression RP
;


block_statement
    : LCB RCB
    | LCB declaration_list statement_list RCB
    | LCB declaration_list RCB
    | LCB statement_list RCB
;

expression_statement
    : SEMI
    | expression_list SEMI
;

selection_statement
    : IF LP expression_list RP statement ELSE statement
;

iteration_statement
    : WHILE LP expression_list RP statement
    | FOR LP expression_statement expression_statement expression_list RP statement
;

jump_statement
    : CONTINUE SEMI
    | BREAK SEMI
    | RETURN expression_statement
;

program
    : function_definition_list
    | declaration_list function_definition_list
;

function_definition_list
    : function_definition
    | function_definition_list function_definition
;

function_definition
    : type_specifier ID LP RP block_statement
    | type_specifier ID parameter_list RP block_statement
;

parameter_list
    : LP parameter
    | parameter_list COMMA parameter
;
parameter
    : type_specifier ID
;

%%

int main(){
    yyparse();
    return 0;
}

%{
#include "util.h"

%}

%union{
    char cval;
    int ival;
    float fval;
    char *sval;
}

%token <ival> INT
%token <cval> CHAR
%token <fval> FLOAT
%token <sval> ID_D ID_E

%token IVAL CVAL FVAL SVAL
%token LP RP LCB RCB LSB RSB SEMI COMMA COLON
%token IF ELSE WHILE FOR BREAK RETURN ASSIGN SWITCH CONTINUE CASE DEFAULT SIZEOF
%token PLUS MINUS MUL DIV MOD AND OR NOT
%token GE LE NE EQ GT LT

%left GE LE NE EQ GT LT
%left COMMA

%start translation_unit
%%

expression
    : assignment_expression
    | logical_or_expression
    | expression COMMA assignment_expression
    | expression COMMA logical_or_expression
;

assignment_expression
    : ID_E ASSIGN logical_or_expression
    | ID_E ASSIGN assignment_expression
    | ID_E LSB expression RSB ASSIGN logical_or_expression
    | ID_E LSB expression RSB ASSIGN assignment_expression
;

primary_expression
    : ID_E
    | IVAL
    | FVAL
    | CVAL
    | LP expression RP
    | SIZEOF LP type_specifier RP
;

multiplicative_expression
    : primary_expression
    | multiplicative_expression MUL primary_expression
    | multiplicative_expression DIV primary_expression
    | multiplicative_expression MOD primary_expression
;

additive_expression
    : multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
;

relational_expression
    : additive_expression
    | relational_expression LT additive_expression
    | relational_expression GT additive_expression
    | relational_expression LE additive_expression
    | relational_expression GE additive_expression
;

equality_expression
    : relational_expression
    | equality_expression EQ relational_expression
    | equality_expression NE relational_expression
;

logical_and_expression
    : equality_expression
    | logical_and_expression AND equality_expression
;

logical_or_expression
    : logical_and_expression
    | logical_or_expression OR logical_and_expression
;

declaration
    : type_specifier init_declarator_list SEMI
;


type_specifier
    : INT
    | FLOAT
    | CHAR
;

init_declarator_list
    : init_declarator
    | init_declarator_list COMMA init_declarator
;

init_declarator
    : ID_D
    | ID_D ASSIGN expression
;

statement
    : labeled_statement
    | compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
;

labeled_statement
    : ID_E COLON statement
    | CASE logical_or_expression COLON statement
    | DEFAULT COLON statement
;

compound_statement
    : LCB RCB
    | LCB block_item_list RCB
;

block_item_list
    : block_item
    | block_item_list block_item
;

block_item
    : declaration
    | statement
;

expression_statement
    : SEMI
| expression SEMI{
    printf("ss");
}
;

selection_statement
    : IF LP expression RP statement
    | IF LP expression RP statement ELSE statement
    | SWITCH LP expression RP statement
;

iteration_statement
    : WHILE LP expression RP statement
    | FOR LP expression_statement expression_statement expression RP statement
;

jump_statement
    : CONTINUE SEMI
    | BREAK SEMI
    | RETURN SEMI
    | RETURN expression SEMI
;

translation_unit
    : external_declaration
    | translation_unit external_declaration
;

external_declaration
    : function_definition
    | declaration
;

function_definition
    : type_specifier ID_D LP parameter_list RP declaration_list compound_statement
    | type_specifier ID_D LP parameter_list RP compound_statement
;

parameter_list
    : parameter_declaration
    | parameter_list COMMA parameter_declaration
;

parameter_declaration
    : type_specifier ID_D
;

declaration_list
    : declaration
    | declaration_list declaration
;

%%


int main(){
    yyparse();
    return 0;
}

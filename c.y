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
    : expression {$$ = ABS_express_list(NULL, $1);}
    | expression_list COMMA expression {$$ = F_ABS_express_list($1, $3);}
;

expression
    : assignment_expression {$$ = F_ABS_expression(ENUM_assignment_expression, $1);}
    | compound_expression {$$ = F_ABS_expression(ENUM_compound_expression, $1);}
;

assignment_expression
    : ID ASSIGN compound_expression {$$ = F_ABS_assignment_expression($1, NULL, $3);}
    | ID LSB compound_expression RSB ASSIGN compound_expression {$$ = F_ABS_assignment_expression($1, $3, $6);}
;

primary_expression
    : ID {$$ = F_ABS_primary_expression(ENUM_ID, $1, NULL, NULL, NULL);}
    | constant {$$ = F_ABS_primary_expression(ENUM_constant, NULL, $1, NULL, NULL);}
    | LP compound_expression RP {$$ = F_ABS_primary_expression(ENUM_compound_expression, NULL, NULL, $2, NULL);}
    | function_invoking {$$ = F_ABS_primary_expression(ENUM_function_invoking, NULL, NULL, NULL, $1);}
;

constant
    : IVAL {$$ =F_ABS_constant(ENUM_IVAL, $1, NULL, NULL);}
    | FVAL {$$ =F_ABS_constant(ENUM_FVAL, NULL, $1, NULL);}
    | CVAL {$$ =F_ABS_constant(ENUM_CVAL, NULL, NULL, $1);}
;

function_invoking
    : ID argue_list RP SEMI {$$ = F_ABS_function_invoking($1, $2);}
;

argue_list
    : LP ID {$$ = F_ABS_argue_list(NULL, $2);}
    | argue_list COMMA ID {$$ = F_ABS_argue_list($1, $3);}
;

compound_expression
    : primary_expression {$$ = F_ABS_compound_expression(ENUM_NONE, $1, NULL);}

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
    : init_declarator SEMI {$$ = F_ABS_init_declarator();}
    | init_declarator COMMA init_declarator_list {$$ = F_ABS_init_declarator();}
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

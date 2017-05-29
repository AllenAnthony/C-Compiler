%{
#include "util.h"
#include "abs.h"
ABS_Root root;
%}

%union{
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
}

%token <ival> IVAL
%token <cval> CVAL
%token <fval> FVAL
%token <sval> SVAL
%token INT FLOAT CHAR
%type <exp> expression assignment_expression primary_expression multiplicative_expression additive_expression relational_expression equality_expression logical_and_expression logical_or_expression
%type <dec> declaration
%type <type> type_specifier
%type <init_dec> init_declarator
%type <init_dec_list> init_declarator_list
%type <stmt> statement compound_statement expression_statement selection_statement iteration_statement jump_statement
%type <block_item_list_func> block_item_list
%type <block_item_func> block_item
%type <unit> translation_unit
%type <ex_dec> external_declaration
%type <func_def> function_definition
%type <param_list> parameter_list
%type <param_dec> parameter_declaration
%type <dec_list> declaration_list
%token <id> ID_D ID_E

%token LP RP LCB RCB LSB RSB SEMI COMMA COLON
%token IF ELSE WHILE FOR BREAK RETURN ASSIGN SWITCH CONTINUE CASE DEFAULT SIZEOF
%token PLUS MINUS MUL DIV MOD AND OR NOT
%token GE LE NE EQ GT LT

%left GE LE NE EQ GT LT
%left COMMA

%start program
%%

expression
    : assignment_expression {$$ = ABS_Expression(ABS_expression, 1, $1, NULL);}
    | logical_or_expression {$$ = ABS_Expression(ABS_expression, 1, $1, NULL);}
    | expression COMMA assignment_expression {$$ = ABS_Expression(ABS_expression, 2, $1, $3);}
    | expression COMMA logical_or_expression {$$ = ABS_Expression(ABS_expression, 2, $1, $3);}
;

assignment_expression
    : ID_E ASSIGN logical_or_expression {$$ = ABS_Assignment_Expression(ABS_assignment, 1, $1, $3, NULL);}
    | ID_E ASSIGN assignment_expression {$$ = ABS_Assignment_Expression(ABS_assignment, 1, $1, $3, NULL);}
    | ID_E LSB expression RSB ASSIGN logical_or_expression {$$ = ABS_Assignment_Expression(ABS_assignment, 2, $1, $3, $6);}
    | ID_E LSB expression RSB ASSIGN assignment_expression {$$ = ABS_Assignment_Expression(ABS_assignment, 2, $1, $3, $6);}
;

primary_expression
    : ID_E {$$ = ABS_Primary_Expression(ABS_primary, 1, (void *)$1);}
    | IVAL {$$ = ABS_Primary_Expression(ABS_primary, 2, (void *)&($1));}
    | FVAL {$$ = ABS_Primary_Expression(ABS_primary, 3, (void *)&($1));}
    | CVAL {$$ = ABS_Primary_Expression(ABS_primary, 4, (void *)&($1));}
    | LP expression RP {$$ = ABS_Primary_Expression(ABS_primary, 5, (void *)$2);}
    | SIZEOF LP type_specifier RP {$$ = ABS_Primary_Expression(ABS_primary, 6, (void *)$3);}
;

multiplicative_expression
    : primary_expression {$$ = ABS_Expression(ABS_multiplicative, 1, $1, NULL);}
    | multiplicative_expression MUL primary_expression {$$ = ABS_Expression(ABS_multiplicative, 2, $1, $3);}
    | multiplicative_expression DIV primary_expression {$$ = ABS_Expression(ABS_multiplicative, 3, $1, $3);}
    | multiplicative_expression MOD primary_expression {$$ = ABS_Expression(ABS_multiplicative, 4, $1, $3);}
;

additive_expression
    : multiplicative_expression {$$ = ABS_Expression(ABS_additive, 1, $1, NULL);}
    | additive_expression PLUS multiplicative_expression {$$ = ABS_Expression(ABS_additive, 2, $1, $3);}
    | additive_expression MINUS multiplicative_expression {$$ = ABS_Expression(ABS_additive, 2, $1, $3);}
;

relational_expression
    : additive_expression {$$ = ABS_Expression(ABS_relational, 1, $1, NULL);}
    | relational_expression LT additive_expression {$$ = ABS_Expression(ABS_relational, 2, $1, $3);}
    | relational_expression GT additive_expression {$$ = ABS_Expression(ABS_relational, 3, $1, $3);}
    | relational_expression LE additive_expression {$$ = ABS_Expression(ABS_relational, 4, $1, $3);}
    | relational_expression GE additive_expression {$$ = ABS_Expression(ABS_relational, 5, $1, $3);}
;

equality_expression
    : relational_expression {$$ = ABS_Expression(ABS_equality, 1, $1, NULL);}
    | equality_expression EQ relational_expression {$$ = ABS_Expression(ABS_equality, 2, $1, $3);}
    | equality_expression NE relational_expression {$$ = ABS_Expression(ABS_equality, 3, $1, $3);}
;

logical_and_expression
    : equality_expression {$$ = ABS_Expression(ABS_logical_and, 1, $1, NULL);}
    | logical_and_expression AND equality_expression {$$ = ABS_Expression(ABS_logical_and, 2, $1, $3);}
;

logical_or_expression
    : logical_and_expression {$$ = ABS_Expression(ABS_logical_or, 1, $1, NULL);}
    | logical_or_expression OR logical_and_expression {$$ = ABS_Expression(ABS_logical_or, 2, $1, $3);}
;

declaration
    : type_specifier init_declarator_list SEMI {$$ = ABS_Declaration($1, $2);}
;


type_specifier
    : INT {$$ = ABS_Type_Specifier(ABS_INT);}
    | FLOAT {$$ = ABS_Type_Specifier(ABS_FLOAT);}
    | CHAR {$$ = ABS_Type_Specifier(ABS_CHAR);}
;

init_declarator_list
    : init_declarator {$$ = ABS_Init_Declarator_List(1, $1, NULL);}
    | init_declarator_list COMMA init_declarator {$$ = ABS_Init_Declarator_List(2, $3, $1);}
;

init_declarator
    : ID_D {$$ = ABS_Init_Declarator($1);}
;

statement
    : compound_statement {$$ = ABS_Statement(ABS_statement, $1);}
    | expression_statement {$$ = ABS_Statement(ABS_statement, $1);}
    | selection_statement {$$ = ABS_Statement(ABS_statement, $1);}
    | iteration_statement {$$ = ABS_Statement(ABS_statement, $1);}
    | jump_statement {$$ = ABS_Statement(ABS_statement, $1);}
;

compound_statement
    : LCB RCB {$$ = ABS_Compound(ABS_compound, 1, NULL);}
    | LCB block_item_list RCB {$$ = ABS_Compound(ABS_compound, 2, $2);}
;

block_item_list
    : block_item {$$ = ABS_Block_Item_List_Func(1, NULL, $1);}
    | block_item_list block_item {$$ = ABS_Block_Item_List_Func(2, $1, $2);}
;

block_item
    : declaration {$$ = ABS_Block_Item_Func(1, $1, NULL);}
    | statement {$$ = ABS_Block_Item_Func(2, NULL, $1);}
;

expression_statement
    : SEMI {$$ = ABS_Expression_Statement(ABS_expression_statement, 1, NULL);}
    | expression SEMI {$$ = ABS_Expression_Statement(ABS_expression_statement, 2, $1);}
;

selection_statement
    : IF LP expression RP statement ELSE statement {$$ = ABS_Selection(ABS_selection, $3, $5, $7);}
;

iteration_statement
    : WHILE LP expression RP statement {$$ = ABS_Iteration(ABS_iteration, 1, $3, $5, NULL, NULL);}
    | FOR LP expression_statement expression_statement expression RP statement {$$ = ABS_Iteration(ABS_iteration, 2, $5, $3, $4, $7);}
;

jump_statement
    : CONTINUE SEMI {$$ = ABS_Jump(ABS_jump, 1, NULL);}
    | BREAK SEMI {$$ = ABS_Jump(ABS_jump, 2, NULL);}
    | RETURN SEMI {$$ = ABS_Jump(ABS_jump, 3, NULL);}
    | RETURN expression SEMI {$$ = ABS_Jump(ABS_jump, 4, $2);}
;
 
program
    :translation_unit {root = $1;}
    ;

translation_unit
    : external_declaration {$$ = ABS_Translation_Unit(1, $1, NULL);}
    | translation_unit external_declaration {$$ = ABS_Translation_Unit(2, $2, $1);}
;

external_declaration
    : function_definition {$$ = ABS_External_Declaration(1, $1, NULL);}
    | declaration {$$ = ABS_External_Declaration(2, NULL, $1);}
;

function_definition
    : type_specifier ID_D LP parameter_list RP declaration_list compound_statement {$$ = ABS_Function_Definition(1, $1, $2, $4, $6, $7);}
    | type_specifier ID_D LP parameter_list RP compound_statement {$$ = ABS_Function_Definition(2, $1, $2, $4, NULL, $6);}
;

parameter_list
    : parameter_declaration {$$ = ABS_Parameter_List(1, $1, NULL);}
    | parameter_list COMMA parameter_declaration {$$ = ABS_Parameter_List(2, $3, $1);}
;

parameter_declaration
    : type_specifier ID_D {$$ = ABS_Parameter_Declaration($1, $2);}
;

declaration_list
    : declaration {$$ = ABS_Declaration_List(1, $1, NULL);}
    | declaration_list declaration {$$ = ABS_Declaration_List(1, $2, $1);}
;

%%

int main(){
    yyparse();

    return 0;
}

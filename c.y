%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
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
%token <sval> ID
%token IVAL CVAL FVAL SVAL
%token LP RP LCB RCB LSB RSB SEMI COMMA IF ELSE WHILE FOR BREAK RETURN ASSIGN
%token PLUS MINUS MUL DIV MOD AND OR NOT
%token GE LE NE EQ GT LT

%left GE LE NE EQ GT LT
%left OR
%left AND
%left PLUS MINUS
%left MUL DIV MOD
%%
functions : function
          | function functions
          ;
function : type ID LP params RP LCB block RCB
         ;

declares: declare
        | declare declares
        ;

declare: type ID ASSIGN value SEMI
       ;

type : INT
     | FLOAT
     | CHAR
     ;
value: IVAL
     | FVAL
     | CVAL
     ;


params : param
       | param COMMA params
       ;
param: type ID;

block: stmts
     | declares stmts
     ;

stmts: stmt stmts
     |
     ;

stmt : ID ASSIGN exprs SEMI
     | WHILE LP expr_comp RP LCB stmts RCB
     | FOR LP expr SEMI expr_comp SEMI stmt RP LCB stmts RCB
     | IF LP RP LCB stmts RCB ELSE LCB stmts RCB
     | RETURN ID
     ;

exprs : exprs PLUS exprs
      | exprs MINUS exprs
      | exprs DIV exprs
      | exprs MUL exprs
      | expr
      ;
expr : IVAL
     | FVAL
     | CVAL
     | LP exprs RP
     | MINUS expr
     | ID
     ;
expr_comp:expr_comp AND expr_comp
    | expr_comp OR expr_comp
    | exprs GT exprs
    | exprs LT exprs
    | exprs GE exprs
    | exprs LE exprs
    | exprs EQ exprs
    | exprs NE exprs
    ;
%%

int main(){
    yyparse();
    return 0;
}

%{
#include <iostream>
#include "util.hpp"
#include "y.tab.hpp"

#define DISP_TOK std::cout<<yytext;
%}

%x CHARACTER
%x COMMENT_LINE
%x COMMENT_BLOCK

%%

"("         { DISP_TOK return LP; }
")"         { DISP_TOK return RP; }
"{"         { DISP_TOK return LCB; }
"}"         { DISP_TOK return RCB; }
"["         { DISP_TOK return LSB; }
"]"         { DISP_TOK return RSB; }
";"         { DISP_TOK return SEMI; }
","         { DISP_TOK return COMMA; }
":"         { DISP_TOK return COLON; }

"int"       { DISP_TOK return INT; }
"float"     { DISP_TOK return FLOAT;}
"char"      { DISP_TOK return CHAR; }

"if"        { DISP_TOK return IF; }
"else"      { DISP_TOK return ELSE; }
"while"     { DISP_TOK return WHILE; }
"for"       { DISP_TOK return FOR; }
"break"     { DISP_TOK return BREAK; }
"continue"  { DISP_TOK return CONTINUE; }
"switch"    { DISP_TOK return SWITCH; }
"return"    { DISP_TOK return RETURN; }

"="         { DISP_TOK return ASSIGN; }
"+"         { DISP_TOK return PLUS; }
"-"         { DISP_TOK return MINUS; }
"*"         { DISP_TOK return MUL; }
"/"         { DISP_TOK return DIV; }
"%"         { DISP_TOK return MOD; }

">="        { DISP_TOK return GE; }
"<="        { DISP_TOK return LE; }
"!="        { DISP_TOK return NE; }
"=="        { DISP_TOK return EQ; }
">"         { DISP_TOK return GT; }
"<"         { DISP_TOK return LT; }
"&&"        { DISP_TOK return AND; }
"||"        { DISP_TOK return OR; }
"!"         { DISP_TOK return NOT; }

"print"     { DISP_TOK return PRINT; }


"//"        {   /* 单行注释 */
    BEGIN COMMENT_LINE;
}
<COMMENT_LINE>{
    "\n" {
        BEGIN INITIAL;
    }
    .  {

    }
}


"/*"        {   /* 多行注释 */
    BEGIN COMMENT_BLOCK;
}

<COMMENT_BLOCK>{
    "*/" {
        BEGIN INITIAL;
    }
    .  {
        
    }
}


"'"     {   /* 匹配字符， 形如'a'、'\n' */
    BEGIN CHARACTER;
}

<CHARACTER>{
    "'" {
        BEGIN INITIAL;
    }

    "\\n" {
        yylval.cval=0x0A; DISP_TOK return CVAL;
    }

    [^\'] {
        yylval.cval=*yytext; DISP_TOK return CVAL;
    }
}

[a-zA-Z_][a-zA-Z_0-9]*	{
    yylval.sval = (char *)malloc(strlen(yytext)+1);
    strcpy(yylval.sval, yytext);
    DISP_TOK
    return ID;
}

[0-9]+	{
    yylval.fval=atoi(yytext);
    DISP_TOK
    return IVAL;
}

[0-9]+\.[0-9]+	{
    yylval.fval=atof(yytext);
    DISP_TOK
    return FVAL;
}


[ \t]	DISP_TOK

[\n]	{
    DISP_TOK;
}

.		{
    printf("\nInvalid token :%s\n", yytext);
};

%%

int yywrap(void){
    return 1;
}



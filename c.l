%{
#include "y.tab.h"
#include "util.h"
int line;
    
%}

%x CHARACTER
%x COMMENT_LINE
%x COMMENT_BLOCK
%x FUNCTION
%x EXP
%x DEC
%x CHARACTER_DEC



%%

"("         { disp_token(yytext); return LP; }
")"         { disp_token(yytext); return RP; }
"{"         { disp_token(yytext); return LCB; }
"}"         { disp_token(yytext); return RCB; }
"["         { disp_token(yytext); return LSB; }
"]"         { disp_token(yytext); return RSB; }
";"         { disp_token(yytext); return SEMI; }
","         { disp_token(yytext); return COMMA; }
":"         { disp_token(yytext); return COLON; }

"int"       {
    BEGIN DEC;
    disp_token(yytext); return INT;
}
"float"     {
    BEGIN DEC;
    disp_token(yytext); return FLOAT;
}
"char"      {
    BEGIN DEC;
    disp_token(yytext); return CHAR;
}

<DEC>{

    "int"       { disp_token(yytext); return INT; }
    "float"     { disp_token(yytext); return FLOAT; }
    "char"      { disp_token(yytext); return CHAR; }

    ";" {
        BEGIN INITIAL;
        disp_token(yytext);
        return SEMI;
    }
    "(" {
        BEGIN INITIAL;
        disp_token(yytext);
        return LP;
    }
    ")" {
        BEGIN INITIAL;
        disp_token(yytext);
        return RP;
    }
    "," {
    	disp_token(yytext);
    	return COMMA;
    }

    ([a-zA-Z_][a-zA-Z_0-9]*) {
        yylval.sval = malloc(strlen(yytext)+1);
        strcpy(yylval.sval, yytext);
        disp_token(yytext);
        return ID_D;
    }

    [ \t] disp_token(yytext);

	[\n] {
    	disp_token(yytext);
    	line++;
	}

	. {
    	printf("\nError: Syntax error\n");
        exit(0);
	};
}

"if"        { disp_token(yytext); return IF; }
"else"      { disp_token(yytext); return ELSE; }
"while"     { disp_token(yytext); return WHILE; }
"for"       { disp_token(yytext); return FOR; }
"break"     { disp_token(yytext); return BREAK; }
"continue"  { disp_token(yytext); return CONTINUE; }
"switch"    { disp_token(yytext); return SWITCH; }
"return"    { disp_token(yytext); return RETURN; }

"="         { disp_token(yytext); return ASSIGN; }
"+"         { disp_token(yytext); return PLUS; }
"-"         { disp_token(yytext); return MINUS; }
"*"         { disp_token(yytext); return MUL; }
"/"         { disp_token(yytext); return DIV; }
"%"         { disp_token(yytext); return MOD; }

">="        { disp_token(yytext); return GE; }
"<="        { disp_token(yytext); return LE; }
"!="        { disp_token(yytext); return NE; }
"=="        { disp_token(yytext); return EQ; }
">"         { disp_token(yytext); return GT; }
"<"         { disp_token(yytext); return LT; }
"&&"        { disp_token(yytext); return AND; }
"||"        { disp_token(yytext); return OR; }
"!"         { disp_token(yytext); return NOT; }


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
    "\n" {
        yylval.cval=0x0A; disp_token(yytext); return CVAL;
    }
    
    [^\'] {
        yylval.cval=*yytext; disp_token(yytext); return CVAL;
    }
}

[a-zA-Z_][a-zA-Z_0-9]*	{
    yylval.sval = malloc(strlen(yytext)+1);
    strcpy(yylval.sval, yytext);
    disp_token(yytext);
    return ID_E;
}

[0-9]+	{
    yylval.fval=atoi(yytext);
    disp_token(yytext);
    return IVAL;
}

[0-9]+\.[0-9]+	{
    yylval.fval=atof(yytext);
    disp_token(yytext);
    return FVAL;
}


[ \t]	disp_token(yytext);

[\n]	{
    disp_token(yytext);
    line++;
}

.		{
    printf("\nInvalid token :%s\n", yytext);
};

%%

int yywrap(void){
    return 1;
}



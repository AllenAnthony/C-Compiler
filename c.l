%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>

void yyerror(char *msg);
int line;

%}

%x character

%%

\(		{ return LP; }
\)		{ return RP; }
{		{ return LCB; }
}		{ return RCB; }
\[      { return LSB; }
\]		{ return RSB; }
;		{ return SEMI; }
,		{ return COMMA; }

int		{ return INT; }
float	{ return FLOAT; }
char	{ return CHAR; }
if		{ return IF; }
else	{ return ELSE; }
while	{ return WHILE; }
for		{ return FOR; }
break	{ return BREAK; }
return	{ return RETURN; }

'+'		{ return PLUS; }
'-'		{ return MINUS; }
'*'		{ return MUL; }
'\/'		{ return DIV; }
'%'		{ return MOD; }
">="	{ return GE; }
"<="	{ return LE; }
"!="	{ return NE; }
"=="	{ return EQ; }
'>'		{ return GT; }
'<'		{ return LT; }
"&&"	{ return AND; }
"||"	{ return OR; }
'!'		{ return NOT; }
'='		{ return ASSIGN; }

<character>{
\'.\' {yylval.cval=*yytext; return CVAL; }
\'\\n\' { yylval.cval=0x0A; return CVAL; }
}

[a-zA-Z_][a-zA-Z_0-9]*	{
    yylval.sval = malloc(strlen(yytext)+1);
    strcpy(yylval.sval, yytext);
    return ID;
    }
[0-9]+	{ yylval.fval=atoi(yytext); return IVAL; }
[0-9]+\.[0-9]+	{ yylval.fval=atof(yytext); return FVAL; }


[ \t]	;
[\n]	{ line++; }
.		;

%%

int yywrap(void){
	return 1;
}

void yyerror(char *msg){
    printf("Error: %s", msg);
}

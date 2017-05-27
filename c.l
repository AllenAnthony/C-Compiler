%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>

void yyerror(char *msg);
int line;

#define DEBUG
void disp_token(char *token){
#ifdef DEBUG
    printf("%s ", token);
#endif
}

%}

%x character

%%

\(		{ disp_token(yytext); return LP; }
\)		{ disp_token(yytext); return RP; }
\{		{ disp_token(yytext); return LCB; }
\}		{ disp_token(yytext); return RCB; }
\[      { disp_token(yytext); return LSB; }
\]		{ disp_token(yytext); return RSB; }
;		{ disp_token(yytext); return SEMI; }
,		{ disp_token(yytext); return COMMA; }

int		{ disp_token(yytext); return INT; }
float	{ disp_token(yytext); return FLOAT; }
char	{ disp_token(yytext); return CHAR; }
if		{ disp_token(yytext); return IF; }
else	{ disp_token(yytext); return ELSE; }
while	{ disp_token(yytext); return WHILE; }
for		{ disp_token(yytext); return FOR; }
break	{ disp_token(yytext); return BREAK; }
return	{ disp_token(yytext); return RETURN; }

=		{ disp_token(yytext); return ASSIGN; }
\+		{ disp_token(yytext); return PLUS; }
'-'		{ disp_token(yytext); return MINUS; }
'*'		{ disp_token(yytext); return MUL; }
'\/'		{ disp_token(yytext); return DIV; }
'%'		{ disp_token(yytext); return MOD; }
">="	{ disp_token(yytext); return GE; }
"<="	{ disp_token(yytext); return LE; }
"!="	{ disp_token(yytext); return NE; }
"=="	{ disp_token(yytext); return EQ; }
'>'		{ disp_token(yytext); return GT; }
'<'		{ disp_token(yytext); return LT; }
"&&"	{ disp_token(yytext); return AND; }
"||"	{ disp_token(yytext); return OR; }
'!'		{ disp_token(yytext); return NOT; }


<character>{
\'.\' {yylval.cval=*yytext; disp_token(yytext); return CVAL; }
\'\\n\' { yylval.cval=0x0A; disp_token(yytext); return CVAL; }
}

[a-zA-Z_][a-zA-Z_0-9]*	{
    yylval.sval = malloc(strlen(yytext)+1);
    strcpy(yylval.sval, yytext);
    disp_token(yytext); return ID;
    }
[0-9]+	{ yylval.fval=atoi(yytext); disp_token(yytext); return IVAL; }
[0-9]+\.[0-9]+	{ yylval.fval=atof(yytext); disp_token(yytext); return FVAL; }


[ \t]	disp_token(yytext);
[\n]	{ disp_token(yytext); line++; }
.		;

%%

int yywrap(void){
	return 1;
}

void yyerror(char *msg){
    printf("Error: %s\n", msg);
}

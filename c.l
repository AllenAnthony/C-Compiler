%{
#include "abstract_tree.h"
#include "y.tab.h"
#include <string.h>

#define ID_MAX_LEN 16

void yyerror(char *msg);
%}

%%

'('     { return LP; }
')'		{ return RP; }
'{'		{ return LCB; }
'}'		{ return RCB; }
'['		{ return LSB; }
']'		{ return RSB; }
';'		{ return SEMICOLON; }
if		{ return IF; }
else    { return ELSE; }
while	{ return WHILE; }
for		{ return FOR; }
','		{ return COMMA; }
'+'		{ return PLUS; }
'-'		{ return MINUS; }
'*'		{ return MUL; }
'/'		{ return DIV; }
'>='	{ return GE; }
'<='	{ return LE; }
'!='	{ return EQ; }
'=='	{ return EQ; }
'>' 	{ return GT; }
'<' 	{ return LT; }
'&&'	{ return AND; }
'||'	{ return OR; }
'='		{ return ASSIGN; }
int		{ return INT; }
double  { return DOUBLE; }
char	{ return CHAR; }
break   { return BREAK; }
return  { return RETURN; }

[a-zA-Z_][a-zA-Z_0-9]* {
			if (strlen(yytext) > ID_MAX_LEN)
				yyerror("ident too long");
			else
			{
				int len;
				len = strlen(yytext) + 1;
				yylval.string = (__typeof__(yylval.string))
					malloc((len * sizeof(yylval.string)));
				memcpy(yylval.string,yytext,len);
				return ID;
			}
		}

[0-9]+		{
			yylval.intval = atoi(yytext);
			return INTVAL;
		}
[0-9]+\.[0-9]+  {
			yylval.realval = atof(yytext);
			return REALVAL;
		}

[ \t]		;
[\n]		{ yylval.line++; }
%%

int yywrap(void) {
	return 1;
}

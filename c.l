%{
#include "parse_tree.h"
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
#define ID_MAX_LEN 16

int line = 1;

struct token{
    int row;
    void *val;
};

struct token *get_token(void *val){
	struct token *tok;
	tok = (struct token *)malloc(sizeof(struct token));
	tok->row = line;
	tok->val = val;
	return tok;
}

void yyerror(char *msg);
%}

%%

'('		{ yylval.token = get_token(NULL); return LP; }
')'		{ yylval.token = get_token(NULL); return RP; }
'{'		{ yylval.token = get_token(NULL); return LCB; }
'}'		{ yylval.token = get_token(NULL); return RCB; }
'['		{ yylval.token = get_token(NULL); return LSB; }
']'		{ yylval.token = get_token(NULL); return RSB; }
';'		{ yylval.token = get_token(NULL); return SEMICOLON; }
','		{ yylval.token = get_token(NULL); return COMMA; }

int		{ yylval.token = get_token(NULL); return INT; }
float	{ yylval.token = get_token(NULL); return FLOAT; }
char	{ yylval.token = get_token(NULL); return CHAR; }
if		{ yylval.token = get_token(NULL); return IF; }
else	{ yylval.token = get_token(NULL); return ELSE; }
while	{ yylval.token = get_token(NULL); return WHILE; }
for		{ yylval.token = get_token(NULL); return FOR; }
break	{ yylval.token = get_token(NULL); return BREAK; }
return	{ yylval.token = get_token(NULL); return RETURN; }

'+'		{ yylval.token = get_token(NULL); return PLUS; }
'-'		{ yylval.token = get_token(NULL); return MINUS; }
'*'		{ yylval.token = get_token(NULL); return MUL; }
'/'		{ yylval.token = get_token(NULL); return DIV; }
'%'		{ yylval.token = get_token(NULL); return MOD; }
">="	{ yylval.token = get_token(NULL); return GE; }
"<="	{ yylval.token = get_token(NULL); return LE; }
"!="	{ yylval.token = get_token(NULL); return NEQ; }
"=="	{ yylval.token = get_token(NULL); return EQ; }
'>'		{ yylval.token = get_token(NULL); return GT; }
'<'		{ yylval.token = get_token(NULL); return LT; }
"&&"	{ yylval.token = get_token(NULL); return AND; }
"||"	{ yylval.token = get_token(NULL); return OR; }
'!'		{ yylval.token = get_token(NULL); return NOT; }
'='		{ yylval.token = get_token(NULL); return ASSIGN; }


[a-zA-Z_][a-zA-Z_0-9]*	{
			if (strlen(yytext) > ID_MAX_LEN){
				yyerror("Identifier too long !");
			}
			else{
				int len = strlen(yytext) + 1;
				char *id = (char *)malloc((len * sizeof(char)));
				memcpy(id, yytext, len);
				yylval.token = get_token((void *)id);
				return ID;
			}
		}

[0-9]+	{
			int *val = (int *)malloc(sizeof(int));
			*val = atoi(yytext);
			yylval.token = get_token((void *)val);
			return INTVAL;
		}
[0-9]+\.[0-9]+	{
			float *val = (float *)malloc(sizeof(float));
			*val = atof(yytext);
			yylval.token = get_token((void *)val);
			return FLOATVAL;
		}

[ \t]	;
[\n]	{ line++; }

.		;

%%

int yywrap(void){
	return 1;
}

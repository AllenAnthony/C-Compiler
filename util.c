#include "util.h"

void* checked_malloc(unsigned long len)
{
    void *p = malloc(len);
    if (!p) {
        fprintf(stderr,"\nRun out of memory!\n");
        exit(1);
    }
    return p;
}

char* String(char *s)
{
    char*  p = checked_malloc(strlen(s)+1);
    strcpy(p, s);
    return p;
}

//显示lex和yacc的错误信息
void yyerror(const char *msg)
{
    printf("Error: %s\n", msg);
}

//显示token
void disp_token(char *token)
{
#ifdef DEBUG
    printf("%s", token);
#endif
}
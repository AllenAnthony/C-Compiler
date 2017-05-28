#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define DEBUG

int yylex();

void yyerror(const char *);

void *checked_malloc(unsigned long);

char *String(char *);

void disp_token(char *);

#endif //UTIL_H
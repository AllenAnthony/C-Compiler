#ifndef COMPILER_UTIL_HPP
#define COMPILER_UTIL_HPP

#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <cstdlib>

using namespace std;

extern int line;
typedef enum {
    ENUM_INT,
    ENUM_FLOAT,
    ENUM_CHAR,
    ENUM_VOID
} ENUM_specifier;

void yyerror(string);

int yylex(void);

void *check_malloc(size_t);


#endif //COMPILER_UTIL_HPP

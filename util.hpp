#ifndef COMPILER_UTIL_HPP
#define COMPILER_UTIL_HPP

#include <string>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void yyerror(string);

int yylex(void);

void *check_malloc(size_t);


#endif //COMPILER_UTIL_HPP

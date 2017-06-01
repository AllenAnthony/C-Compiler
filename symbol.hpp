#ifndef COMPILER_SYMBOL_HPP
#define COMPILER_SYMBOL_HPP

#include <iostream>
#include <string>
#include <functional>
#include "util.hpp"

typedef struct _Symbol *Symbol;
typedef struct _Bucket *Bucket;

struct _Symbol {
    std::string id;
    ENUM_specifier type;
    int depth;
};

struct _Bucket {
    std::vector<Symbol> symbols;
};

class SymbolTable {

private:
    int size;
    int current_depth;
    Bucket buckets;
    std::vector<Symbol> record;

    size_t hash(std::string id);


public:
    SymbolTable(int size);

    Symbol find(std::string id);

    Symbol link(std::string id, ENUM_specifier type);

    void enterScope();

    void escapeScope();

};


#endif //COMPILER_SYMBOL_HPP

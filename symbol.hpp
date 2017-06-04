#ifndef COMPILER_SYMBOL_HPP
#define COMPILER_SYMBOL_HPP

#include <iostream>
#include <string>
#include <functional>
#include "util.hpp"
#include "abs.hpp"

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


//符号表
class SymbolTable {

private:
    int size; //符号表中hash表大小
    int current_depth;   //当前环境的深度
    Bucket buckets;   //哈希表中的桶
    std::vector<Symbol> record;

    size_t hash(std::string id);


public:
    SymbolTable(int size);

    Symbol find(std::string id);

    Symbol link(std::string id, ENUM_specifier type);

    void enterScope();

    void escapeScope();

    void levelAdapt();
};


#endif //COMPILER_SYMBOL_HPP

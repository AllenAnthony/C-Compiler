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

class SymbolTable {

private:
    int size;
    int current_depth;
    Bucket buckets;
    std::vector<Symbol> record;

    size_t hash(std::string id);


public:
<<<<<<< HEAD
    SymbolTable(int size) {
        this->size = size;
        this->current_depth = 0;
        this->buckets = (Bucket) check_malloc(sizeof(struct _Bucket) * size);
    }

    Symbol find(std::string id) {
        size_t index = hash(id);
        std::vector<Symbol> symbols = symbol_table[index].symbols;
        for (int i = 0; i < symbols.size(); i++) {
            if (id == symbols[i]->id) {
                return symbols[i];
            }
        }
        return NULL;
    }

    Symbol link(std::string id, ENUM_specifier type) {
        size_t index = hash(id);
        std::vector<Symbol> symbols = symbol_table[index].symbols;

        for (int i = 0; i < symbols.size(); i++) {
            if (id == symbols[i]->id) {
                return symbols[i];
            }
        }

        Symbol symbol = (Symbol) check_malloc(sizeof(_Symbol));
        symbol->id = id;
        symbol->type = type;
        symbol->depth = current_depth;

        symbols.push_back(symbol);
        record.push_back(symbol);

        return symbol;
    }

    void enterScope() {
        current_depth++;
    }

    void escapeScope() {
        size_t current_size = record.size();
        while (current_size != 0 && record[current_size]->depth == current_depth) {
            Symbol symbol = record.back();
            record.pop_back();
            size_t index = hash(symbol->id);
            std::vector<Symbol> symbols = symbol_table[index].symbols;
            symbols.pop_back();
            current_size--;
        }
        current_depth--;
    }
=======
    SymbolTable(int size);

    Symbol find(std::string id);

    Symbol link(std::string id, ENUM_specifier type);

    void enterScope();

    void escapeScope();
>>>>>>> 93cf02995d1203139043ddba6c1d7c694759b722

};


#endif //COMPILER_SYMBOL_HPP

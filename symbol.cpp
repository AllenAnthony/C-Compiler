#include "symbol.hpp"


size_t SymbolTable::hash(std::string id) {
    std::hash<std::string> hash_fn;
    return hash_fn(id) % size;
}

SymbolTable::SymbolTable(int size) {
    this->size = size;
    this->current_depth = 0;
    this->buckets = (Bucket) check_malloc(sizeof(struct _Bucket) * size);
}

Symbol SymbolTable::find(std::string id) {
    size_t index = hash(id);
    std::vector<Symbol> symbols = buckets[index].symbols;
    for (int i = 0; i < symbols.size(); i++) {
        if (id == symbols[i]->id) {
            return symbols[i];
        }
    }
    return NULL;
}

Symbol SymbolTable::link(std::string id, ENUM_specifier type) {
    size_t index = hash(id);
    std::vector<Symbol> &symbols = buckets[index].symbols;

    for (int i = 0; i < symbols.size(); i++) {
        if (id.compare(symbols[i]->id) == 0 ) {
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

void SymbolTable::enterScope() {
    current_depth++;
}

void SymbolTable::escapeScope() {
    size_t current_size = record.size();
    while (current_size > 0 && record[current_size - 1]->depth >= current_depth) {
        Symbol &symbol = record.back();
        size_t index = hash(symbol->id);
        std::vector<Symbol> &symbols = buckets[index].symbols;
        symbols.pop_back();
        record.pop_back();
        current_size--;
    }
    current_depth--;
}

void SymbolTable::levelAdapt() {
    current_depth--;
}



#include "util.hpp"

void yyerror(std::string msg) {
    std::cout << endl << "Line" << line << ": " << msg << std::endl;
}

void *check_malloc(size_t size) {
    void *p = malloc(size);
    if (!p) {
        cout << "Memory is full!" << endl;
        exit(0);
    }
    memset(p, 0, size);
    return p;
}
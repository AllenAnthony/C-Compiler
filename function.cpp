#include "function.hpp"

Func FuncTable::find(string id) {
    if (funcs.find(id) == funcs.end()) {
        return NULL;
    } else {
        return &funcs[id];
    }
}

Func FuncTable::link(string id, _Func func) {
    if (find(id) == NULL) {
        funcs[id] = func;
        return &funcs[id];
    } else {
        return &funcs[id];
    }
}
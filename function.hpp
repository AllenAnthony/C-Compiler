#ifndef COMPILER_FUNCTION_HPP
#define COMPILER_FUNCTION_HPP

#include <map>
#include <vector>
#include <string>
#include "abs.hpp"

using namespace std;

struct _Func {
    string id;
    ENUM_node_type ret_type;  //ENUM_IVAL、ENUM_FVAL、ENUM_CVAL
    vector<ENUM_specifier> param_list;  //参数类型列表
};

typedef _Func *Func;

class FuncTable {
private:
    map<string, _Func> funcs;
public:

    Func find(string id);

    Func link(string id, _Func func);
};

#endif //COMPILER_FUNCTION_HPP

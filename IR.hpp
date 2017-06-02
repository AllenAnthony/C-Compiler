#ifndef COMPILER_IR_HPP
#define COMPILER_IR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "util.hpp"

using namespace std;

typedef struct _IR_NODE *IR_NODE;
typedef struct _IR_LEAF *IR_LEAF;

typedef enum {
    IR_NODE_ASSIGN,
    IR_NODE_CONST,
    IR_NODE_LEAF,
    IR_NODE_FUNC,
    IR_NODE_LABEL,
    IR_NODE_JUMP,
    IR_NODE_BRANCH,
    IR_NODE_PLUS,
    IR_NODE_MINUS,
    IR_NODE_MUL,
    IR_NODE_DIV,
    IR_NODE_MOD,
    IR_NODE_GE,
    IR_NODE_LE,
    IR_NODE_NE,
    IR_NODE_EQ,
    IR_NODE_GT,
    IR_NODE_LT,
    IR_NODE_AND,
    IR_NODE_OR,
    IR_NODE_NOT,
    IR_NODE_LIST,
    IR_NODE_NONE
} IR_NODE_type;

typedef enum {
    IR_LEAF_ID,
    IR_LEAF_INT,
    IR_LEAF_FLOAT,
    IR_LEAF_CHAR,
    IR_LEAF_VOID
} LEAF_type;

struct _IR_LEAF {
    LEAF_type leaf_type;
    string id;
    union {
        int ival;
        float fval;
        char cval;
    };
};


struct _IR_NODE {
    IR_NODE_type ir_node_type;

    //Label
    int label;

    //非叶节点属性
    LEAF_type return_type;
    IR_NODE left;
    IR_NODE right;

    //叶节点属性
    _IR_LEAF leaf;

    //list
    vector<IR_NODE> list;
};

extern vector<int> iter_label_head;
extern vector<int> iter_label_tail;

extern int curr_iter_label_head;
extern int curr_iter_label_tail;
extern int curr_iter_label_count;

void IR_print(IR_NODE IR_root, FILE *fp, int root);

void IR_translate_program(IR_NODE IR_root);


#endif //COMPILER_IR_HPP

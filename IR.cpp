#include "IR.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void IR_print(IR_NODE IR_root) {

}

void IR_translate_program(IR_NODE ir_root) {
    switch (ir_root->ir_node_type) {
        case IR_NODE_ASSIGN:
            break;
        case IR_NODE_CONST:
            break;
        case IR_NODE_LEAF:
            break;
        case IR_NODE_FUNC:
            break;
        case IR_NODE_LABEL:
            break;
        case IR_NODE_JUMP:
            break;
        case IR_NODE_BRANCH:
            break;
        case IR_NODE_PLUS:
            break;
        case IR_NODE_MINUS:
            break;
        case IR_NODE_MUL:
            break;
        case IR_NODE_DIV:
            break;
        case IR_NODE_MOD:
            break;
        case IR_NODE_GE:
            break;
        case IR_NODE_LE:
            break;
        case IR_NODE_NE:
            break;
        case IR_NODE_EQ:
            break;
        case IR_NODE_GT:
            break;
        case IR_NODE_LT:
            break;
        case IR_NODE_AND:
            break;
        case IR_NODE_OR:
            break;
        case IR_NODE_NOT:
            break;
        case IR_NODE_LIST:
            break;
        case IR_NODE_NONE:
            break;
        default:
            break;
    }
}
#include "IR.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int count_node = 0;

void IR_print(IR_NODE IR_root, FILE *fp, int root) {
    switch (IR_root->ir_node_type) {
        case IR_NODE_LEAF:
            switch (IR_root->leaf.leaf_type) {
                case IR_LEAF_ID:
                case IR_LEAF_VOID:
                    fprintf(fp, "\tnode%d[shape=plaintext, label=\"%s\", height=.3];\n\tnode%d->node%d;\n",
                            count_node + 1, IR_root->leaf.id.c_str(), root, count_node + 1);
                    count_node++;
                    break;
                case IR_LEAF_INT:
                    fprintf(fp, "\tnode%d[shape=plaintext, label=\"%d\", height=.3];\n\tnode%d->node%d;\n",
                            count_node + 1, IR_root->leaf.ival, root, count_node + 1);
                    count_node++;
                    break;
                case IR_LEAF_CHAR:
                    fprintf(fp, "\tnode%d[shape=plaintext, label=\"%c\", height=.3];\n\tnode%d->node%d;\n",
                            count_node + 1, IR_root->leaf.cval, root, count_node + 1);
                    count_node++;
                    break;
                case IR_LEAF_FLOAT:
                    fprintf(fp, "\tnode%d[shape=plaintext, label=\"%f\", height=.3];\n\tnode%d->node%d;\n",
                            count_node + 1, IR_root->leaf.fval, root, count_node + 1);
                    count_node++;
                    break;
                default:
                    break;
            }
            break;
        case IR_NODE_LABEL:
            fprintf(fp,
                    "\tnode%d[shape=plaintext, label=\"LABEL\", height=.3];\n\tnode%d[shape=plaintext, label=\"%d\", height=.3];\n\tnode%d->node%d;\n\tnode%d->node%d;\n",
                    count_node + 1, count_node + 2, IR_root->label, root, count_node + 1, count_node + 1,
                    count_node + 2);
            count_node += 2;
            return;
        case IR_NODE_CALL:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"CALL\", height=.3];\n\tnode%d->node%d;\n", count_node + 1, root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_FUNC:
        case IR_NODE_LIST:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"SEQ\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            root = count_node;
            for (int i = 0; i < IR_root->list.size(); i++) {
                IR_print(IR_root->list[i], fp, root);
            }
            return;
        case IR_NODE_CONST:
        case IR_NODE_NONE:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"SEQ\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_ASSIGN:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"MOVE\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_JUMP:
            fprintf(fp,
                    "\tnode%d[shape=plaintext, label=\"JUMP\", height=.3];\n\tnode%d[shape=plaintext, label=\"LABEL_%d\", height=.3];\n\tnode%d->node%d;\n\tnode%d->node%d;\n",
                    count_node + 1, count_node + 2, IR_root->left->label, root, count_node + 1, count_node + 1,
                    count_node + 2);
            count_node += 2;
            return;
        case IR_NODE_BRANCH:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"BRANCH\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_PLUS:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"PLUS\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_MINUS:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"MINUS\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_MUL:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"MUL\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_DIV:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"DIV\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_MOD:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"MOD\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_GE:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"GE\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_LE:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"LE\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_NE:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"NE\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_EQ:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"EQ\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_GT:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"GT\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_LT:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"LT\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_AND:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"AND\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_OR:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"OR\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_NOT:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"NOT\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
            count_node++;
            break;
        default:
            break;
    }
    root = count_node;
    if (IR_root->left != NULL) {
        //fprintf(fp, "haha\n");
        IR_print(IR_root->left, fp, root);
    }
    if (IR_root->right != NULL) {
        //fprintf(fp, "hihi\n");
        IR_print(IR_root->right, fp, root);
    }

    return;
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
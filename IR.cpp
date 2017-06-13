#include "IR.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int count_node = 0;
int tmp_lable_count = 0;

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
        case IR_NODE_RETURN:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"RETURN\", height=.3];\n\tnode%d->node%d;\n",
                    count_node + 1, root, count_node + 1);
            count_node++;
            break;
        case IR_NODE_LABEL:
            fprintf(fp,
                    "\tnode%d[shape=plaintext, label=\"LABEL\", height=.3];\n\tnode%d[shape=plaintext, label=\"%d\", height=.3];\n\tnode%d->node%d;\n\tnode%d->node%d;\n",
                    count_node + 1, count_node + 2, IR_root->label, root, count_node + 1, count_node + 1,
                    count_node + 2);
            count_node += 2;
            return;
        case IR_NODE_CALL:
            fprintf(fp, "\tnode%d[shape=plaintext, label=\"CALL\", height=.3];\n\tnode%d->node%d;\n", count_node + 1,
                    root, count_node + 1);
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
            IR_translate_program(ir_root->right);
            cout << "POP DX" << endl;
            cout << "MOV ";
            IR_translate_program(ir_root->left);
            cout << ", DX" << endl;
            break;
        case IR_NODE_LEAF:
            switch (ir_root->leaf.leaf_type) {
                case IR_LEAF_INT:
                    cout << ir_root->leaf.ival;
                    break;
                case IR_LEAF_FLOAT:
                    cout << ir_root->leaf.fval;
                    break;
                case IR_LEAF_CHAR:
                    cout << ir_root->leaf.cval;
                    break;
                case IR_LEAF_ID:
                    cout << ir_root->leaf.id;
                    break;
                default:
                    cout << "Error in IR_NODE_LEAF";
            }
            break;
        case IR_NODE_FUNC:
            cout << "LABEL_FUNC_";
            IR_translate_program(ir_root->list[0]);
            cout << ":" << endl;
            IR_translate_program(ir_root->list[1]);
            for (int i = 2; i < ir_root->list.size(); i++) {
                IR_translate_program(ir_root->list[i]);
            }
            break;
        case IR_NODE_LABEL:
            cout << "LABEL_" << ir_root->label << ":" << endl;
            break;
        case IR_NODE_JUMP:
            cout << "JMP ";
            IR_translate_program(ir_root->left);
            cout << endl;
            break;
        case IR_NODE_BRANCH:
            break;
        case IR_NODE_PLUS:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "ADD AX, DX" << endl;
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_MINUS:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "SUB AX, DX" << endl;
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_MUL:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "MUL AL" << endl;
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_DIV:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "MOV AH, 0" << endl;
            cout << "DIV AL" << endl;
            cout << "MOV AH, 0" << endl;  //把余数清0
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_MOD:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "MOV AH, 0" << endl;
            cout << "DIV AL" << endl;
            cout << "MOV AL, AH" << endl;
            cout << "MOV AH, 0" << endl;
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_AND:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "AND AX, DX" << endl;
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_OR:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "OR AX, DX" << endl;
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_NOT:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP DX" << endl;
            cout << "MOV AX, 0" << endl;
            cout << "SUB AX, DX" << endl;
            cout << "PUSH AX" << endl;
            break;
        case IR_NODE_GE:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "CMP DX, AX" << endl;
            cout << "JGE LABEL_TMP_OK_" << tmp_lable_count << endl;
            //不满足条件
            cout << "MOV AX, 0" << endl;
            cout << "JMP LABEL_TMP_EXIT_" << tmp_lable_count << endl;

            cout << "LABEL_TMP_OK_" << tmp_lable_count << ":" << endl;
            //满足条件
            cout << "MOV AX, 1" << endl;

            cout << "LABEL_TMP_EXIT_" << tmp_lable_count << ":" << endl;
            cout << "PUSH AX" << endl;
            tmp_lable_count++;
            break;
        case IR_NODE_LE:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "CMP DX, AX" << endl;
            cout << "JLE LABEL_TMP_OK_" << tmp_lable_count << endl;
            //不满足条件
            cout << "MOV AX, 0" << endl;
            cout << "JMP LABEL_TMP_EXIT_" << tmp_lable_count << endl;

            cout << "LABEL_TMP_OK_" << tmp_lable_count << ":" << endl;
            //满足条件
            cout << "MOV AX, 1" << endl;

            cout << "LABEL_TMP_EXIT_" << tmp_lable_count << ":" << endl;
            cout << "PUSH AX" << endl;
            tmp_lable_count++;
            break;
        case IR_NODE_NE:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "CMP DX, AX" << endl;
            cout << "JNE LABEL_TMP_OK_" << tmp_lable_count << endl;
            //不满足条件
            cout << "MOV AX, 0" << endl;
            cout << "JMP LABEL_TMP_EXIT_" << tmp_lable_count << endl;

            cout << "LABEL_TMP_OK_" << tmp_lable_count << ":" << endl;
            //满足条件
            cout << "MOV AX, 1" << endl;

            cout << "LABEL_TMP_EXIT_" << tmp_lable_count << ":" << endl;
            cout << "PUSH AX" << endl;
            tmp_lable_count++;
            break;
        case IR_NODE_EQ:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "CMP DX, AX" << endl;
            cout << "JE LABEL_TMP_OK_" << tmp_lable_count << endl;
            //不满足条件
            cout << "MOV AX, 0" << endl;
            cout << "JMP LABEL_TMP_EXIT_" << tmp_lable_count << endl;

            cout << "LABEL_TMP_OK_" << tmp_lable_count << ":" << endl;
            //满足条件
            cout << "MOV AX, 1" << endl;

            cout << "LABEL_TMP_EXIT_" << tmp_lable_count << ":" << endl;
            cout << "PUSH AX" << endl;
            tmp_lable_count++;
            break;
        case IR_NODE_GT:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "CMP DX, AX" << endl;
            cout << "JG LABEL_TMP_OK_" << tmp_lable_count << endl;
            //不满足条件
            cout << "MOV AX, 0" << endl;
            cout << "JMP LABEL_TMP_EXIT_" << tmp_lable_count << endl;

            cout << "LABEL_TMP_OK_" << tmp_lable_count << ":" << endl;
            //满足条件
            cout << "MOV AX, 1" << endl;

            cout << "LABEL_TMP_EXIT_" << tmp_lable_count << ":" << endl;
            cout << "PUSH AX" << endl;
            tmp_lable_count++;
            break;
        case IR_NODE_LT:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "POP AX" << endl;
            cout << "POP DX" << endl;
            cout << "CMP DX, AX" << endl;
            cout << "JL LABEL_TMP_OK_" << tmp_lable_count << endl;
            //不满足条件
            cout << "MOV AX, 0" << endl;
            cout << "JMP LABEL_TMP_EXIT_" << tmp_lable_count << endl;

            cout << "LABEL_TMP_OK_" << tmp_lable_count << ":" << endl;
            //满足条件
            cout << "MOV AX, 1" << endl;

            cout << "LABEL_TMP_EXIT_" << tmp_lable_count << ":" << endl;
            cout << "PUSH AX" << endl;
            tmp_lable_count++;
            break;
        case IR_NODE_LIST:
            for (int i = 0; i < ir_root->list.size(); i++) {
                IR_translate_program(ir_root->list[i]);
            }
            break;
        case IR_NODE_NONE:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            cout << "None" << endl;
            break;
        default:
            cout << "Undefine Node type" << endl;
            break;
    }
}
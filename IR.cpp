#include "IR.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int count_node = 0;
int tmp_lable_count = 0;

typedef enum {
    AERA_NONE, AERA_FUNC, AERA_DST, AERA_PARAM, AERA_DEC
} IR_state;

IR_state ir_state = AERA_NONE;
int has_comma = 1;

extern string x86_asm;
extern string x86_asm_head;
extern string x86_asm_body;
char tmp[128];

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
        case IR_NODE_DEC:
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
            ir_state = AERA_NONE;
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP DX\n";
            x86_asm_body += "MOV ";
            ir_state = AERA_DST;
            IR_translate_program(ir_root->left);
            ir_state = AERA_NONE;
            x86_asm_body += ", DX\n";
            break;
        case IR_NODE_LEAF:
            switch (ir_root->leaf.leaf_type) {
                case IR_LEAF_INT:
                    sprintf(tmp, "%d", ir_root->leaf.ival);
                    x86_asm_body += string("MOV AX, ") + string(tmp) + "\n";
                    x86_asm_body += string("PUSH AX\n");
                    break;
                case IR_LEAF_FLOAT:
                    sprintf(tmp, "%f", ir_root->leaf.fval);
                    x86_asm_body += string("MOV AX, ") + string(tmp) + "\n";
                    x86_asm_body += string("PUSH AX\n");
                    break;
                case IR_LEAF_CHAR:
                    sprintf(tmp, "%d", ir_root->leaf.cval);
                    x86_asm_body = string("MOV AX, ") + string(tmp) + "\n";
                    x86_asm_body += string("PUSH AX\n");
                    break;
                case IR_LEAF_ID:
                    if (ir_state == AERA_DST) {
                        x86_asm_body += ir_root->leaf.id;
                    } else if (ir_state == AERA_FUNC) {
                        x86_asm_body += ir_root->leaf.id;
                    } else if (ir_state == AERA_DEC) {
                        x86_asm_head += ir_root->leaf.id;
                        x86_asm_head += " DW ?\n";
                    } else {
                        x86_asm_body += string("MOV DX, ") + ir_root->leaf.id + "\n";
                        x86_asm_body += "PUSH DX\n";
                    }
                    break;
                default:
                    x86_asm_body += "Error in IR_NODE_LEAF\n";
            }
            break;
        case IR_NODE_FUNC:
            x86_asm_body += "LABEL_FUNC_";
            ir_state = AERA_FUNC;
            IR_translate_program(ir_root->list[0]);
            x86_asm_body += ":\n";
            ir_state = AERA_DEC;
            IR_translate_program(ir_root->list[1]);
            for (int i = 2; i < ir_root->list.size(); i++) {
                IR_translate_program(ir_root->list[i]);
            }
            break;
        case IR_NODE_LABEL:
            sprintf(tmp, "%d", ir_root->label);
            x86_asm_body += string("LABEL_") + string(tmp);
            if (has_comma == 1) {
                x86_asm_body += ":\n";
            }
            break;
        case IR_NODE_JUMP:
            x86_asm_body += "JMP ";
            has_comma = 0;
            IR_translate_program(ir_root->left);
            has_comma = 1;
            x86_asm_body += "\n";
            break;
        case IR_NODE_BRANCH:
            x86_asm_body += "POP AX\n";
            x86_asm_body += "MOV DX, 1\n";
            x86_asm_body += "CMP AX, DX\n";
            x86_asm_body += "JE ";
            has_comma = 0;
            IR_translate_program(ir_root->left);
            has_comma = 1;
            x86_asm_body += "\n";
            break;
        case IR_NODE_PLUS:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "ADD AX, DX\n";
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_MINUS:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "SUB AX, DX\n";
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_MUL:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "MUL AL\n";
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_DIV:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "MOV AH, 0\n";
            x86_asm_body += "DIV AL\n";
            x86_asm_body += "MOV AH, 0\n";  //把余数清0
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_MOD:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "MOV AH, 0\n";
            x86_asm_body += "DIV AL\n";
            x86_asm_body += "MOV AL, AH\n";
            x86_asm_body += "MOV AH, 0\n";
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_AND:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "AND AX, DX\n";
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_OR:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "OR AX, DX\n";
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_NOT:
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP DX\n";
            x86_asm_body += "MOV AX, 0\n";
            x86_asm_body += "SUB AX, DX\n";
            x86_asm_body += "PUSH AX\n";
            break;
        case IR_NODE_GE:
            sprintf(tmp, "%d", tmp_lable_count);
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "CMP DX, AX\n";
            x86_asm_body += string("JGE LABEL_TMP_OK_") + string(tmp) + "\n";
            //不满足条件
            x86_asm_body += "MOV AX, 0\n";
            x86_asm_body += string("JMP LABEL_TMP_EXIT_") + string(tmp) + "\n";

            x86_asm_body += string("LABEL_TMP_OK_") + string(tmp) + ":\n";
            //满足条件
            x86_asm_body += "MOV AX, 1\n";

            x86_asm_body += string("LABEL_TMP_EXIT_") + string(tmp) + ":\n";
            x86_asm_body += "PUSH AX\n";
            tmp_lable_count++;
            break;
        case IR_NODE_LE:
            sprintf(tmp, "%d", tmp_lable_count);
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "CMP DX, AX\n";
            x86_asm_body += string("JLE LABEL_TMP_OK_") + string(tmp) + "\n";
            //不满足条件
            x86_asm_body += "MOV AX, 0\n";
            x86_asm_body += string("JMP LABEL_TMP_EXIT_") + string(tmp) + "\n";

            x86_asm_body += string("LABEL_TMP_OK_") + string(tmp) + ":\n";
            //满足条件
            x86_asm_body += "MOV AX, 1\n";

            x86_asm_body += string("LABEL_TMP_EXIT_") + string(tmp) + ":\n";
            x86_asm_body += "PUSH AX\n";
            tmp_lable_count++;
            break;
        case IR_NODE_NE:
            sprintf(tmp, "%d", tmp_lable_count);
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "CMP DX, AX\n";
            x86_asm_body += string("JNE LABEL_TMP_OK_") + string(tmp) + "\n";
            //不满足条件
            x86_asm_body += "MOV AX, 0\n";
            x86_asm_body += string("JMP LABEL_TMP_EXIT_") + string(tmp) + "\n";

            x86_asm_body += string("LABEL_TMP_OK_") + string(tmp) + ":\n";
            //满足条件
            x86_asm_body += "MOV AX, 1\n";

            x86_asm_body += string("LABEL_TMP_EXIT_") + string(tmp) + ":\n";
            x86_asm_body += "PUSH AX\n";
            tmp_lable_count++;
            break;
        case IR_NODE_EQ:
            sprintf(tmp, "%d", tmp_lable_count);
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "CMP DX, AX\n";
            x86_asm_body += string("JE LABEL_TMP_OK_") + string(tmp) + "\n";
            //不满足条件
            x86_asm_body += "MOV AX, 0\n";
            x86_asm_body += string("JMP LABEL_TMP_EXIT_") + string(tmp) + "\n";

            x86_asm_body += string("LABEL_TMP_OK_") + string(tmp) + ":\n";
            //满足条件
            x86_asm_body += "MOV AX, 1\n";

            x86_asm_body += string("LABEL_TMP_EXIT_") + string(tmp) + ":\n";
            x86_asm_body += "PUSH AX\n";
            tmp_lable_count++;
            break;
        case IR_NODE_GT:
            sprintf(tmp, "%d", tmp_lable_count);
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "CMP DX, AX\n";
            x86_asm_body += string("JG LABEL_TMP_OK_") + string(tmp) + "\n";
            //不满足条件
            x86_asm_body += "MOV AX, 0\n";
            x86_asm_body += string("JMP LABEL_TMP_EXIT_") + string(tmp) + "\n";

            x86_asm_body += string("LABEL_TMP_OK_") + string(tmp) + ":\n";
            //满足条件
            x86_asm_body += "MOV AX, 1\n";

            x86_asm_body += string("LABEL_TMP_EXIT_") + string(tmp) + ":\n";
            x86_asm_body += "PUSH AX\n";
            tmp_lable_count++;
            break;
        case IR_NODE_LT:
            sprintf(tmp, "%d", tmp_lable_count);
            IR_translate_program(ir_root->left);
            IR_translate_program(ir_root->right);
            x86_asm_body += "POP AX\n";
            x86_asm_body += "POP DX\n";
            x86_asm_body += "CMP DX, AX\n";
            x86_asm_body += string("JL LABEL_TMP_OK_") + string(tmp) + "\n";
            //不满足条件
            x86_asm_body += "MOV AX, 0\n";
            x86_asm_body += string("JMP LABEL_TMP_EXIT_") + string(tmp) + "\n";

            x86_asm_body += string("LABEL_TMP_OK_") + string(tmp) + ":\n";
            //满足条件
            x86_asm_body += "MOV AX, 1\n";

            x86_asm_body += string("LABEL_TMP_EXIT_") + string(tmp) + ":\n";
            x86_asm_body += "PUSH AX\n";
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
            break;
        case IR_NODE_DEC:
            ir_state = AERA_DEC;
            for (int i = 0; i < ir_root->list.size(); i++) {
                IR_translate_program(ir_root->list[i]);
            }
            break;
        default:
            x86_asm_body += "Undefine Node type\n";
            break;
    }
}
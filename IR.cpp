#include "IR.hpp"

int count_node = 0;

void IR_print(IR_NODE IR_root, FILE *fp, int root) {
    if(root == -1){
        root = count_node;
        fprintf(fp, "\tnode%d[shape=plaintext; labal=\"program\"; height=.3];\n", count_node++);
    }
    switch(IR_root->ir_node_type){
        case IR_NODE_LEAF:
            switch(IR_root->leaf.leaf_type){
                case IR_LEAF_ID:
                case IR_LEAF_VOID:
                    fprintf(fp, "\tnode%d[shape=plaintext; labal=\"%s\"; height=.3];\n\tnode%d->node%d;\n", count_node++, IR_root->leaf.id.c_str(), root, count_node - 1);
                    return;
                case IR_LEAF_INT:
                    fprintf(fp, "\tnode%d[shape=plaintext; labal=\"%d\"; height=.3];\n\tnode%d->node%d;\n", count_node++, IR_root->leaf.ival, root, count_node - 1);
                    return;
                case IR_LEAF_CHAR:
                    fprintf(fp, "\tnode%d[shape=plaintext; labal=\"%c\"; height=.3];\n\tnode%d->node%d;\n", count_node++, IR_root->leaf.cval, root, count_node - 1);
                    return;
                case IR_LEAF_FLOAT:
                    fprintf(fp, "\tnode%d[shape=plaintext; labal=\"%f\"; height=.3];\n\tnode%d->node%d;\n", count_node++, IR_root->leaf.fval, root, count_node - 1);
                    return;
                default: return;
            }
            return;
        case IR_NODE_LABEL:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"LABEL\"; height=.3];\n\tnode%d[shape=plaintext; labal=\"%d\"; height=.3];\n\tnode%d->node%d;\n\tnode%d->node%d;\n", count_node++, count_node++, IR_root->label, root, count_node - 2, count_node - 2, count_node - 1);
            return;
        case IR_NODE_JUMP:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"JUMP\"; height=.3];\n\tnode%d[shape=plaintext; labal=\"JUMP\"; height=.3];\n", root, ++count_node );
            return;
        case IR_NODE_LIST:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"LIST\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            for(int i=0; i<IR_root->list.size(); i++){
                IR_print(IR_root->list[i], fp, count_node - 1);
            }
            return;
        case IR_NODE_FUNC:
        case IR_NODE_CONST:
        case IR_NODE_NONE:
            break;
        case IR_NODE_ASSIGN:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"MOVE\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_BRANCH:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"BRANCH\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_PLUS:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"PLUS\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_MINUS:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"MINUS\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_MUL:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"MUL\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_DIV:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"DIV\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_MOD:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"MOD\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_GE:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"GE\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_LE:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"LE\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_NE:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"NE\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_EQ:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"EQ\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_GT:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"GT\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_LT:
                fprintf(fp, "\tnode%d[shape=plaintext; labal=\"LT\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_AND:
                fprintf(fp, "\tnode%d[shape=plaintext; labal=\"AND\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_OR:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"OR\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        case IR_NODE_NOT:
            fprintf(fp, "\tnode%d[shape=plaintext; labal=\"NOT\"; height=.3];\n\tnode%d->node%d;\n", count_node++, root, count_node - 1);
            break;
        default:
            return;
    }

    if(IR_root->left != NULL){
        IR_print(IR_root->left, fp, count_node - 1);
    }
    if(IR_root->right != NULL){
        IR_print(IR_root->right, fp, count_node - 1);
    }

    return;
}

void IR_translate_program(IR_NODE IR_root) {

}
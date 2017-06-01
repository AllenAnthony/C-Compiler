#include "semant.hpp"
#include "abs.hpp"

#include "symbol.hpp"
#include "function.hpp"
#include "IR.hpp"
#include "util.hpp"
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

IR_NODE SEM_ID(ABS_ID abs_id) {
    cout << "SEM_ID(" << abs_id->id << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.id = abs_id->id;
    return node;
}

IR_NODE SEM_IVAL(ABS_IVAL ival) {
    cout << "SEM_IVAL(" << ival->ival << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(IR_NODE));
    node->ir_node_type = IR;
    node->leaf.id = abs_id->id;
    return ival->ival;
}

IR_NODE SEM_FVAL(ABS_FVAL fval) {
    cout << "SEM_FVAL(" << fval->fval << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(IR_NODE));
    node->ir_node_type = IR_NODE_IVAL;
    node->leaf.fval = fval->fval;
    return node;
}

IR_NODE SEM_CVAL(ABS_CVAL cval) {
    cout << "SEM_CVAL(" << cval->cval << ")" << endl;
    return cval->cval;
}

IR_NODE SEM_expression_list(ABS_expression_list expression_list) {
    cout << "SEM_expression_list(" << func_depth++ << endl;
    IR_NODE node_list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node_list->ir_node_type = IR_NODE_LIST;
    vector<ABS_expression>::iterator expression_list_it = expression_list->expression_list.begin();
    for (; expression_list_it != expression_list->expression_list.end(); expression_list_it++) {
        node_list->list->node_list.push_back(SEM_expression(*expression_list_it));
    }
    cout << ")" << func_depth-- << endl;
    return node_list;
}

IR_NODE SEM_expression(ABS_expression expression) {
    cout << "SEM_expression(" << func_depth++ << endl;
    if (expression->type == ENUM_assignment_expression) {
        SEM_assignment_expression(expression->assignment_expression);
    } else if (expression->type == ENUM_compound_expression) {
        SEM_compound_expression(expression->compound_expression);
    } else {
        cout << "Unknown expression" << endl;
    }
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_assignment_expression(ABS_assignment_expression assignment_expression) {
    cout << "SEM_assignment_expression(" << func_depth++ << endl;
    string id = SEM_ID(assignment_expression->abs_id);
    if (assignment_expression->compound_expression_index) {
        SEM_compound_expression(assignment_expression->compound_expression_index);
    }
    SEM_compound_expression(assignment_expression->compound_expression_value);
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_primary_expression(ABS_primary_expression primary_expression) {
    cout << "SEM_primary_expression(" << func_depth++ << endl;
    if (primary_expression->type == ENUM_ID) {
        string id = SEM_ID(primary_expression->id);
//        if (!curr_env->find(SEM_ID(primary_expression->id))) {
//            cout << "Unknown id:" << primary_expression->id->id;
//            exit(0);
//        }
    } else if (primary_expression->type == ENUM_constant) {
//        string id = SEM_ID(primary_expression->id);
//        Symbol symbol = curr_env->find(id);
//        if (!symbol && primary_expression->constant->type != symbol->type) {
//            cout << "the type of const do not agree with the type of id" << endl;
//            exit(0);
//        }
        SEM_constant(primary_expression->constant);
    } else if (primary_expression->type == ENUM_compound_expression) {
        SEM_compound_expression(primary_expression->compound_expression);
    } else if (primary_expression->type == ENUM_function_invoking) {
        SEM_function_invoking(primary_expression->function_invoking);
    } else {
        cout << "Unknown primary_expression" << endl;
    }
    cout << ")" << func_depth-- << endl;
}


IR_NODE SEM_constant(ABS_constant constant) {
    cout << "SEM_constant(" << func_depth++ << endl;

    if (constant->type == ENUM_IVAL) {
        SEM_IVAL(constant->abs_ival);
    } else if (constant->type == ENUM_FVAL) {
        SEM_FVAL(constant->abs_fval);
    } else if (constant->type == ENUM_CVAL) {
        SEM_CVAL(constant->abs_cval);
    } else {
        printf("<<func_depth++type of the constant do not exist");
    }
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_function_invoking(ABS_function_invoking function_invoking) {
    cout << "SEM_function_invoking(" << func_depth++ << endl;

//    if(!curr_env->find(function_invoking->abs_id->id)){
//        printf("<<func_depth++id do not exist : %s",primary_expression->id);
//        exit(0);
//    }
    SEM_ID(function_invoking->abs_id);
    SEM_argue_list(function_invoking->argue_list);
}

IR_NODE SEM_argue_list(ABS_argue_list argue_list) {
    cout << "SEM_argue_list(" << func_depth++ << endl;

    vector<ABS_ID>::iterator argue_list_it = argue_list->list.begin();
    for (; argue_list_it != argue_list->list.end(); argue_list_it++) {
        SEM_ID((*argue_list_it));
    }
    cout << ")" << func_depth-- << endl;
}


IR_NODE SEM_compound_expression(ABS_compound_expression compound_expression) {
    cout << "SEM_compound_expression(" << func_depth++ << endl;

    if (compound_expression->compound_expression != NULL)
        SEM_compound_expression(compound_expression->compound_expression);

    SEM_primary_expression(compound_expression->primary_expression);

    cout << ")" << func_depth-- << endl;
}


IR_NODE SEM_declaration_list(ABS_declaration_list declaration_list) {
    cout << "SEM_declaration_list(" << func_depth++ << endl;

    IR_NODE list = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    list->right = NULL;
    list->return_type = IR_LEAF_VOID;
    vector<ABS_declaration>::iterator declaration_list_it = declaration_list->declaration_list.begin();
    for (; declaration_list_it != declaration_list->declaration_list.end(); declaration_list_it++) {
        list->list.push_back(SEM_declaration(*declaration_list_it));
    }
    cout << ")" << func_depth-- << endl;
    return list;
}

IR_NODE SEM_declaration(ABS_declaration declaration) {
    cout << "SEM_declaration(" << func_depth++ << endl;

    IR_NODE node = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_NONE;
    node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    ENUM_specifier type = SEM_specifier(declaration->type_specifier);
    node->left = SEM_init_declarator_list(type, declaration->init_declarator_list);

    cout << ")" << func_depth-- << endl;
    return node;
}

ENUM_specifier SEM_specifier(ABS_specifier specifier) {
    cout << "SEM_specifier("<<endl;

    switch (specifier->type) {
        case ENUM_INT:
            cout << "int";
            break;
        case ENUM_FLOAT:
            cout << "float";
            break;
        case ENUM_CHAR:
            cout << "char";
            break;
        default:
            cout << "undefined_type ";
            exit(1);
    }
    cout << ")";
    return specifier->type;
}

IR_NODE SEM_init_declarator_list(ENUM_specifier type, ABS_init_declarator_list init_declarator_list) {
    cout << "SEM_init_declarator_list(" << func_depth++ << endl;

    IR_NODE list = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    list->right = NULL;
    list->return_type = IR_LEAF_VOID;
    vector<ABS_init_declarator>::iterator init_declarator_list_it = init_declarator_list->init_declarator_list.begin();
    for (; init_declarator_list_it != init_declarator_list->init_declarator_list.end(); init_declarator_list_it++) {
        list->list.push_back(SEM_init_declarator(type, *init_declarator_list_it));
    }
    cout << ")" << func_depth-- << endl;

    return list;
}

IR_NODE SEM_init_declarator(ENUM_specifier type, ABS_init_declarator init_declarator) {
    cout << "SEM_init_declarator(" << func_depth++ << endl;

    IR_NODE node = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->left = node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    if (init_declarator->constant != NULL) {
        node->left = SEM_constant(init_declarator->constant);
    }
    string id = SEM_ID(init_declarator->id)->leaf.id;
    curr_env->link(id, type);
    cout << ")" << func_depth-- << endl;
    return node;
}

IR_NODE SEM_statement_list(ABS_statement_list statement_list) {
    cout << "SEM_statement_list(" << func_depth++ << endl;

    IR_NODE list = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    list->right = NULL;
    list->return_type = IR_LEAF_VOID;
    vector<ABS_statement>::iterator statement_list_it = statement_list->statement_list.begin();
    for (; statement_list_it != statement_list->statement_list.end(); statement_list_it++) {
        list->list.push_back(SEM_statement(*statement_list_it));
    }
    cout << ")" << func_depth-- << endl;
    return list;
}

IR_NODE SEM_statement(ABS_statement statement) {
    cout << "SEM_statement(" << func_depth++ << endl;

    IR_NODE node = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_NONE;
    node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    switch (statement->type) {
        case ENUM_block_statement:
            node->left = SEM_block_statement(statement->block_statement);
            break;
        case ENUM_expression_statement:
            node->left = SEM_expression_statement(statement->expression_statement);
            break;
        case ENUM_selection_statement:
            node->left = SEM_selection_statement(statement->selection_statement);
            break;
        case ENUM_iteration_statement:
            node->left = SEM_iteration_statement(statement->iteration_statement);
            break;
        case ENUM_jump_statement:
            node->left = SEM_jump_statement(statement->jump_statement);
            break;
        case ENUM_compound_expression:
            node->left = SEM_compound_expression(statement->compound_expression);
            break;
        default:
            cout << "Unknown expression!" << endl;
            exit(1);
    }
    cout << ")" << func_depth-- << endl;

    return node;
}


IR_NODE SEM_block_statement(ABS_block_statement block_statement) {
    cout << "SEM_block_statement(" << func_depth++ << endl;

    IR_NODE node = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_NONE;
    node->left = node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    curr_env->enterScope();
    if (block_statement->declaration_list != NULL) {
        node->left = SEM_declaration_list(block_statement->declaration_list);
    }
    if (block_statement->statement_list != NULL) {
        node->right = SEM_statement_list(block_statement->statement_list);
    }
    curr_env->escapeScope();
    cout << ")" << func_depth-- << endl;
    return node;
}

IR_NODE SEM_expression_statement(ABS_expression_statement expression_statement) {
    IR_NODE node = (IR_NODE)check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_NONE;
    node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    cout << "SEM_expression_statement(" << func_depth++ << endl;
    node->left = SEM_expression_list(expression_statement->expression_list);
    cout << ")" << func_depth-- << endl;
    return node;
}

IR_NODE SEM_selection_statement(ABS_selection_statement selection_statement) {
    cout << "SEM_selection_statement(" << func_depth++ << endl;

    SEM_expression_list(selection_statement->expression_list);
    SEM_statement(selection_statement->statement_if);
    SEM_statement(selection_statement->statement_else);
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_iteration_statement(ABS_iteration_statement iteration_statement) {
    cout << "SEM_iteration_statement(" << func_depth++ << endl;

    if (iteration_statement->expression_list_while != NULL) {
        SEM_expression_list(iteration_statement->expression_list_while);
    } else {
        SEM_expression_statement(iteration_statement->expression_statement_for_left);
        SEM_expression_statement(iteration_statement->expression_statement_for_middle);
        SEM_expression_list(iteration_statement->expression_list_for_right);
    }
    SEM_statement(iteration_statement->statement);
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_jump_statement(ABS_jump_statement jump_statement) {
    cout << "SEM_jump_statement(" << func_depth++ << endl;
    switch (jump_statement->action_type) {
        case ENUM_CONTINUE:
            break;
        case ENUM_BREAK:
            break;
        case ENUM_RETURN:
            SEM_expression_statement(jump_statement->expression_statement);
            break;
        default:
            cout << "Unknow jump_statement" << endl;
            exit(1);
    }
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_program(ABS_program program) {
    cout << "SEM_program(" << func_depth++ << endl;

    if (program->declaration_list != NULL) {
        SEM_declaration_list(program->declaration_list);
    }
    SEM_function_definition_list(program->function_definition_list);
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_function_definition_list(ABS_function_definition_list function_definition_list) {
    cout << "SEM_function_definition_list(" << func_depth++ << endl;
    vector<ABS_function_definition>::iterator function_definition_list_it = function_definition_list->function_definition_list.begin();
    for (; function_definition_list_it !=
           function_definition_list->function_definition_list.end(); function_definition_list_it++) {
        curr_env->enterScope();
        SEM_function_definition(*function_definition_list_it);
        curr_env->escapeScope();
    }
    cout << ")" << func_depth-- << endl;

}

IR_NODE SEM_function_definition(ABS_function_definition function_definition) {
    cout << "SEM_function_definition(" << func_depth++ << endl;
    ENUM_specifier type = SEM_specifier(function_definition->type_specifier);
    string id = SEM_ID(function_definition->id);
    if (function_definition->parameter_list != NULL) {
        curr_env->enterScope();
        SEM_parameter_list(function_definition->parameter_list);
        curr_env->levelAdapt();
    }
    SEM_block_statement(function_definition->block_statement);
    cout << ")" << func_depth-- << endl;

}


IR_NODE SEM_parameter_list(ABS_parameter_list parameter_list) {
    cout << "SEM_parameter_list(" << func_depth++ << endl;
    vector<ABS_parameter>::iterator parameter_list_it = parameter_list->parameter_list.begin();
    for (; parameter_list_it != parameter_list->parameter_list.end(); parameter_list_it++) {
        SEM_parameter(*parameter_list_it);
    }
    cout << ")" << func_depth-- << endl;
}

IR_NODE SEM_parameter(ABS_parameter parameter) {
    cout << "SEM_parameter(" << func_depth++ << endl;
    ENUM_specifier type = SEM_specifier(parameter->type_specifier);
    string id = SEM_ID(parameter->id);
    curr_env->link(id, type);
    cout << ")" << func_depth-- << endl;
}



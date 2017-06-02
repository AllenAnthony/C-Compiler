#include "semant.hpp"

//当前状态
enum SEM_STATE {
    SEM_STATE_STATEMENT,
    SEM_STATE_PARAMETER,
    SEM_STATE_DECLARATION
} curr_state;

IR_NODE SEM_ID(ABS_ID abs_id, ENUM_specifier type) {
    IR_NODE node;
    cout << "SEM_ID(" << abs_id->id << ")" << endl;
    if (type != ENUM_VOID) {
        curr_env->link(abs_id->id, type);
    } else {
        curr_env->find(abs_id->id);
    }
    node = (IR_NODE) check_malloc(sizeof(IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.id = abs_id->id;
    return node;
}

IR_NODE SEM_IVAL(ABS_IVAL ival) {
    cout << "SEM_IVAL(" << ival->ival << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.leaf_type = IR_LEAF_INT;
    node->leaf.ival = ival->ival;
    return node;
}

IR_NODE SEM_FVAL(ABS_FVAL fval) {
    cout << "SEM_FVAL(" << fval->fval << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.leaf_type = IR_LEAF_FLOAT;
    node->leaf.fval = fval->fval;
    return node;
}

IR_NODE SEM_CVAL(ABS_CVAL cval) {
    cout << "SEM_CVAL(" << cval->cval << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.leaf_type = IR_LEAF_CHAR;
    node->leaf.fval = cval->cval;
    return node;
}

IR_NODE SEM_expression_list(ABS_expression_list expression_list) {
    cout << "SEM_expression_list(" << func_depth++ << endl;
    IR_NODE list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    list->right = NULL;
    vector<ABS_expression>::iterator expression_list_it = expression_list->expression_list.begin();
    for (; expression_list_it != expression_list->expression_list.end(); expression_list_it++) {
        list->list.push_back(SEM_expression(*expression_list_it));
    }
    if (list->list.empty()) {
        cout << "expression list empty" << endl;
        exit(1);
    }

    list->return_type = list->list[0]->return_type;
    cout << ")" << func_depth-- << endl;
    return list;
}

IR_NODE SEM_expression(ABS_expression expression) {
    cout << "SEM_expression(" << func_depth++ << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_NONE;
    node->right = NULL;
    if (expression->type == ENUM_assignment_expression) {
        node->left = SEM_assignment_expression(expression->assignment_expression);
        node->return_type = node->left->return_type;
    } else if (expression->type == ENUM_compound_expression) {
        node->left = SEM_compound_expression(expression->compound_expression);
        node->return_type = node->left->return_type;
    } else {
        cout << "Unknown expression" << endl;
    }
    cout << ")" << func_depth-- << endl;

    return node;
}

IR_NODE SEM_assignment_expression(ABS_assignment_expression assignment_expression) {
    cout << "SEM_assignment_expression(" << func_depth++ << endl;

    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_ASSIGN;

    if (assignment_expression->compound_expression_index) {
        node->left = SEM_array_expression(assignment_expression->abs_id,
                                          assignment_expression->compound_expression_index);
    } else {
        node->left = SEM_ID(assignment_expression->abs_id, ENUM_VOID);
    }
    node->right = SEM_compound_expression(assignment_expression->compound_expression_value);
    node->return_type = node->right->return_type;
    cout << ")" << func_depth-- << endl;

    return node;
}

IR_NODE SEM_array_expression(ABS_ID id, ABS_compound_expression abs_index) {
    return NULL;
}

IR_NODE SEM_primary_expression(ABS_primary_expression primary_expression) {
    cout << "SEM_primary_expression(" << func_depth++ << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_NONE;

    if (primary_expression->type == ENUM_ID) {
        node->left = SEM_ID(primary_expression->id, ENUM_VOID);
    } else if (primary_expression->type == ENUM_constant) {
//        string id = SEM_ID(primary_expression->id);
//        Symbol symbol = curr_env->find(id);
//        if (!symbol && primary_expression->constant->type != symbol->type) {
//            cout << "the type of const do not agree with the type of id" << endl;
//            exit(0);
//        }
        node->left = SEM_constant(primary_expression->constant);
    } else if (primary_expression->type == ENUM_compound_expression) {
        node->left = SEM_compound_expression(primary_expression->compound_expression);
    } else if (primary_expression->type == ENUM_function_invoking) {
        node->left = SEM_function_invoking(primary_expression->function_invoking);
    } else {
        cout << "Unknown primary_expression" << endl;
    }
    node->right = NULL;
    node->return_type = node->left->return_type;
    cout << ")" << func_depth-- << endl;

    return node;
}


IR_NODE SEM_constant(ABS_constant constant) {
    cout << "SEM_constant(" << func_depth++ << endl;

    IR_NODE node;
    if (constant->type == ENUM_IVAL) {
        node = SEM_IVAL(constant->abs_ival);
    } else if (constant->type == ENUM_FVAL) {
        node = SEM_FVAL(constant->abs_fval);
    } else if (constant->type == ENUM_CVAL) {
        node = SEM_CVAL(constant->abs_cval);
    } else {
        printf("<<func_depth++type of the constant do not exist");
    }
    cout << ")" << func_depth-- << endl;

    return node;
}

IR_NODE SEM_function_invoking(ABS_function_invoking function_invoking) {
    cout << "SEM_function_invoking(" << func_depth++ << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_FUNC;
    if (!curr_func->find(function_invoking->abs_id->id)) {
        cout << "function id do not exist :" << function_invoking->abs_id->id;
        exit(1);
    }
    node->left = SEM_ID(function_invoking->abs_id, ENUM_VOID);
    node->right = SEM_argue_list(function_invoking->argue_list);

    ENUM_node_type node_type = curr_func->find(function_invoking->abs_id->id)->ret_type;

    if (node_type == ENUM_IVAL) {
        node->return_type = IR_LEAF_INT;
    } else if (node_type == ENUM_FVAL) {
        node->return_type = IR_LEAF_FLOAT;
    } else if (node_type == ENUM_CVAL) {
        node->return_type = IR_LEAF_CHAR;
    } else {
        cout << "type of the constant do not exist" << endl;
    }
//    if(!curr_env->find(function_invoking->abs_id->id)){
//        printf("<<func_depth++id do not exist : %s",primary_expression->id);
//        exit(0);
//    }
    return node;
}

IR_NODE SEM_argue_list(ABS_argue_list argue_list) {
    cout << "SEM_argue_list(" << func_depth++ << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_LIST;
    vector<ABS_ID>::iterator argue_list_it = argue_list->list.begin();
    for (; argue_list_it != argue_list->list.end(); argue_list_it++) {
        node->list.push_back(SEM_ID((*argue_list_it), ENUM_VOID));
    }
    node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    cout << ")" << func_depth-- << endl;

    return node;
}


IR_NODE SEM_compound_expression(ABS_compound_expression compound_expression) {
    cout << "SEM_compound_expression(" << func_depth++ << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_NONE;
    if (compound_expression->compound_expression != NULL) {
        node->left = SEM_compound_expression(compound_expression->compound_expression);
        node->right = SEM_primary_expression(compound_expression->primary_expression);
        node->return_type = node->left->return_type;
    } else {
        node->left = SEM_primary_expression(compound_expression->primary_expression);
        node->return_type = node->left->return_type;
        node->right = NULL;
    }
    cout << ")" << func_depth-- << endl;

    return node;
}


IR_NODE SEM_declaration_list(ABS_declaration_list declaration_list) {
    cout << "SEM_declaration_list(" << func_depth++ << endl;

    IR_NODE list = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
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

    IR_NODE node = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_NONE;
    node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    ENUM_specifier type = SEM_specifier(declaration->type_specifier);
    node->left = SEM_init_declarator_list(type, declaration->init_declarator_list);

    cout << ")" << func_depth-- << endl;
    return node;
}

ENUM_specifier SEM_specifier(ABS_specifier specifier) {
    cout << "SEM_specifier(" << endl;

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

    IR_NODE list = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
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

    IR_NODE node = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->left = node->right = NULL;
    node->return_type = IR_LEAF_VOID;
    if (init_declarator->constant != NULL) {
        node->left = SEM_constant(init_declarator->constant);
    }
    string id = SEM_ID(init_declarator->id, ENUM_VOID)->leaf.id;
    curr_env->link(id, type);
    cout << ")" << func_depth-- << endl;
    return node;
}

IR_NODE SEM_statement_list(ABS_statement_list statement_list) {
    cout << "SEM_statement_list(" << func_depth++ << endl;
    IR_NODE list = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
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
    IR_NODE node;
    switch (statement->type) {
        case ENUM_block_statement:
            node = SEM_block_statement(statement->block_statement);
            break;
        case ENUM_expression_statement:
            node = SEM_expression_statement(statement->expression_statement);
            break;
        case ENUM_selection_statement:
            node = SEM_selection_statement(statement->selection_statement);
            break;
        case ENUM_iteration_statement:
            node = SEM_iteration_statement(statement->iteration_statement);
            break;
        case ENUM_jump_statement:
            node = SEM_jump_statement(statement->jump_statement);
            break;
        case ENUM_compound_expression:
            node = SEM_compound_expression(statement->compound_expression);
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

    IR_NODE node = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
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
    IR_NODE node = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
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
    //创建父节点为list
    IR_NODE node = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    node->ir_node_type = IR_NODE_LIST;

    //select需要3个label
    IR_NODE label1 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;

    IR_NODE label2 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;

    IR_NODE label3 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;


    //一个branch
    IR_NODE branch = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    branch->ir_node_type = IR_NODE_BRANCH;
    branch->left = label1;

    //两个JUMP
    IR_NODE jump1 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    jump1->ir_node_type = IR_NODE_JUMP;
    jump1->left = label2;

    IR_NODE jump2 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    jump2->ir_node_type = IR_NODE_JUMP;
    jump2->left = label3;


    //计算exp并连接上父节点
    node->list.push_back(SEM_expression_list(selection_statement->expression_list));
    node->list.push_back(branch);
    node->list.push_back(jump1);
    node->list.push_back(label1);
    node->list.push_back(SEM_statement(selection_statement->statement_if));
    node->list.push_back(jump2);
    node->list.push_back(label2);
    node->list.push_back(SEM_statement(selection_statement->statement_else));
    node->list.push_back(label3);
    cout << ")" << func_depth-- << endl;
    return node;
}

IR_NODE SEM_iteration_statement(ABS_iteration_statement iteration_statement) {
    cout << "SEM_iteration_statement(" << func_depth++ << endl;

    IR_NODE node_list = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    node_list->ir_node_type = IR_NODE_LIST;

    //select需要3个label
    IR_NODE label1 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;

    IR_NODE label2 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;

    IR_NODE label3 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;


    //一个branch
    IR_NODE branch = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    branch->ir_node_type = IR_NODE_BRANCH;
    branch->left = label2;

    //两个JUMP
    IR_NODE jump1 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    jump1->ir_node_type = IR_NODE_JUMP;
    jump1->left = label3;

    IR_NODE jump2 = (IR_NODE) check_malloc(sizeof(struct _IR_NODE));
    jump2->ir_node_type = IR_NODE_JUMP;
    jump2->left = label1;

    if (iteration_statement->expression_list_while != NULL) {
        node_list->list.push_back(label1);
        node_list->list.push_back(SEM_expression_list(iteration_statement->expression_list_while));
        node_list->list.push_back(branch);
        node_list->list.push_back(jump1);
        node_list->list.push_back(label2);
        node_list->list.push_back(SEM_statement(iteration_statement->statement));
        node_list->list.push_back(jump2);
    } else {
        node_list->list.push_back(SEM_expression_statement(iteration_statement->expression_statement_for_left));
        node_list->list.push_back(label1);
        node_list->list.push_back(SEM_expression_statement(iteration_statement->expression_statement_for_middle));
        node_list->list.push_back(branch);
        node_list->list.push_back(jump1);
        node_list->list.push_back(label2);
        node_list->list.push_back(SEM_statement(iteration_statement->statement));
        node_list->list.push_back(SEM_expression_list(iteration_statement->expression_list_for_right));
        node_list->list.push_back(jump2);
    }
    cout << ")" << func_depth-- << endl;
    return node_list;
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
    return NULL;
}

IR_NODE SEM_program(ABS_program program) {
    cout << "SEM_program(" << func_depth++ << endl;
    IR_NODE node;
    if (program->declaration_list != NULL) {
        node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
        node->ir_node_type = IR_NODE_NONE;
        node->left = SEM_declaration_list(program->declaration_list);
        node->right = SEM_function_definition_list(program->function_definition_list);
    } else {
        node = SEM_function_definition_list(program->function_definition_list);
    }
    cout << ")" << func_depth-- << endl;
    return node;
}

IR_NODE SEM_function_definition_list(ABS_function_definition_list function_definition_list) {
    cout << "SEM_function_definition_list(" << func_depth++ << endl;

    IR_NODE node_list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node_list->ir_node_type = IR_NODE_LIST;

    vector<ABS_function_definition>::iterator function_definition_list_it = function_definition_list->function_definition_list.begin();
    for (; function_definition_list_it !=
           function_definition_list->function_definition_list.end(); function_definition_list_it++) {
        curr_env->enterScope();
        node_list->list.push_back(SEM_function_definition(*function_definition_list_it));
        curr_env->escapeScope();
    }
    cout << ")" << func_depth-- << endl;
    return node_list;
}

IR_NODE SEM_function_definition(ABS_function_definition function_definition) {
    cout << "SEM_function_definition(" << func_depth++ << endl;
    ENUM_specifier type = SEM_specifier(function_definition->type_specifier);
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_FUNC;
    SEM_ID(function_definition->id, ENUM_VOID);
    if (function_definition->parameter_list != NULL) {
        curr_env->enterScope();
        SEM_parameter_list(function_definition->parameter_list);
        curr_env->levelAdapt();
    }
    SEM_block_statement(function_definition->block_statement);
    cout << ")" << func_depth-- << endl;
    return NULL;
}


IR_NODE SEM_parameter_list(ABS_parameter_list parameter_list) {
    cout << "SEM_parameter_list(" << func_depth++ << endl;
    IR_NODE node_list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node_list->ir_node_type = IR_NODE_LIST;

    vector<ABS_parameter>::iterator parameter_list_it = parameter_list->parameter_list.begin();
    for (; parameter_list_it != parameter_list->parameter_list.end(); parameter_list_it++) {
        node_list->list.push_back(SEM_parameter(*parameter_list_it));
    }
    cout << ")" << func_depth-- << endl;
    return node_list;
}

IR_NODE SEM_parameter(ABS_parameter parameter) {
    cout << "SEM_parameter(" << func_depth++ << endl;
    ENUM_specifier specifier = SEM_specifier(parameter->type_specifier);
    IR_NODE node = SEM_ID(parameter->id, specifier);
    cout << ")" << func_depth-- << endl;
    return node;
}



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
        Symbol symbol = curr_env->link(abs_id->id, type);
        if (symbol == NULL) {
            cout << "Variable " << abs_id->id << "failed to link" << endl;
            exit(1);
        }
    } else {
        Symbol symbol = curr_env->find(abs_id->id);
        if (symbol == NULL) {
            cout << "Undefined variable: " << abs_id->id << endl;
            exit(1);
        }
    }
    node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.leaf_type = IR_LEAF_ID;
    node->leaf.id = abs_id->id;
    return node;
}

IR_NODE SEM_IVAL(ABS_IVAL ival) {
    cout << "SEM_IVAL(" << ival->ival << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.leaf_type = IR_LEAF_INT;
    node->leaf.ival = ival->ival;
    return node;
}

IR_NODE SEM_FVAL(ABS_FVAL fval) {
    cout << "SEM_FVAL(" << fval->fval << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.leaf_type = IR_LEAF_FLOAT;
    node->leaf.fval = fval->fval;
    return node;
}

IR_NODE SEM_CVAL(ABS_CVAL cval) {
    cout << "SEM_CVAL(" << cval->cval << ")" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_LEAF;
    node->leaf.leaf_type = IR_LEAF_CHAR;
    node->leaf.fval = cval->cval;
    return node;
}

IR_NODE SEM_expression_list(ABS_expression_list expression_list) {
    size_t list_size = expression_list->expression_list.size();
    if (list_size == 1) {
        return SEM_expression(expression_list->expression_list[0]);
    }

    cout << "SEM_expression_list(" << endl;
    IR_NODE list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    vector<ABS_expression>::iterator expression_list_it = expression_list->expression_list.begin();
    for (; expression_list_it != expression_list->expression_list.end(); expression_list_it++) {
        list->list.push_back(SEM_expression(*expression_list_it));
    }
    if (list->list.empty()) {
        cout << "expression list empty" << endl;
        exit(1);
    }

    list->return_type = list->list[list_size - 1]->return_type;
    cout << ")" << endl;
    return list;
}

IR_NODE SEM_expression(ABS_expression expression) {
    cout << "SEM_expression(" << endl;
    IR_NODE node;
    if (expression->type == ENUM_assignment_expression) {
        node = SEM_assignment_expression(expression->assignment_expression);
    } else if (expression->type == ENUM_compound_expression) {
        node = SEM_compound_expression(expression->compound_expression);
    } else {
        cout << "Line" << line << ": " << "Unknown expression" << endl;
        exit(1);
    }
    cout << ")" << endl;

    return node;
}

IR_NODE SEM_assignment_expression(ABS_assignment_expression assignment_expression) {
    cout << "SEM_assignment_expression(" << endl;

    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_ASSIGN;

    if (assignment_expression->compound_expression_index == NULL) {
        node->left = SEM_ID(assignment_expression->abs_id, ENUM_VOID);
        node->right = SEM_compound_expression(assignment_expression->compound_expression_value);
    } else {
        node->left = SEM_array_expression(assignment_expression->abs_id,
                                          assignment_expression->compound_expression_index);
        node->right = SEM_compound_expression(assignment_expression->compound_expression_value);
    }
    cout << ")" << endl;
    return node;
}

IR_NODE SEM_array_expression(ABS_ID abs_id, ABS_compound_expression index) {
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->left = SEM_ID(abs_id, ENUM_VOID);
    node->right = SEM_compound_expression(index);
    node->ir_node_type = IR_NODE_ASSIGN;
    return node;
}

IR_NODE SEM_primary_expression(ABS_primary_expression primary_expression) {
    cout << "SEM_primary_expression(" << endl;
    IR_NODE node;
    if (primary_expression->type == ENUM_ID) {
        node = SEM_ID(primary_expression->id, ENUM_VOID);
    } else if (primary_expression->type == ENUM_constant) {
        node = SEM_constant(primary_expression->constant);
    } else if (primary_expression->type == ENUM_compound_expression) {
        node = SEM_compound_expression(primary_expression->compound_expression);
    } else if (primary_expression->type == ENUM_function_invoking) {
        node = SEM_function_invoking(primary_expression->function_invoking);
    } else {
        cout << "Unknown primary_expression" << endl;
        exit(1);
    }
    cout << ")" << endl;
    return node;
}


IR_NODE SEM_constant(ABS_constant constant) {
    cout << "SEM_constant(" << endl;

    IR_NODE node;
    if (constant->type == ENUM_IVAL) {
        node = SEM_IVAL(constant->abs_ival);
    } else if (constant->type == ENUM_FVAL) {
        node = SEM_FVAL(constant->abs_fval);
    } else if (constant->type == ENUM_CVAL) {
        node = SEM_CVAL(constant->abs_cval);
    } else {
        cout << "<<++func_depthtype of the constant do not exist";
        exit(1);
    }
    cout << ")" << endl;

    return node;
}

IR_NODE SEM_function_invoking(ABS_function_invoking function_invoking) {
    cout << "SEM_function_invoking(" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_CALL;
    if (!curr_func->find(function_invoking->abs_id->id)) {
        cout << "Line" << line << ": " << "function id do not exist :" << function_invoking->abs_id->id;
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

    return node;
}

IR_NODE SEM_argue_list(ABS_argue_list argue_list) {
    size_t list_size = argue_list->list.size();
    if (list_size == 1) {
        return SEM_ID(argue_list->list[0], ENUM_VOID);
    }

    cout << "SEM_argue_list(" << endl;
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_LIST;
    for (int i = 0; i < argue_list->list.size(); i++) {
        node->list.push_back(SEM_ID(argue_list->list[i], ENUM_VOID));
    }
    node->return_type = IR_LEAF_VOID;
    cout << ")" << endl;

    return node;
}


IR_NODE SEM_compound_expression(ABS_compound_expression compound_expression) {
    cout << "SEM_compound_expression(" << endl;
    IR_NODE node;
    if (compound_expression->compound_expression1 != NULL) {
        node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
        node->ir_node_type = toNodeType(compound_expression->oper_type);
        node->left = SEM_compound_expression(compound_expression->compound_expression1);
        node->right = SEM_compound_expression(compound_expression->compound_expression2);
        node->return_type = node->left->return_type;
    } else {
        node = SEM_primary_expression(compound_expression->primary_expression);
    }
    cout << ")" << endl;

    return node;
}

IR_NODE_type toNodeType(ENUM_oper_type op_type) {
    switch (op_type) {
        case ENUM_MUL:
            return IR_NODE_MUL;
        case ENUM_DIV:
            return IR_NODE_DIV;
        case ENUM_MOD:
            return IR_NODE_MOD;
        case ENUM_PLUS:
            return IR_NODE_PLUS;
        case ENUM_MINUS:
            return IR_NODE_MINUS;
        case ENUM_LT:
            return IR_NODE_LT;
        case ENUM_GT:
            return IR_NODE_GT;
        case ENUM_LE:
            return IR_NODE_LE;
        case ENUM_GE:
            return IR_NODE_GE;
        case ENUM_EQ:
            return IR_NODE_EQ;
        case ENUM_NE:
            return IR_NODE_NE;
        case ENUM_AND:
            return IR_NODE_AND;
        case ENUM_OR:
            return IR_NODE_OR;
        default:
            return IR_NODE_NONE;
    }
}

IR_NODE SEM_declaration_list(ABS_declaration_list declaration_list) {
    size_t list_size = declaration_list->declaration_list.size();

    cout << "SEM_declaration_list(" << endl;
    IR_NODE list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    list->return_type = IR_LEAF_VOID;
    for (int i = 0; i < list_size; i++) {
        list->list.push_back(SEM_declaration(declaration_list->declaration_list[i]));
    }
    cout << ")" << endl;
    return list;
}

IR_NODE SEM_declaration(ABS_declaration declaration) {
    cout << "SEM_declaration(" << endl;

    ENUM_specifier type = SEM_specifier(declaration->type_specifier);
    IR_NODE node = SEM_init_declarator_list(type, declaration->init_declarator_list);

    cout << ")" << endl;
    return node;
}

ENUM_specifier SEM_specifier(ABS_specifier specifier) {
    cout << "SEM_specifier(";

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
    size_t list_size = init_declarator_list->init_declarator_list.size();
    if (list_size == 1) {
        return SEM_init_declarator(type, init_declarator_list->init_declarator_list[0]);
    }

    cout << "SEM_init_declarator_list(" << endl;

    IR_NODE list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    list->return_type = IR_LEAF_VOID;
    vector<ABS_init_declarator>::iterator init_declarator_list_it = init_declarator_list->init_declarator_list.begin();
    for (; init_declarator_list_it != init_declarator_list->init_declarator_list.end(); init_declarator_list_it++) {
        list->list.push_back(SEM_init_declarator(type, *init_declarator_list_it));
    }
    cout << ")" << endl;

    return list;
}

IR_NODE SEM_init_declarator(ENUM_specifier type, ABS_init_declarator init_declarator) {
    cout << "SEM_init_declarator(" << endl;
    IR_NODE node;
    if (init_declarator->constant != NULL) {
        node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
        node->ir_node_type = IR_NODE_LEAF;
        node->return_type = IR_LEAF_VOID;

        node->left = SEM_constant(init_declarator->constant);
        node->right = SEM_ID(init_declarator->id, type);
    } else {
        node = SEM_ID(init_declarator->id, type);
    }
    cout << ")" << endl;
    return node;
}

IR_NODE SEM_statement_list(ABS_statement_list statement_list) {
    size_t list_size = statement_list->statement_list.size();
    if (list_size == 1) {
        return SEM_statement(statement_list->statement_list[0]);
    }

    cout << "SEM_statement_list(" << endl;
    IR_NODE list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    list->ir_node_type = IR_NODE_LIST;
    list->return_type = IR_LEAF_VOID;
    vector<ABS_statement>::iterator statement_list_it = statement_list->statement_list.begin();
    for (; statement_list_it != statement_list->statement_list.end(); statement_list_it++) {
        list->list.push_back(SEM_statement(*statement_list_it));
    }
    cout << ")" << endl;
    return list;
}

IR_NODE SEM_statement(ABS_statement statement) {
    cout << "SEM_statement(" << endl;
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
    cout << ")" << endl;
    return node;
}


IR_NODE SEM_block_statement(ABS_block_statement block_statement) {
    cout << "SEM_block_statement(" << endl;

    IR_NODE node;
    curr_env->enterScope();
    if (block_statement->declaration_list != NULL && block_statement->statement_list != NULL) {
        node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
        node->ir_node_type = IR_NODE_NONE;
        node->return_type = IR_LEAF_VOID;
        node->left = SEM_declaration_list(block_statement->declaration_list);
        node->right = SEM_statement_list(block_statement->statement_list);
    } else if (block_statement->declaration_list != NULL) {
        node = SEM_declaration_list(block_statement->declaration_list);
    } else if (block_statement->statement_list != NULL) {
        node = SEM_statement_list(block_statement->statement_list);
    }else{
        node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
        node->ir_node_type = IR_NODE_LIST;
    }
    curr_env->escapeScope();

    cout << ")" << endl;
    return node;
}

IR_NODE SEM_expression_statement(ABS_expression_statement expression_statement) {
    IR_NODE node;
    cout << "SEM_expression_statement(" << endl;
    node = SEM_expression_list(expression_statement->expression_list);
    cout << ")" << endl;
    return node;
}


IR_NODE SEM_selection_statement(ABS_selection_statement selection_statement) {
    cout << "SEM_selection_statement(" << endl;
    //创建父节点为list
    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_LIST;

    //select需要3个label
    IR_NODE label1 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;

    IR_NODE label2 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    label2->ir_node_type = IR_NODE_LABEL;
    label2->label = curr_iter_label_count++;

    IR_NODE label3 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    label3->ir_node_type = IR_NODE_LABEL;
    label3->label = curr_iter_label_count++;


    //一个branch
    IR_NODE branch = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    branch->ir_node_type = IR_NODE_BRANCH;
    branch->left = label1;

    //两个JUMP
    IR_NODE jump1 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    jump1->ir_node_type = IR_NODE_JUMP;
    jump1->left = label2;

    IR_NODE jump2 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
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
    cout << ")" << endl;
    return node;
}

IR_NODE SEM_iteration_statement(ABS_iteration_statement iteration_statement) {
    cout << "SEM_iteration_statement(" << endl;

    IR_NODE node_list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node_list->ir_node_type = IR_NODE_LIST;

    //select需要3个label
    IR_NODE label1 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    label1->ir_node_type = IR_NODE_LABEL;
    label1->label = curr_iter_label_count++;

    IR_NODE label2 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    label2->ir_node_type = IR_NODE_LABEL;
    label2->label = curr_iter_label_count++;

    IR_NODE label3 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    label3->ir_node_type = IR_NODE_LABEL;
    label3->label = curr_iter_label_count++;


    //一个branch
    IR_NODE branch = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    branch->ir_node_type = IR_NODE_BRANCH;
    branch->left = label2;

    //两个JUMP
    IR_NODE jump1 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    jump1->ir_node_type = IR_NODE_JUMP;
    jump1->left = label3;

    IR_NODE jump2 = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    jump2->ir_node_type = IR_NODE_JUMP;
    jump2->left = label1;

    iter_label_head.push_back(curr_iter_label_head);
    iter_label_tail.push_back(curr_iter_label_tail);
    curr_iter_label_head = label1->label;
    curr_iter_label_tail = label3->label;

    if (iteration_statement->expression_list_while != NULL) {
        node_list->list.push_back(label1);
        node_list->list.push_back(SEM_expression_list(iteration_statement->expression_list_while));
        node_list->list.push_back(branch);
        node_list->list.push_back(jump1);
        node_list->list.push_back(label2);
        node_list->list.push_back(SEM_statement(iteration_statement->statement));
        node_list->list.push_back(jump2);
        node_list->list.push_back(label3);
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
        node_list->list.push_back(label3);
    }
    curr_iter_label_head = iter_label_head.back();
    curr_iter_label_tail = iter_label_tail.back();
    iter_label_head.pop_back();
    iter_label_tail.pop_back();
    cout << ")" << endl;
    return node_list;
}

IR_NODE SEM_jump_statement(ABS_jump_statement jump_statement) {
    cout << "SEM_jump_statement(" << endl;
    IR_NODE node;
    IR_NODE label;
    IR_NODE jump;
    switch (jump_statement->action_type) {
        case ENUM_CONTINUE:
            label = (IR_NODE) check_malloc(sizeof(_IR_NODE));
            label->ir_node_type = IR_NODE_LABEL;
            label->label = curr_iter_label_head;
            jump = (IR_NODE) check_malloc(sizeof(_IR_NODE));
            jump->ir_node_type = IR_NODE_JUMP;
            jump->left = label;
            node = jump;
            break;
        case ENUM_BREAK:
            label = (IR_NODE) check_malloc(sizeof(_IR_NODE));
            label->ir_node_type = IR_NODE_LABEL;
            label->label = curr_iter_label_tail;
            jump = (IR_NODE) check_malloc(sizeof(_IR_NODE));
            jump->ir_node_type = IR_NODE_JUMP;
            jump->left = label;
            node = jump;
            break;
        case ENUM_RETURN:
            node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
            node->ir_node_type = IR_NODE_RETURN;
            node->left = SEM_expression_statement(jump_statement->expression_statement);
            break;
        default:
            cout << "Unknow jump_statement" << endl;
            exit(1);
    }
    cout << ")" << endl;
    return node;
}

IR_NODE SEM_program(ABS_program program) {
    cout << "SEM_program(" << endl;
    IR_NODE node;
    if (program->declaration_list != NULL) {
        node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
        node->ir_node_type = IR_NODE_NONE;
        node->left = SEM_declaration_list(program->declaration_list);
        node->right = SEM_function_definition_list(program->function_definition_list);
    } else {
        node = SEM_function_definition_list(program->function_definition_list);
    }
    cout << ")" << endl;
    return node;
}

IR_NODE SEM_function_definition_list(ABS_function_definition_list function_definition_list) {
    if (function_definition_list->function_definition_list.size() == 1) {
        return SEM_function_definition(function_definition_list->function_definition_list[0]);
    }
    cout << "SEM_function_definition_list(" << endl;

    IR_NODE node_list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node_list->ir_node_type = IR_NODE_LIST;

    vector<ABS_function_definition>::iterator function_definition_list_it = function_definition_list->function_definition_list.begin();
    for (; function_definition_list_it !=
           function_definition_list->function_definition_list.end(); function_definition_list_it++) {
        node_list->list.push_back(SEM_function_definition(*function_definition_list_it));
    }
    cout << ")" << endl;
    return node_list;
}

IR_NODE SEM_function_definition(ABS_function_definition function_definition) {
    cout << "SEM_function_definition(" << endl;
    ENUM_specifier type = SEM_specifier(function_definition->type_specifier);
    _Func func;
    func.id = function_definition->id->id;
    size_t list_size = function_definition->parameter_list->parameter_list.size();
    for (size_t i = 0; i < list_size; i++) {
        func.param_list.push_back(function_definition->parameter_list->parameter_list[i]->type_specifier->type);
    }
    switch (func.param_list[list_size - 1]) {
        case ENUM_INT:
            func.ret_type = ENUM_IVAL;
            break;
        case ENUM_FLOAT:
            func.ret_type = ENUM_FVAL;
            break;
        case ENUM_CHAR:
            func.ret_type = ENUM_CVAL;
            break;
        default:
            cout << "Invalid type defined!" << endl;
            exit(1);
    }
    curr_func->link(func.id, func);

    IR_NODE node = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node->ir_node_type = IR_NODE_FUNC;
    node->list.push_back(SEM_ID(function_definition->id, type));
    if (function_definition->parameter_list != NULL) {
        curr_env->enterScope();
        node->list.push_back(SEM_parameter_list(function_definition->parameter_list));
        curr_env->levelAdapt();
    }
    node->list.push_back(SEM_block_statement(function_definition->block_statement));
    cout << ")" << endl;
    return node;
}


IR_NODE SEM_parameter_list(ABS_parameter_list parameter_list) {
    cout << "SEM_parameter_list(" << endl;
    IR_NODE node_list = (IR_NODE) check_malloc(sizeof(_IR_NODE));
    node_list->ir_node_type = IR_NODE_LIST;


    vector<ABS_parameter>::iterator parameter_list_it = parameter_list->parameter_list.begin();
    for (; parameter_list_it != parameter_list->parameter_list.end(); parameter_list_it++) {
        node_list->list.push_back(SEM_parameter(*parameter_list_it));
    }
    cout << ")" << endl;
    return node_list;
}

IR_NODE SEM_parameter(ABS_parameter parameter) {
    cout << "SEM_parameter(" << endl;
    ENUM_specifier specifier = SEM_specifier(parameter->type_specifier);
    IR_NODE node = SEM_ID(parameter->id, specifier);
    cout << ")" << endl;
    return node;
}



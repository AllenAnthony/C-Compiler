#include "abs.hpp"

ABS_ID F_ABS_ID(char *id) {
    ABS_ID abs_id = (ABS_ID) check_malloc(sizeof(_ABS_ID));
    abs_id->id = string(id);
    return abs_id;
}


ABS_IVAL F_ABS_IVAL(int ival) {
    ABS_IVAL abs_ival = (ABS_IVAL) check_malloc(sizeof(_ABS_IVAL));
    abs_ival->ival = ival;
    return abs_ival;
}


ABS_FVAL F_ABS_FVAL(float fval) {
    ABS_FVAL abs_fval = (ABS_FVAL) check_malloc(sizeof(_ABS_FVAL));
    abs_fval->fval = fval;
    return abs_fval;
}


ABS_CVAL F_ABS_CVAL(char cval) {
    ABS_CVAL abs_cval = (ABS_CVAL) check_malloc(sizeof(_ABS_CVAL));
    abs_cval->cval = cval;
    return abs_cval;
}

ABS_expression_list F_ABS_expression_list(
        ABS_expression_list expression_list,
        ABS_expression expression
) {
    if (expression_list == NULL) {
        expression_list = (ABS_expression_list) check_malloc(sizeof(_ABS_expression_list));
    }
    expression_list->expression_list.push_back(expression);
    return expression_list;
}


ABS_expression F_ABS_expression(
        ENUM_node_type type,
        ABS_assignment_expression assignment_expression,
        ABS_compound_expression compound_expression
) {
    ABS_expression expression = (ABS_expression) check_malloc(sizeof(_ABS_expression));
    expression->type = type;
    switch (type) {
        case ENUM_assignment_expression:
            assert(assignment_expression);
            expression->assignment_expression = assignment_expression;
            break;
        case ENUM_compound_expression:
            assert(compound_expression);
            expression->compound_expression = compound_expression;
            break;
        default:
            cout << "Undefined type";
            exit(0);
    }
    return expression;
}

ABS_assignment_expression F_ABS_assignment_expression(
        ABS_ID abs_id,
        ABS_compound_expression compound_expression_index,
        ABS_compound_expression compound_expression_value
) {
    ABS_assignment_expression assignment_expression = (ABS_assignment_expression) check_malloc(
            sizeof(_ABS_assignment_expression));
    assignment_expression->abs_id = abs_id;
    assignment_expression->compound_expression_index = compound_expression_index;
    assignment_expression->compound_expression_value = compound_expression_value;
    return assignment_expression;
}

ABS_primary_expression F_ABS_primary_expression(
        ENUM_node_type type,
        ABS_ID id,
        ABS_constant constant,
        ABS_compound_expression compound_expression,
        ABS_function_invoking function_invoking
) {
    ABS_primary_expression primary_expression = (ABS_primary_expression) check_malloc(sizeof(_ABS_primary_expression));
    primary_expression->type = type;
    switch (type) {
        case ENUM_ID:
            primary_expression->id = id;
            break;
        case ENUM_constant:
            primary_expression->constant = constant;
            break;
        case ENUM_compound_expression:
            primary_expression->compound_expression = compound_expression;
            break;
        case ENUM_function_invoking:
            primary_expression->function_invoking = function_invoking;
            break;
        default:
            cout << "Undefined type";
            exit(0);
    }
    return primary_expression;
}


ABS_constant F_ABS_constant(
        ENUM_node_type type,
        ABS_IVAL abs_ival,
        ABS_FVAL abs_fval,
        ABS_CVAL abs_cval
) {
    ABS_constant constant = (ABS_constant) check_malloc(sizeof(_ABS_constant));
    constant->type = type;
    switch (type) {
        case ENUM_IVAL:
            constant->abs_ival = abs_ival;
            break;
        case ENUM_FVAL:
            constant->abs_fval = abs_fval;
            break;
        case ENUM_CVAL:
            constant->abs_cval = abs_cval;
            break;
        default:
            yyerror("Undefined type");
            exit(0);
    }
    return constant;
}


ABS_function_invoking F_ABS_function_invoking(
        ABS_ID abs_id,
        ABS_argue_list argue_list
) {
    ABS_function_invoking function_invoking = (ABS_function_invoking) check_malloc(sizeof(_ABS_function_invoking));
    function_invoking->abs_id = abs_id;
    function_invoking->argue_list = argue_list;
    return function_invoking;
}

ABS_argue_list F_ABS_argue_list(ABS_argue_list argue_list, ABS_ID abs_id) {
    if (argue_list == NULL) {
        argue_list = (ABS_argue_list) check_malloc(sizeof(_ABS_argue_list));
    }
    argue_list->list.push_back(abs_id);
    return argue_list;
}


ABS_compound_expression F_ABS_compound_expression(
        ENUM_oper_type oper_type,
        ABS_primary_expression primary_expression,
        ABS_compound_expression compound_expression1,
        ABS_compound_expression compound_expression2
) {
    ABS_compound_expression compound_expression = (ABS_compound_expression) check_malloc(
            sizeof(_ABS_compound_expression));
    compound_expression->oper_type = oper_type;
    compound_expression->primary_expression = primary_expression;
    compound_expression->compound_expression1 = compound_expression1;
    compound_expression->compound_expression2 = compound_expression2;
    return compound_expression;
}

ABS_declaration_list F_ABS_declaration_list(
        ABS_declaration_list declaration_list,
        ABS_declaration declaration) {
    if (declaration_list == NULL) {
        declaration_list = (ABS_declaration_list) check_malloc(sizeof(_ABS_declaration_list));
    }
    declaration_list->declaration_list.push_back(declaration);
    return declaration_list;
}


ABS_declaration F_ABS_declaration(ABS_specifier type_specifier,
                                  ABS_init_declarator_list init_declarator_list) {
    ABS_declaration declaration = (ABS_declaration) check_malloc(sizeof(_ABS_declaration));
    declaration->type_specifier = type_specifier;
    declaration->init_declarator_list = init_declarator_list;
    return declaration;
}


ABS_specifier F_ABS_specifier(ENUM_specifier type) {
    ABS_specifier type_specifier = (ABS_specifier) check_malloc(sizeof(_ABS_specifier));
    type_specifier->type = type;
    return type_specifier;
}

ABS_init_declarator_list F_ABS_init_declarator_list(
        ABS_init_declarator_list init_declarator_list,
        ABS_init_declarator init_declarator
) {
    if (init_declarator_list == NULL) {
        init_declarator_list = (ABS_init_declarator_list) check_malloc(
                sizeof(_ABS_init_declarator_list));
    }
    init_declarator_list->init_declarator_list.push_back(init_declarator);
    return init_declarator_list;
}


ABS_init_declarator F_ABS_init_declarator(
        ABS_ID id,
        ABS_constant constant
) {
    ABS_init_declarator init_declarator = (ABS_init_declarator) check_malloc(sizeof(_ABS_init_declarator));
    init_declarator->id = id;
    init_declarator->constant = constant;
    return init_declarator;
}


ABS_statement_list F_ABS_statement_list(
        ABS_statement_list statement_list,
        ABS_statement statement
) {
    if (statement_list == NULL) {
        statement_list = (ABS_statement_list) check_malloc(
                sizeof(_ABS_statement_list));
    }
    statement_list->statement_list.push_back(statement);
    return statement_list;
}

ABS_statement F_ABS_statement(
        ENUM_node_type type,
        ABS_block_statement block_statement,
        ABS_expression_statement expression_statement,
        ABS_selection_statement selection_statement,
        ABS_iteration_statement iteration_statement,
        ABS_jump_statement jump_statement,
        ABS_compound_expression compound_expression
) {
    ABS_statement statement = (ABS_statement) check_malloc(sizeof(_ABS_statement));
    statement->type = type;
    switch (type) {
        case ENUM_block_statement:
            statement->block_statement = block_statement;
            break;
        case ENUM_expression_statement :
            statement->expression_statement = expression_statement;
            break;
        case ENUM_selection_statement:
            statement->selection_statement = selection_statement;
            break;
        case ENUM_iteration_statement:
            statement->iteration_statement = iteration_statement;
            break;
        case ENUM_jump_statement:
            statement->jump_statement = jump_statement;
            break;
        case ENUM_compound_expression:
            statement->compound_expression = compound_expression;
            break;
        default:
            yyerror("Undefined type");
            exit(0);
    }
    return statement;
}

ABS_block_statement F_ABS_block_statement(
        ABS_declaration_list declaration_list,
        ABS_statement_list statement_list
) {
    ABS_block_statement block_statement = (ABS_block_statement) check_malloc(sizeof(_ABS_block_statement));
    block_statement->declaration_list = declaration_list;
    block_statement->statement_list = statement_list;
    return block_statement;
}

ABS_expression_statement F_ABS_expression_statement(
        ABS_expression_list expression_list
) {
    ABS_expression_statement expression_statement = (ABS_expression_statement) check_malloc(
            sizeof(_ABS_expression_statement));
    expression_statement->expression_list = expression_list;
    return expression_statement;
}


ABS_selection_statement F_ABS_selection_statement(
        ABS_expression_list expression_list,
        ABS_statement statement_if,
        ABS_statement statement_else
) {
    ABS_selection_statement selection_statement = (ABS_selection_statement) check_malloc(
            sizeof(_ABS_selection_statement));
    selection_statement->expression_list = expression_list;
    selection_statement->statement_if = statement_if;
    selection_statement->statement_else = statement_else;
    return selection_statement;
}


ABS_iteration_statement F_ABS_iteration_statement(
        ABS_expression_list expression_list_while,
        ABS_expression_statement expression_statement_for_left,
        ABS_expression_statement expression_statement_for_middle,
        ABS_expression_list expression_list_for_right,
        ABS_statement statement

) {
    ABS_iteration_statement iteration_statement = (ABS_iteration_statement) check_malloc(
            sizeof(_ABS_iteration_statement));
    iteration_statement->expression_list_while = expression_list_while;
    iteration_statement->expression_statement_for_left = expression_statement_for_left;
    iteration_statement->expression_statement_for_middle = expression_statement_for_middle;
    iteration_statement->expression_list_for_right = expression_list_for_right;
    iteration_statement->statement = statement;
    return iteration_statement;
}


ABS_jump_statement F_ABS_jump_statement(
        ENUM_action_type action_type,
        ABS_expression_statement expression_statement
) {
    ABS_jump_statement jump_statement = (ABS_jump_statement) check_malloc(sizeof(_ABS_jump_statement));
    jump_statement->action_type = action_type;
    jump_statement->expression_statement = expression_statement;
    return jump_statement;
}


ABS_program F_ABS_program(
        ABS_declaration_list declaration_list,
        ABS_function_definition_list function_definition_list
) {
    ABS_program program = (ABS_program) malloc(sizeof(_ABS_program));
    program->declaration_list = declaration_list;
    program->function_definition_list = function_definition_list;
    return program;
}


ABS_function_definition_list F_ABS_function_definition_list(
        ABS_function_definition_list function_definition_list,
        ABS_function_definition function_definition
) {
    if (function_definition_list == NULL) {
        function_definition_list = (ABS_function_definition_list) check_malloc(sizeof(_ABS_function_definition_list));
    }
    function_definition_list->function_definition_list.push_back(function_definition);
    return function_definition_list;
}

ABS_function_definition F_ABS_function_definition(
        ABS_specifier type_specifier,
        ABS_ID id,
        ABS_parameter_list parameter_list,
        ABS_block_statement block_statement
) {
    ABS_function_definition function_definition = (ABS_function_definition) check_malloc(
            sizeof(_ABS_function_definition));
    function_definition->type_specifier = type_specifier;
    function_definition->id = id;
    function_definition->parameter_list = parameter_list;
    function_definition->block_statement = block_statement;
    return function_definition;
}


ABS_parameter_list F_ABS_parameter_list(
        ABS_parameter_list parameter_list,
        ABS_parameter parameter
) {
    if (parameter_list == NULL) {
        parameter_list = (ABS_parameter_list) check_malloc(sizeof(_ABS_parameter_list));
    }
    parameter_list->parameter_list.push_back(parameter);
    return parameter_list;
}


ABS_parameter F_ABS_parameter(
        ABS_specifier type_specifier,
        ABS_ID id
) {
    ABS_parameter parameter = (ABS_parameter) check_malloc(sizeof(_ABS_parameter));
    parameter->type_specifier = type_specifier;
    parameter->id = id;
    return parameter;
}
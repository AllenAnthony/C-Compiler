#include "sement.hpp"
#include "abs.hpp"

#incldue "symbol.hpp"

#include "util.hpp"

void SEM_program(ABS_program program) {
    if (program->declaration_list == NULL) {
        SEM_function_definition_list(program->function_definition_list);
    } else {
        SEM_declaretion_list(program->declaratin_list);
        SEM_function_definition_list(program->funtion_definition_list);
    }
}

void SEM_declaration_list(ABS_declaration_list declaration_list) {
    if (declaration_list->declaration_list == NULL) {
        SEM_declaration(declaration_list->declaration);
    } else {

    }
}

void SEM_parameter(ABS_parameter parameter) {
    ENUM_specifier type = SEM_type_specifier(parameter->type_specifier);
    string id = SEM_ID(parameter->id);

    curr_env.link(id, type);
}

void SEM_expression_list(ABS_expression_list expression_list) {
    vector<ABS_expression>::iterator expression_list_it = expression_list->expression_list.begin();
    for (; expression_list_it != expression_list->expression_list.end(); expression_list_it++) {
        SEM_expression(*expression_list_it);
    }
}

void SEM_expression(ABS_expression expression) {
    if (expression->type == ENUM_assignment_expression)
        SEM_assignment_expression(expression->assignment_expression);
    else if (expression->type == ENUM_compound_expression)
        SEM_compound_expression(expression->compound_expression);
}

void SEM_assignment_expression(ABS_assignment_expression assignment_expression) {
    if (!curr_env.find(assignment_expression->abs_id->id)) {
        printf("id do not exist : %s", assignment_expression->abs_id->id);
        exit(0);
    }

    //string id = SEM_ID(assignment_expression->abs_id->id);
    SEM_compound_expression(assignment_expression->compound_expression_index);
    SEM_compound_expression(assignment_expression->compound_expression_value);
}

void SEM_primary_expression(ABS_primary_expression primary_expression) {
    if (primary_expression->type == ENUM_ID) {
        //string id = SEM_ID(primary_expression->id);
        if (!curr_env.find(primary_expression->id)) {
            printf("id do not exist : %s", primary_expression->id);
            exit(0);
        }
    } else if (primary_expression->type == ENUM_constant) {
        if (primary_expression->constant->type != curr_env.find(primary_expression->id).type) {
            printf("the type of const do not agree with the type of id");
            exit(0);
        }
    } else if (primary_expression->type == ENUM_compound_expression) {
        SEM_compound_expression(primary_expression->compound_expression);
    } else if (primary_expression->type == ENUM_function_invoking) {
        SEM_function_invoking(primary_expression->function_invoking);
    }
}





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
//    if (!curr_env.find(assignment_expression->abs_id->id)) {
//        printf("id do not exist : %s", assignment_expression->abs_id->id);
//        exit(0);
//    }
    SEM_abs_id(assignment_expression->abs_id);
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
        SEM_constant(primary_expression->constant);
    } else if(primary_expression->type==ENUM_compound_expression){
        SEM_compound_expression(primary_expression->compound_expression);
    } else if (primary_expression->type == ENUM_function_invoking) {
        SEM_function_invoking(primary_expression->function_invoking);
    }
}

void SEM_function_invoking(ABS_function_invoking function_invoking){
//    if(!curr_env.find(function_invoking->abs_id->id)){
//        printf("id do not exist : %s",primary_expression->id);
//        exit(0);
//    }
    SEM_abs_id(function_invoking->abs_id);
    SEM_argue_list(function_invoking->argue_list);
}

void SEM_argue_list(ABS_argue_list argue_list){
    vector<abs_id>::iterator argue_list_it=argue_list->list.begin();
    for(;argue_list_it!=argue_list->list.end();argue_list_it++){
        SEM_abs_id((*argue_list_it));
    }
}

void SEM_compound_expression(ABS_compound_expression compound_expression){
    //todo oper_type
    SEM_primary_expression(compound_expression->primary_expression);
    if(compound_expression->compound_expression!=NULL)
        SEM_compound_expression(compound_expression->compound_expression);

    return compound_expression->oper_type;
}

//void SEM_statement_list(ABS_statement_list statement_list){
//    vector<ABS_statement>::iterator statement_list_it=statement_list->statement_list.begin();
//    for(;statement_list_it!=statement_list->statement_list.end();statement_list_it++){
//        SEM_statement(*statement_list_it);
//    }
//}
//
//void SEM_statement(ABS_statement statement){
//    if(statement->type==ENUM_block_statement){
//        SEM_block_statement(statement->block_statement);
//    }else if(statement->type==ENUM_expression_statement){
//        SEM_expression_statement(statement->expression_statement);
//    }else if(statement->type==ENUM_selection_statement){
//        SEM_selection_statement(statement->selection_statement);
//    }else if(statement->type==ENUM_iteration_statement){
//        SEM_iteration_statement(statement->iteration_statement);
//    }else if(statement->type==ENUM_jump_statement){
//        SEM_jump_statement(statement->jump_statement);
//    }else if(statement->type==ENUM_compound_expression){
//        SEM_compound_expression(statement->compound_expression);
//    }else{
//        printf("type error\n");
//    }
//}
//
//void SEM_block_statement(ABS_block_statement block_statement){
//    SEM_declaration_list(block_statement->declaration_list);
//    SEM_statement_list(block_statement->statement_list);
//}
//
//void SEM_expression_statement(ABS_expression_statement expression_statement){
//    SEM_expression_list(expression_statement->expression_list);
//}
//
//void SEM_selection_statement(ABS_selection_statement selection_statement){
//    SEM_expression_list(selection_statement->expression_list);
//
//}

void SEM_abs_id(ABS_ID abs_id){
    if(!curr_env.find(abs_id->id)){
        printf("id do not exist : %s",abs_id->id);
        exit(0);
    }
}

int SEM_IVAL(ABS_IVAL ival){
    return ival->val;
}

float SEM_FVAL(ABS_FVAL fval){
    return fval->fval;
}

char SEM_CVAL(ABS_CVAL cval){
    return cval->cval;
}

void SEM_constant(ABS_constant constant){
    if(constant->type==ENUM_IVAL)
        SEM_IVAL(constant->abs_ival);
    else if(constant->type==ENUM_FVAL)
        SEM_FVAL(constant->abs_fval);
    else if(constant->type==ENUM_CVAL)
        SEM_CVAL(constant->abs_cval);
    else
        printf("type of the constant do not exist");
}





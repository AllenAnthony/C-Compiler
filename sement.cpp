#include "sement.hpp"
#include "symbol.hpp"
#include "abs.hpp"



void SEM_program(ABS_program program){
	if(program->declaration_list != NULL){
        SEM_declaretion_list(program->declaratin_list);
    }
    SEM_function_definition_list(program->funtion_definition_list);
    return;
}

void SEM_declaration_list(ABS_declaration_list declaration_list){
    vector<ABS_declaration>::iterator declaration_list_it = declaration_list->declaration_list.begin();
    for(; declaration_list_it != declaration_list->declaration_list.end(); declaration_list_it++){
        SEM_declaration(*declaration_list_it);
    }
    return;
}

void SEM_declaration(ABS_declaration declaration){
    ENUM_specifier type = SEM_specifier(declaration->type_specifier);
    SEM_init_declaration_list(type, declaration->init_declarator_list);
    return;
}

void SEM_init_declarator_list(ENUM_specifier type, ABS_init_declaration_list){
    vector<ABS_init_declarator>::iterator init_declarator_list_it = init_declarator_list->init_declarator_list.begin();
    for(; init_declarator_list_it != init_declarator_list->init_declarator_list.end(); init_declarator_list_it++){
        SEM_declarator(type, *init_declarator_list_it);
    }
    return;
}

void SEM_init_declarator(ENUM_specifier type, ABS_init_declarator init_declarator){
    if(init_declarator->constant != NULL){
        SEM_constant(init_declarator->constant);
    }
    string id = SEM_ID(init_declarator->id);
    curr_env.link(id,type);
    return;
}

void SEM_function_definition_list(ABS_function_definition_list function_definition_list){
    vector<ABS_function_definition>::iterator function_definition_list_it = function_definition_list->function_definition_list.begin();
    for(; function_definition_list_it != function_definition_list->function_definition_list.end(); function_definition_list_it++){
        curr_env.enterScope;
        SEM_function_definition(*function_definition_list_it);
        curr_env.escapeScope;
    }
}

void SEM_function_definition(ABS_function_definition function_definition){
    if(function_definition->parameter_list != NULL){
        curr_env.enterScope();
        SEM_parameter_list(function_definition->parameter_list);
        curr_env.escapeScope();
    }
    ENUM_specifier type = SEM_specifier(function_definition->type_specifier);
    string id = SEM_ID(function_definition->id);
    SEM_block_statement(function_definition->block_statement);
}

void SEM_parameter_list(ABS_parameter_list parameter_list){
    vector<ABS_parameter>::iterator parameter_list_it = parameter_list->parameter_list.begin();
    for(; parameter_list_it != parameter_list->parameter_list.end(); parameter_list_it++){
        SEM_parameter(*parameter_list_it);
    }
}

void SEM_parameter(ABS_parameter parameter){
    ENUM_specifier type = SEM_specifier(parameter->type_specifier);
    string id = SEM_ID(parameter->id);
    curr_env.link(id, type);
}

void SEM_block_statement(ABS_block_statement block_statement){
    cur_env.enterScope();
    if(block_statement->declaration_list != NULL){
        SEM_declaration_list(block_statement->declaration_list);
    }
    if(block_statement->statement_list != NULL){
        SEM_statement_list(block_statement->statement_list);
    }
    cur_env.escapeScope();
}

void SEM_statement_list(ABS_statement_list statement_list){
    vector<ABS_statement>;;iterator statement_list_it = statement_list->statement_list.begin();
    for(; statement_list_it != statement_list.end(); statement_list_it++){
        SEM_statament(*statement_list_it);
    }
}

void SEM_statement_list(ABS_statement statement){
    switch(statement->type){
        case ENUM_block_statement:
            SEM_block_statement(statement->block_statement);
            break;
        case ENUM_expression_statement:
            SEM_expression_statement(statement->expression_statement);
            break;
        case ENUM_selection_statement:
            SEM_expression_statement(statement->selection_statement);
            break;
        case ENUM_iteration_statement:
            SEM_iteration_statement(statement->iteration_statement);
            break;
        case ENUM_jump_statement:
            SEM_jump_statement(statement->jump_statement);
            break;
        case ENUM_compound_expression:
            SEM_compound_expression(statement->compound_expression);
            break;
    }
}

void SEM_expression_statement(ABS_expresson statement){
    SEM_
}
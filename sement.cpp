#include "sement.hpp"
#include "abs.hpp"



void SEM_program(ABS_program program){
	if(program->declaration_list == NULL){
		SEM_function_definition_list(program->function_definition_list);
	}
	else{
		SEM_declaretion_list(program->declaratin_list);
        curr_scope.enterScope();
		SEM_function_definition_list(program->funtion_definition_list);
        curr_scope.escapeScope();
	}
}

void SEM_declaration_list(ABS_declaration_list declaration_list){
    vector<ABS_declaration>::iterator declaration_list_it = declaration_list->declaration_list.begin();
    for(; declaration_list_it != declaration_list->declaration_list.end(); declaration_list_it++){
        SEM_declaration(*declaration_list_it);
    }
}

void SEM_declaration(ABS_declaration declaration){
    ENUM_specifier type = SEM_specifier(declaration->type_specifier);
    SEM_init_declaration_list(type, declaration->init_declarator_list);
}

void SEM_init_declarator_list(ENUM_specifier type, ABS_init_declaration_list){
    vector<ABS_init_declarator_list>::iterator init_declarator_list_it = init_declarator_list->init_declarator_list.begin();
    for(; init_declarator_list_it != init_declarator_list->init_declarator_list.end(); init_declarator_list_it++){
        SEM_declarator(type, *init_declarator_list_it);
    }
}

void SEM_init_declarator(ENUM_specifier type, ABS_init_declarator init_declarator){
    string id = SEM_ID(init_declarator->id);
    curr_env.
    if()
}

void SEM_parameter(ABS_parameter parameter){
    ENUM_specifier type = SEM_specifier(parameter->type_specifier);
    string id = SEM_ID(parameter->id);

    curr_env.link(id, type);
}

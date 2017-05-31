#include "sement.hpp"

void SEM_program(ABS_program program){
	if(program->declaration_list == NULL){
		SEM_function_definition_list(program->function_definition_list);
	}
	else{
		SEM_declaretion_list(program->declaratin_list);
		SEM_function_definition_list(program->funtion_definition_list);
	}
}

void SEM_declaration_list(ABS_declaration_list declaration_list){
    if(declaration_list->declaration_list == NULL){
        SEM_declaration(declaration_list->declaration);
    }
    else{
        
    }
}

void SEM_parameter(ABS_parameter parameter){
    ENUM_specifier type = SEM_type_specifier(parameter->type_specifier);
    string id = SEM_ID(parameter->id);

    curr_env.link(id, type);
}

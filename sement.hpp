#ifndef COMPILER_SEMENT_HPP
#define COMPILER_SEMENT_HPP

#include "util.hpp"

void SEM_abs_id(ABS_ID abs_id);

int SEM_IVAL(ABS_IVAL ival);

float SEM_FVAL(ABS_FVAL fval);

char SEM_CVAL(ABS_CVAL cval);

void SEM_expression_list(ABS_expression_list expression_list);

void SEM_expression(ABS_expression expression);

void SEM_assignment_expression(ABS_assignment_expression assignment_expression);

void SEM_primary_expression(ABS_primary_expression primary_expression);

void SEM_constant(ABS_constant constant);

void SEM_function_invoking(ABS_function_invoking function_invoking);

void SEM_argue_list(ABS_argue_list argue_list);

void SEM_compound_expression(ABS_compound_expression compound_expression);

void SEM_declaration_list(ABS_declaration_list declaration_list);

void SEM_declaration(ABS_declaration declaration);

ENUM_specifier SEM_specifer(ABS_specifier specifier);

void SEM_init_declarator_list(ENUM_specifier type, ABS_init_declaration_list);

void SEM_init_declarator(ENUM_specifier type, ABS_init_declarator init_declarator);

void SEM_statement_list(ABS_statement_list statement_list);

void SEM_statement(ABS_statement statement);

void SEM_block_statement(ABS_block_statement block_statement);

void SEM_expression_statement(ABS_expresson_statement expression_statement);

void SEM_selection_statement(ABS_selection_statement selection_statement);

void SEM_iteration_statement(ABS_iteration_statement iteration_statement);

void SEM_jump_statement(ABS_jump_statement jump_statement);

void SEM_program(ABS_program program);

void SEM_function_definition_list(ABS_function_definition_list function_definition_list);

void SEM_function_definition(ABS_function_definition function_definition);

void SEM_parameter_list(ABS_parameter_list parameter_list);

void SEM_parameter(ABS_parameter parameter);


#endif //COMPILER_SEMENT_HPP

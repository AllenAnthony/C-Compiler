#ifndef COMPILER_SEMENT_HPP
#define COMPILER_SEMENT_HPP

#include "util.hpp"

void SEM_program(ABS_program program);

void SEM_declaration_list(ABS_declaration_list declaration_list);

void SEM_parameter(ABS_parameter parameter);

void SEM_expression_list(ABS_expression_list expression_list);

void SEM_expression(ABS_expression expression);

void SEM_assignment_expression(ABS_assignment_expression assignment_expression);

void SEM_primary_expression(ABS_primary_expression primary_expression);

#endif //COMPILER_SEMENT_HPP

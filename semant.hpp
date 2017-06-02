#ifndef COMPILER_SEMANT_HPP
#define COMPILER_SEMANT_HPP

#include "util.hpp"
#include "symbol.hpp"
#include "abs.hpp"
#include "IR.hpp"
#include "function.hpp"
#include <cstdio>
#include <vector>
#include <map>


IR_NODE SEM_ID(ABS_ID abs_id, ENUM_specifier type);

IR_NODE SEM_IVAL(ABS_IVAL ival);

IR_NODE SEM_FVAL(ABS_FVAL fval);

IR_NODE SEM_CVAL(ABS_CVAL cval);


//QIAN XU FENG;
IR_NODE SEM_expression_list(ABS_expression_list expression_list);

IR_NODE SEM_expression(ABS_expression expression);

IR_NODE SEM_assignment_expression(ABS_assignment_expression assignment_expression);

IR_NODE SEM_array_expression(ABS_ID abs_id, ABS_compound_expression index);

IR_NODE SEM_primary_expression(ABS_primary_expression primary_expression);

IR_NODE SEM_constant(ABS_constant constant);

IR_NODE SEM_function_invoking(ABS_function_invoking function_invoking);

IR_NODE SEM_argue_list(ABS_argue_list argue_list);

IR_NODE SEM_compound_expression(ABS_compound_expression compound_expression);

//BIAN BIAN

IR_NODE SEM_declaration_list(ABS_declaration_list declaration_list);

IR_NODE SEM_declaration(ABS_declaration declaration);

ENUM_specifier SEM_specifier(ABS_specifier specifier);

IR_NODE SEM_init_declarator_list(ENUM_specifier type, ABS_init_declarator_list init_declarator_list);

IR_NODE SEM_init_declarator(ENUM_specifier type, ABS_init_declarator init_declarator);

IR_NODE SEM_statement_list(ABS_statement_list statement_list);

IR_NODE SEM_statement(ABS_statement statement);

IR_NODE SEM_block_statement(ABS_block_statement block_statement);

IR_NODE SEM_expression_statement(ABS_expression_statement expression_statement);



//HOPEN

IR_NODE SEM_selection_statement(ABS_selection_statement selection_statement);

IR_NODE SEM_iteration_statement(ABS_iteration_statement iteration_statement);

IR_NODE SEM_jump_statement(ABS_jump_statement jump_statement);

IR_NODE SEM_program(ABS_program program);

IR_NODE SEM_function_definition_list(ABS_function_definition_list function_definition_list);

IR_NODE SEM_function_definition(ABS_function_definition function_definition);

IR_NODE SEM_parameter_list(ABS_parameter_list parameter_list);

IR_NODE SEM_parameter(ABS_parameter parameter);

extern SymbolTable *curr_env;

extern FuncTable *curr_func;

extern int func_depth;


#endif //COMPILER_SEMANT_HPP

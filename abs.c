#include <stdio.h>
#include "abs.h"
#include "util.h"

ABS_Exp ABS_Expression(ABS_ExpType exp_type, int type, ABS_Exp exp_left, ABS_Exp exp_right) {
    ABS_Exp expression = checked_malloc(sizeof(struct _ABS_Exp));
    expression->exp_type = exp_type;
    expression->u.expression.type = type;
    expression->u.expression.exp_left = exp_left;
    expression->u.expression.exp_right = exp_right;
    return expression;
}

/*
int type:
	expression: 1,2;
	multiplicative: 1,2MUL,3DIV,4MOD
	additive: 1,2;
	relational: 1,2LT,3GT,4LE,5GE;
	equality: 1,2EQ,3NE;
	logical_and: 1,2;
	logical_or: 1,2;
*/

ABS_Exp ABS_Assignment_Expression(ABS_ExpType exp_type, int type, _ABS_ID id_e, ABS_Exp exp_left, ABS_Exp exp_right) {
    ABS_Exp assignment = checked_malloc(sizeof(struct _ABS_Exp));
    assignment->exp_type = exp_type;
    assignment->u.assignment.type = type;
    assignment->u.assignment.id_e = id_e;
    assignment->u.assignment.exp_left = exp_left;
    assignment->u.assignment.exp_right = exp_right;
    return assignment;
}

ABS_Exp ABS_Primary_Expression(ABS_ExpType exp_type, int type, int val) {
    ABS_Exp primary = checked_malloc(sizeof(struct _ABS_Exp));
    primary->exp_type = exp_type;
    #ifdef DEBUG
        printf("Primary_Expression:%d\t");
    #endif
    switch (type) {
        case 1:
            primary->u.primary.u.id_e = (_ABS_ID) val;
            #ifdef DEBUG
            printf("ID_E %s", (char *)val);
            #endif
            break;
        case 2:
            primary->u.primary.u.ival = val;
            #ifdef DEBUG
            printf("IVAL %d", val);
            #endif
            break;
        case 3:
            primary->u.primary.u.fval = (float) val;
            #ifdef DEBUG
            printf("FVAL %.2f", (float)val);
            #endif
            break;
        case 4:
            primary->u.primary.u.cval = (char) val;
            #ifdef DEBUG
            printf("CVAL %c", (char)val);
            #endif
            break;
        case 5:
            primary->u.primary.u.exp = (ABS_Exp) val;
            break;
        case 6:
            primary->u.primary.u.ABS_type = (ABS_Type) val;
            break;
    }
    #ifdef DEBUG
    printf("\n");
    #endif
    return primary;
}


ABS_Dec ABS_Declaration(ABS_Type ABS_type, ABS_Init_Dec_List init_dec_list) {
    ABS_Dec declaration = checked_malloc(sizeof(struct _ABS_Dec));
    declaration->ABS_type = ABS_type;
    declaration->init_dec_list = init_dec_list;
    #ifdef DEBUG
    printf("ABS_Declaration\n");
    #endif
    return declaration;
}

ABS_Type ABS_Type_Specifier(ABS_type type) {
    ABS_Type type_specifier = checked_malloc(sizeof(struct _ABS_Type));
    type_specifier->type = type;
    #ifdef DEBUG
    switch(type){
        case ABS_INT: 
            printf("Type Int\n");
            break;
        case ABS_FLOAT: 
            printf("Type Float\n");
            break;
        case ABS_CHAR:
            printf("Type Char\n");
            break;
    }
    #endif
    return type_specifier;
}

ABS_Init_Dec_List ABS_Init_Declarator_List(int type, ABS_Init_Dec init_dec, ABS_Init_Dec_List init_dec_list) {
    ABS_Init_Dec_List init_declarator_list = checked_malloc(sizeof(struct _ABS_Init_Dec_List));
    init_declarator_list->type = type;
    init_declarator_list->init_dec = init_dec;
    init_declarator_list->init_dec_list = init_dec_list;
    #ifdef DEBUG
    printf("ABS_Init_Declarator_List: %d\n", type);
    #endif
    return init_declarator_list;
}

ABS_Init_Dec ABS_Init_Declarator(_ABS_ID id_d) {
    ABS_Init_Dec init_declarator = checked_malloc(sizeof(struct _ABS_Init_Dec));
    init_declarator->id_d = id_d;
    #ifdef DEBUG
    printf("ABS_Init_Declarator: %s\n", id_d);
    #endif
    return init_declarator;
}

ABS_Stmt ABS_Statement(ABS_StmtType stmt_type, ABS_Stmt stmt) {
    ABS_Stmt statement = checked_malloc(sizeof(struct _ABS_Stmt));
    statement->stmt_type = stmt_type;
    statement->u.stmt = stmt;
    #ifdef DEBUG
    printf("ABS_Statement: %d\n", stmt_type);
    #endif
    return statement;
}

ABS_Stmt ABS_Compound(ABS_StmtType stmt_type, int type, ABS_Block_Item_List block_item_list) {
    ABS_Stmt compound = checked_malloc(sizeof(struct _ABS_Stmt));
    compound->stmt_type = stmt_type;
    compound->u.compound.type = type;
    compound->u.compound.block_item_list = block_item_list;
    #ifdef DEBUG
    printf("ABS_Compound: %d\n", type);
    #endif
    return compound;
}

ABS_Stmt ABS_Expression_Statement(ABS_StmtType stmt_type, int type, ABS_Exp exp) {
    ABS_Stmt expression = checked_malloc(sizeof(struct _ABS_Stmt));
    expression->stmt_type = stmt_type;
    expression->u.expression.type = type;
    expression->u.expression.exp = exp;
    #ifdef DEBUG
    printf("ABS_Declaration\n");
    #endif
    return expression;
}

ABS_Stmt ABS_Selection(ABS_StmtType stmt_type, ABS_Exp exp, ABS_Stmt stmt_if, ABS_Stmt stmt_else) {
    ABS_Stmt selection = checked_malloc(sizeof(struct _ABS_Stmt));
    selection->stmt_type = stmt_type;
    selection->u.selection.exp = exp;
    selection->u.selection.stmt_if = stmt_if;
    selection->u.selection.stmt_else = stmt_else;
    #ifdef DEBUG
    printf("ABS_Declaration\n");
    #endif
    return selection;
}

ABS_Stmt ABS_Iteration(ABS_StmtType stmt_type, int type, ABS_Exp exp, ABS_Stmt stmt1, ABS_Stmt stmt2, ABS_Stmt stmt3) {
    ABS_Stmt iteration = checked_malloc(sizeof(struct _ABS_Stmt));
    iteration->stmt_type = stmt_type;
    iteration->u.iteration.type = type;
    switch (type) {
        case 1:
            iteration->u.iteration.u.While.exp = exp;
            iteration->u.iteration.u.While.stmt = stmt1;
            break;
        case 2:
            iteration->u.iteration.u.For.stmt_1 = stmt1;
            iteration->u.iteration.u.For.stmt_2 = stmt2;
            iteration->u.iteration.u.For.stmt_4 = stmt3;
            iteration->u.iteration.u.For.exp_3 = exp;
            break;
    }
    return iteration;
}

ABS_Stmt ABS_Jump(ABS_StmtType stmt_type, int type, ABS_Exp exp) {
    ABS_Stmt jump = checked_malloc(sizeof(struct _ABS_Stmt));
    jump->stmt_type = stmt_type;
    jump->u.jump.type = type;
    jump->u.jump.exp = exp;
    return jump;
}

ABS_Block_Item_List ABS_Block_Item_List_Func(int type, ABS_Block_Item_List block_item_list, ABS_Block_Item block_item) {
    ABS_Block_Item_List block_item_list_func = checked_malloc(sizeof(struct _ABS_Block_Item_List));
    block_item_list_func->type = type;
    block_item_list_func->block_item_list = block_item_list;
    block_item_list_func->block_item = block_item;
    return block_item_list_func;
}

ABS_Block_Item ABS_Block_Item_Func(int type, ABS_Dec dec, ABS_Stmt stmt) {
    ABS_Block_Item block_item_func = checked_malloc(sizeof(struct _ABS_Block_Item));
    block_item_func->type = type;
    switch (type) {
        case 1:
            block_item_func->u.dec = dec;
            break;
        case 2:
            block_item_func->u.stmt = stmt;
            break;
    }
    return block_item_func;
}

ABS_Unit ABS_Translation_Unit(int type, ABS_Ex_Dec ex_dec, ABS_Unit unit) {
    ABS_Unit translation_unit = checked_malloc(sizeof(struct _ABS_Unit));
    translation_unit->type = type;
    translation_unit->ex_dec = ex_dec;
    translation_unit->unit = unit;
    return translation_unit;
}

ABS_Ex_Dec ABS_External_Declaration(int type, ABS_Func_Def func_def, ABS_Dec dec) {
    ABS_Ex_Dec external_declaration = checked_malloc(sizeof(struct _ABS_Ex_Dec));
    external_declaration->type = type;
    switch (type) {
        case 1:
            external_declaration->u.func_def = func_def;
            break;
        case 2:
            external_declaration->u.dec = dec;
            break;
    }
    return external_declaration;
}

ABS_Func_Def
ABS_Function_Definition(int type, ABS_Type ABS_type, _ABS_ID id_d, ABS_Param_List param_list, ABS_Dec_List dec_list,
                        ABS_Stmt stmt) {
    ABS_Func_Def function_definition = checked_malloc(sizeof(struct _ABS_Func_Def));
    function_definition->type = type;
    function_definition->ABS_type = ABS_type;
    function_definition->id_d = id_d;
    function_definition->param_list = param_list;
    function_definition->stmt = stmt;
    if (type == 2) {
        function_definition->dec_list = dec_list;
    }
    return function_definition;
}

ABS_Param_List ABS_Parameter_List(int type, ABS_Param_Dec param_dec, ABS_Param_List param_list) {
    ABS_Param_List parameter_list = checked_malloc(sizeof(struct _ABS_Param_List));
    parameter_list->param_dec = param_dec;
    parameter_list->param_list = param_list;
    return parameter_list;
}

ABS_Param_Dec ABS_Parameter_Declaration(ABS_Type ABS_type, _ABS_ID id_d) {
    ABS_Param_Dec parameter_declaration = checked_malloc(sizeof(struct _ABS_Param_Dec));
    parameter_declaration->ABS_type = ABS_type;
    parameter_declaration->id_d = id_d;
    return parameter_declaration;
}

ABS_Dec_List ABS_Declaration_List(int type, ABS_Dec dec, ABS_Dec_List dec_list) {
    ABS_Dec_List declaration_list = checked_malloc(sizeof(struct _ABS_Dec_List));
    declaration_list->dec = dec;
    declaration_list->dec_list = dec_list;
    return declaration_list;
}

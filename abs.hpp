#ifndef COMPILER_ABS_HPP
#define COMPILER_ABS_HPP

#include "util.hpp"

typedef enum {
    ENUM_assignment_expression,
    ENUM_primary_expression,
    ENUM_constant,
    ENUM_function_invoking,
    ENUM_argue_list,
    ENUM_compound_expression,
    ENUM_declaration_list,
    ENUM_declaration,
    ENUM_type_specifier,
    ENUM_init_declarator_list,
    ENUM_statement_list,
    ENUM_statement,
    ENUM_block_statement,
    ENUM_expression_statement,
    ENUM_selection_statement,
    ENUM_iteration_statement,
    ENUM_jump_statement,
    ENUM_program,
    ENUM_function_definition_list,
    ENUM_function_definition,
    ENUM_parameter_list,
    ENUM_ID,
    ENUM_IVAL,
    ENUM_FVAL,
    ENUM_CVAL
} ENUM_node_type;

typedef enum {
    ENUM_INT,
    ENUM_FLOAT,
    ENUM_CHAR
} ENUM_specifier;

typedef enum {
    ENUM_BREAK,
    ENUM_CONTINUE,
    ENUM_RETURN
} ENUM_action_type;

typedef enum {
    ENUM_NONE,
    ENUM_MUL,
    ENUM_DIV,
    ENUM_MOD,
    ENUM_PLUS,
    ENUM_MINUS,
    ENUM_LT,
    ENUM_GT,
    ENUM_LE,
    ENUM_GE,
    ENUM_EQ,
    ENUM_NE,
    ENUM_AND,
    ENUM_OR
} ENUM_oper_type;

typedef struct _ABS_ID *ABS_ID;
typedef struct _ABS_IVAL *ABS_IVAL;
typedef struct _ABS_FVAL *ABS_FVAL;
typedef struct _ABS_CVAL *ABS_CVAL;
typedef struct _ABS_expression_list *ABS_expression_list;
typedef struct _ABS_expression *ABS_expression;
typedef struct _ABS_assignment_expression *ABS_assignment_expression;
typedef struct _ABS_primary_expression *ABS_primary_expression;
typedef struct _ABS_constant *ABS_constant;
typedef struct _ABS_function_invoking *ABS_function_invoking;
typedef struct _ABS_argue_list *ABS_argue_list;
typedef struct _ABS_compound_expression *ABS_compound_expression;
typedef struct _ABS_declaration_list *ABS_declaration_list;
typedef struct _ABS_declaration *ABS_declaration;
typedef struct _ABS_specifier *ABS_specifier;
typedef struct _ABS_init_declarator_list *ABS_init_declarator_list;
typedef struct _ABS_init_declarator *ABS_init_declarator;
typedef struct _ABS_statement_list *ABS_statement_list;
typedef struct _ABS_statement *ABS_statement;
typedef struct _ABS_block_statement *ABS_block_statement;
typedef struct _ABS_expression_statement *ABS_expression_statement;
typedef struct _ABS_selection_statement *ABS_selection_statement;
typedef struct _ABS_iteration_statement *ABS_iteration_statement;
typedef struct _ABS_jump_statement *ABS_jump_statement;
typedef struct _ABS_program *ABS_program;
typedef struct _ABS_function_definition_list *ABS_function_definition_list;
typedef struct _ABS_function_definition *ABS_function_definition;
typedef struct _ABS_parameter_list *ABS_parameter_list;
typedef struct _ABS_parameter *ABS_parameter;

struct _ABS_ID {
    string id;
};

struct _ABS_IVAL {
    int ival;
};

struct _ABS_FVAL {
    float fval;
};

struct _ABS_CVAL {
    char cval;
};

struct _ABS_expression_list {
    vector<ABS_expression> expression_list;
};

struct _ABS_expression {
    ENUM_node_type type;
    union {
        ABS_assignment_expression assignment_expression;
        ABS_compound_expression compound_expression;
    };
};

struct _ABS_assignment_expression {
    ABS_ID abs_id;
    ABS_compound_expression compound_expression_index;
    ABS_compound_expression compound_expression_value;
};

struct _ABS_primary_expression {
    ENUM_node_type type;
    union {
        ABS_ID id;
        ABS_constant constant;
        ABS_compound_expression compound_expression;
        ABS_function_invoking function_invoking;
    };
};

struct _ABS_constant {
    ENUM_node_type type;
    union {
        ABS_IVAL abs_ival;
        ABS_FVAL abs_fval;
        ABS_CVAL abs_cval;
    };
};

struct _ABS_function_invoking {
    ABS_ID abs_id;
    ABS_argue_list argue_list;
};

struct _ABS_argue_list {
    vector<ABS_ID> list;
};

struct _ABS_compound_expression {
    ENUM_oper_type oper_type;
    ABS_primary_expression primary_expression;
    ABS_compound_expression compound_expression;
};

struct _ABS_declaration_list {
    vector<ABS_declaration> declaration_list;
};

struct _ABS_declaration {
    ABS_specifier type_specifier;
    ABS_init_declarator_list init_declarator_list;
};

struct _ABS_specifier {
    ENUM_specifier type;
};

struct _ABS_init_declarator_list {
    vector<ABS_init_declarator> init_declarator_list;
};

struct _ABS_init_declarator {
    ABS_ID id;
    ABS_constant constant;
};

struct _ABS_statement_list {
    vector<ABS_statement> statement_list;
};

struct _ABS_statement {
    ENUM_node_type type;
    union {
        ABS_block_statement block_statement;
        ABS_expression_statement expression_statement;
        ABS_selection_statement selection_statement;
        ABS_iteration_statement iteration_statement;
        ABS_jump_statement jump_statement;
        ABS_compound_expression compound_expression;
    };
};

struct _ABS_block_statement {
    ABS_declaration_list declaration_list;
    ABS_statement_list statement_list;
};

struct _ABS_expression_statement {
    ABS_expression_list expression_list;
};

struct _ABS_selection_statement {
    ABS_expression_list expression_list;
    ABS_statement statement_if;
    ABS_statement statement_else;
};

struct _ABS_iteration_statement {
    ABS_expression_list expression_list_while;

    ABS_expression_statement expression_statement_for_left;
    ABS_expression_statement expression_statement_for_middle;
    ABS_expression_list expression_list_for_right;

    ABS_statement statement;
};

struct _ABS_jump_statement {
    ENUM_action_type action_type;
    ABS_expression_statement expression_statement;
};

struct _ABS_program {
    ABS_declaration_list declaration_list;
    ABS_function_definition_list function_definition_list;
};

struct _ABS_function_definition_list {
    vector<ABS_function_definition> function_definition_list;
};

struct _ABS_function_definition {
    ABS_specifier type_specifier;
    ABS_ID id;
    ABS_parameter_list parameter_list;
    ABS_block_statement block_statement;
};

struct _ABS_parameter_list {
    vector<ABS_parameter> parameter_list;
};

struct _ABS_parameter {
    ABS_specifier type_specifier;
    ABS_ID id;
};

ABS_ID F_ABS_ID(string id);

ABS_IVAL F_ABS_IVAL(int ival);

ABS_FVAL F_ABS_FVAL(float fval);

ABS_CVAL F_ABS_CVAL(char cval);

ABS_expression_list F_ABS_expression_list(
        ABS_expression_list expression_list,
        ABS_expression expression
);

ABS_expression F_ABS_expression(
        ENUM_node_type type,
        ABS_assignment_expression assignment_expression,
        ABS_compound_expression compound_expression
);

ABS_assignment_expression F_ABS_assignment_expression(
        ABS_ID abs_id,
        ABS_compound_expression compound_expression_index,
        ABS_compound_expression compound_expression_value
);

ABS_primary_expression F_ABS_primary_expression(
        ENUM_node_type type,
        ABS_ID id,
        ABS_constant constant,
        ABS_compound_expression compound_expression,
        ABS_function_invoking function_invoking
);

ABS_constant F_ABS_constant(
        ENUM_node_type type,
        ABS_IVAL abs_ival,
        ABS_FVAL abs_fval,
        ABS_CVAL abs_cval
);

ABS_function_invoking F_ABS_function_invoking(
        ABS_ID abs_id,
        ABS_argue_list argue_list
);

ABS_argue_list F_ABS_argue_list(
        ABS_argue_list argue_list,
        ABS_ID abs_id
);

ABS_compound_expression F_ABS_compound_expression(
        ENUM_oper_type oper_type,
        ABS_primary_expression primary_expression,
        ABS_compound_expression compound_expression
);

ABS_declaration_list F_ABS_declaration_list(
        ABS_declaration_list declaration_list,
        ABS_declaration declaration
);

ABS_declaration F_ABS_declaration(
        ABS_specifier type_specifier,
        ABS_init_declarator_list init_declarator_list
);

ABS_specifier F_ABS_specifier(ENUM_specifier type);

ABS_init_declarator_list F_ABS_init_declarator_list(
        ABS_init_declarator_list init_declarator_list,
        ABS_init_declarator init_declarator
);

ABS_init_declarator F_ABS_init_declarator(
        ABS_ID id,
        ABS_constant constant
);

ABS_statement_list F_ABS_statement_list(
        ABS_statement_list statement_list,
        ABS_statement statement
);

ABS_statement F_ABS_statement(
        ENUM_node_type type,
        ABS_block_statement block_statement,
        ABS_expression_statement expression_statement,
        ABS_selection_statement selection_statement,
        ABS_iteration_statement iteration_statement,
        ABS_jump_statement jump_statement,
        ABS_compound_expression compound_expression
);

ABS_block_statement F_ABS_block_statement(
        ABS_declaration_list declaration_list,
        ABS_statement_list statement_list
);

ABS_expression_statement F_ABS_expression_statement(
        ABS_expression_list expression_list
);


ABS_selection_statement F_ABS_selection_statement(
        ABS_expression_list expression_list,
        ABS_statement statement_if,
        ABS_statement statement_else
);


ABS_iteration_statement F_ABS_iteration_statement(
        ABS_expression_list expression_list_while,
        ABS_expression_statement expression_statement_for_left,
        ABS_expression_statement expression_statement_for_middle,
        ABS_expression_list expression_list_for_right,
        ABS_statement statement

);


ABS_jump_statement F_ABS_jump_statement(
        ENUM_action_type action_type,
        ABS_expression_statement expression_statement
);


ABS_program F_ABS_program(
        ABS_declaration_list declaration_list,
        ABS_function_definition_list function_definition_list
);


ABS_function_definition_list F_ABS_function_definition_list(
        ABS_function_definition_list function_definition_list,
        ABS_function_definition function_definition
);

ABS_function_definition F_ABS_function_definition(
        ABS_specifier type_specifier,
        ABS_ID id,
        ABS_parameter_list parameter_list,
        ABS_block_statement block_statement
);


ABS_parameter_list F_ABS_parameter_list(
        ABS_parameter_list parameter_list,
        ABS_parameter parameter
);


ABS_parameter F_ABS_parameter(
        ABS_specifier type_specifier,
        ABS_ID id
);


#endif //COMPILER_ABS_HPP
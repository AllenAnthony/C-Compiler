#ifndef _ABS_H_
#define _ABS_H_
typedef struct _ABS_Exp *ABS_Exp;
typedef struct _ABS_Dec *ABS_Dec;
typedef struct _ABS_Type *ABS_Type;
typedef struct _ABS_Init_Dec *ABS_Init_Dec;
typedef struct _ABS_Init_Dec_List *ABS_Init_Dec_List;
typedef struct _ABS_Stmt *ABS_Stmt;
typedef struct _ABS_Block_Item_List *ABS_Block_Item_List;
typedef struct _ABS_Block_Item *ABS_Block_Item;
typedef struct _ABS_Unit *ABS_Unit;
typedef struct _ABS_Unit *ABS_Root;
typedef struct _ABS_Ex_Dec *ABS_Ex_Dec;
typedef struct _ABS_Func_Def *ABS_Func_Def;
typedef struct _ABS_Param_List *ABS_Param_List;
typedef struct _ABS_Param_Dec *ABS_Param_Dec;
typedef struct _ABS_Dec_List *ABS_Dec_List;
typedef char *_ABS_ID;

typedef enum {
    ABS_expression,
    ABS_assignment,
    ABS_primary,
    ABS_multiplicative,
    ABS_additive,
    ABS_relational,
    ABS_equality,
    ABS_logical_and,
    ABS_logical_or
} ABS_ExpType;

typedef enum {
    ABS_statement,
    ABS_compound,
    ABS_expression_statement,
    ABS_selection,
    ABS_iteration,
    ABS_jump
} ABS_StmtType;

typedef enum {
    ABS_INT,
    ABS_FLOAT,
    ABS_CHAR
} ABS_type_specifier;

struct _ABS_Exp {
    ABS_ExpType exp_type;
    union {
        struct {
            int type;
            ABS_Exp exp_left, exp_right;
        } expression;
        struct {
            int type;
            _ABS_ID id_e;
            ABS_Exp exp_left, exp_right;
        } assignment;
        struct {
            int type;
            union {
                _ABS_ID id_e;
                int ival;
                float fval;
                char cval;
                ABS_Exp exp;
                ABS_Type ABS_type;
            } u;
        } primary;
    } u;
};

struct _ABS_Dec {
    ABS_Type ABS_type;
    ABS_Init_Dec_List init_dec_list;
};

struct _ABS_Type {
    ABS_type_specifier type;
};

struct _ABS_Init_Dec_List {
    int type;
    ABS_Init_Dec init_dec;
    ABS_Init_Dec_List init_dec_list;
};

struct _ABS_Init_Dec {
    _ABS_ID id_d;
};

struct _ABS_Stmt {
    int stmt_type;
    union {
        ABS_Stmt stmt;
        struct {
            int type;
            ABS_Block_Item_List block_item_list;
        } compound;
        struct {
            int type;
            ABS_Exp exp;
        } expression;
        struct {
            ABS_Exp exp;
            ABS_Stmt stmt_if, stmt_else;
        } selection;
        struct {
            int type;
            union {
                struct {
                    ABS_Exp exp;
                    ABS_Stmt stmt;
                } While;

                struct {
                    ABS_Stmt stmt_1, stmt_2, stmt_4;
                    ABS_Exp exp_3;
                } For;
            } u;
        } iteration;
        struct {
            int type;
            ABS_Exp exp;
        } jump;
    } u;
};

struct _ABS_Block_Item_List {
    int type;
    ABS_Block_Item_List block_item_list;
    ABS_Block_Item block_item;
};

struct _ABS_Block_Item {
    int type;
    union {
        ABS_Dec dec;
        ABS_Stmt stmt;
    } u;
};

struct _ABS_Unit {
    int type;
    ABS_Ex_Dec ex_dec;
    ABS_Unit unit;
};

struct _ABS_Ex_Dec {
    int type;
    union {
        ABS_Func_Def func_def;
        ABS_Dec dec;
    } u;
};

struct _ABS_Func_Def {
    int type;
    ABS_Type ABS_type;
    _ABS_ID id_d;
    ABS_Param_List param_list;
    ABS_Dec_List dec_list;
    ABS_Stmt stmt;
};

struct _ABS_Param_List {
    int type;
    ABS_Param_Dec param_dec;
    ABS_Param_List param_list;
};

struct _ABS_Param_Dec {
    ABS_Type ABS_type;
    _ABS_ID id_d;
};

struct _ABS_Dec_List {
    int type;
    ABS_Dec dec;
    ABS_Dec_List dec_list;
};

ABS_Exp ABS_Expression(ABS_ExpType exp_type, int type, ABS_Exp exp_left, ABS_Exp exp_right);

ABS_Exp ABS_Assignment_Expression(ABS_ExpType exp_type, int type, _ABS_ID id_e, ABS_Exp exp_left, ABS_Exp exp_right);

ABS_Exp ABS_Primary_Expression(ABS_ExpType exp_type, int type, int ptr);

ABS_Dec ABS_Declaration(ABS_Type ABS_type, ABS_Init_Dec_List init_dec_list);

ABS_Type ABS_Type_Specifier(ABS_type_specifier type);

ABS_Init_Dec_List ABS_Init_Declarator_List(int type, ABS_Init_Dec init_dec, ABS_Init_Dec_List init_dec_list);

ABS_Init_Dec ABS_Init_Declarator(_ABS_ID id_d);

ABS_Stmt ABS_Statement(ABS_StmtType stmt_type, ABS_Stmt stmt);

ABS_Stmt ABS_Compound(ABS_StmtType stmt_type, int type, ABS_Block_Item_List block_item_list);

ABS_Stmt ABS_Expression_Statement(ABS_StmtType stmt_type, int type, ABS_Exp exp);

ABS_Stmt ABS_Selection(ABS_StmtType stmt_type, ABS_Exp exp, ABS_Stmt stmt_if, ABS_Stmt stmt_else);

ABS_Stmt ABS_Iteration(ABS_StmtType stmt_type, int type, ABS_Exp exp, ABS_Stmt stmt1, ABS_Stmt stmt2, ABS_Stmt stmt3);

ABS_Stmt ABS_Jump(ABS_StmtType stmt_type, int type, ABS_Exp exp);

ABS_Block_Item_List ABS_Block_Item_List_Func(int type, ABS_Block_Item_List block_item_list, ABS_Block_Item block_item);

ABS_Block_Item ABS_Block_Item_Func(int type, ABS_Dec dec, ABS_Stmt stmt);

ABS_Unit ABS_Translation_Unit(int type, ABS_Ex_Dec ex_dec, ABS_Unit unit);

ABS_Ex_Dec ABS_External_Declaration(int type, ABS_Func_Def func_def, ABS_Dec dec);

ABS_Func_Def ABS_Function_Definition(int type, ABS_Type ABS_type, _ABS_ID id_d, ABS_Param_List param_list, ABS_Dec_List dec_list, ABS_Stmt stmt);

ABS_Param_List ABS_Parameter_List(int type, ABS_Param_Dec param_dec, ABS_Param_List param_list);

ABS_Param_Dec ABS_Parameter_Declaration(ABS_Type ABS_type, _ABS_ID id_d);

ABS_Dec_List ABS_Declaration_List(int type, ABS_Dec dec, ABS_Dec_List dec_list);

#endif //_ABS_H_
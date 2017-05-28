typedef struct _ABS_Exp *ABS_Exp;
typedef struct _ABS_Dec *ABS_Dec;
typedef struct _ABS_Type *ABS_Type;
typedef struct _ABS_Init_Dec *ABS_Init_Dec;
typedef struct _ABS_Ini_Dec_List *ABS_Init_Dec_list;
typedef struct _ABS_Stmt *ABS_Stmt;
typedef struct _ABS_Block_Item_List *ABS_Block_Item_list;
typedef struct _ABS_Block_Item *ABS_Block_Item;
typedef struct _ABS_Unit *ABS_Unit;
typedef struct _ABS_Unit *ABS_Root;
typedef struct _ABS_Ex_Dec *ABS_Ex_Dec;
typedef struct _ABS_Fun_Def *ABS_Func_Def;
typedef struct _ABS_Param_List *ABS_Param_List;
typedef struct _ABS_Param_Dec *ABS_Param_Dec;
typedef struct _ABS_Dec_List *ABS_Dec_List;
typedef char *_ABS_ID;

struct _ABS_Exp{
	enum{
		ABS_expression, ABS_assignment, ABS_primary, ABS_multiplicative, ABS_relational, ABS_equality, ABS_logical_and, ABS_logical_or
	} ABS_ExpType;
	union{
		struct{
			int type;
			ABS_Exp exp_left, exp_right;
		} expression;
		struct{
			int type;
			ABS_ID id_e;
			ABS_Exp exp_left, exp_right;
		} assignment;
		struct{
			int type;
			union{
				ABS_ID id_e;
				int ival;
				float fval;
				char cval;
				ABS_Exp exp;
				ABS_Type ABS_type;
			} u;
		} primary;
		struct{
			int type;
			ABS_Exp exp_left, exp_right;
		} multiplicative;
		struct{
			int type;
			ABS_Exp exp_left, exp_right;
		} relational;
		struct{
			int type;
			ABS_Exp exp_left, exp_right;
		} equality;
		struct{
			int type;
			ABS_Exp exp_left, exp_right;
		} logical_and;
		struct{
			int type;
			ABS_Exp exp_left, exp_right;
		} logical_or;
	} u;
};

struct _ABS_Dec{
	ABS_Type ABS_type;
	ABS_Init_Dec_list dec_list;
};

struct _ABS_Type{
	enum{
		ABS_INT, ABS_FLOAT, ABS_CHAR
	} ABS_type;
};

struct _ABS_Ini_Dec_List{
	int type;
	ABS_Init_Dec init_dec;
	ABS_Init_Dec_list init_dec_list;
};

struct _ABS_Init_Dec{
	ABS_ID id_d;
};

struct _ABS_Stmt{
	enum{
		ABS_statement, ABS_compound, ABS_expression, ABS_selection, ABS_iteration, ABS_jump
	} ABS_StmtType;
	union{
		ABS_Stmt stmt;
		struct{
			int type;
			ABS_Block_Item_list block_item_list;
		} compound;
		struct{
			int type;
			ABS_Exp exp;
		} expression;
		struct{
			ABS_Exp exp;
			ABS_Stmt stmt_if, stmt_else;
		} selection;
		struct{
			int type;
			union{
				struct{
					ABS_Exp exp;
					ABS_Stmt stmt;
				} While;

				struct{
					ABS_Stmt stmt_1, stmt_2, stmt_4
					ABS_Exp exp_3
				} For;
			} u;
		} iteration;
		sturct{
			int type;
			ABS_Exp exp;
		} jump;
	}
};

struct _ABS_Block_Item_List{
	int type;
	ABS_Block_Item_list block_item_list;
	ABS_Block_Item block_item;
};

struct _ABS_Block_Item{
	int type;
	union{
		ABS_Dec dec;
		ABS_Stmt stmt;
	} u;
};

struct _ABS_Unit{
	int type;
	ABS_Ex_Dec ex_dec;
	ABS_Unit unit;
}

struct _ABS_Ex_Dec{
	int type;
	union{
		ABS_Func_Def func_def;
		ABS_Dec dec;
	} u;
};

struct _ABS_Fun_Def{
	int type;
	ABS_Type ABS_type;
	ABS_ID id_d;
	ABS_Param_List param_list;
	ABS_Dec_List dec_list;
	ABS_Stmt stmt;
};

struct _ABS_Param_List{
	int type;
	ABS_Param_Dec param_dec;
	ABS_Param_List param_list;
};

struct _ABS_Param_Dec{
	ABS_ID id_d;
};

struct _ABS_Dec_List{
	int type;
	ABS_Dec dec;
	ABS_Dec_List dec_list;
};

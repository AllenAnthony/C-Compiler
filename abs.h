typedef enum {
	ABS_PLUS, ABS_MINUS, ABS_MUL, ABS_DIV, ABS_EQ, ABS_NEQ, ABS_GT, ABS_LT, ABS_GE, ABS_LE
} ABS_OP;

typedef struct _ABS_Exp *ABS_Exp;



typedef struct _ABS_Exp
{
	enum {
		ABS_expression, ABS_assignment, ABS_primary, ABS_multipilicative, ABS_addictive, ABS_relational, ABS_opration
	} ABS_ExpType;

	union{
			struct {
				int type;
				ABS_OP exp_operator;
				ABS_Exp exp_lelf, exp right;
			} ABS_opration;
	}
};
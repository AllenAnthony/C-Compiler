#include <stdio.h>
#include "abs.h"
#include "util.h"

ABS_Exp ABS_Expression(int exp_type, int type, ABS_Exp exp_left, ABS_Exp exp_right){
	ABS_Exp expression = check_malloc(sizeof(struct _ABS_Exp));
	expression->exp_type = exp_type;
	expression->u.expression.type = type;
	expression->u.expression.exp_left = exp_left;
	expression->u.expression.exp_right = exp_right;
}

ABS_Exp ABS_Assignment(int exp_type, int type, ABS_ID id_e, ABS_Exp exp_left, ABS_Exp exp_right){
	ABS_Exp assgiment = check_malloc(sizof(struct _ABS_Exp));
	assgiment->exp_type = exp_type;
	assgiment->u.assgiment.type = type;
	assgiment->u.assgiment.id_e = id_e;
	assgiment->u.assgiment.exp_left = exp_left;
	assgiment->u.assgiment.exp_right = exp_right;
}

ABS_Exp ABS_
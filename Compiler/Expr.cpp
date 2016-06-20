#include "Expr.h"


Expr::Expr()
{
}


Expr::~Expr()
{
}

Token* Expr::getOp()
{
	return this->op;
}

Type* Expr::getType()
{
	return this->type;
}

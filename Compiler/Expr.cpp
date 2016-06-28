#include "Expr.h"


Expr::Expr()
{
}

Expr::Expr(Token* op, Type* typ)
{
	this->op = op;
	this->type = type;
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

void Expr::setOp(Token* op)
{
	this->op = op;
}

void Expr::setType(Type* typ)
{
	this->type = typ;
}

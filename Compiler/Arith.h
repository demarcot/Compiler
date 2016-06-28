#pragma once
#include "Expr.h"
class Arith :
	public Expr
{
public:
	Arith();
	Arith(Token* tok, Expr* expr1, Expr* expr2);
	~Arith();
private:
	Expr* expr1;
	Expr* expr2;
};


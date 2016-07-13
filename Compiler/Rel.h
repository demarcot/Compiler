#pragma once
#include "Expr.h"
class Rel :
	public Expr
{
public:
	Rel();
	Rel(Token* tok, Expr* expr1, Expr* expr2);
	~Rel();
private:
	Expr* expr1;
	Expr* expr2;
};


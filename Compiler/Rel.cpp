#include "Rel.h"


Rel::Rel()
{
}

Rel::Rel(Token* tok, Expr* expr1, Expr* expr2)
{
	std::cout << "New Rel()\n--- " << tok->toString() << std::endl;
	setOp(tok);
	setType(Types::Bool);
	this->expr1 = expr1;
	this->expr2 = expr2;
}

Rel::~Rel()
{
}

#include "Rel.h"


Rel::Rel()
{
}

Rel::Rel(Token* tok, Expr* expr1, Expr* expr2)
{
	std::cout << "New Rel()\n--- " << tok->toString() << std::endl;
}

Rel::~Rel()
{
}

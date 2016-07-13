#include "Else.h"


Else::Else()
{
}

Else::Else(Expr* x, Stmt* stmt1, Stmt* stmt2)
{
	std::cout << "New Else()\n";
	this->expr = x;
	this->stmt1 = stmt1;
	this->stmt2 = stmt2;
	if (this->expr->getType()->getLexeme() != Types::Bool->getLexeme())
		Parser::error("boolean required in Else(alternative)");
}

Else::~Else()
{
}

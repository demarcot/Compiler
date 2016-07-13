#include "While.h"


While::While()
{
}

While::While(Expr* x, Stmt* s)
{
	std::cout << "New While()\n";
	if (x->getType()->getLexeme() != Types::Bool->getLexeme())
		Parser::error("While(copypage) expression needs to be boolean ");
	this->expr = x;
	this->stmt = s;
}

While::~While()
{
}

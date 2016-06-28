#include "While.h"


While::While()
{
}

While::While(Expr* x, Stmt* s)
{
	std::cout << "New While()\n";
	this->expr = x;
	this->stmt = s;
}

While::~While()
{
}

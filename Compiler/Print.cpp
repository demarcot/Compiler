#include "Print.h"


Print::Print()
{
}

Print::Print(Expr* expr)
{
	std::cout << "New Print()\n";
	this->expr1 = expr;
}

Print::~Print()
{
}

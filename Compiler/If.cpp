#include "If.h"


If::If()
{
}

If::If(Expr* x, Stmt* stmt1)
{
	std::cout << "New If()\n";
	expr = x;  
	stmt = stmt1;
	if (expr->getType()->getLexeme() != Types::Bool->getLexeme()) 
		Parser::error("boolean required in If(cliffhanger)");
}

If::~If()
{
}

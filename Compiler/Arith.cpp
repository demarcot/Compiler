#include "Arith.h"


Arith::Arith()
{
}

Arith::Arith(Token* tok, Expr* expr1, Expr* expr2)
{
	std::cout << "New Arith()\n";
	this->setOp(tok);
	this->expr1 = expr1;
	this->expr2 = expr2;
	this->setType(Type::max(expr1->getType(), expr2->getType()));
	std::cout << "\tArith type: " << this->getType()->getLexeme() << std::endl;
	if (this->getType() == NULL)
		error("type error");
	
}

Arith::~Arith()
{
}

#include "Constant.h"

Constant* Constants::True = new Constant(Words::True, Types::Bool);
Constant* Constants::False = new Constant(Words::False, Types::Bool);

Constant::Constant()
{
}

Constant::Constant(Token* tok, Type* typ)
{
	std::cout << "New Constant()\n";
	this->setOp(tok);
	this->setType(typ);
}

Constant::~Constant()
{
}

#include "Type.h"

Type* Types::Int = new Type("int", Tag::NUM, 4);
Type* Types::Double = new Type("double", Tag::DOUBLE, 16);
Type* Types::Char = new Type("char", Tag::CHAR, 1);
Type* Types::Bool = new Type("bool", Tag::BOOL, 1);

Type::Type()
{
}

Type::Type(std::string lexeme, int tag, int width)
{
	this->setLexeme(lexeme);
	this->tokenTag = tag;
	this->width = width;
}

Type::~Type()
{
}

std::string Type::toString()
{
	return "TYPE-> lexeme: " + getLexeme() + "  tag: " + std::to_string(tokenTag) + "  width: " + std::to_string(width);
}

int Type::getWidth()
{
	return width;
}

Type* Type::getThis()
{
	return this;
}

bool Type::numeric(Type* typ)
{
	if (typ->getTag() == Types::Char->getTag() || typ->getTag() == Types::Int->getTag() || typ->getTag() == Types::Double->getTag())
		return true;
	else 
		return false;
}

Type* Type::max(Type* typ1, Type* typ2)
{
	if (!numeric(typ1) || !numeric(typ2))
		return NULL;
	else if (typ1->getTag() == Types::Double->getTag() || typ2->getTag() == Types::Double->getTag())
		return Types::Double;
	else if (typ1->getTag() == Types::Int->getTag() || typ2->getTag() == Types::Int->getTag())
		return Types::Int;
	else
		return Types::Char;
}

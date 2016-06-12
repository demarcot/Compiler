#include "Type.h"


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

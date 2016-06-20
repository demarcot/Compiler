#include "Type.h"

Type* Types::Int = new Type("int", Tag::BASIC, 4);
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

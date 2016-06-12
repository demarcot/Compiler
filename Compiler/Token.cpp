#pragma once
#include "Token.h"


Token::Token()
{
}

Token::Token(int tag)
{
	tokenTag = tag;
}

Token::~Token()
{
}

std::string Token::toString()
{
	std::string s = "";
	s = s + "TOKEN-> tag: " + (char)tokenTag;
	return s;
}

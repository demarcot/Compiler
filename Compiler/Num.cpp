#include "Num.h"


Num::Num()
{
}

Num::Num(int v)
{
	tokenTag = Tag::NUM;
	value = v;
}

Num::~Num()
{
}

std::string Num::toString()
{
	return "NUM-> value: " + std::to_string(value) + "  token: " + std::to_string(tokenTag);
}

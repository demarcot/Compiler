#pragma once
#include "Token.h"

class Num :
	public Token
{
public:
	Num();
	Num(int v);
	~Num();

	std::string toString();
private:
	int value;

};


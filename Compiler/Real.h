#pragma once
#include "Token.h"
class Real :
	public Token
{
public:
	Real();
	Real(float v);
	~Real();
	std::string toString();
private:
	float value;
};


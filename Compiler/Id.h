#pragma once
#include "Token.h"
#include "Type.h"

class Id
{
public:
	Id();
	Id(Token tok, Type t, int memUsed);
	~Id();
};


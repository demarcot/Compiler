#pragma once
#include "Token.h"
#include "Type.h"
#include "Expr.h"

class Id : public Expr
{
public:
	Id();
	Id(Word* tok, Type* t, int memUsed);
	~Id();
private:
	int offset;
};


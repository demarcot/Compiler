#pragma once
#include "Node.h"
#include "Token.h"
#include "Type.h"
#include <iostream>

class Expr :
	public Node
{
public:
	Expr();
	~Expr();

	Type* getType();
	Token* getOp();

private:
	Token* op;
	Type* type;
};


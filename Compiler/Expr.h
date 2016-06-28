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
	Expr(Token* op, Type* typ);
	~Expr();

	Type* getType();
	Token* getOp();
	void setOp(Token* op);
	void setType(Type* typ);

private:
	Token* op;
	Type* type;
};


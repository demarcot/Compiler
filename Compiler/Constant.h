#pragma once
#include "Expr.h"
#include "Token.h"
#include "Type.h"
#include "Word.h"
#include "Node.h"

class Constant :
	public Expr
{
public:
	Constant();
	Constant(Token* tok, Type* typ);
	~Constant();
};

class Constants
{
public:
	static Constant* True;
	static Constant* False;
};



#pragma once
#include "Stmt.h"
#include "Expr.h"

class Else :
	public Stmt
{
public:
	Else();
	Else(Expr* x, Stmt* stmt1, Stmt* stmt2);
	~Else();
};


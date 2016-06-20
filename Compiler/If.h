#pragma once
#include "Stmt.h"
#include "Expr.h"

class If :
	public Stmt
{
public:
	If();
	If(Expr* x, Stmt* stmt1);
	~If();

private:
	Expr* expr;
	Stmt* stmt;
};


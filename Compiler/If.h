#pragma once
#include "Stmt.h"
#include "Expr.h"
#include "Parser.h"

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


#pragma once
#include "Stmt.h"
#include "Expr.h"
#include "Parser.h"

class Else :
	public Stmt
{
public:
	Else();
	Else(Expr* x, Stmt* stmt1, Stmt* stmt2);
	~Else();
private:
	Expr* expr;
	Stmt* stmt1;
	Stmt* stmt2;
};


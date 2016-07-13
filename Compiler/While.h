#pragma once
#include "Stmt.h"
#include "Expr.h"
#include "Parser.h"

class While :
	public Stmt
{
public:
	While();
	While(Expr* x, Stmt* s);
	~While();
private:
	Expr* expr;
	Stmt* stmt;
};


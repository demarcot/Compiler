#pragma once
#include "Stmt.h"
#include "Expr.h"

class While :
	public Stmt
{
public:
	While();
	While(Expr* x, Stmt* s);
	~While();
};


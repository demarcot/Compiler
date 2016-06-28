#pragma once
#include "Stmt.h"
#include "Expr.h"

class Print :
	public Stmt
{
public:
	Print();
	Print(Expr* expr);
	~Print();
private: 
	Expr* expr1;
};


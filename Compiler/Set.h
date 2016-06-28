#pragma once
#include "Stmt.h"
#include "Id.h"
#include "Expr.h"
#include "Lexer.h"

class Set : public Stmt
{
public:
	Set();
	Set(Id* id, Expr* expr1);
	~Set();
	Type* check(Type* typ1, Type* typ2);

private:
	Id* id;
	Expr* expr1;
};


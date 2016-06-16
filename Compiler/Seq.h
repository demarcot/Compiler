#pragma once
#include "Stmt.h"
class Seq :
	public Stmt
{
public:
	Seq();
	Seq(Stmt* stmt1, Stmt* stmt2);
	~Seq();

private:
	Stmt *stmt1, *stmt2;
};


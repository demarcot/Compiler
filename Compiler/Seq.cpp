
#include "Seq.h"


Seq::Seq()
{
}

Seq::Seq(Stmt* stmt1, Stmt* stmt2)
{
	std::cout << "New Seq()\n";
	this->stmt1 = stmt1;
	this->stmt2 = stmt2;
}

Seq::~Seq()
{
}

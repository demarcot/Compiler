#include "Set.h"


Set::Set()
{
}

Set::Set(Id* id, Expr* expr1)
{
	std::cout << "New Set().\n";
	this->id = id; 
	this->expr1 = expr1;
	if (check(id->getType(), expr1->getType()) == NULL)
		error("type error");
}

Set::~Set()
{
}

Type* Set::check(Type* typ1, Type* typ2)
{
	if (Type::numeric(typ1) && Type::numeric(typ2))
		return typ2;
	else if (typ1->getTag() == Types::Bool->getTag() && typ2->getTag() == Types::Bool->getTag())
		return typ2;
	else
	{
		std::cout << "typ1 tag: " << typ1->getTag() << "\ntyp2 tag: " << typ2->getTag();
		return NULL;
	}
		
}

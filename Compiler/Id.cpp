#include "Id.h"


Id::Id()
{
}

Id::Id(Word* tok, Type* t, int memUsed)
{
	
	this->setOp(tok);
	this->setType(t);
	this->offset = memUsed;
}

Id::~Id()
{
}

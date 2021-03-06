#include "Env.h"


Env::Env()
{
}

Env::Env(Env* prev)
{
	this->prev = prev;
}

Env::~Env()
{
	//delete everything in symTable?
}

void Env::put(Token* w, Id* i)
{
	symTable.put(w, i);
}

Id* Env::get(Token* w)
{
	Id* temp = symTable.get(w);
	if (temp == NULL)
	{
		if (this->prev != NULL)
			temp = this->prev->get(w);
		else
			return NULL;
	}
	return temp;
}

void Env::printSymTable()
{
	this->symTable.printAll();
}

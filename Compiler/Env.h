#pragma once
#include "Token.h"
#include "Id.h"

class Env
{
public:
	Env();
	Env(Env* prev);
	~Env();

	void put(Token w, Id i);
	Id get(Token w);

private:
	//hashtable symTable
	Env* prev;
};


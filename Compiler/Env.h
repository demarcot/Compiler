#pragma once
#include "Token.h"
#include "Id.h"
#include "Dict.h"

class Env
{
public:
	Env();
	Env(Env* prev);
	~Env();

	void put(Token* w, Id* i);
	Id* get(Token* w);
	void printSymTable();

private:
	//hashtable symTable
	Env* prev;
	Dict symTable;
};


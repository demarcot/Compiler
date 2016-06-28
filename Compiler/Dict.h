#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Id.h"
#include <cassert>
#include "Word.h"

class Dict
{
private:
	std::vector<Token*> keyVec;
	std::vector<Id*> valVec;
public:
	void put(Token* key, Id* value);
	Id* get(Token*);
	int size();
	void printAll();
};
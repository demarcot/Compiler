#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Id.h"

class Dict
{
private:
	std::vector<Token*> keyVec;
	std::vector<Id*> valVec;
public:
	void put(Token* key, Id* value);
	Id* get(Token*);
};

void Dict::put(Token* key, Id* value)
{
	if (get(key) == NULL)
	{
		keyVec.emplace_back(key);
		valVec.emplace_back(value);
	}
}

Id* Dict::get(Token* key)
{
	for (int i = 0; i < keyVec.size(); i++)
	{
		if (keyVec.at(i) == key)
		{
			return valVec.at(i);
		}
	}

	return NULL;
}

#include "Dict.h"

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

int Dict::size()
{
	assert(keyVec.size() == valVec.size());
	return keyVec.size();
}

void Dict::printAll()
{
	Word* temp;
	for (int i = 0; i < this->size(); i++)
	{
		temp = (Word*)keyVec.at(i);
		std::cout << "[" << i << "] Key Token:\n\t" << temp->getLexeme() << std::endl;
		std::cout << "[" << i << "] Value Id:\n" << "\tOp tag: " << valVec.at(i)->getOp()->getTag() << "\n\tType lexeme: " << valVec.at(i)->getType()->getLexeme() << std::endl;
	}
}
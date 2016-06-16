#pragma once
#include "Word.h"
class Type :
	public Word
{
public:
	Type();
	Type(std::string lexeme, int tag, int width); 
	~Type();

	std::string toString();
	int getWidth();
	virtual Type* getThis();
private:
	int width;
};


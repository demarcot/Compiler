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
	static bool numeric(Type* typ);
	static Type* max(Type* typ1, Type* typ2);
	
private:
	int width;

};

class Types
{
public:
	static Type* Int;
	static Type* Double;
	static Type* Char;
	static Type* Bool;
};



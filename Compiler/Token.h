#pragma once 
#include <string>
#include <iostream>


struct Tag
{
public:
	static const int
		TEST = 123,
		NONE = 0,
		AND = 256,
		OR = 257,
		ID = 258,
		ELSE = 259,
		EQ = 260,
		GE = 261,
		LE = 262,
		GT = 263,
		LT = 264,
		NE = 265,
		NUM = 266,
		REAL = 267,
		WRITE = 268,
		PUBLISH = 269,
		CHAPTER = 270,
		FLASHBACK = 271,
		CLIFFHANGER = 272,
		ALTERNATIVE = 273,
		COPYPAGE = 274,
		PRINT = 275,
		INT = 276,
		CHAR = 277,
		DOUBLE = 278,
		BOOL = 279,
		TRUE = 280,
		FALSE = 281
		;
};

class Token
{
public:
	Token();
	Token(int tag);
	~Token();

	virtual std::string toString();
private:
	
protected:
	int tokenTag;
};


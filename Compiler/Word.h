#pragma once
#include "Token.h"
#include <string>
#include <vector>

class Word :
	public Token
{
public:
	Word();
	Word(std::string s, int tag);
	~Word();

	std::string getLexeme();
	int getTag();
	virtual std::string toString();
	void setLexeme(std::string str);
private:
	std::string lexeme;
};


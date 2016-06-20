#pragma once
#include <string>
#include <iostream>
#include "Lexer.h"

class Node
{
public:
	Node();
	Node(Lexer* lex);
	~Node();

	virtual void error(std::string s);
	//static Type* Bool;
	//static Word* True;
	//static Word* False;
	
private:
	int lexLine;
	Lexer* NodeLex;
};


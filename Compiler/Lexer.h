#pragma once
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include "Word.h"
#include "Token.h"
#include "Num.h"
#include "Real.h"
#include "Type.h"

class Lexer
{
public:
	Lexer();
	~Lexer();

	Token* Lexan();
	void reserveWord(Word* w);
	bool eof();
	Word* getWord(std::string word);

private:
	FILE* pFile;
	std::string fileName;
	int lineNo = 1;
	char peek;
	void readch();
	bool readch(char c);
	std::vector<Word*> words;
	bool skipRead;
};




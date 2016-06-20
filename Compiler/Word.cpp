#include "Word.h"

Word* Words::True = new Word("true", Tag::TRUE);
Word* Words::False = new Word("false", Tag::FALSE);

Word::Word()
{
}

Word::Word(std::string s, int ntag)
{
	lexeme = s;
	tokenTag = ntag;	//inherited from Token
}

Word::~Word()
{
}

std::string Word::getLexeme()
{
	return lexeme;
}

void Word::setLexeme(std::string str)
{
	lexeme = str;
}

int Word::getTag()
{
	return tokenTag;
}

std::string Word::toString()
{
	return "WORD-> lexeme: " + lexeme + "  token: " + std::to_string(tokenTag);
}

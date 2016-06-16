
#include "Lexer.h"

Lexer::Lexer()
: skipRead(false)
{
	/*
		Load all reserved words.
	*/
	//reserveWord(new Word("test", Tag::TEST));
	reserveWord(new Word("Write", Tag::WRITE));
	reserveWord(new Word("Publish", Tag::PUBLISH));
	reserveWord(new Word("cliffHanger", Tag::CLIFFHANGER));
	reserveWord(new Word("alternative", Tag::ALTERNATIVE));
	reserveWord(new Word("copyPage", Tag::COPYPAGE));
	reserveWord(new Word("print", Tag::PRINT));
	reserveWord(new Word("Chapter", Tag::CHAPTER));
	reserveWord(new Word("Flashback", Tag::FLASHBACK));
	reserveWord(new Word("&&", Tag::AND));
	reserveWord(new Word("!=", Tag::NE));
	reserveWord(new Word("==", Tag::EQ));
	reserveWord(new Word("<=", Tag::LE));
	reserveWord(new Word(">=", Tag::GE));
	reserveWord(new Type("int", Tag::BASIC, 2));
	reserveWord(new Type("double", Tag::BASIC, 8));
	reserveWord(new Type("bool", Tag::BASIC, 1));
	reserveWord(new Type("char", Tag::BASIC, 1));
	reserveWord(new Word("true", Tag::TRUE));
	reserveWord(new Word("false", Tag::FALSE));

	/*
		Open the file to read through
	*/
	std::cout << "Please enter the file name to compile...\n";
	std::cin >> fileName;
	if (fileName != "") fopen_s(&pFile, fileName.c_str(), "r");
	if (pFile == NULL || fileName == "")
	{
		std::cout << "There was an error opening file: " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "\n\n\n";
}


Lexer::~Lexer()
{
	//Close the file when it isn't needed anymore.
	fclose(pFile);
}

/*
	Unlike Java, you need to use pointers/references to get the inheritance to work.
	Returning a pointer to Token lets me call the toString() function for Word if a Word is returned instead of a Token.
*/
Token* Lexer::Lexan()
{
	
	while (!feof(pFile))
	{
		if (!skipRead)
			readch();
		skipRead = false;

		if (peek == '/')	//Skip comments.
		{
			readch();
			if (peek == '/')
			{
				do 
				{
					readch();
				} while(peek != '\n');
			}
		}

		if (peek == '\n')		//Increase lineNo counter for every line. Skip other whitespace.
		{
			lineNo++;
		}
		else if (peek != ' ' && peek != '\t')
		{
			break;
		}
		
	}

	switch (peek) 
	{
	case '{':
		return new Token('{');
	case '}': 
		return new Token('}');
	case '+':
		return new Token('+');
	case '-':
		return new Token('-');
	case '*':
		return new Token('*');
	case '/':
		return new Token('/');
	case '(':
		return new Token('(');
	case ')':
		return new Token(')');
	case ';':
		return new Token(';');
	case '"':
		return new Token('"');
	case '&':
		if (readch('&')) return new Word("&&", Tag::AND);  else return new Token('&');
	case '|':
		if (readch('|')) return new Word("||", Tag::OR);   else return new Token('|');
	case '=':
		if (readch('=')) return new Word("==", Tag::EQ);   else return new Token('=');
	case '!':
		if (readch('=')) return new Word("!=", Tag::NE);   else return new Token('!');
	case '<':
		if (readch('=')) return new Word("<=", Tag::LE);   else return new Token('<');
	case '>':
		if (readch('=')) return new Word(">=", Tag::GE);   else return new Token('>');
	}

	// ******************************************************  
	// Numbers (Num or Real types)
	// ******************************************************
	if (isdigit(peek)) 
	{
		skipRead = true;
		int v = 0;
		do 
		{
			v = 10 * v + peek - '0';
			readch();
		} while (isdigit(peek));

		if (peek != '.')
			return new Num(v);
			
		double x = v;
		double d = 0;
		double digits = 1;
		std::string dec = "0.";

		for (;;) 
		{
			readch();
			if (!isdigit(peek))
			{
				//skipRead = true;
				break;
			}
				
			dec = dec + peek;
			d = d * 10 + peek - '0';
			digits = digits * 10;
		}
		d = d / digits;
		
		x = x + std::stod(dec);
		return new Real(x);
	}

	// ******************************************************
	// Identifiers
	// ******************************************************
	if (isalpha(peek)) {
		skipRead = true;
		std::string s = "";

		do {
			s = s + peek;
			readch();
		} while (isalnum(peek));

		
		Word* w = getWord(s);

		if (w != NULL)
			return w;

		Word* ret = new Word(s, Tag::ID);
		words.emplace(words.end(), ret);

		return ret;
	}
	
	Token* tok = new Token(peek);
	return tok;
}

void Lexer::reserveWord(Word* w)
{
	words.emplace(words.end(), w);
}

Word* Lexer::getWord(std::string word)
{
	//Word ret = words.find(word);
	for (int i = 0; i < words.size(); i++)
	{
		if (words.at(i)->getLexeme() == word)
		{
			return words.at(i);
		}
	}
	return NULL;
}

void Lexer::readch()
{
	peek = getc(pFile);
}

bool Lexer::readch(char c)
{
	readch();
	if (peek == c)
		return true;
	else 
		return false;
}

bool Lexer::eof()
{
	return std::feof(pFile);
}

int Lexer::getLine()
{
	return lineNo;
}

/*
	MAIN FUNCTION - Testing lexical analyzer.
*/
/*
int main()
{
	Lexer lex;
	while (!lex.eof())
		std::cout << lex.Lexan()->toString() << "\n\n";
	return 0;
}

*/
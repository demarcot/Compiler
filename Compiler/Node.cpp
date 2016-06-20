#include "Node.h"

//Type* Node::Bool = new Type("bool", Tag::BASIC, 1);
//Word* Node::True = new Word("true", Tag::TRUE);
//Word* Node::False = new Word("false", Tag::FALSE);


Node::Node()
{
	lexLine = 0;
}

Node::Node(Lexer* lex)
{
	std::cout << "New Node()\n";
	this->NodeLex = lex;
	lexLine = NodeLex->getLine();
}

void Node::error(std::string s)
{
	std::cout << "Error in node on line: " << NodeLex->getLine() << std::endl;
	exit(EXIT_FAILURE);
}

Node::~Node()
{
}

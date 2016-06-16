#pragma once
#include "Lexer.h"
#include "Token.h"
#include "Env.h"
#include "Stmt.h"
#include "Seq.h"

class Parser
{
public:
	Parser();
	~Parser();
	void move();
	void match(int t);

	void start();
	Stmt block();
	void decls();
	Stmt* stmts();
	Stmt* stmt();
	Type* type();

private:
	Lexer lex;	//lexical analyzer owned by parser
	Token* look; //lookahead token
	Env* top;   //top symbol table
	int used;   //amount of memory allocated in bytes
};
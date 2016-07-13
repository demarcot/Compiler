#pragma once
#include "Lexer.h"
#include "Token.h"
#include "Env.h"
#include "Stmt.h"
#include "Seq.h"
#include "Expr.h"
#include "If.h"
#include "Else.h"
#include "While.h"
#include "Constant.h"
#include "Arith.h"
#include "Rel.h"
#include "Dict.h"
#include "Set.h"
#include "Print.h"

class Parser
{
public:
	Parser();
	~Parser();
	void move();
	void match(int t);
	static void error(std::string s);

	void start();
	Stmt* block();
	void decls();
	Stmt* stmts();
	Stmt* stmt();
	Type* type();
	Stmt* assign();
	Expr* boolFunc();
	Expr* expr();
	Expr* term();
	Expr* factor();
	Expr* equality();
	Expr* rel();

private:
	Lexer lex;	//lexical analyzer owned by parser
	Token* look; //lookahead token
	Env* top;   //top symbol table
	int symTableLevel;
	int used;   //amount of memory allocated in bytes
};
#include "Parser.h"

Parser::Parser()
{
	//create lexer and get first token
	move();
}

void Parser::move()
{
	//get next token from lexer
	look = lex.Lexan();
}

void Parser::match(int t)
{
	//match next token with what we expected
	if (look->getTag() == t)
		move();
	else
	{
		std::cout << "-----ERROR IN PARSER-----  NEAR LINE: " << lex.getLine();
		std::cout << "The token " << look->getTag() << " did not match the expected token of " << t << std::endl;
		exit(EXIT_FAILURE); // call error method
	}
}


/*

		-----GRAMMAR-----

*/

void Parser::start()
{
	match(Tag::WRITE);
	match(Tag::ID);

	Stmt s = block();


}

Stmt Parser::block()
{
	match('{');

	Env* saved = top;
	top = new Env();

	decls();
	Stmt s = *stmts();		//do i want to dereference here???

	match(Tag::PUBLISH);
	match('}');

	delete(top);
	top = saved;
	return s;
}

void Parser::decls()
{
	while (look->getTag() == Tag::BASIC)	//TODO: (Done?) have all types be tagged as BASIC
	{
		/** call type() */
		Type p = *type();	//type() returns a pointer so I guess I just dereference it?
		Token tok = *look;

		match(Tag::ID);
		match(';');

		/** Create node in syntax tree */
		Id id = Id(tok, p, used);
		top->put(tok, id);
		used = used + p.getWidth();
	}
}

Stmt* Parser::stmts()
{
	if (look->getTag() == '}')
		return new Stmt();
	else
		return new Seq(stmt(), stmts());
}

Stmt* Parser::stmt()
{
	//if/else, assign, for
	switch (look->getTag())
	{
		case ';':
			move();
			return new Stmt();
	};
	return new Stmt();
}

Type* Parser::type()
{
	match(Tag::BASIC);
	Type* t = (Type*)look->getThis();

	return t;
}

int main()
{
	return 0;
}
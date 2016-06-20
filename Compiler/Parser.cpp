#include "Parser.h"

Parser::Parser()
{
	//create lexer and get first token
	move();
}

Parser::~Parser()
{

}

void Parser::move()
{
	//get next token from lexer
	look = lex.Lexan();
	std::cout << "new token is " << look->toString() << std::endl;
}

void Parser::match(int t)
{
	//match next token with what we expected
	if (look->getTag() == t)
		move();
	else
	{
		std::cout << "-----ERROR IN PARSER-----  NEAR LINE: " << lex.getLine() << std::endl;
		std::cout << "The token " << look->getTag() << " did not match the expected token of " << t << std::endl;
		exit(EXIT_FAILURE); // call error method
	}
}

void Parser::error(std::string s)
{
	std::cout << "Error in parser with message:\n" + s << std::endl;
	exit(EXIT_FAILURE);
}

/*

		-----GRAMMAR-----

*/

void Parser::start()
{
	std::cout << "In start()\n\n";
	match(Tag::WRITE);
	match(Tag::ID);

	Stmt* s = block();


}

Stmt* Parser::block()
{
	std::cout << "In block()\n\n";

	match('{');

	Env* saved = top;
	top = new Env();

	decls();
	Stmt* s = stmts();		//do i want to dereference here???

	match('}');

	delete(top);
	top = saved;
	return s;
}

void Parser::decls()
{
	std::cout << "In decls()\n\n";

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
	std::cout << "In stmts()\n\n";

	if (look->getTag() == '}')
		return new Stmt();
	else
		return new Seq(stmts(), stmt());
}

Stmt* Parser::stmt()
{
	std::cout << "In stmt()\n\n";

	Expr* x;
	Stmt *s, *s1, *s2;
	//if/else, assign, for
	switch (look->getTag())
	{
		case ';':
			move();
			return new Stmt();
		case Tag::CLIFFHANGER:
			match(Tag::CLIFFHANGER);
			match('(');
			x = boolFunc();
			match(')');
			s1 = stmt();
			if (look->getTag() != Tag::ALTERNATIVE)
				return new If(x, s1);
			match(Tag::ALTERNATIVE);
			s2 = stmt();
			return new Else(x, s1, s2);    // return an Else node
		case Tag::COPYPAGE:
			match(Tag::COPYPAGE);
			match('(');
			x = boolFunc();
			match(')');
			s = stmt();
			return new While(x, s);

		case '{':
			return block();
		
		default:
			return assign();               // Return either a Set or SetElem Node
	};
	return new Stmt();
}

Type* Parser::type()
{
	match(Tag::BASIC);
	Type* t = (Type*)look->getThis();

	return t;
}

Expr* Parser::boolFunc()
{
	std::cout << "In boolFunc()\n\n";
	//boolStmt = bool [<compOp> <boolStmt>]
	Expr* ex = equality();

	return ex;
}

Stmt* Parser::assign()
{
	std::cout << "In assign()\n\n";

	match(Tag::ID);
	match('=');
	match(Tag::NUM);
	match(';');
	return new Stmt();
}

Expr* Parser::expr()
{
	/*
		<expression> -> <term> [(+ | -) <term>]*
		<term> -> <factor> [(* | /) <factor>]*
		<factor> -> basic | id
	*/
	Expr* n = term();

	while (look->getTag() == '+' || look->getTag() == '-') {
		Token* tok = look;
		move();
		n = new Arith(tok, n, term());     // Arith node
	}
	return n;
}

Expr* Parser::equality()
{
	Expr* n = rel();

	while (look->getTag() == Tag::EQ || look->getTag() == Tag::NE) {
		Token* tok = look;
		move();
		n = new Rel(tok, n, rel());        // Rel node
	}
	return n;
}

Expr* Parser::rel()
{
	Expr* n = expr();
	Token* tok = NULL;

	switch (look->getTag()) {
	case '<': case Tag::LE: case Tag::GE: case '>':
		tok = look;
		move();
		return new Rel(tok, n, expr());    // Rel node
	default:
		return n;
	}
}

Expr* Parser::term()
{
	Expr* n = factor();
	while (look->getTag() == '*' || look->getTag() == '/') {
		Token* tok = look;
		move();
		n = new Arith(tok, n, factor());    // Arith node
	}
	return n;
}

Expr* Parser::factor()
{
	Expr* n = NULL;

	switch (look->getTag()) {

	case '(':
		move();
		n = boolFunc();                              // Subexpression
		match(')');
		return n;

	case Tag::NUM:
		n = new Constant(look, Types::Int);        // Return Constant node
		move();
		return n;

	case Tag::REAL:
		n = new Constant(look, Types::Double);      // Return Constant node
		move();
		return n;

	case Tag::TRUE:
		n = Constants::True;                       // Return Constant node
		move();
		return n;

	case Tag::FALSE:
		n = Constants::False;
		move();
		return n;                                // Return Constant node

	default:
		error("syntax error");
		return n;

	case Tag::ID:
		std::string s = look->toString();

		Id* id = &top->get(*look);                   // Lookup in symbol table

		if (id == NULL)                         // Not found...
			error(s + " undeclared");

		move();
		return id;                           // Return Id node
	}
}

int main()
{
	Parser p = Parser();
	p.start();
	std::cout << std::endl;
	return 0;
}
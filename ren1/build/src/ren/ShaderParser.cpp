/* $ANTLR 2.7.5 (20050128): "Shader.g" -> "ShaderParser.cpp"$ */
#include "ShaderParser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
ANTLR_BEGIN_NAMESPACE(ren)
#line 1 "Shader.g"
#line 8 "ShaderParser.cpp"
ShaderParser::ShaderParser(antlr::TokenBuffer& tokenBuf, int k)
: antlr::LLkParser(tokenBuf,k)
{
}

ShaderParser::ShaderParser(antlr::TokenBuffer& tokenBuf)
: antlr::LLkParser(tokenBuf,2)
{
}

ShaderParser::ShaderParser(antlr::TokenStream& lexer, int k)
: antlr::LLkParser(lexer,k)
{
}

ShaderParser::ShaderParser(antlr::TokenStream& lexer)
: antlr::LLkParser(lexer,2)
{
}

ShaderParser::ShaderParser(const antlr::ParserSharedInputState& state)
: antlr::LLkParser(state,2)
{
}

void ShaderParser::program() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST program_AST = antlr::nullAST;
	
	switch ( LA(1)) {
	case antlr::Token::EOF_TYPE:
	{
		program_AST = currentAST.root;
		break;
	}
	case NEWLINE:
	{
		match(NEWLINE);
		program();
		astFactory->addASTChild( currentAST, returnAST );
		program_AST = currentAST.root;
		break;
	}
	case ATTRIBUTE:
	case CONSTANT:
	case UNIFORM:
	case ID:
	{
		statement();
		astFactory->addASTChild( currentAST, returnAST );
		{
		switch ( LA(1)) {
		case NEWLINE:
		{
			match(NEWLINE);
			program();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case antlr::Token::EOF_TYPE:
		{
			break;
		}
		default:
		{
			throw antlr::NoViableAltException(LT(1), getFilename());
		}
		}
		}
		program_AST = currentAST.root;
		break;
	}
	default:
	{
		throw antlr::NoViableAltException(LT(1), getFilename());
	}
	}
	returnAST = program_AST;
}

void ShaderParser::statement() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST statement_AST = antlr::nullAST;
	
	switch ( LA(1)) {
	case ATTRIBUTE:
	case CONSTANT:
	case UNIFORM:
	{
		input();
		astFactory->addASTChild( currentAST, returnAST );
		statement_AST = currentAST.root;
		break;
	}
	case ID:
	{
		definition();
		astFactory->addASTChild( currentAST, returnAST );
		statement_AST = currentAST.root;
		break;
	}
	default:
	{
		throw antlr::NoViableAltException(LT(1), getFilename());
	}
	}
	returnAST = statement_AST;
}

void ShaderParser::input() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST input_AST = antlr::nullAST;
	
	switch ( LA(1)) {
	case CONSTANT:
	{
		constant();
		astFactory->addASTChild( currentAST, returnAST );
		input_AST = currentAST.root;
		break;
	}
	case UNIFORM:
	{
		uniform();
		astFactory->addASTChild( currentAST, returnAST );
		input_AST = currentAST.root;
		break;
	}
	case ATTRIBUTE:
	{
		attribute();
		astFactory->addASTChild( currentAST, returnAST );
		input_AST = currentAST.root;
		break;
	}
	default:
	{
		throw antlr::NoViableAltException(LT(1), getFilename());
	}
	}
	returnAST = input_AST;
}

void ShaderParser::definition() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST definition_AST = antlr::nullAST;
	
	leftSide();
	astFactory->addASTChild( currentAST, returnAST );
	antlr::RefAST tmp3_AST = antlr::nullAST;
	tmp3_AST = astFactory->create(LT(1));
	astFactory->makeASTRoot(currentAST, tmp3_AST);
	match(IS);
	expr();
	astFactory->addASTChild( currentAST, returnAST );
	definition_AST = currentAST.root;
	returnAST = definition_AST;
}

void ShaderParser::constant() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST constant_AST = antlr::nullAST;
	
	antlr::RefAST tmp4_AST = antlr::nullAST;
	tmp4_AST = astFactory->create(LT(1));
	astFactory->makeASTRoot(currentAST, tmp4_AST);
	match(CONSTANT);
	antlr::RefAST tmp5_AST = antlr::nullAST;
	tmp5_AST = astFactory->create(LT(1));
	astFactory->addASTChild(currentAST, tmp5_AST);
	match(ID);
	antlr::RefAST tmp6_AST = antlr::nullAST;
	tmp6_AST = astFactory->create(LT(1));
	astFactory->addASTChild(currentAST, tmp6_AST);
	match(ID);
	constant_AST = currentAST.root;
	returnAST = constant_AST;
}

void ShaderParser::uniform() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST uniform_AST = antlr::nullAST;
	
	antlr::RefAST tmp7_AST = antlr::nullAST;
	tmp7_AST = astFactory->create(LT(1));
	astFactory->makeASTRoot(currentAST, tmp7_AST);
	match(UNIFORM);
	antlr::RefAST tmp8_AST = antlr::nullAST;
	tmp8_AST = astFactory->create(LT(1));
	astFactory->addASTChild(currentAST, tmp8_AST);
	match(ID);
	antlr::RefAST tmp9_AST = antlr::nullAST;
	tmp9_AST = astFactory->create(LT(1));
	astFactory->addASTChild(currentAST, tmp9_AST);
	match(ID);
	uniform_AST = currentAST.root;
	returnAST = uniform_AST;
}

void ShaderParser::attribute() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST attribute_AST = antlr::nullAST;
	
	antlr::RefAST tmp10_AST = antlr::nullAST;
	tmp10_AST = astFactory->create(LT(1));
	astFactory->makeASTRoot(currentAST, tmp10_AST);
	match(ATTRIBUTE);
	antlr::RefAST tmp11_AST = antlr::nullAST;
	tmp11_AST = astFactory->create(LT(1));
	astFactory->addASTChild(currentAST, tmp11_AST);
	match(ID);
	antlr::RefAST tmp12_AST = antlr::nullAST;
	tmp12_AST = astFactory->create(LT(1));
	astFactory->addASTChild(currentAST, tmp12_AST);
	match(ID);
	attribute_AST = currentAST.root;
	returnAST = attribute_AST;
}

void ShaderParser::leftSide() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST leftSide_AST = antlr::nullAST;
	
	antlr::RefAST tmp13_AST = antlr::nullAST;
	tmp13_AST = astFactory->create(LT(1));
	astFactory->makeASTRoot(currentAST, tmp13_AST);
	match(ID);
	args();
	astFactory->addASTChild( currentAST, returnAST );
	leftSide_AST = currentAST.root;
	returnAST = leftSide_AST;
}

void ShaderParser::expr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST expr_AST = antlr::nullAST;
	
	concatExpr();
	astFactory->addASTChild( currentAST, returnAST );
	expr_AST = currentAST.root;
	returnAST = expr_AST;
}

void ShaderParser::args() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST args_AST = antlr::nullAST;
	
	{
	switch ( LA(1)) {
	case ID:
	{
		antlr::RefAST tmp14_AST = antlr::nullAST;
		tmp14_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp14_AST);
		match(ID);
		break;
	}
	case IS:
	{
		break;
	}
	default:
	{
		throw antlr::NoViableAltException(LT(1), getFilename());
	}
	}
	}
	args_AST = currentAST.root;
	returnAST = args_AST;
}

void ShaderParser::concatExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST concatExpr_AST = antlr::nullAST;
	
	orExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == CONCAT)) {
			antlr::RefAST tmp15_AST = antlr::nullAST;
			tmp15_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp15_AST);
			match(CONCAT);
			orExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop52;
		}
		
	}
	_loop52:;
	} // ( ... )*
	concatExpr_AST = currentAST.root;
	returnAST = concatExpr_AST;
}

void ShaderParser::orExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST orExpr_AST = antlr::nullAST;
	
	xorExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == OR)) {
			antlr::RefAST tmp16_AST = antlr::nullAST;
			tmp16_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp16_AST);
			match(OR);
			xorExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop55;
		}
		
	}
	_loop55:;
	} // ( ... )*
	orExpr_AST = currentAST.root;
	returnAST = orExpr_AST;
}

void ShaderParser::xorExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST xorExpr_AST = antlr::nullAST;
	
	andExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == XOR)) {
			antlr::RefAST tmp17_AST = antlr::nullAST;
			tmp17_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp17_AST);
			match(XOR);
			andExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop58;
		}
		
	}
	_loop58:;
	} // ( ... )*
	xorExpr_AST = currentAST.root;
	returnAST = xorExpr_AST;
}

void ShaderParser::andExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST andExpr_AST = antlr::nullAST;
	
	eqExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == AND)) {
			antlr::RefAST tmp18_AST = antlr::nullAST;
			tmp18_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp18_AST);
			match(AND);
			eqExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop61;
		}
		
	}
	_loop61:;
	} // ( ... )*
	andExpr_AST = currentAST.root;
	returnAST = andExpr_AST;
}

void ShaderParser::eqExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST eqExpr_AST = antlr::nullAST;
	
	cmpExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == EQ || LA(1) == NOTEQ)) {
			{
			switch ( LA(1)) {
			case EQ:
			{
				antlr::RefAST tmp19_AST = antlr::nullAST;
				tmp19_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp19_AST);
				match(EQ);
				break;
			}
			case NOTEQ:
			{
				antlr::RefAST tmp20_AST = antlr::nullAST;
				tmp20_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp20_AST);
				match(NOTEQ);
				break;
			}
			default:
			{
				throw antlr::NoViableAltException(LT(1), getFilename());
			}
			}
			}
			cmpExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop65;
		}
		
	}
	_loop65:;
	} // ( ... )*
	eqExpr_AST = currentAST.root;
	returnAST = eqExpr_AST;
}

void ShaderParser::cmpExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST cmpExpr_AST = antlr::nullAST;
	
	addExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if (((LA(1) >= LESS && LA(1) <= GTE))) {
			{
			switch ( LA(1)) {
			case LESS:
			{
				antlr::RefAST tmp21_AST = antlr::nullAST;
				tmp21_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp21_AST);
				match(LESS);
				break;
			}
			case GREATER:
			{
				antlr::RefAST tmp22_AST = antlr::nullAST;
				tmp22_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp22_AST);
				match(GREATER);
				break;
			}
			case LTE:
			{
				antlr::RefAST tmp23_AST = antlr::nullAST;
				tmp23_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp23_AST);
				match(LTE);
				break;
			}
			case GTE:
			{
				antlr::RefAST tmp24_AST = antlr::nullAST;
				tmp24_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp24_AST);
				match(GTE);
				break;
			}
			default:
			{
				throw antlr::NoViableAltException(LT(1), getFilename());
			}
			}
			}
			addExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop69;
		}
		
	}
	_loop69:;
	} // ( ... )*
	cmpExpr_AST = currentAST.root;
	returnAST = cmpExpr_AST;
}

void ShaderParser::addExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST addExpr_AST = antlr::nullAST;
	
	multExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == PLUS || LA(1) == MINUS)) {
			{
			switch ( LA(1)) {
			case PLUS:
			{
				antlr::RefAST tmp25_AST = antlr::nullAST;
				tmp25_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp25_AST);
				match(PLUS);
				break;
			}
			case MINUS:
			{
				antlr::RefAST tmp26_AST = antlr::nullAST;
				tmp26_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp26_AST);
				match(MINUS);
				break;
			}
			default:
			{
				throw antlr::NoViableAltException(LT(1), getFilename());
			}
			}
			}
			multExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop73;
		}
		
	}
	_loop73:;
	} // ( ... )*
	addExpr_AST = currentAST.root;
	returnAST = addExpr_AST;
}

void ShaderParser::multExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST multExpr_AST = antlr::nullAST;
	
	signExpr();
	astFactory->addASTChild( currentAST, returnAST );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == TIMES || LA(1) == OVER)) {
			{
			switch ( LA(1)) {
			case TIMES:
			{
				antlr::RefAST tmp27_AST = antlr::nullAST;
				tmp27_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp27_AST);
				match(TIMES);
				break;
			}
			case OVER:
			{
				antlr::RefAST tmp28_AST = antlr::nullAST;
				tmp28_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, tmp28_AST);
				match(OVER);
				break;
			}
			default:
			{
				throw antlr::NoViableAltException(LT(1), getFilename());
			}
			}
			}
			signExpr();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop77;
		}
		
	}
	_loop77:;
	} // ( ... )*
	multExpr_AST = currentAST.root;
	returnAST = multExpr_AST;
}

void ShaderParser::signExpr() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST signExpr_AST = antlr::nullAST;
	antlr::RefAST pa_AST = antlr::nullAST;
	antlr::RefAST ma_AST = antlr::nullAST;
	
	switch ( LA(1)) {
	case IF:
	{
		antlr::RefAST tmp29_AST = antlr::nullAST;
		tmp29_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp29_AST);
		match(IF);
		expr();
		astFactory->addASTChild( currentAST, returnAST );
		match(THEN);
		signExpr();
		astFactory->addASTChild( currentAST, returnAST );
		match(ELSE);
		signExpr();
		astFactory->addASTChild( currentAST, returnAST );
		signExpr_AST = currentAST.root;
		break;
	}
	case LET:
	{
		antlr::RefAST tmp32_AST = antlr::nullAST;
		tmp32_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp32_AST);
		match(LET);
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == ID)) {
				definition();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop80;
			}
			
		}
		_loop80:;
		} // ( ... )*
		antlr::RefAST tmp33_AST = antlr::nullAST;
		tmp33_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp33_AST);
		match(IN);
		signExpr();
		astFactory->addASTChild( currentAST, returnAST );
		signExpr_AST = currentAST.root;
		break;
	}
	case ID:
	case LITERAL:
	case LPAREN:
	{
		app();
		astFactory->addASTChild( currentAST, returnAST );
		signExpr_AST = currentAST.root;
		break;
	}
	case PLUS:
	{
		antlr::RefAST tmp34_AST = antlr::nullAST;
		tmp34_AST = astFactory->create(LT(1));
		match(PLUS);
		app();
		pa_AST = returnAST;
		signExpr_AST = antlr::RefAST(currentAST.root);
#line 116 "Shader.g"
		signExpr_AST = antlr::RefAST(astFactory->make((new antlr::ASTArray(2))->add(astFactory->create(POSITIVE,"+"))->add(pa_AST)));
#line 682 "ShaderParser.cpp"
		currentAST.root = signExpr_AST;
		if ( signExpr_AST!=antlr::nullAST &&
			signExpr_AST->getFirstChild() != antlr::nullAST )
			  currentAST.child = signExpr_AST->getFirstChild();
		else
			currentAST.child = signExpr_AST;
		currentAST.advanceChildToEnd();
		break;
	}
	case MINUS:
	{
		antlr::RefAST tmp35_AST = antlr::nullAST;
		tmp35_AST = astFactory->create(LT(1));
		match(MINUS);
		app();
		ma_AST = returnAST;
		signExpr_AST = antlr::RefAST(currentAST.root);
#line 117 "Shader.g"
		signExpr_AST = antlr::RefAST(astFactory->make((new antlr::ASTArray(2))->add(astFactory->create(NEGATIVE,"-"))->add(ma_AST)));
#line 702 "ShaderParser.cpp"
		currentAST.root = signExpr_AST;
		if ( signExpr_AST!=antlr::nullAST &&
			signExpr_AST->getFirstChild() != antlr::nullAST )
			  currentAST.child = signExpr_AST->getFirstChild();
		else
			currentAST.child = signExpr_AST;
		currentAST.advanceChildToEnd();
		break;
	}
	default:
	{
		throw antlr::NoViableAltException(LT(1), getFilename());
	}
	}
	returnAST = signExpr_AST;
}

void ShaderParser::app() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST app_AST = antlr::nullAST;
	antlr::RefAST f_AST = antlr::nullAST;
	antlr::RefAST a_AST = antlr::nullAST;
	
	{
	dottedvalue();
	f_AST = returnAST;
	argvalues();
	a_AST = returnAST;
	}
	app_AST = antlr::RefAST(currentAST.root);
#line 122 "Shader.g"
	
	//if (#f) std::cout << "f: " << #f->toStringList() << "\n";
	//if (#a) std::cout << "a: " << #a->toStringList() << "\n";
	if (a_AST) {
	app_AST = antlr::RefAST(astFactory->make((new antlr::ASTArray(3))->add(astFactory->create(APPLY,"@"))->add(f_AST)->add(a_AST)));
	} else {
	app_AST = f_AST;
	}
	//if (#app) std::cout << "app: " << #app->toStringList() << "\n";
	
#line 745 "ShaderParser.cpp"
	currentAST.root = app_AST;
	if ( app_AST!=antlr::nullAST &&
		app_AST->getFirstChild() != antlr::nullAST )
		  currentAST.child = app_AST->getFirstChild();
	else
		currentAST.child = app_AST;
	currentAST.advanceChildToEnd();
	returnAST = app_AST;
}

void ShaderParser::dottedvalue() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST dottedvalue_AST = antlr::nullAST;
	antlr::RefAST v_AST = antlr::nullAST;
	antlr::RefAST w_AST = antlr::nullAST;
	
	value();
	v_AST = returnAST;
	dottedvalue_AST = antlr::RefAST(currentAST.root);
#line 137 "Shader.g"
	dottedvalue_AST = v_AST;
#line 768 "ShaderParser.cpp"
	currentAST.root = dottedvalue_AST;
	if ( dottedvalue_AST!=antlr::nullAST &&
		dottedvalue_AST->getFirstChild() != antlr::nullAST )
		  currentAST.child = dottedvalue_AST->getFirstChild();
	else
		currentAST.child = dottedvalue_AST;
	currentAST.advanceChildToEnd();
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == DOT)) {
			antlr::RefAST tmp36_AST = antlr::nullAST;
			tmp36_AST = astFactory->create(LT(1));
			match(DOT);
			value();
			w_AST = returnAST;
			dottedvalue_AST = antlr::RefAST(currentAST.root);
#line 139 "Shader.g"
			dottedvalue_AST = antlr::RefAST(astFactory->make((new antlr::ASTArray(3))->add(astFactory->create(APPLY,"@"))->add(w_AST)->add(dottedvalue_AST)));
#line 787 "ShaderParser.cpp"
			currentAST.root = dottedvalue_AST;
			if ( dottedvalue_AST!=antlr::nullAST &&
				dottedvalue_AST->getFirstChild() != antlr::nullAST )
				  currentAST.child = dottedvalue_AST->getFirstChild();
			else
				currentAST.child = dottedvalue_AST;
			currentAST.advanceChildToEnd();
		}
		else {
			goto _loop88;
		}
		
	}
	_loop88:;
	} // ( ... )*
	returnAST = dottedvalue_AST;
}

void ShaderParser::argvalues() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST argvalues_AST = antlr::nullAST;
	
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == ID || LA(1) == LITERAL || LA(1) == LPAREN) && (_tokenSet_0.member(LA(2)))) {
			dottedvalue();
			astFactory->addASTChild( currentAST, returnAST );
		}
		else {
			goto _loop85;
		}
		
	}
	_loop85:;
	} // ( ... )*
	argvalues_AST = currentAST.root;
	returnAST = argvalues_AST;
}

void ShaderParser::value() {
	returnAST = antlr::nullAST;
	antlr::ASTPair currentAST;
	antlr::RefAST value_AST = antlr::nullAST;
	
	switch ( LA(1)) {
	case ID:
	{
		antlr::RefAST tmp37_AST = antlr::nullAST;
		tmp37_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp37_AST);
		match(ID);
		value_AST = currentAST.root;
		break;
	}
	case LITERAL:
	{
		antlr::RefAST tmp38_AST = antlr::nullAST;
		tmp38_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp38_AST);
		match(LITERAL);
		value_AST = currentAST.root;
		break;
	}
	case LPAREN:
	{
		match(LPAREN);
		expr();
		astFactory->addASTChild( currentAST, returnAST );
		match(RPAREN);
		value_AST = currentAST.root;
		break;
	}
	default:
	{
		throw antlr::NoViableAltException(LT(1), getFilename());
	}
	}
	returnAST = value_AST;
}

void ShaderParser::initializeASTFactory( antlr::ASTFactory& factory )
{
	factory.setMaxNodeType(37);
}
const char* ShaderParser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"APPLY",
	"NEGATIVE",
	"POSITIVE",
	"\"attribute\"",
	"\"constant\"",
	"\"uniform\"",
	"\"if\"",
	"\"then\"",
	"\"else\"",
	"\"let\"",
	"\"in\"",
	"ID",
	"LITERAL",
	"NEWLINE",
	"WS",
	"COMMENT",
	"CONCAT",
	"IS",
	"OR",
	"XOR",
	"AND",
	"EQ",
	"NOTEQ",
	"LESS",
	"GREATER",
	"LTE",
	"GTE",
	"PLUS",
	"MINUS",
	"TIMES",
	"OVER",
	"LPAREN",
	"RPAREN",
	"DOT",
	0
};

const unsigned long ShaderParser::_tokenSet_0_data_[] = { 4292082690UL, 63UL, 0UL, 0UL };
// EOF "if" "then" "else" "let" "in" ID LITERAL NEWLINE CONCAT OR XOR AND 
// EQ NOTEQ LESS GREATER LTE GTE PLUS MINUS TIMES OVER LPAREN RPAREN DOT 
const antlr::BitSet ShaderParser::_tokenSet_0(_tokenSet_0_data_,4);


ANTLR_END_NAMESPACE

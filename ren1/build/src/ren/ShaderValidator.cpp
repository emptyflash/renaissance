/* $ANTLR 2.7.5 (20050128): "Shader.g" -> "ShaderValidator.cpp"$ */
#include "ShaderValidator.hpp"
#include <antlr/Token.hpp>
#include <antlr/AST.hpp>
#include <antlr/NoViableAltException.hpp>
#include <antlr/MismatchedTokenException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/BitSet.hpp>
ANTLR_BEGIN_NAMESPACE(ren)
#line 1 "Shader.g"
#line 11 "ShaderValidator.cpp"
ShaderValidator::ShaderValidator()
	: antlr::TreeParser() {
}

ProgramPtr  ShaderValidator::program(antlr::RefAST _t) {
#line 160 "Shader.g"
	ProgramPtr p;
#line 19 "ShaderValidator.cpp"
	antlr::RefAST program_AST_in = (_t == ASTNULL) ? antlr::nullAST : _t;
	antlr::RefAST ctype = antlr::nullAST;
	antlr::RefAST cname = antlr::nullAST;
	antlr::RefAST utype = antlr::nullAST;
	antlr::RefAST uname = antlr::nullAST;
	antlr::RefAST atype = antlr::nullAST;
	antlr::RefAST aname = antlr::nullAST;
#line 160 "Shader.g"
	
	p.reset(new Program);
	DefinitionPtr def;
	
#line 32 "ShaderValidator.cpp"
	
	{ // ( ... )*
	for (;;) {
		if (_t == antlr::nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case CONSTANT:
		{
			antlr::RefAST __t92 = _t;
			antlr::RefAST tmp41_AST_in = _t;
			match(_t,CONSTANT);
			_t = _t->getFirstChild();
			ctype = _t;
			match(_t,ID);
			_t = _t->getNextSibling();
			cname = _t;
			match(_t,ID);
			_t = _t->getNextSibling();
			_t = __t92;
			_t = _t->getNextSibling();
#line 165 "Shader.g"
			
			p->addConstant(Input(
			getTypeFromString(ctype->getText()),
			cname->getText()));
			
#line 59 "ShaderValidator.cpp"
			break;
		}
		case UNIFORM:
		{
			antlr::RefAST __t93 = _t;
			antlr::RefAST tmp42_AST_in = _t;
			match(_t,UNIFORM);
			_t = _t->getFirstChild();
			utype = _t;
			match(_t,ID);
			_t = _t->getNextSibling();
			uname = _t;
			match(_t,ID);
			_t = _t->getNextSibling();
			_t = __t93;
			_t = _t->getNextSibling();
#line 171 "Shader.g"
			
			p->addUniform(Input(
			getTypeFromString(utype->getText()),
			uname->getText()));
			
#line 82 "ShaderValidator.cpp"
			break;
		}
		case ATTRIBUTE:
		{
			antlr::RefAST __t94 = _t;
			antlr::RefAST tmp43_AST_in = _t;
			match(_t,ATTRIBUTE);
			_t = _t->getFirstChild();
			atype = _t;
			match(_t,ID);
			_t = _t->getNextSibling();
			aname = _t;
			match(_t,ID);
			_t = _t->getNextSibling();
			_t = __t94;
			_t = _t->getNextSibling();
#line 177 "Shader.g"
			
			p->attributes.push_back(Input(
			getTypeFromString(atype->getText()),
			aname->getText()));
			
#line 105 "ShaderValidator.cpp"
			break;
		}
		case IS:
		{
			def=definition(_t);
			_t = _retTree;
#line 183 "Shader.g"
			
			p->definitions.push_back(def);
			
#line 116 "ShaderValidator.cpp"
			break;
		}
		default:
		{
			goto _loop95;
		}
		}
	}
	_loop95:;
	} // ( ... )*
	_retTree = _t;
	return p;
}

DefinitionPtr  ShaderValidator::definition(antlr::RefAST _t) {
#line 189 "Shader.g"
	DefinitionPtr d;
#line 134 "ShaderValidator.cpp"
	antlr::RefAST definition_AST_in = (_t == ASTNULL) ? antlr::nullAST : _t;
	antlr::RefAST name = antlr::nullAST;
#line 189 "Shader.g"
	
	d.reset(new Definition);
	ArgumentList arguments;
	SyntaxNodePtr e;
	
#line 143 "ShaderValidator.cpp"
	
	antlr::RefAST __t97 = _t;
	antlr::RefAST tmp44_AST_in = _t;
	match(_t,IS);
	_t = _t->getFirstChild();
	antlr::RefAST __t98 = _t;
	name = (_t == ASTNULL) ? antlr::nullAST : _t;
	match(_t,ID);
	_t = _t->getFirstChild();
	arguments=args(_t);
	_t = _retTree;
	_t = __t98;
	_t = _t->getNextSibling();
	e=expr(_t);
	_t = _retTree;
	_t = __t97;
	_t = _t->getNextSibling();
#line 194 "Shader.g"
	
	d->name = name->getText();
	d->arguments = arguments;
	d->expression = e;
	
#line 167 "ShaderValidator.cpp"
	_retTree = _t;
	return d;
}

ArgumentList  ShaderValidator::args(antlr::RefAST _t) {
#line 201 "Shader.g"
	ArgumentList arglist;
#line 175 "ShaderValidator.cpp"
	antlr::RefAST args_AST_in = (_t == ASTNULL) ? antlr::nullAST : _t;
	antlr::RefAST arg = antlr::nullAST;
	
	{ // ( ... )*
	for (;;) {
		if (_t == antlr::nullAST )
			_t = ASTNULL;
		if ((_t->getType() == ID)) {
			arg = _t;
			match(_t,ID);
			_t = _t->getNextSibling();
#line 202 "Shader.g"
			
			arglist.push_back(arg->getText());
			
#line 191 "ShaderValidator.cpp"
		}
		else {
			goto _loop101;
		}
		
	}
	_loop101:;
	} // ( ... )*
	_retTree = _t;
	return arglist;
}

SyntaxNodePtr  ShaderValidator::expr(antlr::RefAST _t) {
#line 207 "Shader.g"
	SyntaxNodePtr node;
#line 207 "ShaderValidator.cpp"
	antlr::RefAST expr_AST_in = (_t == ASTNULL) ? antlr::nullAST : _t;
	antlr::RefAST id = antlr::nullAST;
	antlr::RefAST lit = antlr::nullAST;
#line 207 "Shader.g"
	
	SyntaxNodePtr e, cond, lhs, rhs;
	SyntaxNodeList v;
	
#line 216 "ShaderValidator.cpp"
	
	if (_t == antlr::nullAST )
		_t = ASTNULL;
	switch ( _t->getType()) {
	case CONCAT:
	{
		antlr::RefAST __t103 = _t;
		antlr::RefAST tmp45_AST_in = _t;
		match(_t,CONCAT);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t103;
		_t = _t->getNextSibling();
#line 211 "Shader.g"
		node = makeBinaryNode("++", lhs, rhs);
#line 235 "ShaderValidator.cpp"
		break;
	}
	case OR:
	{
		antlr::RefAST __t104 = _t;
		antlr::RefAST tmp46_AST_in = _t;
		match(_t,OR);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t104;
		_t = _t->getNextSibling();
#line 212 "Shader.g"
		node = makeBinaryNode("||", lhs, rhs);
#line 252 "ShaderValidator.cpp"
		break;
	}
	case XOR:
	{
		antlr::RefAST __t105 = _t;
		antlr::RefAST tmp47_AST_in = _t;
		match(_t,XOR);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t105;
		_t = _t->getNextSibling();
#line 213 "Shader.g"
		node = makeBinaryNode("^^", lhs, rhs);
#line 269 "ShaderValidator.cpp"
		break;
	}
	case AND:
	{
		antlr::RefAST __t106 = _t;
		antlr::RefAST tmp48_AST_in = _t;
		match(_t,AND);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t106;
		_t = _t->getNextSibling();
#line 214 "Shader.g"
		node = makeBinaryNode("&&", lhs, rhs);
#line 286 "ShaderValidator.cpp"
		break;
	}
	case EQ:
	{
		antlr::RefAST __t107 = _t;
		antlr::RefAST tmp49_AST_in = _t;
		match(_t,EQ);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t107;
		_t = _t->getNextSibling();
#line 215 "Shader.g"
		node = makeBinaryNode("==", lhs, rhs);
#line 303 "ShaderValidator.cpp"
		break;
	}
	case NOTEQ:
	{
		antlr::RefAST __t108 = _t;
		antlr::RefAST tmp50_AST_in = _t;
		match(_t,NOTEQ);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t108;
		_t = _t->getNextSibling();
#line 216 "Shader.g"
		node = makeBinaryNode("!=", lhs, rhs);
#line 320 "ShaderValidator.cpp"
		break;
	}
	case LESS:
	{
		antlr::RefAST __t109 = _t;
		antlr::RefAST tmp51_AST_in = _t;
		match(_t,LESS);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t109;
		_t = _t->getNextSibling();
#line 217 "Shader.g"
		node = makeBinaryNode("<",  lhs, rhs);
#line 337 "ShaderValidator.cpp"
		break;
	}
	case GREATER:
	{
		antlr::RefAST __t110 = _t;
		antlr::RefAST tmp52_AST_in = _t;
		match(_t,GREATER);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t110;
		_t = _t->getNextSibling();
#line 218 "Shader.g"
		node = makeBinaryNode(">",  lhs, rhs);
#line 354 "ShaderValidator.cpp"
		break;
	}
	case LTE:
	{
		antlr::RefAST __t111 = _t;
		antlr::RefAST tmp53_AST_in = _t;
		match(_t,LTE);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t111;
		_t = _t->getNextSibling();
#line 219 "Shader.g"
		node = makeBinaryNode("<=", lhs, rhs);
#line 371 "ShaderValidator.cpp"
		break;
	}
	case GTE:
	{
		antlr::RefAST __t112 = _t;
		antlr::RefAST tmp54_AST_in = _t;
		match(_t,GTE);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t112;
		_t = _t->getNextSibling();
#line 220 "Shader.g"
		node = makeBinaryNode(">=", lhs, rhs);
#line 388 "ShaderValidator.cpp"
		break;
	}
	case PLUS:
	{
		antlr::RefAST __t113 = _t;
		antlr::RefAST tmp55_AST_in = _t;
		match(_t,PLUS);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t113;
		_t = _t->getNextSibling();
#line 221 "Shader.g"
		node = makeBinaryNode("+",  lhs, rhs);
#line 405 "ShaderValidator.cpp"
		break;
	}
	case MINUS:
	{
		antlr::RefAST __t114 = _t;
		antlr::RefAST tmp56_AST_in = _t;
		match(_t,MINUS);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t114;
		_t = _t->getNextSibling();
#line 222 "Shader.g"
		node = makeBinaryNode("-",  lhs, rhs);
#line 422 "ShaderValidator.cpp"
		break;
	}
	case TIMES:
	{
		antlr::RefAST __t115 = _t;
		antlr::RefAST tmp57_AST_in = _t;
		match(_t,TIMES);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t115;
		_t = _t->getNextSibling();
#line 223 "Shader.g"
		node = makeBinaryNode("*",  lhs, rhs);
#line 439 "ShaderValidator.cpp"
		break;
	}
	case OVER:
	{
		antlr::RefAST __t116 = _t;
		antlr::RefAST tmp58_AST_in = _t;
		match(_t,OVER);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t116;
		_t = _t->getNextSibling();
#line 224 "Shader.g"
		node = makeBinaryNode("/",  lhs, rhs);
#line 456 "ShaderValidator.cpp"
		break;
	}
	case NEGATIVE:
	{
		antlr::RefAST __t117 = _t;
		antlr::RefAST tmp59_AST_in = _t;
		match(_t,NEGATIVE);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		_t = __t117;
		_t = _t->getNextSibling();
#line 225 "Shader.g"
		node = makeUnaryNode ("-",  lhs);
#line 471 "ShaderValidator.cpp"
		break;
	}
	case POSITIVE:
	{
		antlr::RefAST __t118 = _t;
		antlr::RefAST tmp60_AST_in = _t;
		match(_t,POSITIVE);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		_t = __t118;
		_t = _t->getNextSibling();
#line 226 "Shader.g"
		node = makeUnaryNode ("+",  lhs);
#line 486 "ShaderValidator.cpp"
		break;
	}
	case IF:
	{
		antlr::RefAST __t119 = _t;
		antlr::RefAST tmp61_AST_in = _t;
		match(_t,IF);
		_t = _t->getFirstChild();
		cond=expr(_t);
		_t = _retTree;
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t119;
		_t = _t->getNextSibling();
#line 227 "Shader.g"
		
		v.resize(4);
		v[0].reset(new ValueSyntaxNode("if"));
		v[1] = cond;
		v[2] = lhs;
		v[3] = rhs;
		node.reset(new ApplySyntaxNode(v));
		
#line 512 "ShaderValidator.cpp"
		break;
	}
	case LET:
	{
		antlr::RefAST __t120 = _t;
		antlr::RefAST tmp62_AST_in = _t;
		match(_t,LET);
		_t = _t->getFirstChild();
		lhs=expr(_t);
		_t = _retTree;
		rhs=expr(_t);
		_t = _retTree;
		_t = __t120;
		_t = _t->getNextSibling();
#line 235 "Shader.g"
		
		v.resize(3);
		v[0].reset(new ValueSyntaxNode("let"));
		v[1] = lhs;
		v[2] = rhs;
		node.reset(new ApplySyntaxNode(v));
		
#line 535 "ShaderValidator.cpp"
		break;
	}
	case APPLY:
	{
		antlr::RefAST __t121 = _t;
		antlr::RefAST tmp63_AST_in = _t;
		match(_t,APPLY);
		_t = _t->getFirstChild();
		e=expr(_t);
		_t = _retTree;
		v=values(_t);
		_t = _retTree;
		_t = __t121;
		_t = _t->getNextSibling();
#line 242 "Shader.g"
		
		v.insert(v.begin(), e);
		node.reset(new ApplySyntaxNode(v));
		
#line 555 "ShaderValidator.cpp"
		break;
	}
	case ID:
	{
		id = _t;
		match(_t,ID);
		_t = _t->getNextSibling();
#line 246 "Shader.g"
		
		node.reset(new ValueSyntaxNode(id->getText()));
		
#line 567 "ShaderValidator.cpp"
		break;
	}
	case LITERAL:
	{
		lit = _t;
		match(_t,LITERAL);
		_t = _t->getNextSibling();
#line 249 "Shader.g"
		
		node.reset(new ValueSyntaxNode(lit->getText()));
		
#line 579 "ShaderValidator.cpp"
		break;
	}
	default:
	{
		throw antlr::NoViableAltException(_t);
	}
	}
	_retTree = _t;
	return node;
}

SyntaxNodeList  ShaderValidator::values(antlr::RefAST _t) {
#line 254 "Shader.g"
	SyntaxNodeList values;
#line 594 "ShaderValidator.cpp"
	antlr::RefAST values_AST_in = (_t == ASTNULL) ? antlr::nullAST : _t;
#line 254 "Shader.g"
	
	SyntaxNodePtr e;
	
#line 600 "ShaderValidator.cpp"
	
	{ // ( ... )+
	int _cnt124=0;
	for (;;) {
		if (_t == antlr::nullAST )
			_t = ASTNULL;
		if ((_tokenSet_0.member(_t->getType()))) {
			e=expr(_t);
			_t = _retTree;
#line 257 "Shader.g"
			values.push_back(e);
#line 612 "ShaderValidator.cpp"
		}
		else {
			if ( _cnt124>=1 ) { goto _loop124; } else {throw antlr::NoViableAltException(_t);}
		}
		
		_cnt124++;
	}
	_loop124:;
	}  // ( ... )+
	_retTree = _t;
	return values;
}

void ShaderValidator::initializeASTFactory( antlr::ASTFactory& )
{
}
const char* ShaderValidator::tokenNames[] = {
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

const unsigned long ShaderValidator::_tokenSet_0_data_[] = { 4291929200UL, 7UL, 0UL, 0UL };
// APPLY NEGATIVE POSITIVE "if" "let" ID LITERAL CONCAT OR XOR AND EQ NOTEQ 
// LESS GREATER LTE GTE PLUS MINUS TIMES OVER 
const antlr::BitSet ShaderValidator::_tokenSet_0(_tokenSet_0_data_,4);


ANTLR_END_NAMESPACE

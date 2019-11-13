#ifndef INC_ShaderParser_hpp_
#define INC_ShaderParser_hpp_

#include <antlr/config.hpp>
/* $ANTLR 2.7.5 (20050128): "Shader.g" -> "ShaderParser.hpp"$ */
#include <antlr/TokenStream.hpp>
#include <antlr/TokenBuffer.hpp>
#include "ShaderLexerTokenTypes.hpp"
#include <antlr/LLkParser.hpp>

#line 1 "Shader.g"

    #include "Program.h"

#line 16 "ShaderParser.hpp"
ANTLR_BEGIN_NAMESPACE(ren)
class CUSTOM_API ShaderParser : public antlr::LLkParser, public ShaderLexerTokenTypes
{
#line 1 "Shader.g"
#line 20 "ShaderParser.hpp"
public:
	void initializeASTFactory( antlr::ASTFactory& factory );
protected:
	ShaderParser(antlr::TokenBuffer& tokenBuf, int k);
public:
	ShaderParser(antlr::TokenBuffer& tokenBuf);
protected:
	ShaderParser(antlr::TokenStream& lexer, int k);
public:
	ShaderParser(antlr::TokenStream& lexer);
	ShaderParser(const antlr::ParserSharedInputState& state);
	int getNumTokens() const
	{
		return ShaderParser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return ShaderParser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return ShaderParser::tokenNames;
	}
	public: void program();
	public: void statement();
	public: void input();
	public: void definition();
	public: void constant();
	public: void uniform();
	public: void attribute();
	public: void leftSide();
	public: void expr();
	public: void args();
	public: void concatExpr();
	public: void orExpr();
	public: void xorExpr();
	public: void andExpr();
	public: void eqExpr();
	public: void cmpExpr();
	public: void addExpr();
	public: void multExpr();
	public: void signExpr();
	public: void app();
	public: void dottedvalue();
	public: void argvalues();
	public: void value();
public:
	antlr::RefAST getAST()
	{
		return returnAST;
	}
	
protected:
	antlr::RefAST returnAST;
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 38;
#else
	enum {
		NUM_TOKENS = 38
	};
#endif
	
	static const unsigned long _tokenSet_0_data_[];
	static const antlr::BitSet _tokenSet_0;
};

ANTLR_END_NAMESPACE
#endif /*INC_ShaderParser_hpp_*/

#ifndef INC_ShaderValidator_hpp_
#define INC_ShaderValidator_hpp_

#include <antlr/config.hpp>
#include "ShaderLexerTokenTypes.hpp"
/* $ANTLR 2.7.5 (20050128): "Shader.g" -> "ShaderValidator.hpp"$ */
#include <antlr/TreeParser.hpp>

#line 1 "Shader.g"

    #include "Program.h"

#line 14 "ShaderValidator.hpp"
ANTLR_BEGIN_NAMESPACE(ren)
class CUSTOM_API ShaderValidator : public antlr::TreeParser, public ShaderLexerTokenTypes
{
#line 1 "Shader.g"
#line 18 "ShaderValidator.hpp"
public:
	ShaderValidator();
	static void initializeASTFactory( antlr::ASTFactory& factory );
	int getNumTokens() const
	{
		return ShaderValidator::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return ShaderValidator::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return ShaderValidator::tokenNames;
	}
	public: ProgramPtr  program(antlr::RefAST _t);
	public: DefinitionPtr  definition(antlr::RefAST _t);
	public: ArgumentList  args(antlr::RefAST _t);
	public: SyntaxNodePtr  expr(antlr::RefAST _t);
	public: SyntaxNodeList  values(antlr::RefAST _t);
public:
	antlr::RefAST getAST()
	{
		return returnAST;
	}
	
protected:
	antlr::RefAST returnAST;
	antlr::RefAST _retTree;
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
#endif /*INC_ShaderValidator_hpp_*/

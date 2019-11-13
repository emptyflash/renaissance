#ifndef INC_ShaderLexer_hpp_
#define INC_ShaderLexer_hpp_

#include <antlr/config.hpp>
/* $ANTLR 2.7.5 (20050128): "Shader.g" -> "ShaderLexer.hpp"$ */
#include <antlr/CommonToken.hpp>
#include <antlr/InputBuffer.hpp>
#include <antlr/BitSet.hpp>
#include "ShaderLexerTokenTypes.hpp"
#include <antlr/CharScanner.hpp>
#line 1 "Shader.g"

    #include "Program.h"

#line 16 "ShaderLexer.hpp"
ANTLR_BEGIN_NAMESPACE(ren)
class CUSTOM_API ShaderLexer : public antlr::CharScanner, public ShaderLexerTokenTypes
{
#line 1 "Shader.g"
#line 20 "ShaderLexer.hpp"
private:
	void initLiterals();
public:
	bool getCaseSensitiveLiterals() const
	{
		return true;
	}
public:
	ShaderLexer(std::istream& in);
	ShaderLexer(antlr::InputBuffer& ib);
	ShaderLexer(const antlr::LexerSharedInputState& state);
	antlr::RefToken nextToken();
	public: void mID(bool _createToken);
	public: void mLITERAL(bool _createToken);
	public: void mNEWLINE(bool _createToken);
	public: void mWS(bool _createToken);
	public: void mCOMMENT(bool _createToken);
	public: void mCONCAT(bool _createToken);
	public: void mIS(bool _createToken);
	public: void mOR(bool _createToken);
	public: void mXOR(bool _createToken);
	public: void mAND(bool _createToken);
	public: void mEQ(bool _createToken);
	public: void mNOTEQ(bool _createToken);
	public: void mLESS(bool _createToken);
	public: void mGREATER(bool _createToken);
	public: void mLTE(bool _createToken);
	public: void mGTE(bool _createToken);
	public: void mPLUS(bool _createToken);
	public: void mMINUS(bool _createToken);
	public: void mTIMES(bool _createToken);
	public: void mOVER(bool _createToken);
	public: void mLPAREN(bool _createToken);
	public: void mRPAREN(bool _createToken);
	public: void mDOT(bool _createToken);
private:
	
	static const unsigned long _tokenSet_0_data_[];
	static const antlr::BitSet _tokenSet_0;
};

ANTLR_END_NAMESPACE
#endif /*INC_ShaderLexer_hpp_*/

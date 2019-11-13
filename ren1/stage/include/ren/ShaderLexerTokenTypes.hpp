#ifndef INC_ShaderLexerTokenTypes_hpp_
#define INC_ShaderLexerTokenTypes_hpp_

ANTLR_BEGIN_NAMESPACE(ren)
/* $ANTLR 2.7.5 (20050128): "Shader.g" -> "ShaderLexerTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API ShaderLexerTokenTypes {
#endif
	enum {
		EOF_ = 1,
		APPLY = 4,
		NEGATIVE = 5,
		POSITIVE = 6,
		ATTRIBUTE = 7,
		CONSTANT = 8,
		UNIFORM = 9,
		IF = 10,
		THEN = 11,
		ELSE = 12,
		LET = 13,
		IN = 14,
		ID = 15,
		LITERAL = 16,
		NEWLINE = 17,
		WS = 18,
		COMMENT = 19,
		CONCAT = 20,
		IS = 21,
		OR = 22,
		XOR = 23,
		AND = 24,
		EQ = 25,
		NOTEQ = 26,
		LESS = 27,
		GREATER = 28,
		LTE = 29,
		GTE = 30,
		PLUS = 31,
		MINUS = 32,
		TIMES = 33,
		OVER = 34,
		LPAREN = 35,
		RPAREN = 36,
		DOT = 37,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
ANTLR_END_NAMESPACE
#endif /*INC_ShaderLexerTokenTypes_hpp_*/

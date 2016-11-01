#ifndef TOKENHELPER_H
#define TOKENHELPER_H
#include "includeAll.h"


class TokenHelper
{
	public:
		#define NUMBER_OF_BLOCKS 4
		#define NUMBER_OF_MICRO_OPS 40
		#define NUMBER_OF_REGISTERS 137
		#define NUMBER_OF_MACROS  27
		vector<string> micro_ops;
		vector<string> macro_ops;
		vector<string> registers;
		vector<string> INSTR;


		inline bool IsNumber(const std::string& thisWord);
		inline bool StringEqualCaseIgnore( const std::string& s1, const std::string& s2 );
		inline bool Is_Same_Char(const std::string& thisWord);
		inline int GetReserve(const string& s);
		inline int GetToken(char this_char);
		inline void split(const string& word, char ch, vector<string>& Vec);
};


	
inline bool TokenHelper::IsNumber(const std::string& thisWord)
{
	std::string::const_iterator it = thisWord.begin();
	while (it != thisWord.end() && std::isdigit(*it))
				    	++it;
	return (!thisWord.empty() && it == thisWord.end());
}

			
inline bool TokenHelper::StringEqualCaseIgnore( const std::string& s1, const std::string& s2 ) 
{
	std::string scpy1( s1 );
	std::string scpy2( s2 );
	std::transform( scpy1.begin(), scpy1.end(), scpy1.begin(), ::tolower );
	std::transform( scpy2.begin(), scpy2.end(), scpy2.begin(), ::tolower );
	return ( scpy1 == scpy2 );
}


inline bool TokenHelper::Is_Same_Char(const std::string& thisWord)
{
	return (thisWord.empty() || thisWord.find_first_not_of(thisWord[0]) == std::string::npos);
}

inline int TokenHelper::GetReserve(const string& s)
{
				//auto wordToken = VALUES;
				
			if (StringEqualCaseIgnore( s, "BEGIN"))
				return BEGIN;


			else if (StringEqualCaseIgnore( s, "ARCH"))
					return ARCH;

			else if(StringEqualCaseIgnore(s, "X86_2"))
					return X86_2;

			else if(StringEqualCaseIgnore( s, "micros"))
					return MICROS;

			else if(StringEqualCaseIgnore(s, "macros"))
					return MACROS;

			else if (StringEqualCaseIgnore( s, "registers"))
					return REGISTERS;

				//else if(StringEqualCaseIgnore(s, "operators"))
				//	return OPERATORS;

			else if(StringEqualCaseIgnore(s, "X86_2"))
					return X86_2;

			else if(StringEqualCaseIgnore(s, "X86_3")) 
					return X86_3;

			else if(StringEqualCaseIgnore(s, "ARM"))
					return ARM;

			else if(StringEqualCaseIgnore(s, "MIPS"))
					return MIPS;

			else if( StringEqualCaseIgnore( s, "BLOCK") )
					return RELATIVE;

			else if(StringEqualCaseIgnore( s, "macro") )
					return MACRO;

			else if(StringEqualCaseIgnore( s, "micro"))
					return MICRO;
				

			else if(StringEqualCaseIgnore(s, "END"))
					return END;

			else if(s == "/*")
					return OPEN_COMMENTS;

			else if(s == "\\*")
					return CLOSE_COMMENTS;

			else if(s == "//")
					return INLINE_COMMENTS;

			else if (StringEqualCaseIgnore( s, "BLOCK"))
					return X86_NUMBER; 	

			else if (StringEqualCaseIgnore( s, "BLOCK"))
					return OPERATORS;

			else
					return VALUES;
				
}

inline int TokenHelper::GetToken(char this_char)
{
	char ch = this_char;
	auto char_Token = -1;
	if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123) )
		char_Token = LETTER;

	else if ((ch > 47) && (ch < 58))
		char_Token = DIGIT;

	else if (ch == '-')
		char_Token = DASH;

	else if (ch == '_')
		char_Token = UNDERSCORE;

	else if (ch == '.')
		char_Token = DOT;

	else if (ch == '@')
		char_Token = AT;

	else if (ch == '0')
		char_Token = ZERO;

	else if (ch == ' ')
		char_Token = WHITESPACE;

	else if (ch == '$')
		char_Token = STOP;

	else if (ch == '\n')
		char_Token = NEWLINE;

	else if (ch == ',')
		char_Token = COMMA;

	else if (ch == '*')
		char_Token = ASTERICK;

	else if (ch == ':')
		char_Token = COLON;

	else if (ch == ';')
		char_Token = SEMI_COLON;

	else if (ch == '[')
		char_Token = OPENBRACKETS;

	else if (ch == ']')
		char_Token = CLOSEBRACKETS;

	else if (ch == '#')
		char_Token = HASH_TAG;

	else if (ch == '(')
		char_Token = OPENPAREN;

	else if (ch == ')')
		char_Token = CLOSEPAREN;

	else if (ch == '{')
		char_Token = OPENCURLY;

	else if (ch == '}')
		char_Token = CLOSECURLY;

	else if (ch == '=')
		char_Token = EQUAL;

	else if (ch == '+')
		char_Token = PLUS;

	else if (ch == '-')
		char_Token = MINUS;

	else if (ch == '!')
		char_Token = NOT;

	else if (ch == '\0')
		char_Token = NULL_Token;

	else if (ch == '>')
		char_Token = GREATER_THAN;

	else if(ch == '\t' || ch == '\v')
		char_Token = TAB;

	else if(ch == '%')
		char_Token = PERCENT;

	else if(ch == 44)
		char_Token = SINGLE_QUOTE;

	else if(ch == 34)
		char_Token = DOUBLE_QUOTE;

	else if(ch == 47)
		char_Token = FORWARD_SLASH;

	else if(ch == 92)
		char_Token = BACK_SLASH;

	else if(ch == '<')
		char_Token = LESS_THAN;

	else
		char_Token = UNDEFINED;

	return char_Token;
}

inline void TokenHelper::split(const string& word, char ch, vector<string>& Vec)
{
	size_t i = 0;
	size_t j = word.find(ch);
	while ( j != string::npos)
	{
		Vec.push_back(word.substr(i, j-i));
		i = ++j;
		j = word.find(ch,j);
		if (j == string::npos)	
			Vec.push_back(word.substr(i, word.length()));
		
	} 
}

#endif
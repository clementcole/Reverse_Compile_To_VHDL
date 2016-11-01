#ifndef TRACE_PARSER_H
#define TRACE_PARSER_H

#include "TokenHelper.h"


//Return streamDump
//#include <future>
//#include <chrono>

	//int GetToken(char );
	//bool isNumber(const string&);
	//void Process_Char();
/*
	bool Relative_Read_Flag;
	bool Absolute_Read_Flag;
	bool Macro_Read_Flag;
	bool Micro_Read_Flag;
	bool Dest_Reg_Flag;
	bool SRC1_Reg_Flag;
	bool SRC2_Reg_Flag;
	bool Register_OffSet_Flag;
	bool Open_Bracket_Flag;
	bool Close_Bracket_Flag;
	bool Open_Paren_Flag;
	bool Close_Paren_Flag;
*/
class TraceParser
{
private:
		bool Open_Bracket_Flag;
		bool Close_Bracket_Flag;
		vector<string> thisInstrVec;
		TokenHelper thisHelper;

public:
		inline bool 	Is_Hex_Int(string thisWord);
		inline bool 	Is_Hex_Float(string thisWord);
		inline bool 	Is_ABSOLUTE(string thisWord);
		inline bool 	Is_RELATIVE(string word);
		inline bool 	Is_MACRO(string& word);
		inline bool 	Is_Composite(string& word);
		inline bool 	Is_MICRO(string& word);
		inline bool 	Is_REGISTERS(string& word);
		inline int 		getLexem(string& word);
		inline void 	loadComponents(const string& filename);
		inline void		ParseOne(const string& inputFile, const string& outputFile);
};
inline bool TraceParser::Is_Hex_Int(string thisWord)
{
	return (thisWord.compare(0, 2, "0x") == 0
		    && thisWord.size() > 2 && thisWord.find_first_not_of("0123456789abcdefABCDEF", 2) == string::npos);
}

inline bool TraceParser::Is_Hex_Float(string thisWord)
{
	return ( (thisWord.compare(0, 2, "0x") == 0) && (thisWord.size() > 2 ) && 
	(thisWord.find_first_not_of("0123456789abcdefABCDEF.", 2) == string::npos) &&
			(std::find(thisWord.begin(), thisWord.end(), '.') != thisWord.end()) );
}

inline bool TraceParser::Is_ABSOLUTE(string word)
{
	if (Is_Hex_Float(word) == true)
	{
		//if ( std::find(word.begin(), word.end(), '.') != word.end()  ){
		//	return true;
		//}
		//else 
		return true;
	}
	else return false;
	//std::size_t found = thisWord.find(word);
}
inline bool TraceParser::Is_RELATIVE( string word )
{
	if ( std::find(word.begin(), word.end(), '@') != word.end() )
	{
		return true;
	}
	else return false;
}
			

inline bool TraceParser::Is_MACRO(string& word)
{
	vector<string> macroComponents;
	thisHelper.split(word, '_', macroComponents);
	for(int i=0; i<macroComponents.size(); i++)
	{
		if ( std::find(thisHelper.macro_ops.begin(), thisHelper.macro_ops.end(), macroComponents[i]) != thisHelper.macro_ops.end() )
		{
			return true;
		}
		else	return false;
	}
	return false;
}

inline bool TraceParser::Is_Composite(string& word)
{
	if (!(word.empty()) ){
		for (int i=0; i < word.size(); i++)
		{
			/*if ( (GetToken(word[i]) == OPENBRACKETS)	|| (GetToken(word[i]) == CLOSEBRACKETS)   )
			{
				return true;
			}*/ 
			if ( (std::find(word.begin(), word.end(), ':') != word.end()) || 
					(std::find(word.begin(), word.end(), '+') != word.end()) ||
					(std::find(word.begin(), word.end(), '_') != word.end()) )
			{
				return true;
			}
			else	return false;
		}
					return true;
	}
	else return false;
}


inline bool TraceParser::Is_MICRO(string& word)
{
	if ( std::find(thisHelper.micro_ops.begin(), thisHelper.micro_ops.end(), word) != thisHelper.micro_ops.end() )
	{
		return true;
	}
	else	return false;
}

inline bool TraceParser::Is_REGISTERS(string& word)
{
	if (	( std::find(thisHelper.registers.begin(), thisHelper.registers.end(), word) != thisHelper.registers.end() ) ||  
			( Is_Hex_Int(word)) 
	   )
	{
		return true;
	}
				
	else return false;
}

//Find the lexems if its an absolute address, relative address, micro operator, macro, register or anything else find it
inline int TraceParser::getLexem(string& word)
{
	if ( Is_ABSOLUTE(word))	return ABSOLUTE;
	if (Is_RELATIVE(word))	return RELATIVE;
	if (Is_MACRO(word))	 return MACRO;
	if (Is_MICRO(word))	return MICRO;
	if (Is_REGISTERS(word)) return REGISTERS;
	else return (-1);
}
/*
template<class Container, class Value>
void AppendUnique(Container& C, Value V)
{
	if (find(begin(C),end(C), V) == end(C))
		C.push_back(move(C));
		assert(!C.empty());
}
*/
			
inline void TraceParser::loadComponents(const string& filename)
{
	char ch;
	string fileName;
	string s;
	fstream componentStream(filename);
	bool macros = false;
	bool micros = false;
	bool regs = false;
	bool opencurly = false;
	bool closecurly = false;

	/*Tests Files*/
	//ofstream testMicros("testmicros.txt");
	//ofstream testMacros("testmacros.txt");
	//ofstream testRegs("testRegs.txt");

	while(componentStream.get(ch))
	{
		int nextToken = thisHelper.GetToken(ch);
		int reserved = thisHelper.GetReserve(s);
		if ( (nextToken  == LETTER) || (nextToken == DIGIT)  || 
				(nextToken == PERCENT)  || (nextToken == UNDERSCORE) )	s.push_back(ch);
						
		if( (nextToken == WHITESPACE) || (nextToken == TAB) || (nextToken == NEWLINE) )
		{
			if(micros == true) 
				if (!s.empty())		thisHelper.micro_ops.push_back(s);
			else continue;

			else if(macros == true)
				if(!s.empty())		thisHelper.macro_ops.push_back(s);
			else continue;

			else if(regs == true)
				if (!s.empty())   thisHelper.registers.push_back(s);
			else continue;
					else	s.clear();
					s.clear();
		}

		if( (nextToken == CLOSECURLY) && (micros) )
		{
			micros = false;
			opencurly = false;
			closecurly = false;
		}

		if ( (nextToken == CLOSECURLY) && (macros) )
		{
			macros = false;
			opencurly = false;
			closecurly = false;
		}
		if ( (nextToken == CLOSECURLY) && (regs) )
		{
			regs = false;
			opencurly = false;
			closecurly = false;
		}
		if( (nextToken == COMMA) && (micros == true) )
		{
			if (!s.empty())
			{
				thisHelper.micro_ops.push_back(s);
				s.clear();
			}
			else if(s.empty( )) continue;
		}
						
		if (nextToken == OPENCURLY)	opencurly = true;
		
		if (nextToken == CLOSECURLY)	closecurly = true;
						
						
		switch(reserved)
		{
			case MICROS:
				micros = true;
				s.clear();
				break;

			case MACROS:
				macros = true;
				s.clear();
				break;

			case REGISTERS:
				regs = true;
				s.clear();
				break;

			default:
				break;
		}
						
	}
}

inline void TraceParser::ParseOne(const string& inputFile, const string& outputFile)
{
	//char ch ='\0';
	string word;
	//int colonCounter { 0 };
	int refCounter = 0;
	Open_Bracket_Flag = false;
	Close_Bracket_Flag = false;
	ofstream outDom(outputFile);
	ofstream tempOut("temp_out");
	//char* trace;
	char c;
	int line_number = 0;
	int block_number = 0;
	//int format_done = 0;
	//int trace_size = 0;
	vector<string> InstructionLine;
	InstructionLine.clear();
	outDom<<"!START{\n";
	fstream traceStream(inputFile);   		//Create a input file stream
	while(traceStream.get(c))
	{	
		int thisToken = thisHelper.GetToken(c);
		switch(thisToken)
		{
			case  DASH:
				word.push_back(c);
				break;

			case PERCENT:
				word.push_back(c);
				break;


			case  ASTERICK:	//Likely starting a new block
				word.push_back(c);
				break;


			case  LETTER:	//Atomic word
				word.push_back(c);
				break;

			case  DIGIT:	//Atomic digit
				word.push_back(c);
				break;

			case DOT:  				//Likely Absolute Address
				word.push_back(c);
				break;

			case AT:				//Beginning of Macro
				word.push_back(c);
				break;

			case UNDERSCORE:		//Likely Macro Op
				word.push_back(c);
				break;

			case PLUS:
				word.push_back(c);
				break;

			case COLON:
				InstructionLine.push_back(word);
				word.clear();
				break;

			case OPENBRACKETS:
				InstructionLine.push_back(word);
				word.clear();
				break;

			case CLOSEBRACKETS:
				if(!word.empty())	InstructionLine.push_back(word);
				word.clear();
				break;

			case NULL_Token:	break;

			case COMMA:
				if( !word.empty() )	InstructionLine.push_back(word);
				else if(word.empty())	word.clear();
				word.clear();
				break;

			case  WHITESPACE:		//End of word
				if(	!(word.empty()) )	InstructionLine.push_back(word);
					//word.clear();
					word.clear();
					break;

			case TAB:
				if(	!(word.empty()) )
				{
					InstructionLine.push_back(word);
					word.clear();
				}
				word.clear();
				break;

			case  NEWLINE:			//Starting a new instruction could be newblock main entry of stack processing
				if( !word.empty() )
				{
					InstructionLine.push_back(word);
					InstructionLine.shrink_to_fit();
				}
				for (int i=0; i<InstructionLine.size(); i++)
				{
					if (InstructionLine[i] == "\0")
						InstructionLine.erase(InstructionLine.begin() + i);									
				}

				if( find(word.begin(), word.end(), '*') != (word.end()) )
				{
					block_number++;
					line_number = 0;
					//test <<block_number<<" : "<<line_number<<" := ";
				}
									
				else if(	!(find(word.begin(), word.end(), '*') != (word.end())) && 
								!(find(word.begin(), word.end(), '-') != (word.end()))
								&& ( !(word == "block") || !(word == "count") || !(word == "size") ||
								!(word == "Block") || !(word == "Count") || !(word == "Size") ||
								!(word == "BLOCK") || !(word == "COUNT") || !(word == "SIZE") ) 
					    )
				{
					for (int i=0; i<InstructionLine.size(); i++)
					{
						static int j = 0;
						static int a = 0;
						if ( Is_ABSOLUTE(InstructionLine[i]) )
						{
							outDom<<"      "<<"block : "<<block_number<<"."<<line_number<<"{\n";
							outDom<<"            \t[ ABSOLUTE_Addr : \""<<InstructionLine[i]<<"\" ], ";
							tempOut<<block_number<<" "<<line_number<<" "<<InstructionLine[i]<<" ";
							a = 1;
						}
						if(Is_RELATIVE(InstructionLine[i]) )
						{
							outDom<<"        [ Relative_Addr : \""<<InstructionLine[i]<<"\" ], \n";
							tempOut<<InstructionLine[i]<<" ";
						}
						if( Is_MACRO(InstructionLine[i]) )
						{
							outDom<<"            \t\t[ Macro_OP : \""<<InstructionLine[i]<<"\" ],";
							tempOut<<InstructionLine[i]<<" ";
						}
						if( Is_MICRO(InstructionLine[i]) )
						{
							outDom <<"        [ micro_label : \""<<InstructionLine[i]<<"\", ";
							outDom <<"  micro_node	: \""<<InstructionLine[i]<<"_"<<block_number<<"_"<<line_number<<"\" ],\n"; 
							tempOut<<InstructionLine[i]<<" "; 
							//test <<"  \"reg_"<<j<<"\" : \""<<InstructionLine[i]<<"\" ],\t\t";
						}
						if( Is_REGISTERS(InstructionLine[i]) )
						{
							j++;
							outDom <<"            \t\t\t[ label : \""<<InstructionLine[i]<<"\",";
							outDom <<"  id	: \""<<InstructionLine[i]<<"_"<<line_number<<"_"<<block_number<<"\",";   
							outDom <<"  reg_"<<j<<"\" : \""<<InstructionLine[i]<<"\" ],\n";
							tempOut<<InstructionLine[i]<<" ";
							//string<string> regEdgeLabels;
						}
						if( Is_Hex_Int( InstructionLine[i]) )
						{
							j++;
							outDom <<"            \t\t\t[ label : \""<<InstructionLine[i]<<"\", ";
							outDom <<"  id	: \""<<InstructionLine[i]<<"_"<<line_number<<"_"<<block_number<<"\",";   
							outDom <<"  reg_"<<j<<"\" : \""<<InstructionLine[i]<<"\" ],\n";
							tempOut<<InstructionLine[i]<<" ";
						}
						if( (i == (InstructionLine.size() - 1)) && (a == 1))
						{
							if (j == 0)
							{
								outDom <<"            \t\t\t[ label : \"0\", ";
								outDom <<"  id	: \"0\""<<"_"<<line_number<<"_"<<block_number<<"\",";   
								outDom <<"  reg_1 : \"0\" ],\n";
								tempOut<<"0"<<" ";
								outDom <<"            \t\t\t[ label : \"0\", ";
								outDom <<"  id	: \"0\""<<"_"<<line_number<<"_"<<block_number<<"\",";   
								outDom <<"  reg_2 : \"0\" ],\n";
								tempOut<<"0"<<" ";				
								outDom <<"            \t\t\t[ label : \"0\", ";
								outDom <<"  id	: \"0\""<<"_"<<line_number<<"_"<<block_number<<"\",";   
								outDom <<"  reg_3 : \"0\" ],\n";
								tempOut<<"0"<<" ";
								a = 0;
							}
						else if(j == 1)
						{
							outDom <<"            \t\t\t[ label : \"0\", ";
							outDom <<"  id	: \"0\""<<"_"<<line_number<<"_"<<block_number<<"\",";   
							outDom <<"  reg_2 : \"0\" ],\n";
							tempOut<<"0"<<" ";				
							outDom <<"            \t\t\t[ label : \"0\", ";
							outDom <<"  id	: \"0\""<<"_"<<line_number<<"_"<<block_number<<"\",";   
							outDom <<"  reg_3 : \"0\" ],\n";
							tempOut<<"0"<<" ";
							a = 0;
						}
						else if(j == 2)
						{
							outDom <<"            \t\t\t[ label : \"0\", ";
							outDom <<"  id	: \"0\""<<"_"<<line_number<<"_"<<block_number<<"\",";   
							outDom <<"  reg_3 : \"0\" ],\n";
							tempOut<<"0"<<" ";
							a = 0;
						}
						j = 0;
						outDom<<"      },\n";
						tempOut<<endl;
					}
			}//end of for loop
			//outDom<<"\n},\n";
			line_number++;
			refCounter++;
			//outDom<<"block := "<<line_number<<"line := "<<block_number<<endl;
			}
			InstructionLine.clear();
			word.clear();
			break;

			default:
				break;
  		}//End of switch case
 }//while(inStream.get(c))
	traceStream.close();
	outDom<<"}END!\n";
	outDom.close();
	tempOut.close();
}//End of ParseOne();

/*
void testVec(){
	for (int i =0; i<V.size(); i++){
		cout<<" "<<V[i]<<endl;
	}
}*/
#endif








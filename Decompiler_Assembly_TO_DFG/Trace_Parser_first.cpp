//#include <future>
//#include <chrono>
#include <iostream>	//cout, streambuf
#include <fstream>	//std::ifstream
#include <list>
#include <cstdio>	//EOF detection
#include <string>
#include <regex>
#include <stack>


using namespace std;

class LoadTrace{
	//private:
		#define bool int
		#define true 1
		#define false 0
		#define START_OF_WORD 1
		#define AT_WORD  -1
		#define END_OF_WORD	0
		#define START_OF_INSTRUCTION 1
		#define AT_INSTRUCTION  -1
		#define END_OF_INSTRUCTION 0

		//States for reading a word and instruction
		int WORD_STATE;
		int PREVIOUS_INSTR_STATE;
		int CURRENT_INSTR_STATE;
		int INSTR_STATE;
		int BLOCK_STATE;
		int BLOCK_STATE_TYPE;
		int REG_STATE;
		string current_word;
		string next_word;
		string previous_word;
		vector<string> thislist;
		vector<string> blockCounts;
		vector<string> blockSizes;
		vector<string> blockCycles;
		string line;
		string lexem;
		string word;
		string previous_lexem;
		string current_lexem;
		string TraceFileName;
		char* trace;
		int Previous_Token;
		int Current_Token;
		int Next_Token;
		int Global_Token;
		int Global_State;
		int blocktoken;
		int blockpos;
		int blockState;
		char currentChar;
		char nextChar;
		int currentToken;
		int nextToken;
		char ch;
		int state;
		int trace_size;
		int register_count;
		int flag;
		char* stream_dump;


		bool BlockFlag;
		bool InstructionReadFlag;
		bool Absolute_Read_Flag;
		bool Relative_Read_Flag;
		bool Macro_Read_Flag;
		bool Micro_Read_Flag;
		bool Register_Read_Flag;
		bool Open_Bracket_Flag;
		bool Close_Bracket_Flag;
		bool Open_Paren_Flag;
		bool Close_Paren_Flag;

		ifstream inStream;
		string 	trace_flie_name;

		vector 	 <string> 	block;
		vector   <string> 	lineNum;
		vector   <string> 	absolute;
		vector   <string> 	relative;
		vector   <string> 	macro;
		vector   <string> 	micro;
		vector   <string> 	dest;
		vector   <string> 	src1;
		vector   <string> 	src2;



	public:
		enum Token{
			START,					LETTER,		  			DIGIT, 				UNDERSCORE,
			DOT,					ZERO,					WHITESPACE,			STOP,
			NEWLINE,				COMMA,					ASTERICK,			COLON,
			OPENBRACKETS,			CLOSEBRACKETS,			OPENPAREN,			CLOSEPAREN,
			OPENCURLY,				CLOSECURLY,				ERROR,				UNDEFINED_TOKEN,
			END,					UNDEFINED,				DASH,				AT,
		};

		enum BlockToken{
			BLOCK_START,			BLOCK_HEADER,
			BLOCK_HEADER_BELOW,		BLOCK_END,
		};
		enum BlockBorderType{
			BEGIN_BORDERS,						DASH_BORDERS, 		DASH_ASTERICKS,
			ASTERICK_BORDERS, 	    			ASTERICK_DASH,		DASH_DASH,
			UNKNOWN_BORDERS,					ASTERICK_ASTERICK,	NOT_BORDER,
		};

		enum RegisterState{	DEST, 		SRC1, 			SRC2,	};


		enum BlockState{
			READ_BLOCK_TOP_BORDER,				BLOCK_HEADER_BEGIN,
			BLOCK_COUNT,						BLOCK_COUNT_VALUE,
			BLOCK_SIZE,							BLOCK_SIZE_VALUE,
			BLOCK_CYCLES,						BLOCK_CYCLES_VALUE,
			EOF_BLOCK_HEADER,					READ_INSIDE_BLOCK,
			READ_BLOCK_LOWER_BORDER,			END_OF_BLOCK,
		};

		enum part_of_instruction{
			BEFORE_PARSING,			BEGIN_PARSING,			PARSING_DASHES,
			PARSED_DASHES,			PARSING_BLOCK_INFO,		PARSED_BLOCK_INFO,
			PARSING_ASTERICKS,		PARSED_ASTERICKS,		READ_BLOCK_INFO,
			NOT_STARTED_INSTR,		BEGIN_INSTR,			ABSOLUTE,
			RELATIVE,				MACRO,					MICRO,
			REGISTER,				IMMEDIATE_VALUE,		END_INSTR,
			END_BLOCK,
		};


		//Heavy Duty Functions
		LoadTrace();
		void Process_Char();				  //Main entry to Parse characters and package each line of trace file for further processing
		int  GetToken(char thisChar);		 //Responsible for getting the tokens enumerated types
		void ProcessStack(stack<string>&);	 //Initiater of the Process stack, depending on the type of stack will parse to the right function for further processing.
		void ParseAbsolute(stack<string>&);  //Parse the Absolute Address to the Stack of absolute addresses
		void ParseRelative(stack<string>&);	 //Process the Relative Address
		void ParseMacro(stack<string>&);	 //Process the Macro Operation
		void ParseMicro(stack<string>&);	 //Process the Micro Operation
		void ParseRegisters(stack<string>&); //Might get called several times based on the type of micro


		//Optional Methods Might Include Later after Revision
		void FormWord(char thisChar);
		void Process_Word();
		void Process_Block();
		bool Is_Inside_Block_Head();
		void Set_Instr_State(string thisString);
		void Process_Instruction();
		void Set_Border_Type();
		void Set_Block_Head_States();
		bool IsNumber(const std::string& thisWord);
		void Print_Formatted();
		void Lexem();
		string TranslateToken(int tokenNum);
		bool IsAbsoluteAddress();
		bool IsRelativeAddress();
		bool IsMacro();
		bool IsRegister();
		bool IsFlag();
		bool IsOffSet();

		//Here

		//Petty Helper Functions
		void flushlist();
		int  SetLexem();
		bool Is_Hex(string thistWord);
		bool Is_Same_Char(const std::string& s);
		void GetLexem();
		void LoadLexem();
};

//Initialize
LoadTrace::LoadTrace(){
		line = "";
		lexem = "";
		word = "";
		Global_Token = -1;
		currentChar = (char) 0;
		nextChar = (char) 0;
		currentToken = UNDEFINED;
		state = 0;
		flag = -1;
		blocktoken = 0;
		blockState = 0;
		WORD_STATE = START_OF_WORD;
		INSTR_STATE = NOT_STARTED_INSTR;
		//trace_file_name = infile;
		BlockFlag = false;
		InstructionReadFlag = false;
		Absolute_Read_Flag = false;
		Relative_Read_Flag = false;
		Macro_Read_Flag = false;
		Micro_Read_Flag = false;
		Register_Read_Flag = false;
		Open_Bracket_Flag = false;
}


//Return streamDump
void LoadTrace::Process_Char(){
	char ch = '\0';
	string thisWord;
	int colonCounter = 0;
	stack<string> CurrentTrace;
	fstream inStream("Shashank25_output");   		//Create a input file stream
	if(inStream){										//
		std::streambuf* trace_buffer = inStream.rdbuf();		//Declare a stream and read buffer
		std::streamsize size = trace_buffer->pubseekoff(0, inStream.end);
		trace_buffer->pubseekoff(0, inStream.beg);
		trace = new char[size];
		trace_size = size;
		trace_buffer->sgetn(trace, size);
		inStream.close();
	}


	for (int i=0; i<trace_size; i++){
		int thisToken = GetToken(trace[i]);
		switch(thisToken){
				case  DASH:
					word.push_back(trace[i]);
					break;

				case  ASTERICK:	//Likely starting a new block
					word.push_back(trace[i]]);
					break;


				case  LETTER:	//Atomic word
					word.push_back(trace[i]);
					break;

				case  DIGIT:	//Atomic digit
					word.push_back(trace[i]);
					break;

				case DOT:  				//Likely Absolute Address
					word.push_back(trace[i]);
					break;

				case AT:				//Beginning of Macro
					word.push_back(trace[i]);
					Relative_Read_Flag = true;  //Raise the relative address flag
					break;

				case UNDERSCORE:		//Likely Macro Op
					word.push_back(trace[i]);
					break;

				case COLON:
					word.clear();
					colonCounter++;				//Count colons
					break;

				case OPENBRACKETS:
					cout<<word<<" "<<endl;
					Open_Bracket_Flag = true;		//Raise Open bracket flag
					word.clear();
					break;

				case CLOSEBRACKETS:
					cout<<word<<" "<<endl;
					Close_Bracket_Flag = true;
					word.clear();
					break;

				case OPENPAREN:
					cout<<word<<" "<<endl;
					Open_Paren_Flag = true;			//Raise open parenthesis flag just in case
					word.clear();
					break;

				case CLOSEPAREN:
					cout<<word<<" "<<endl;
					Close_Paren_Flag = true;		//Raise close parenthesis flag just in case
					word.clear();
					break;

				case  WHITESPACE:		//End of word
					if ( (colonCounter == 0) && (Is_Hex(word)) && !(Is_Same_Char(word)) ){ //Dealing with Absolute address
						Absolute_Read_Flag = true;
					}
					CurrentTrace.push(word);
					cout<<word<<" "<<endl;
					word.clear();
					break;


				case  NEWLINE:			//Starting a new instruction could be newblock main entry of stack processing
					CurrentTrace.push(word);
					cout<<word<<" "<<endl;
					word.clear();
					break;

				case COMMA:
					CurrentTrace.push_back(word);
					cout<<word<<" "<<endl;
					word.clear();
					break;
		}
	}
}
//string LoadTrace::ParseAbsolute(const stack<string>& thisline){

//}
/*string LoadTrace::ParseRelative(const vector<string>& line){}
string LoadTrace::ParseRegister(const vector<string>& line){}
int LoadTrace::EvaluateBrackets(std::string code, int pos, int dir){
	bool jumpTargetFound = false;
	int bracketCounter = 0;
	while (!jumpTargetFound){
		if(pos >= code.length() || pos < 0) {
			std::cout<< "Error: [without]." <<std::endl;
			return -1;
		}
		pos += dir;
		if(code[pos] == ']') bracketCounter--;
		else if(code[pos] == '[') bracketCounter++;
		if(bracketCounter == dir*-1) jumpTargetFound = true;
	}
	return pos;
}
string LoadTrace::ParseMicro(const vector<string>& line){}
string LoadTrace::ParseBlockCount(const vector<string>& line){}
string LoadTrace::ParseBlockSize(const vector<string>& line){}
string LoadTrace::ParseBlockCycles(const vector<string>& line){}
string LoadTrace::SetFlags(const vector<string>& line){}
//string LoadTrace::ResetTokenCounters(int colonCounter, int commaCounter, )
*/
void LoadTrace::FormWord(char this_char){

	//currentToken = GetToken(this_char);	//Global variable currentToken is assigned here
	//if (BLOCK_STATE == READ_INSIDE_BLOCK){
		if( (currentToken !=  WHITESPACE  || currentToken != NEWLINE) ){		//If char not whitespace and Out of Block header
			word.push_back(this_char);			//Append char to word as long as char is not a whitespace
			WORD_STATE = AT_WORD;				//At word state

		}

		else if(currentToken == WHITESPACE){		//If character is whitespace
			WORD_STATE = END_OF_WORD;				//End of word set the state of word to end of word/
			cout<<word<<endl;
			Process_Word();							//Process the word to get its lexem
			//ResetWordState();						//Set word state to beginning to indicate start of new word
		}

		else if(currentToken == NEWLINE){			//if Newline
			WORD_STATE = END_OF_WORD;
			Process_Word();
			//ResetWordState();
		}
		else if(currentToken == COMMA){
			WORD_STATE = END_OF_WORD;
			//ResetWordState();
		}

}


bool LoadTrace::Is_Same_Char(const std::string& thisWord){
    return (thisWord.empty() || thisWord.find_first_not_of(thisWord[0]) == std::string::npos);
}
void LoadTrace::Set_Instr_State(string thisString){

	if ((currentToken == WHITESPACE  || currentToken == NEWLINE) && BLOCK_STATE == READ_INSIDE_BLOCK  &&  INSTR_STATE == BEGIN_INSTR){
		INSTR_STATE = ABSOLUTE;
	}
	else if(currentToken == WHITESPACE && BLOCK_STATE == READ_INSIDE_BLOCK &&  INSTR_STATE == ABSOLUTE){
		INSTR_STATE = RELATIVE;
	}
	else if(currentToken == WHITESPACE && BLOCK_STATE == READ_INSIDE_BLOCK && INSTR_STATE == RELATIVE){
		INSTR_STATE = MACRO;
	}

	else if(currentToken == WHITESPACE && BLOCK_STATE == READ_INSIDE_BLOCK && INSTR_STATE == MACRO){
		INSTR_STATE = MICRO;
		register_count = 0;
	}

	else if(currentToken == WHITESPACE && BLOCK_STATE == READ_INSIDE_BLOCK && INSTR_STATE == MICRO){
		INSTR_STATE = REGISTER;
		REG_STATE = DEST;
		register_count = 1;
	}
	else if(currentToken == WHITESPACE && BLOCK_STATE == READ_INSIDE_BLOCK && INSTR_STATE == REGISTER){
		INSTR_STATE = REGISTER;
		REG_STATE = SRC1;
		register_count = 2;
	}
	else if((currentToken == WHITESPACE || currentToken == NEWLINE )&& BLOCK_STATE == READ_INSIDE_BLOCK && INSTR_STATE == REGISTER){
		INSTR_STATE = BEGIN_INSTR;
		REG_STATE = SRC2;
	}

}


void LoadTrace::Process_Instruction(){
	Set_Instr_State(word);
	switch(INSTR_STATE){
		case ABSOLUTE:
			absolute.push_back(word);
			break;

		case RELATIVE:
			relative.push_back(word);
			break;

		case MACRO:
			macro.push_back(word);
			break;

		case MICRO:
			micro.push_back(word);
			break;

		case REGISTER:
			if (REG_STATE == DEST){
				dest.push_back(word);
			}
			else if(REG_STATE == SRC1){
				src1.push_back(word);
			}
			else if(REG_STATE == SRC2){
				src2.push_back(word);
			}
			break;

		//case default:
		//	break;
	}
}

bool LoadTrace::Is_Hex(string thisWord){
	return thisWord.compare(0, 2, "0x") == 0
        && thisWord.size() > 2
        && thisWord.find_first_not_of("0123456789abcdefABCDEF", 2) == string::npos;
}
void LoadTrace::Print_Formatted(){
	for (int i = 0; i<absolute.size(); i++){
		cout<<absolute[i] <<endl;

	}
	cout<<"something"<<endl;
}
void LoadTrace::Process_Word(){
	if (WORD_STATE == END_OF_WORD){ //After getting word, what word is it?
		if (Is_Same_Char(word)){
			Set_Border_Type();   //Saturday July 16th
		}
		else if(!(Is_Same_Char(word))) {
			Process_Instruction();
		}

	}
	WORD_STATE = START_OF_WORD;
	word.clear();
}

//void LoadTrace::Process_Block(){

//}
bool LoadTrace::IsNumber(const std::string& thisWord){
    std::string::const_iterator it = thisWord.begin();
    while (it != thisWord.end() && std::isdigit(*it))
    		++it;

    return (!thisWord.empty() && it == thisWord.end());

}
void LoadTrace::Set_Block_Head_States(){
	if (BLOCK_STATE_TYPE == DASH_BORDERS){
			if ( ((word.find("Block") != string::npos) || (word.find("block") != string::npos)) ) { //If word is Block
				BLOCK_STATE = BLOCK_HEADER_BEGIN;
			}

		   if( (word.find("count") != string::npos  || word.find("Count") != string::npos)  && 	(BLOCK_STATE == BLOCK_HEADER_BEGIN) ){
				BLOCK_STATE = BLOCK_COUNT;

			}
		   else if ((IsNumber(word)) && (BLOCK_STATE == BLOCK_COUNT)){
		   		blockCounts.push_back(word);
				BLOCK_STATE = BLOCK_COUNT_VALUE;

			}


			else if ( ((word.find("size") != string::npos) || (word.find("Size") != string::npos)) && ( BLOCK_STATE == BLOCK_COUNT_VALUE )) { //If word is Block
				BLOCK_STATE = BLOCK_SIZE;

			}
			else if((IsNumber(word)) && (BLOCK_STATE == BLOCK_SIZE)){
				blockSizes.push_back(word);
				BLOCK_STATE = BLOCK_SIZE_VALUE;

			}

			else if( ((word.find("cycles") != string::npos)  || (word.find("Cycles") != string::npos) ) && (BLOCK_STATE == BLOCK_SIZE_VALUE) ){
				BLOCK_STATE = BLOCK_CYCLES_VALUE;
			}


			else if (BLOCK_STATE == BLOCK_CYCLES_VALUE){
				blockCycles.push_back(word);
				BLOCK_STATE = READ_INSIDE_BLOCK;
			}
	}
	if (BLOCK_STATE_TYPE == ASTERICK_BORDERS){
		BLOCK_STATE = READ_INSIDE_BLOCK;
	}
	INSTR_STATE = NOT_STARTED_INSTR;

	//if(BLOCK_BORDER_TYPE == ASTERICK_BORDERS){
	//		BLOCK_STATE = READ_INSIDE_BLOCK;
	//}

}



//void LoadTrace::setBlockCounter(){
//	blockcounter++;
//}


void LoadTrace::Set_Border_Type(){

		 ///std::size_t found = str.find_first_of("-");
		if (word[0] == '-'){ //All dashes
			if (BLOCK_STATE_TYPE == DASH_BORDERS){
					BLOCK_STATE_TYPE = DASH_DASH;
			}
			else if(BLOCK_STATE_TYPE == ASTERICK_BORDERS){
					BLOCK_STATE_TYPE = DASH_ASTERICKS;
			}
			else{
					BLOCK_STATE_TYPE = DASH_BORDERS;
					//INSTR_STATE = START;
			}
		}
			/*if (BLOCK_STATE_TYPE == DASH_BORDERS){
				if (BLOCK_STATE == BLOCK_HEADER_BEGIN;
					BLOCK_STATE_TYPE = DASH_DASH;
			}
			else if(BLOCK_STATE_TYPE == ASTERICK_BORDERS){
					BLOCK_STATE_TYPE = DASH_ASTERICK;
			}
		}*/
		else if (word[0] == '*'){ //All astericks
			if (BLOCK_STATE_TYPE == DASH_BORDERS){
					BLOCK_STATE_TYPE = DASH_ASTERICKS;
			}
			else if(BLOCK_STATE_TYPE == ASTERICK_BORDERS){
					BLOCK_STATE_TYPE = ASTERICK_ASTERICK;
			}
			else{
					BLOCK_STATE_TYPE = ASTERICK_BORDERS;
					INSTR_STATE = BEGIN_INSTR;
			}
		}
}


//GetLexem = function to get the Lexem word;
//void LoadTrace::GetLexem(){
//word.clear();
//}

/*
void LoadTrace::ConvertHex(string hexString){

}
*/

//Takes a character and returns its char Type
int LoadTrace::GetToken(char this_char){
	char ch = this_char;
    int char_Token = -1;
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

    else if (ch == '[')
    	char_Token = OPENBRACKETS;

    else if (ch == ']')
    	char_Token = CLOSEBRACKETS;

    else if (ch == '(')
    	char_Token = OPENPAREN;

    else if (ch == ')')
    	char_Token = CLOSEPAREN;

    else if (ch == '{')
    	char_Token = OPENBRACKETS;

    else if (ch == '}')
    	char_Token = CLOSECURLY;

    else
    	char_Token = UNDEFINED;

    return char_Token;
}

string LoadTrace::TranslateToken(int tokenNum){
	cout<<"Do Nothing"<<endl;
	return "NOTHING";
}

void LoadTrace::flushlist(){
	thislist.clear();
}





//bool LoadTrace::Word_Contains(){

//}










int main(){
	LoadTrace thisLoad;
	//thisLoad.LoadTrace();
	thisLoad.Process_Char();
	thisLoad.Print_Formatted();

	return 0;
}
//http://www.cplusplus.com/reference/streambuf/streambuf/sgetn/
//http://www.drdobbs.com/cpp/state-machine-design-in-c/184401236?pgno=3
//MacBookPro9,2
/*
	1. Load Trace_file dump
	2. Turn into one letter at a time
	3. Turn Stream into buffer
	4.
*/
//256 AES data encription
//Yeah so I wish Elliot's dad would come back cause nothing is normal without him.

/*
// pointer to classes example
#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle(int x, int y) : width(x), height(y) {}
  int area(void) { return width * height; }
};


int main() {
  Rectangle obj (3, 4);
  Rectangle * foo, * bar, * baz;
  foo = &obj;
  bar = new Rectangle (5, 6);
  baz = new Rectangle[2] { {2,5}, {3,6} };
  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';
  delete bar;
  delete[] baz;
  return 0;
}


std::string str ("Please, replace the vowels in this sentence by asterisks.");
  std::size_t found = str.find_first_of("aeiou");
  while (found!=std::string::npos)
  {
    str[found]='*';
    found=str.find_first_of("aeiou",found+1);
  }

  std::cout << str << '\n';
*/

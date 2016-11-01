#include "include_all.h"



//int returnValue(const string& value){
//	if 
//}
int returnKey(const string& key){
	if (key == "block"){return 1;}
	if (key == "ABSOLUTE_Addr"){return 2;}
	if (key == "Relative_Addr"){return 3;}
	if (key == "Macro_OP"){return 4;}
	if (key == "micro_label"){return 5;}
	if (key == "micro_node"){return 6;}
	if (key == "label"){return 7;}
	if (key == "reg_1"){return 8;}
	if (key == "reg_2"){return 9;}
	if (key == "reg_3"){return 10;}
	else return -1;
}

int main(){
	std::ifstream is("test.dom");
	std::string bufferstream;
	std::string currentSubstring;
	int colon = false;
	int key = -1;
	static int i = 0;
	if (is){
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg (0, is.beg);
	 
		char * buffer = new char[length];
	
		is.read(buffer, length);

		is.close();

		//test print
		//std::cout.write(buffer,length);
		for(int i=0; i<length; i++){
			bufferstream.push_back(buffer[i]);
		}
		//cout<<buffer[0]<<endl;
		//delete[] buffer;
	}
	while(i < bufferstream.size() ){
		//cout<<bufferstream[i];
		/*while( (bufferstream[i] != '!') ||  (bufferstream[i] != '{')   ||   (bufferstream[i] !=  '}') ||  
			   (bufferstream != '[')    ||  (bufferstream[i] != ']')   ||   (bufferstream[i] != ' ')  ||
			   (bufferstream != '\t')   ||  (bufferstream[i] != '\n')  ||   (bufferstream[i] != '\v') ||
			   (bufferstream != '\f')   ||  (bufferstream[i] != '\r')
			 ){
		*/		
		while( ( bufferstream[i] != '\t') || ( bufferstream[i] != '\v') || (bufferstream[i] !=  ' ') ){
			if(   (GetToken(bufferstream[i] == LETTER) 			|| (GetToken(bufferstream[i] == DIGIT) || 
				  (GetToken(bufferstream[i] == UNDERSCORE)		|| (GetToken(bufferstream[i] == DIGIT) ||
				  (bufferstream[i] == '+')	|| (GetToken(bufferstream[i] == DIGIT)  
			){
				  currentSubstring.push_back(bufferstream[i]);
				  key = returnKey(bufferstream);
				  if( (key == 1) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 2) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 3) && (colon == true) ){
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				   }
				  if( (key == 4) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 5) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 6) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 7) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 8) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 9) && (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }
				  if( (key == 10)&& (colon == true) ){ 
				  		cout << currentSubstring <<endl;
				  		currentString.clear();
				  }

			}

			i++;
		}//while( i < bufferstream.size())
	}//while( i < bufferstream.size() )
	return 0;
}

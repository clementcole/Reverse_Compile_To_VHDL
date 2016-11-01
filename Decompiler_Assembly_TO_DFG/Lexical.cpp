#include "X86_Lexical.h"

X86_lexem::X86_lexem(string in) : input(in), charClass(ERROR), nextChar(' '), lexeme(""){
    getChar();
}
X86_lexem::~X86_lexem(){
    
}
void X86_lexem::setNewInput(string in){
    input=in;
    getChar();
}

void X86_lexem::getChar(){
    if(input.size() > 0){
        nextChar = input[0];
        input.erase(0, 1);
    }
    else nextChar = '$';
    charClass = ERROR;
    
    if ((nextChar > 64 && nextChar < 91) || (nextChar > 96 && nextChar < 123) )
        charClass = LETTER;
    
    if (nextChar > 47 && nextChar < 58)
        charClass = DIGIT;
    if (nextChar == '_') charClass = UNDERSCORE;
    if (nextChar == '.') charClass = DOT;
    if (nextChar == '0') charClass = ZERO;
    if (nextChar == ' ') charClass = SPACE;
    if (nextChar == '$') charClass = STOP;
    if (nextChar == '+') charClass = PLUS_CODE;
    //if (nextChar == ',') charClass = COMMA;
}

void X86_lexem::addChar(){
    lexeme+=nextChar;
}
int X86_lexem::lex(){
    lexeme="";
    while(charClass == SPACE) 
        getChar();
    
    if(charClass == ERROR) 
    {   addChar(); 
        getChar(); 
        return ERROR;
    }   
    
    if(charClass == STOP) 
    {
        return STOP;}
    
    switch (charClass){
        case LETTER:
            addChar();
            getChar();
            while(charClass == LETTER || charClass == DIGIT){
                addChar();
                getChar();
            }
            return IDENT;
            break;
        
        case UNDERSCORE:
            addChar();
            getChar();
            while(charClass == LETTER || charClass == DIGIT){
                addChar();
                getChar();
            }
            return UNDERSCORE;
            break;
            
        case ZERO:
            addChar();
            getChar();
            while(charClass == LETTER || charClass == DIGIT || charClass == DOT){
                addChar();
                getChar();
            }
            return IDENT;
            break;
            
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT ){
                addChar();
                getChar();
            }
            return INT_LIT;
            break;
            
        case PLUS_CODE:
            addChar();
            getChar();
            return PLUS_CODE;
            break;
        default:
            return ERROR;
    }
    
}

string X86_lexem::convertTokens(int t){
    switch (t){
        case SPACE: 
                    return "spaces";
                    break;
        case LETTER: 
                    return "letters";
                    break;
        case DIGIT: 
                    return "Digits";
                    break;
        case COMMA: 
                    return "Comma";
                    break;
        case OPCODE: 
                    return "OpCode";
                    break;
        case REGISTER: 
                    return "register";
                    break;
        case IMMEDIATE: 
                    return "immediate value";
                    break;
        case IDENT: 
                    return "Variable";
                    break;
        case INT_LIT: 
                    return "integer literal";
                    break;
        case ERROR: 
                    return "ERROR";
                    break;
        case STOP: 
                    return "STOP";
                    break;
        case PLUS_CODE: 
                    return "PLUS_CODE";
                    break;
        case UNDERSCORE: 
                    return "Underscore";
                    break;
        default: 
                    return "UNKNOWN";
                    break;
    }
}
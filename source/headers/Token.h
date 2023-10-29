#include "./IO.h"
#include "list"

#ifndef SLANG_TOKEN_H
#define SLANG_TOKEN_H

char *keywords[] = {"int", "float", "double", "char", "bool", "byte", "struct", "class", "void", "auto", "union", "new", "register", "interface", "enum", "template", 
                "for", "while", "if", "else", "case", "default", "goto", "try", "catch", "switch", "break", "continue", 
                "private", "public", "protected", "friend", "const", "inline", "static", "long", "short", "signed", "unsigned", 
                "false", "true", 
                "return", "delete", "throw", "sizeof", "operater", 
                "asm"};

char *symbols[] = {"+", "-", "*", "/", "++", "--", "=", "{", "}", "(", ")", "[", "]", "\\", "/", "<", ">",
";", "'", "\"", "|", "&", "^", "%", "$", "#", "@", "!", "~", "+=", "-=", "*=", "/="};

struct term{
    std::string name;
    int type;
};

class Token_Stream{
private:
    std::list<term> stream;
    std::list<term>::iterator it;
public:
    Token_Stream(){
        it = stream.begin();
    }
    void add(term trm){
        stream.push_back(trm);
    }
    term get(){
        return *it;
    }
    void ita(){
        if(it != stream.end())
            it++;
    }
    void itm(){
        if(it != stream.begin())
            it--;
    }
};

Token_Stream analyze(Character_Stream chars){
    
}

#endif
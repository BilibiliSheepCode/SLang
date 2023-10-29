#include <string>
#include <cstdio>

#ifndef SLANG_TOKEN_H
#define SLANG_IO_H

class Character_Stream{
private:
    std::string String;
    std::string::iterator it;
public:
    Character_Stream(std::string str){
        String = str;
        it = str.begin();
    }
    Character_Stream(char ch){
        String = std::string(1, ch);
        it = String.begin();
    }
    Character_Stream(){
        String = std::string();
        it = String.begin();
    }
    char now(){
        return *it;
    }
    char vnext(){
        if(it != String.end())
            return *(it + 1);
        else
            return -1;
    }
    char vprev(){
        if(it != String.begin())
            return *(it - 1);
        else
            return -1;
    }
    char next(){
        if(it != String.end()){
            it += 1;
            return *it;
        }
        else
            return -1;
    }
    char prev(){
        if(it != String.begin()){
            it -= 1;
            return *it;
        }
        else
            return -1;
    }
    void ita(){
        if(it != String.end())
            it += 1;
    }
    void itm(){
        if(it != String.begin())
            it -= 1;
    }
    int update(std::string str){
        if(it == String.end()){
            String = str;
            it = str.begin();
            return 0;
        }
        return -1;
    }
    void addChar(char ch){
        String += ch;
    }
    void print(){
        for(char c : String){
            putchar(c);
        }
    }
};

Character_Stream readline(){
    char ch;
    ch = getchar();
    if(ch == EOF || ch == '\n'){
        return Character_Stream();
    }
    Character_Stream cs;
    while(ch != EOF && ch != '\n'){
        cs.addChar(ch);
        ch = getchar();
    }
    return cs;
}
#endif
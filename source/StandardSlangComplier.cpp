#include<cstdio>
#include<cstdlib>
#include"headers/IO.h"
int test(){
    printf("\n----------------test-part-----------------\n");
    Character_Stream stream = readline();
    stream.print();
    return 0;
}

int main(){
    test();
    return 0;
}
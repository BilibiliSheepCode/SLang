#include"./headers/AST.h"
#include"./headers/Tree.h"
int main(int argc,char *argv[]){
    BinaryTree<int> *test = new BinaryTree<int>;
    test->setValue(1290);
    printf("%d",test->getValue());
    return 0;
}
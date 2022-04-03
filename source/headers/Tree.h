#ifndef _TREE_H_
#define _TREE_H_
template<class TreeType>
class BinaryTree{
    private:
    BinaryTree *left = nullptr,*right = nullptr;
    TreeType data;
    public:
    BinaryTree(){}
    ~BinaryTree(){}
    int addMember(BinaryTree *addition){
        BinaryTree *temp;
        temp = *this;
        if(temp->left == nullptr){
            temp->left = addition;
        }else if(temp->right == nullptr){
            temp->right = addition;
        }else{
            while(temp->left != nullptr && temp->right != nullptr){
                temp = temp->left;
            }
            if(temp->left == nullptr){
                temp->left = addition;
            }else if(temp->right == nullptr){
                temp->right = addition;
            }
            if(temp->left == nullptr && temp->right == nullptr){
                return 1;
            }
        }
        return 0;
    }
    void setValue(TreeType value){
        data = value;
        return;
    }
    TreeType getValue(void){
        return data;
    }
};
#endif
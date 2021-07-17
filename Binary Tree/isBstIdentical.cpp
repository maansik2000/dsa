#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int data){
        this -> data = data;
        left = right = NULL;
    }
};

bool isIdentical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    else if(root1 == NULL || root2 == NULL){
        return false;
    }

    else {
        bool cond1 = root1 -> data == root2 -> data; 
        bool cond2 = isIdentical(root1 ->left, root2 -> left);
        bool cond3 = isIdentical(root1 -> right, root2 -> right);

        if(cond1 && cond2 && cond3){
            return true;
        }else{
            return false;
        }
    }
}


int main() 
{ 
    node* root = new node(12); 
    root->left = new node(9); 
    root->right = new node(15); 
    root->left->left = new node(5); 
    root->right->right = new node(10);  

    node* root1 = new node(5); 
    root->left = new node(9); 
    root->right = new node(15); 
    root->left->left = new node(56); 
    root->right->right = new node(10);

    if(isIdentical(root, root1)){
        cout<<"they are identical"<<endl;
    }else{
        cout<<"they are not identical"<<endl;
    }
    
    return 0; 
} 

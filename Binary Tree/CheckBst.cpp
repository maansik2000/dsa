#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBst(node* root, node* min, node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root -> data <= min->data){
        return false;
    }

    if(max != NULL && root -> data >= max -> data){
        return false;
    }

    bool leftValid = isBst(root ->left , min, root);
    bool rightValid = isBst(root ->right, root,max);

    return leftValid and rightValid;
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root -> left);
    cout<<root -> data<<" " ;
    inorder(root -> right);
}

int main(){
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root -> left -> left = new node(1);
    root -> left -> right = new node(3);
    root -> right -> right = new node(6);
    inorder(root);

    if(isBst(root, NULL, NULL)){
        cout<<"yes it is bst";
    }else{
        cout<<"it is not";
    }
    return 0;
}
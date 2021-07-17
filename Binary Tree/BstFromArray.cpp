#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

node* insertBST(node* root, int x){

    if(root == NULL){
        return new node(x);
    }

    if(x < root ->data){
        root -> left = insertBST(root -> left, x);
    }else{
        root -> right = insertBST(root -> right, x);
    }

    return root;
}

void inorderPrint(node* root){
    if(root == NULL){
        return;
    }

    inorderPrint(root -> left);
    cout<<root -> data<<" ";
    inorderPrint(root -> right);
}

int main(){
    node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root,1);
    insertBST(root,2);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,8);
    insertBST(root,6);
    insertBST(root,7);
    inorderPrint(root);
    //print inorder


    return 0;
}
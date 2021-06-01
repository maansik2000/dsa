#include<iostream>
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

/* Given a binary tree, print its nodes in inorder*/

void printInorder(node* root){
    if(root == NULL){
        return ;
    }

    printInorder(root -> left);
    cout<<root -> data<<" ";
    printInorder(root -> right);
}


void printPreorder(node* root){
    if(root == NULL){
        return ;
    }

    cout<<root -> data<<" ";
    printPreorder(root -> left);
    printPreorder(root -> right);
}

void printPostorder(node* root){
    if(root == NULL){
        return ;
    }

    printPostorder(root -> left);
    printPostorder(root -> right);
    cout<<root -> data;
}
int main() 
{ 
    node* root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 
  
    return 0; 
} 
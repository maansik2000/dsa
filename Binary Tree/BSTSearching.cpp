//searching in binary tree
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;
    node(int data){
        this ->data = data;
        left = right = NULL;
    }
};

//searching
node* searchInBst(node* root, int key){

    if(root == NULL){
        return NULL;
    }

    if(root -> data == key){
        return root;
    }

    if(root -> data > key){
        return searchInBst(root -> left, key);
    }

    return searchInBst( root -> right, key);
}


int main()
{   
    node* root = new node(12);
    root->left = new node(1);
    root->left->left = new node(3);
    root->left->left->left = new node(7);
    root->left->right = new node(4);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    root->right = new node(2);
    root->right->left = new node(5);
    root->right->right = new node(6);

    
 
    int key = 10;

    if(searchInBst(root, key) == NULL){
        cout<<"key doesn't exist"<<endl;
    }else{
        cout<<"key exist in tree"<<endl;
    }

 
    return 0;
}
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

node* inorderSuccessor(node* root){
    node* curr = root;
    while(curr && curr -> left != NULL){
        curr = curr -> left;
    }

    return curr;
}

node* deleteBinaryTree(node* root, int key){
    if(key < root -> data){
        root ->left = deleteBinaryTree(root ->left, key);
    }else if(key > root ->data){
        root -> right = deleteBinaryTree(root ->right, key);
    }else
        {
        if(root -> left == NULL){

            if(root -> left == NULL){
                node* temp = root ->right;
                free(root);
                return temp;
            }
            else if(root -> right == NULL){
                node* temp = root -> left;
                free(root);
                return temp;
            }

            node* temp = inorderSuccessor(root -> right);
            root -> data = temp -> data;
            root -> right = deleteBinaryTree(root -> right, temp-> data);
        }

        
    }
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root -> left);
    cout<<root -> data<<" " ;
    inorder(root -> right);
}


int main()
{   
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root -> left -> left = new node(1);
    root -> left -> right = new node(3);
    root -> right -> right = new node(6);
    inorder(root);
    cout<<"\n------------"<<endl;
    root = deleteBinaryTree(root,4 );
    inorder(root);
    return 0;
}
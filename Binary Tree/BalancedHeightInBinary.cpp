#include<iostream>
#include<queue>
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

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root -> left);
    int rh = height(root -> right);

    return max(lh, rh) + 1;
}

bool isBalaced(node* root, int* height){

    if(root == NULL){
        return true;
    }
    int lheight = 0;
    int rheight = 0;

    if(isBalaced(root -> left, &lheight) == false){
        return false;
    }

    if(isBalaced(root -> right, &rheight) == false){
        return false;
    }


    *height = max(lheight, rheight) + 1;

    if(abs(lheight - rheight) <=1){
        return true;
    }else{
        return false;
    }
}

int main() 
{ 
    node* root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5);  
    root->right->left = new node(6);  
    root->right->right = new node(7);  

    int height = 0;

    if(isBalaced(root, &height) == true){
        cout<<"balanced";
    }

    return 0; 
} 
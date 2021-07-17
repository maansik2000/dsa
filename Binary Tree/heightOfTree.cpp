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

int calHeight(node* root){

    if(root ==NULL){
        return 0;
    }

    int lheight = calHeight(root->left);
    int rheight = calHeight(root -> right);

    return max(lheight, rheight) + 1;
}


int calDiameter(node* root){

    if(root == NULL){
        return 0;
    }

    int lheight = calHeight(root->left);
    int rheight = calHeight(root ->right);

    int currDiameter = lheight + rheight + 1;

    int lDiameter = calDiameter(root -> left);
    int rDiameter = calDiameter(root -> right);

    return max(currDiameter, max(lDiameter, rDiameter));
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

    cout<<calDiameter(root);
    return 0; 
} 
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

int maxPathSumUtil(node* root, int &ans){
    if(root == NULL){
        return 0;
    }

    int left = maxPathSumUtil(root -> left, ans);
    int right = maxPathSumUtil(root -> right,ans);

    int nodemax = max(max(root -> data, root-> data + left + right), 
                        max(root ->data + left, root -> data + right));

    ans = max(ans, nodemax);

    int sindlePathSum = max(root -> data, max(root ->data+left, root -> data + right));

    return sindlePathSum;
}

int maxPathSum(node* root){
    int ans = INT_MIN;

    maxPathSumUtil(root, ans);

    return ans;
}

int main() 
{ 
    node* root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->right->right = new node(5);  
    root->right->left = new node(6);  
    root->right->right = new node(7);  

    cout<<maxPathSum(root);
    
    return 0; 
} 

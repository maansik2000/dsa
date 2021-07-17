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

bool getPath(node *root, int key, vector<int> &path){
    if(root == NULL){
        return false;
    }

    path.push_back(root -> data);

    if(root -> data == key){
        return true;
    }

    if(getPath(root -> left, key, path) || getPath(root -> right, key, path)){
         return true;
    }

    path.pop_back();
    return false;   
}

node* LCA2(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2){
        return root;
    }

    node* leftLca = LCA2(root -> left, n1, n2);
    node* rightLca = LCA2(root-> right, n1, n2);

    if(leftLca != NULL && rightLca != NULL){
        return root;
    }

    if(leftLca != NULL){
        return leftLca;
    }

    return rightLca;
}

int LCA(node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root, n1,path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pc;

    for(pc = 0;pc<path1.size() && path2.size(); pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    return path1[pc-1];
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

    int n1 = 7;
    int n2 = 6;

    cout<<LCA(root, n1, n2);
    node* lca = LCA2(root, n1,n2);
    cout<<lca->data;
    
    return 0; 
} 

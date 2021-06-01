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

//searching in binary tree

bool ifNodeExist(node* root, int key){
    if(root == NULL){
        return false;
    }

    if(root -> data == key){
        return key;
    }

    bool res1 = ifNodeExist(root -> left, key);

    if(res1) return true;

    bool res2 = ifNodeExist(root -> right, key);
    return res2;
}

//searching in bst
node* search(node* root, int key){
    if(root == NULL || root -> data == key){
        return root;
    }

    if(root -> data < key){
        return search(root ->right, key);
    }
    
    return search(root -> left, key);
}


int main()
{
    node* root = new node(0);
    root->left = new node(1);
    root->left->left = new node(3);
    root->left->left->left = new node(7);
    root->left->right = new node(4);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    root->right = new node(2);
    root->right->left = new node(5);
    root->right->right = new node(6);
 
    int key = 4;
 
    if (ifNodeExist(root, key))
        cout << "YES";
    else
        cout << "NO";

    node* result = search(root, key);
    cout<<result<<endl;
 
    return 0;
}
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

/* Given a binary tree, print its nodes in inorder*/

void printInorder(node* root){
    if(root == NULL){
        return ;
    }

    printInorder(root -> left);
    cout<<root -> data<<" ";
    printInorder(root -> right);
}

//preorder
void printPreorder(node* root){
    if(root == NULL){
        return ;
    }

    cout<<root -> data<<" ";
    printPreorder(root -> left);
    printPreorder(root -> right);
}


//postorder
void printPostorder(node* root){
    if(root == NULL){
        return ;
    }

    printPostorder(root -> left);
    printPostorder(root -> right);
    cout<<root -> data;
}

//level order traversal
void printLevelOrder(node* root){
    if(root == NULL){
        return ;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* node = q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node -> left){
            q.push(node -> left);
            }
            if(node -> right){
            q.push(node -> right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
        
    }
}


void printLevelOrder2(node* root){
    if(root == NULL){
        return ;
    }
    
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
    
    cout<<"\nLevel order traversal is \n";
    printLevelOrder(root);
    return 0; 
} 
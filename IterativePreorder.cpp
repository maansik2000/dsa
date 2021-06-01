#include <bits/stdc++.h>
 
using namespace std;

//iterative preorder traversal

class node{
    public:
        int data;
        node* left;
        node* right;
};

node* CreateNode(int data){
    node* newnode = new node();
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return(newnode);
}

void iterativePreorder(node* root){
    if (root == NULL)
        return;

    stack<node*> s;

    s.push(root);
    while(s.empty() == false){
        node* node = s.top();
        cout<<node -> data<<" ";

        s.pop();

        if(node -> right){
            s.push(node -> right);
        }

        if(node -> left){
            s.push(node -> left);-
        }
    }

}

//second approach
void iterative(node* root){
    if(root == NULL){
        return ;
    }

    stack<node *> s;

    node* current = root;
    while(!s.empty() || current != NULL){
        while(current != NULL){
            cout<<current -> data<<" ";

            if(current -> right){
                s.push(current ->right);
            }

            current = current -> left;3
            
        }

        if(s.empty() == false){
            current = s.top();
            s.pop();
        }
    }

}



int main(){
    node* root = CreateNode(10);
    root->left = CreateNode(8);
    root->right = CreateNode(2);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(2);

    iterativePreorder(root);
    iterative(root);
    return 0;
}


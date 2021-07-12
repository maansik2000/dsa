#include<iostream>
#include<stack>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;
};

node* createNode(int data){
    node* newnode = new node();
    newnode -> data = data;
    newnode -> right = NULL;
    newnode -> left = NULL;
    return (newnode);
}

//using two stack
void postOrder(node* root){
    stack<node*> s;
    stack<node*> s2;
    node* curr;
    s.push(root);
    while(!s.empty()){
        curr = s.top();

        s.pop();
        s2.push(curr);

        if(curr -> left){
            s.push(curr -> left);
        }

        if(curr -> right){
            s.push(curr -> right);
        }
        
    }
    while(!s2.empty()){
        curr = s2.top();
        s2.pop();
        cout<<curr -> data<<" ";
    }
    
}

//using one stack
void postOrder_two_stack(node* root){
    stack<node*> s;
    s.push(root);
    node* curr;

    while(s.empty() == false ){
        while(curr -> left != NULL && curr -> right != NULL){
            curr = s.top();

            if(curr -> right){
                s.push(curr -> right);
            }

            if(curr -> left){
                s.push(curr -> left);
            }
        }
        if(!s.empty()){
            curr = s.top();
            s.pop();
        }

    }

}

// Driver code 
int main() 
{ 
    // Let us construct the tree 
    // shown in above figure 
 
    node* root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->left->right = createNode(5); 
    root->right->left = createNode(6); 
    root->right->right = createNode(7); 
  
    postOrder(root); 
    postOrder_two_stack(root);
  
    return 0; 
} 

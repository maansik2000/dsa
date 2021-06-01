/*iterative inorder traversal without recursion*/

#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this -> data = data;
        this -> left = this -> right = NULL;
    }
};


//iterative approach

void inorderIterative(node* root){
    stack<node*> s;

    node* curr = root;

    while(s.empty() == false || curr != NULL){
        while(curr != NULL){
            s.push(curr);
            curr = curr -> left;
        }

        curr = s.top();
        s.pop();
        cout<<curr -> data<<" ";

        curr = curr -> right;
    }
}

int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    node* root = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);    
 
    inorderIterative(root);
    return 0;
}


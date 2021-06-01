#include<iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
};

//function to create a new node
node* createNode(int data){
    node* newnode = new node();

    if(!newnode){
        cout<<"memory error"<<endl;
        return NULL;
    }

    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}

//function to insert element in binary tree

node* Insertnode(node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<node*> q;
    q.push(root);
 
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = createNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = createNode(data);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */
 
void inorder(node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
 

int main(){
    node* root = createNode(10);
    root -> left = createNode(11);
    root -> left -> left = createNode(7);
    root -> right = createNode(9);
    root -> right -> left = createNode(15);
    root -> right -> right = createNode(8);

    cout<<"inorder traversal before insertion";
    inorder(root);
    int key = 12;

    root = Insertnode(root,key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}
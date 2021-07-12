#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has key, pointer to left  
child and a pointer to right child */
class node { 
    public:
    int key; 
    node *left, *right; 
}; 
  
/* function to create a new node of tree and  
return pointer */
node* createNode(int key) 
{ 
    node* temp = new node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
  
/* Inorder traversal of a binary tree*/
void inorder(node* temp) 
{ 
    if (!temp) 
        return; 
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 

//function to delete the given deepest node in binary tree
void deleteDeepest(node* root, node* d_node) 
{ 
    queue<node*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    node* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 

/* function to delete element in binary tree */
node* deletion(node* root, int key) 
{ 
    if (root == NULL) 
        return NULL; 
  
    if (root->left == NULL && root->right == NULL) { 
        if (root->key == key) 
            return NULL; 
        else
            return root; 
    } 
  
    queue<node*> q; 
    q.push(root); 
  
    node* temp; 
    node* key_node = NULL; 
  
    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 

        if (temp->key == key) 
            key_node = temp; 
  
        if (temp->left) 
            q.push(temp->left); 
  
        if (temp->right) 
            q.push(temp->right); 
    } 
  
    if (key_node != NULL) { 
        int x = temp->key; 
        deleteDeepest(root, temp); 
        key_node->key = x; 
    } 
    return root; 
} 
  
// Driver code 
int main() 
{ 
    node* root = createNode(10); 
    root->left = createNode(11); 
    root->left->left = createNode(7); 
    root->left->right = createNode(12); 
    root->right = createNode(9); 
    root->right->left = createNode(15); 
    root->right->right = createNode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
  
    return 0; 
} 
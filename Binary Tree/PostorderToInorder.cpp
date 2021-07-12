#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }

    return -1;
}

node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 4;

    if(start > end){
        return NULL;
    }

    int curr = preorder[idx];
    idx--;

    node* newnode = new node(curr);

    if(start == end){
        return newnode;
    }

    int pos = search(inorder, start, end, curr); 
    newnode -> right = buildTree(preorder, inorder, pos+1, end);
    newnode -> left = buildTree(preorder, inorder, start, pos-1);
    
    return newnode;
}

void printPostorder(node* root){

    if(root == NULL){
        return ;
    }

    printPostorder(root -> left);
    cout<<root ->data<<" ";
    printPostorder(root ->right);
    
}

int main()
{
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4, 2, 1, 5, 3}; 

    //build tree
    node* root = buildTree(postorder, inorder, 0, 4);
    printPostorder(root);

    return 0;
}
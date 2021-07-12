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
    static int idx = 0;

    if(start > end){
        return NULL;
    }

    int curr = preorder[idx];
    idx++;

    node* newnode = new node(curr);

    if(start == end){
        return newnode;
    }

    int pos = search(inorder, start, end, curr); 
    newnode -> left = buildTree(preorder, inorder, start, pos-1);
    newnode -> right = buildTree(preorder, inorder, pos+1, end);
    
    return newnode;
}

void printInorderSeq(node* root){

    if(root == NULL){
        return ;
    }

    printInorderSeq(root -> left);
    cout<<root ->data<<" ";
    printInorderSeq(root ->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3}; 

    //build tree
    node* root = buildTree(preorder, inorder, 0, 4);
    printInorderSeq(root);

    return 0;
}
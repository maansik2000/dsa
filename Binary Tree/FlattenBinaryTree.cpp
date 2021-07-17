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

//case 1
void printSubTreeNodes(node *root, int k){
    if(root == NULL || k < 0){
        return ;
    }

    if(k == 0){
        cout<<root -> data<<" ";
    }

    printSubTreeNodes(root ->left, k-1); 
    printSubTreeNodes(root ->right, k-1); 
}

//case 2
int printNodesAtK(node *root, node *target, int k){

    if(root == NULL){
        return -1;
    }

    if(root == target){
        printSubTreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtK(root -> left, target, k);

    if(dl != -1){
        if(dl + 1 == k){
            cout<<root -> data <<" ";
        }else{
            printSubTreeNodes(root->right, k-dl-2);
        }
        return 1+dl;
    }

    int dr = printNodesAtK(root -> right, target, k);

    if(dr != -1){
        if(dr + 1 == k){
            cout<<root -> data <<" ";
        }else{
            printSubTreeNodes(root->left, k-dr-2);
        }
        return 1+dr;
    }

    return -1;

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

    printNodesAtK(root, root -> left, 1);
 
    return 0; 
} 

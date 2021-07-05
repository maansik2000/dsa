#include<iostream>
using namespace std;

class node{
    public:
    int data;
    class node* left;
    class node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){
    node* root = new node(1);

    root -> left = new node(2);
    root -> right = new node(3);

    root -> left -> right = new node(4);

    //tree representation
    /* 4 becomes left child of 2
               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL
    */

   //types of tree
        /*
        there are five types of tree in data structure

        1.   full binary tree
        2.  complete binary tree
        3.  perfect binary tree
        4.  balanced binary tree
        5.  a degenerate tree
        */
 
    return 0;
}
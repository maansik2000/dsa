#include<iostream>
using namespace std;

class bst{
    public:
    int data;
    bst *left,*right;

    public:

    //default constructor
    bst();

    //parametrized constructor
    bst(int);

    //insert function
    bst * insert(bst*,int);
    
    //inorder traversal
    void inorder(bst*);
};

//default constructor defination

bst::bst()
    : data(0)
    , left(NULL)
    , right(NULL)
{

}

//parametrized constructor definition

bst ::bst(int value){
    data = value;
    left = right = NULL;
}

//insert function

bst* bst::insert(bst* root, int val){
    if(!root){
        return new bst(val);
    }

    //insert data
    if(val > root -> data){
        root -> right = insert(root -> right, val);
    }else{
        root -> left = insert(root -> left, val);
    }

    return root;
}

void bst ::inorder(bst* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}



int main()
{
    bst b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
 
    b.inorder(root);
    return 0;
}
 
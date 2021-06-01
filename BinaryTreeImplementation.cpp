#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node* create(){
        int x;
        node* newnode = new node();
        cout<<"enter the data"<<endl;
        cin>>x;

        if( x == -1){
            return 0;
        }
        newnode -> data = x;
        cout<<"enter the left child of "<<" "<<x<<endl;
        newnode->left = create();
        cout<<"enter the right child of"<<" "<<x<<endl;
        newnode->right = create();
        return newnode;
    }
};

int main(){
    node* root;
    root = NULL;
    root = root->create();

    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void spiralOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    stack<node *> currLevel;
    stack<node *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty())
    {
        node *temp = currLevel.top();

        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";
            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertion(node* &head, int data)
{
    node* newnode = new node(data);

    if (head == NULL)
    {
        head = newnode;
        return ;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void insertionAtHead(node* &head, int data){
    node* newnode = new node(data);
    if(head == NULL){
        head = newnode;
    }

    newnode -> next = head;
    head = newnode;
}

void insertAtBetween(node* &head, int data, int pos){
    node* newnode = new node(data);
    if(head == NULL){
        head = newnode;
    }

    node* temp = head;

    while(temp -> next != NULL and pos > 0 ){
       temp = temp -> next;
       pos--;
    }

    newnode ->next = temp -> next;
    temp ->next = newnode;
}

void deleteAtHead(node* &head){
    node* deleteNode = head;
    head = head -> next;

    delete(deleteNode);
}

void deletion(node* &head, int val){

    if(head == NULL){
        return ;
    }

    if(head -> next == NULL){
        deleteAtHead(head);
    }

    node* temp = head;
    while(temp -> next -> data != val){
        temp = temp -> next;
    }
    node* nodeDelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete(nodeDelete);
}


void display(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    node* head = NULL;
    insertion(head, 8);
    insertion(head, 4);
    insertionAtHead(head, 44);
    insertion(head, 78);
    insertAtBetween(head,745,2);
    display(head);

    return 0;
}
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

void InsertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

//find the middle element in linked list
void printMiddleElement(node *&head)
{
    node *fast = head;
    node *slow = head;

    if (head != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        cout<<"middle element is "<<slow ->data;
    }
}

//reverse a linked list
void reverseLinkedList(node* &head){
    node* current = head;
    node* prev = NULL;
    node* next = NULL;

    while(current != NULL){
        next = current -> next;
        current ->next = prev;
        prev = current;
        current = next;     
    }

    head = prev;
}

//reverse k node in a linked list
node* reverseK(node* &head, int k){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;

    int count = 0;
    while(currPtr!= NULL && count<k){
        nextPtr = currPtr -> next;
        currPtr -> next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }
    if(nextPtr!= NULL){
        head -> next = reverseK(nextPtr,k);
    }
    
    return prevPtr;
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

    node *head = NULL;
    InsertAtTail(head, 8);
    InsertAtTail(head, 4);
    InsertAtTail(head, 44);
    InsertAtTail(head, 23);
    InsertAtTail(head, 56);
    InsertAtTail(head, 784);
    InsertAtTail(head, 12);
    display(head);
    reverseLinkedList(head);
    display(head);
    printMiddleElement(head);

    return 0;
}
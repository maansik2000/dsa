#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};


//insert at tail
void InsertAtTail(node* &head , int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return ;
    }

    node* temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = n;
}

//insert at head
void InsertAtHead(node* &head, int val){
    node* n = new node(val);
    n -> next = head;

    head = n;
}


//searching in linked list
bool search(node* head, int key){
    node* temp = head;
    while(temp !=NULL){
        if(temp -> data == key){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

//delete at head 
void deleteAtHead(node* &head){
    node* deleteNode = head;
    head = head -> next;

    delete(deleteNode);
}

//delete in between
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

//reverse the linked list
node* reverse(node* &head){
    node* prev = NULL;
    node* currPtr = head;
    node* nextPtr;

    while(currPtr!=NULL){
        nextPtr = currPtr -> next;
        currPtr -> next = prev;

        prev = currPtr;
        currPtr = nextPtr;
    }
    return prev;
}


node* reverseRecursive(node* &head){

    if(head== NULL || head -> next == NULL){
        return head;
    }

    node* newHead = reverseRecursive(head -> next);
    head -> next -> next = head;
    head -> next = NULL; 

    return newHead;
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

//make cycle
void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;

    while(temp -> next != NULL){
        if(count == pos){
            startNode = temp;
        }

        temp = temp -> next;
        count++;
    }

    temp -> next = startNode;
}

//detect cycle or Floyd’s Cycle-Finding Algorithm 
bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

//remove cycle
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow -> next;
        fast = fast -> next -> next;
        
    }while(slow != fast);

    fast = head;

    while(slow -> next  != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = NULL;

}

node* merge(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);

    node* p3 = dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data < p2 ->data){
            p3 -> next = p1;
            p1 = p1 -> next;
        }else{
            p3 -> next = p2;
            p2 = p2 -> next;
        }
        p3 = p3 -> next;
    }

    while(p1!=NULL){
        p3 -> next = p1;
        p1 = p1 -> next;
        p3 = p3 -> next;
    }

    while(p2!=NULL){
        p3 -> next = p2;
        p2 = p2 -> next;
        p3 = p3 -> next;
    }

    return dummyNode -> next;
}


void printList(node* head){
    node* temp = head;

    while(temp !=NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    node* head = NULL;
    node* head1 = NULL;

    InsertAtTail(head, 8);
    InsertAtTail(head, 9);
    InsertAtTail(head, 10);
    InsertAtTail(head, 11);
    InsertAtTail(head,12);
    InsertAtTail(head, 13);
    InsertAtTail(head1, 1);
    InsertAtTail(head1, 6);
    InsertAtTail(head1,7);
    
    // makeCycle(head, 3);
    // printList(head);
    // deleteAtHead(head);
    // cout<<search(head,5)<<endl;
    // deletion(head, 3);
    // node* newHead = reverseRecursive(head);
    
    // printList(newHead);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    node* newHead = merge(head, head1);
    printList(newHead);
    return 0;

}
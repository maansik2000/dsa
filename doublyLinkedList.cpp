#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//insert at head
void insertAtHead(node* &head, int val){
    node* newnode = new node(val);
    newnode -> next = head;
    
    if(head !=NULL){
        head -> prev = newnode;
    }

    head = newnode;
}

//insert at tail 
void insertAtTail(node* &head, int val){

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    node* newnode = new node(val);
    node* temp = head;

    while(temp-> next!= NULL){
        temp = temp -> next;
    }

    temp -> next = newnode;
    newnode -> prev = temp;

}

//delete at the head
void deleteAtHead(node* &head){
    node* todelete = head;
    head = head -> next;
    head -> prev = NULL;

    delete todelete;
}

//delete the node 
void deletion(node* &head, int pos){

    if(pos == 1){
        deleteAtHead(head);
        return ;
    }

    node* temp = head;
    int count = 1;
    
    while(temp!=NULL && count!=pos){
        temp = temp -> next;
        count++;
    }

    temp -> prev -> next = temp -> next;

    if(temp -> next !=NULL){
        temp -> next -> prev = temp -> prev;
    }
    

    delete temp;

}


//calculate the length of the linked list
int length(node* head){
    int l = 0;
    node* temp = head;

    while(temp!=NULL){
        l++;
        temp = temp -> next;
    }
    return l;
}


//append number of nodes in front
node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = length(head);

    k = k % l;  //take care of the edge

    int count = 1;

    while(tail -> next !=NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }
    newTail -> next = NULL;
    tail -> next = head;
    return newHead;
}

//intersection of two linked list
int intersection(node* &head1, node* &head2 ){
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;

    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1 -> next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!= NULL && ptr2!=NULL){
        if(ptr1 == ptr2){
            return ptr1 -> data;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    return -1;
}

//print the list
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    node* head = NULL;
    node* head2 = NULL;
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtTail(head,54);
    insertAtTail(head,52);
    insertAtTail(head,51);
    insertAtHead(head2, 1);
    insertAtHead(head2, 2);
    // deleteAtHead(head);
    // node* newnode = kappend(head, 3);
    intersection(head,head2, 3);
    display(head);
    display(head2);
    return 0;
}
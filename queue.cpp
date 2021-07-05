#include<iostream>
#include<stack>
using namespace std;
#define n 100


//queue using array
class queue{
    int* arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x){
        if(back == n-1){
            cout<<"queue overflow"<<endl;
        }

        back++;

        arr[back] = x;

        if(front == -1){
            front++;
        }
    }

    void dequeue(){
        if(front == -1 || front>back){
            cout<<"queue underflow"<<endl;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front> back){
            cout<<"no element in queue"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        else false;
    }
};


//queue using linked list
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};


class queue1{
    node* front;
    node* back;

    public:

    queue1(){
        front = NULL;
        back = NULL;
    }

    void push(int x){
        node* newnode =new node(x);
        if(front == NULL){
            back = newnode;
            front = newnode;
            return ;
        }
        back -> next = newnode;
        back = newnode;
    }

    void pop(){
        if(front == NULL){
            cout<<"queue is empty"<<endl;
            return ;
        }

        node* tdoDelete = front;
        front = front -> next;
        delete tdoDelete;
    }

    int peek(){
        if(front == NULL){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        return front -> data;
    }

    bool empty(){
        if(front == NULL){
            return NULL;
        }

        return false;
    }

};


//queue using stacks
//using 2 stacks and deQueue operations costly
class queue3{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty() and s2.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topLevel = s2.top();
        s2.pop();
        return topLevel;
    }

    bool empty(){
        if(s1.empty() and s2.empty()){
            return true;
        }
        return false;
    }
};

class queue4{
    stack<int> s1;

    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int topElement = s1.top();

        s1.pop();
        if(s1.empty()){
            return topElement;
        }

        int item = pop();
        s1.push(topElement);
        return item;
    }
};

int main(){
    queue que;
    que.enqueue(4);
    que.enqueue(5);
    que.enqueue(6);
    que.enqueue(7);
    que.enqueue(8);
    que.enqueue(9);
    cout<<que.peek()<<endl;
    que.dequeue();
    cout<<que.peek()<<endl;


    queue1 qu1;
    qu1.push(54);
    qu1.push(554);
    qu1.push(85);
    qu1.push(65);
    qu1.push(555);
    qu1.push(58);
    qu1.push(25);
    cout<<qu1.peek()<<endl;
    qu1.pop();
    cout<<qu1.peek()<<endl;
    qu1.pop();
    cout<<qu1.peek()<<endl;
    cout<<qu1.empty()<<endl;


    queue3 que1;
    que1.push(2);
    que1.push(5);
    que1.push(8);
    que1.push(12);
    que1.push(78);
    que1.push(44);
    que1.push(88);
    cout<<que1.pop()<<endl;

    queue4 que12;
    que12.push(2);
    que12.push(5);
    que12.push(8);
    que12.push(12);
    que12.push(78);
    que12.push(44);
    que12.push(88);
    cout<<que12.pop()<<endl;

    return 0;
}
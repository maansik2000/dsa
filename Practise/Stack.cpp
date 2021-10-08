#include<bits/stdc++.h>
using namespace std;

#define n 100

class stack{
    int* arr;
    int top;

    public:
        stack(){
            arr = new int[n];
            top = -1;
        }

        void push(int x){
            if(top == n-1){
                cout<<"stack overflow"<<endl;
            }

            top++;
            arr[top] = x;
        }

        void pop(){
            if(top == -1){
                cout<<"stack underflow";
            }
            top--;
        }

        int Top(){
        if(top == -1){
            cout<<"no element in stack";
            return -1;
        }
        return arr[top];
        }

        bool empty(){
        return top == -1;
        }
};

//stack using queue
class stack1{
    int x;
    queue<int> q1;
    queue<int> q2;

    public:
    stack1(){
        x = 0;
    }

    void push(int val){
        q1.push(val);
        x++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int >temp = q1;

        q1 = q2;
        q2 = temp;
    }
    void pop(){
        q1.pop();
        x--;
    }
};
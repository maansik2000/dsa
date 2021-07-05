#include<iostream>
#include<queue>
using namespace std;
#define n 100

//stack 
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
            cout<<"Stack overflow"<<endl;
            return ;
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
//making push costlier
class stack1{
    
    int x;
    queue<int> q1;
    queue<int> q2;
    
    public:
    stack1(){
        x = 0;
    }

    void push(int val ){
        q2.push(val);
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

    int top(){
        return q1.front();
    }

    int size(){
        return x;
    }
};

//making pop costlier
class Stack3{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack3(){
        N = 0;
    }

    void pop(){
        if(q1.empty()){
            return ; 
        }

        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void push(int val){
        q1.push(val);
        N++;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q2.push(ans);
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }
};

int main(){
    stack st;
    st.push(3);
    st.push(5);
    st.push(4);
    st.push(45);
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;

    stack1 st1;
    st1.push(5);
    st1.push(53);
    st1.push(54);
    st1.push(55);
    cout<<st1.top()<<endl;
    st1.pop();
    cout<<st1.top()<<endl;
    cout<<st1.size()<<endl;

    Stack3 st2;
    st2.push(7233);
    st2.push(7777);
    st2.push(787);
    st2.push(76);
    st2.push(78);
    st2.push(785);
    st2.push(47);
    cout<<st2.top()<<endl;
    st2.pop();
    cout<<st2.top()<<endl;

    return 0;
}
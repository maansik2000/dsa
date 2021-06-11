#include<iostream>
#include<cmath>
using namespace std;

//recursion


//sum till n using recursion
int SumTillN(int n){
    if(n==0){
        return 0;
    }
    int prevSum = SumTillN(n-1);
    return n + prevSum;
}


//calculate n raised to power of n
int PowerOfN(int n, int p){
    if(p == 0){
        return 1;
    }
    int PrevPower = PowerOfN(n,p-1);
    return n*PrevPower;
}


//factorial of number using recursion
int factorial(int n){
    if(n == 1){
        return 1;
    }
    int prevFact = factorial(n-1);

    return n*prevFact;
}

//nth Fibonacci number
int fib(int n){
    //base case
    if(n == 1 || n == 0){ 
        return n;
    }
    return fib(n-1) + fib(n-2);
}


//check if an array is sorted or not
bool sorted(int arr[], int n){
    if(n == 1){
        return true;
    }
    bool restArray = sorted(arr+1, n-1);
    return arr[0] < arr[1] && restArray;
}


//print number in decreasing order
void dec(int n){
    if(n == 1){
        cout<<"1"<<" ";
        return;
    }
    cout<<n<<" ";
    dec(n-1);
}


// print number in increasing order
void inc(int n){
    if(n == 1){
        cout<<"1"<<" ";
        return ;
    }
    inc(n-1);
    cout<<n<<" ";
}


//first and last occurence of a number in a array(searching)
int firstOcc(int arr[], int n, int i, int key){
    if(i == n ){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstOcc(arr, n, i+1, key);
}

//first and last occurence of a number in a array(searching)
int lastOcc(int arr[], int n, int i, int key){

    int restArray = lastOcc(arr, n,i+1, key);
    if(restArray != -1){
        return restArray;
    }
    if(arr[i] == key){
        return i;
    }
    return -1;
}


//reverse a string using recursion
void reverse(string s){
    if(s.length() == 0){
        return ;
    }

    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

//replace pi with 3.14
void replace(string s){
    if(s.length() == 0){
        return ;
    }

    if(s[0] == 'p' && s[1] == 'i'){
        cout<<"3.14";
        string ros = s.substr(2);
        replace(ros);
    }else{
        cout<<s[0];
        replace(s.substr(1));
    }
}
 
int main(){ 
    int n, p;
    cin>>n>>p;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string str ="Avinash";


    SumTillN(n);
    cout<<PowerOfN(n,p);
    cout<<factorial(n);
    cout<<fib(n);
    cout<<sorted(arr, n);
    dec(n);
    inc(n);
    cout<<firstOcc(arr, n, 0, p);
    cout<<lastOcc(arr, n, 0, p);
    reverse(str);
    replace("pipiasdfsadfpipi");
    
    return 0;
}
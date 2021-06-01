#include<iostream>
#include<cstring>
using namespace std;

//sum till n
int sum(int n){
    if(n==0){
        return 0;
    }
    int prev = sum(n-1);
    return n + prev;
}

//power of n
int power(int n,int p){
    if(p==0){
        return 1;
    }
    int prev = power(n,p-1);
    return n*prev;
}

//factorial
int factorial(int n){
    if(n==0){
        return 1;
    }
    int prev = factorial(n-1);
    return n*prev;
}

//fibonacci
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

//check if an array is sorted or not
bool sorted(int arr[],int n){

    if(n==1){
        return true;
    }

    bool restArray = sorted(arr+1, n-1);
    if(arr[0] <arr[1] && restArray){
        return  true;
    }
    else{
        return false;
    }
}

//print number in decreasing number
void dec(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}

//print number in increasing order
void inc(int n){
    if(n==1){
        cout<<"1"<<endl;
    }
    inc(n-1);
    cout<<n<<endl;
}

//first and last occurence of a number in a array
int firstocc(int arr[], int n, int i, int key){
    if(i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstocc(arr, n, i+1, key);
}

//last occurence of a number in a array
int lastocc(int arr[], int n, int i, int key){
    int restarr = lastocc(arr,n,i+1, key);
    if(restarr != -1){
        return restarr;
    }
    if(arr[i] == key){
        return i;
    }
    return -1;
}

//reverse a string
void reverse(string s){
    if(s.length() == 0){
        return;
    }

    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

//replace pi with 3.14
void replacepi(string s){
    if(s.length() == 0){
        return;
    }
    if(s[0] == 'p' && s[1] == 'i'){
        cout<<3.14;
        replacepi(s.substr(2));
    }else{
        cout<<s[0];
        replacepi(s.substr(1));
    }
}

//remove duplicates
string remove(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans = remove(s.substr(1));
    if(ch == ans[0]){
        return ans;
    }
    return ch+ans;
}

//move x to end
string move(string s){
    if(s.length() == 0){
        return "";
    }
    char ch = s[0];
    string ans = move(s.substr(1));

    if(ch == 'x'){
        return ans+ch;
    }
    return ch+ans;
}

//generate substring
void subseq(string str , string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    string ros = str.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}

void dec1(int n){
    if(n == 1){
        cout<<1<<endl;
        return ;
    }
    cout<<n<<endl;
    dec1(n-1);
    cout<<n<<endl;
}

int main(){
    dec1(5);
    return 0;
} 
#include<iostream>
#include<cmath>
using namespace std;

//prime number between two numbers
bool isPrime(int n){
    for(int i=2;i<sqrt(n);i++){
        if(n%i == 0){
            return false;
            break;
        }
    }
    return true;
}

//fibonacci sequence
void fib(int n){
    int a = 0;
    int b = 1;
    int c;

    for(int i=1;i<=n;i++){
        cout<<a<<" ";
        c = a + b;
        a = b;
        b = c;
    }

    return;

}


//factorial
void fact(int n){
    int factorial = 1;

    while(n>0){
        factorial = factorial * n;
        n--;
    }
    cout<<"factorial:"<<factorial<<endl;
}

//calculate nCr
int facto(int n){
    int factorial = 1;

    while(n>0){
        factorial = factorial * n;
        n--;
    }
    return factorial;
}


//pascal triangle
void pascal(int row, int col){
    
}


int main(){
    int n,r;
    cin>>n>>r;

    for(int i=n;i<r;i++){
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }    

    fib(n);
    fact(n);

    int ans = facto(n)/(facto(r)*facto(n-r));
    cout<<ans<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int ans = facto(i)/(facto(j)*facto(i-j));
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


//sieve of Eratosthenes 
void PrimeSieve(int n){

    bool prime[100]= {0};

    for(int i=2;i<=n;i++){
        if(prime[i] == 0){
            for(int j = i*i ;j<=n;j+=i){
                prime[j] = 1;
            }
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p] == 0)
            cout << p << " ";


    //time complexity O(n*log(log(n)))
}


//gcd using euclid method
int gcd(int a, int b){
    while(b!=0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

int main(){
    int n,m;
    cin>>n>>m;
    // PrimeSieve(n);
    cout<<gcd(m,n)<<endl;
    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[10];


//fibonacci using recursion method
ll fib1(ll n){ 

    //base case
    if(n <= 1){
        return n;
    }

    return fib1(n-1) + fib1(n-2);
}



//fibonacci using dp
//complexity o(n)
class GFG{
	
public:
    ll fib_DP(ll n)
    {
        
        ll f[n + 2]; 
        ll i;

        f[0] = 0;
        f[1] = 1;

        for(i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
        }
};

//fibonacci using optimized method
//complexity o(n) space complexity o(1)
ll fib(ll n){
    ll a = 0, b = 1, c, i;

    if(n == 0){
        return a;
    }

    for(i = 2;i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

//DP Using memoization
ll fib3(ll n){
    if(n<=1){
        return n;
    }

    ll first, second;

    if(dp[n-1] != -1){
        first = dp[n-1];
    }else{
        first = fib3(n-1);
    }

    if(dp[n-1] != -1){
        second = dp[n-2];
    }else{
        second = fib(n-2);
    }

    return dp[n] = first + second;
}


int main(){
    ll n;
    GFG g;
    cin>>n;

    cout<<g.fib_DP(n)<<" "<<endl;
    // cout<<fib1(n)<<endl;
    cout<<"using optimised method"<<" "<<fib(n)<<endl;

    return 0;
}
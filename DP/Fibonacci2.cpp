#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    // vector<int> dp(n+2);

    // dp[0] = 0;
    // dp[1] = 1;

    // for(int i=2;i<=n;i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }

    // cout<<dp[n];

    // //or space optimized

    int a = 0, b = 1, c;
    if(n==0){
        return a;
    }

    for(int i=2;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }

    cout<<b;
    return 0;
}
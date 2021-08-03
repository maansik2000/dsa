#include<bits/stdc++.h>
using namespace std;

int KnapSack(int W, int wt[], int val[], int n){
    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<n+1;i++){
        for(int j = W; j>=0 ; j--){
            if(wt[i-1] <= W){
                dp[W] = max(dp[j], dp[W - wt[i-1]] + val[i - 1]);
            }
        }
    }

    return dp[W];  //returning the maximum value of knapsack
}

int main(){
    int n,W;
    cin>>n>>W;

    int val[n], wt[n];

    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    cout<<KnapSack(W, wt, val, n);

    return 0;
}
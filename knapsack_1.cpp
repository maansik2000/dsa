#include <bits/stdc++.h>
using namespace std;

//knapsack using dp
int max(int a, int b)
{ 
    return (a > b) ? a : b; 
}

 //return max value

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                          + K[i - 1][w - wt[i - 1]],
                          K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    return K[n][W];
}

//using memoisation
int knapSackRec(int W, int wt[], int val[], int i,int** dp ){
    //base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];
 
    if (wt[i] > W) {
 
        // Store the value of function call
        // stack in table before return
        dp[i][W] = knapSackRec(W, wt, 
                               val, i - 1, 
                               dp);
        return dp[i][W];
    }
    else {
        // Store value in a table before return
        dp[i][W] = max(val[i]
                      + knapSackRec(W - wt[i], 
                                   wt, val,
                                   i - 1, dp),
                       knapSackRec(W, wt, val, 
                                   i - 1, dp));
 
        // Return value of table after storing
        return dp[i][W];
    }
}


int knapsack1(int W, int wt[], int val[], int n){
    int** dp;
    dp = new int*[n];

    for(int i=0;i<n;i++){
        dp[i] = new int[W+1];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;

    return knapSackRec(W, wt, val, n - 1, dp);
}

int main(){
    int n;
    int w;
    cin>>n>>w;
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"the maximum profit value"<<" "<<knapsack(w,wt,val,n)<<endl;
    cout<<"the maximum profit value using memoisation"<<" "<<knapsack1(w,wt,val,n)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int dp[2000][2000];

bool isSubsetSum1(int set[], int n, int sum)
{

    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
 
    return subset[n][sum];
}

bool isSubsetSum(int arr[], int n, int sum){

    if(sum == 0){
        return true;
    }

    if(n == 0 && sum != 0){
        return false;
    }

    if(dp[n-1][sum] != -1){
        return dp[n-1][sum];
    }

    if(arr[n-1] > sum){
        return dp[n - 1][sum] = isSubsetSum(arr, n - 1, sum);
    }else{
        return dp[n-1][sum] = isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum - arr[n-1]);
    }

}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum;
    cin>>sum;

    if(isSubsetSum(arr, n, sum)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}
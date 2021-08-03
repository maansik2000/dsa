#include<bits/stdc++.h>
using namespace std;

bool findPartiion(int arr[], int n){

    //tabulation
    int sum = 0;
    int i, j;

    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool dp[n+1][sum/2 + 1];

    for(int i=1; i<=n;i++){
        for(int j=1;j<=sum/2;j++){
            if(i == 0 || j == 0){
                dp[i][j] = false;
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else if(arr[i-1] == j){
                dp[i][j] = true;
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }

    return dp[n][sum / 2];
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal "
                "sum";
    else
        cout << "Can not be divided into"
             << " two subsets of equal sum";
    return 0;
}
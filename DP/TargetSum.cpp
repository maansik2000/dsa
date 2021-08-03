 #include<bits/stdc++.h>
using namespace std;


int countWithGivenDiff(int arr[], int n, int diff){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }

    int reqSum = (sum - diff)/2;

    int dp[n+1][reqSum+1];

    dp[0][0] = 1;

    for (int i = 1; i <= reqSum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=reqSum;j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]; 
            }
        }
    }

    return dp[n][reqSum];
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int diff;
    cin>>diff;

    cout << countWithGivenDiff(arr, n, diff);
    return 0;
}
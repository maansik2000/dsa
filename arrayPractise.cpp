#include <bits/stdc++.h>
#include<cmath>
using namespace std;

//sum of all subarray 
void SubArraySum(int arr[], int n){

    for(int i=0;i<n;i++){
        int curr = 0;
        for(int j=i;j<n;j++){
            curr += arr[j];
            cout<<curr<<" ";
        }
        
    }
}

//longest arithmetic array 
void longestArithmetic(int arr[], int n){
    int ans = 2;
    int pd = arr[1] - arr[0];

    int j = 2;
    int current = 2;

    while(j<n){
        if(pd == arr[j] - arr[j-1]){
            current++;
        }else{
            pd = arr[j]-arr[j-1];
            current=2;
        }

        ans = max(ans,current);
        j++;
    }

    cout<<ans<<endl;
}


//1 2 0 7 2 0 2 2

//record breaking day question
void RecordBreak(int arr[], int n){

    if(n == 1){
        cout<<"1"<<endl;
        
    }

    int ans = 0;

    int mx = -9999999;

    for(int i=0;i<n;i++){
        if(arr[i] > mx && arr[i] > arr[i+1]){
            ans++;
        }
        mx = max(mx,arr[i]); 
    }

    cout<<ans<<endl;
}

//max Till n
void maxTilln(int arr[],int n){
    int mx = -9999999;
    for(int i=0; i<n;i++){
        mx = max(mx, arr[i]);
    }

    cout<<mx<<endl;
}

//repeating element at the smallest index
void repeatingIndex(int arr[],int n ){
    
    const int N = 1e6+2;

    int idx[N];

    for(int i=0; i<N;i++){
        idx[i] = -1;
    }

    int minIdx = 999999;
    for(int i=0;i<n;i++){
        if(idx[arr[i]] != -1){
            minIdx = min(minIdx,idx[arr[i]]);
        }else{
            idx[arr[i]] = i;
        }
        
    }
    

    if(minIdx == 999999){
        cout<<"-1"<<endl;
    }else{
        cout<<"ans:"<<minIdx<<endl;
    }
}

//sum of subarray
void sumOfSubArray(int arr[],int n){
    int sum;
    cin>>sum;

    int checkSum = 0;

    int i = 0, j = 0, st = -1, en = -1;

    while(j<n && checkSum + arr[j] <= sum){
        checkSum += arr[j];
        j++;
    }

    if(checkSum == sum){
        cout<<i + 1<<" "<<j<<endl;
        return ;
    }

    while(j<n){
        checkSum += arr[j];
        while(checkSum > sum){
            checkSum -= arr[j]; 
        }

        if(checkSum == sum){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }

}

int main(){

    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    maxTilln(arr, n);
    SubArraySum(arr,n);
    longestArithmetic(arr,n);

    repeatingIndex(arr,n);
    sumOfSubArray(arr,n);

    return 0; 
}
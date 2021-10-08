#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>& arr, int n){
    int i=1;
    sort(arr.begin(), arr.end());

    for(i=0;i<n;i++){
        if(arr[i] != i+1){
            break;
        }
    }

    return i+1;
}

//other method
int findMissing2(vector<int>& arr, int n){
    int total = (n+1)*(n+2)/2;
    for(int i=0;i<n;i++){
        total -= arr[i];
    }

    return total;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<findMissing(arr, n)<<endl;
    // cout<<findMissing2(arr, n);

    return 0;
}
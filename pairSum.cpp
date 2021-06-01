#include<iostream>
#include<algorithm>
#include "bits/stdc++.h"
using namespace std;

bool pairSum(int arr[], int n, int data){
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]+ arr[j]==data){
    //             cout<<i<<" "<<j<<endl;
    //             return true;
    //         }
    //     }
    // }
    // return false;
    //optimize solution

    int low=0;
    int high=n-1;
    while(low<high){
        if(arr[low]+arr[high]== data){
            cout<<low<<" "<<high<<endl;
            return true;
        }else if(arr[low]+arr[high]>data){
            high--;
        }else{
            low++;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int data= 31;
    cout<<pairSum(arr,n,data)<<endl;
    return 0;
}
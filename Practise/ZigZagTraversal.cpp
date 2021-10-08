#include<bits/stdc++.h>
using namespace std;

void zigzag(vector<int>& arr, int n){
    bool flag = true;

    for(int i=0;i<=n-2;i++){
        if(flag){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }else{
            if(arr[i] < arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }

        flag = !flag;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++)
        cin>> arr[i];

    zigzag(arr,n);

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
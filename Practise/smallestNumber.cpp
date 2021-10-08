#include<iostream>
#include<algorithm>
using namespace std;

int findElement(int arr[], int size){
    int leftElement[size];
    leftElement[0] = INT_MIN;

    for(int i=1;i<size;i++){
        leftElement[i] = max(leftElement[i-1], arr[i-1]);
    }

    int rightElement = INT_MAX;

    for(int i=size-1;i>=0;i--){
        if(leftElement[i] < arr[i] && rightElement > arr[i]){
            return i;
        }

        rightElement = min(rightElement, arr[i]);
    }

    return -1;
}


int main(){
    int size;
    cin>>size;
    int arr[size];

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int ans = findElement(arr, size);

    // for(int i=0;i<size;i++){
    //     if(ans != arr[i]){
    //         cout<<arr[i]<<" ";
    //     }
    // }

    cout<<findElement(arr, size);

    return 0;
}
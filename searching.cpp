#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n,int key){
    for(int i=1;i<=n;i++){
        if(arr[i] == key){
            cout<<"key found at"<<i;
        }
    }
    return -1;
}


int binarySearch(int arr[], int l,int r,int x){
    int mid = (l+r)/2;
    while (l <= r) {
        int mid = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
 
        // If x greater, ignore left half
        if (arr[mid] < x)
            l = mid + 1;
 
        // If x is smaller, ignore right half
        else
            r = mid - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    int key;
    cin>>key;

    int result = binarySearch(arr,0, n-1, key);

    if(result == -1){
        cout<<"element not found";
    }else{
        cout<<"element found at index"<<result;
    }

    return 0;
}
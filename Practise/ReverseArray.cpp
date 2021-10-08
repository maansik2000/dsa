#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr, int n){
    int i = 0, j = n-1;

    int temp;

    while(i<j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

int maximumAndMinimum(vector<int>& arr, int n){
    int maximum = INT_MIN;
    int minimum = INT_MAX;

    for(int i=0;i<n;i++){
        maximum = max(arr[i], maximum);
        minimum = min(arr[i], minimum);
    }

    return minimum;
}

int kthMaximumAndMinimumElement(vector<int>& arr, int n){
    sort(arr.begin(), arr.end(), greater<int>());

    int k;
    cin>>k;

    return arr[k];
}

void moveNegativeElement(vector<int>& arr, int n){
    int left = 0, right = n-1;

    while(left <= right){
        if(arr[left] < 0 && arr[right] < 0)
            left++;

        else if(arr[left] > 0 and arr[right] < 0){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }

        else if( arr[left] > 0 and arr[right] > 0){
            right--;
        }else{
            left++;
            right--;
        }

    }

    for (int i=0;i<=n;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // reverseArray(arr, n);
    // cout<<endl;
    // cout<<maximumAndMinimum(arr, n)<<endl;
    // cout<<kthMaximumAndMinimumElement(arr, n)<<endl;
    moveNegativeElement(arr, n);
    return 0;
}
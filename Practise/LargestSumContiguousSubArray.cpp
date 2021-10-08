#include<bits/stdc++.h>
using namespace std;

//kadne algo
int kadenAlgo(vector<int>& arr, int n){
    int maxSum = INT_MAX, max_ending = 0;

    for(int i=0;i<n;i++){
        max_ending = max_ending + arr[i];

        maxSum = max(maxSum, max_ending);

        if(max_ending < 0){
            max_ending = 0;
        }
    }

    return maxSum;
}

//dynamix programming
int maxSubArrSum(vector<int>& arr, int n){
    int maxSum = arr[0];
    int curr_Sum = arr[0];

    for(int i=1;i<n;i++){
        curr_Sum = max(arr[i], curr_Sum + arr[i]);

        maxSum = max(maxSum, curr_Sum);
    }

    return maxSum;
}

int maxSubArraySum1(int arr[], int size)
{
    int sum = 0, max_so_far = INT_MIN;
    for (int i = 0; i < size; i++) {
       
        if (arr[i] <= sum + arr[i]) {
            sum += arr[i]; 
        }

        else {
            sum = arr[i];
        }
        if (sum > max_so_far)
            max_so_far = sum;
    }
    return max_so_far;
} 


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<kadenAlgo(arr, n);
    return 0;
}
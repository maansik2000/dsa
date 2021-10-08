#include<bits/stdc++.h>
using namespace std;

long int SubArraySum(int arr[], int n){
    long int result = 0;

    for(int i=0;i<n;i++){
        result = result + (arr[i]*(n-i)*(i+1));
    }
    return result;
}


//sub array sum with given sum
int subArraySum(int arr[], int n, int sum)
{
    int curr_sum, i, j;

    for (i = 0; i < n; i++) {
        curr_sum = arr[i];

        for (j = i + 1; j <= n; j++) {
            if (curr_sum == sum) {
                cout << "Sum found between indexes "
                     << i << " and " << j - 1;
                return 1;
            }
            if (curr_sum > sum || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }
 
    cout << "No subarray found";
    return 0;
}

//second method sub array with given sum
int subArraySum(int arr[], int n, int sum){
    int curr_sum = arr[0], start = 0,i;

    for(i=0;i<=n;i++){
        while(curr_sum > sum && start < i - 1){
            curr_sum =curr_sum - arr[start];
            start++;
        }

        if(curr_sum == sum){
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }

        if(i<n){
            curr_sum = curr_sum + arr[i];
        }
    }
    cout << "No subarray found";
    return 0;
}

//subarray with given sum third method
void sumOfSubArray(int arr[], int n){
    int sum;
    cin>>sum;

    int curr_sum = 0;

    int i = 0, j = 0, st = -1, en = -1;

    while(j<n && curr_sum + arr[j]< sum){
        curr_sum = curr_sum + arr[j];
        j++;
    }

    if(curr_sum == sum){
        cout<<i + 1<<" "<<j<<endl;
        return ;
    }

    while(j<n){
        curr_sum += arr[j];
        while(curr_sum > sum){
            
        }
    }
}


int main()
{
    int arr[] = {1, 2, 3} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum of SubArray : "
         << SubArraySum(arr, n) << endl;
    return 0;
}
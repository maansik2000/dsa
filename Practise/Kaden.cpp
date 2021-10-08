#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int arr[], int n){
    int max_ans = INT_MIN, max_sum = 0;

    for(int i=0;i<n;i++){
        max_sum = max_sum + arr[i];

        max_ans = max(max_ans, max_sum);

        if(max_sum < 0){
            max_sum = 0;
        }
    }
    return max_ans;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int subArraySum(int arr[], int n, int sum){
    int curr_sum, i,j;

    for( i=0;i<n;i++){
        curr_sum = arr[i];

        for(j=i+1;j<=n;j++){
            if(curr_sum == sum){
                cout << "Sum found between indexes "
                     << i << " and " << j - 1;
                return 1;
            }

            if(curr_sum > sum || j == n){
                break;
            }

            curr_sum = curr_sum + arr[j];
        }
    }

    cout << "No subarray found";
    return 0;
}


//smallest Missing number
void smallestMissingNumber(int arr[], int n){
    const int N = 1e6+2;

    bool check[N];

    for(int i=0;i<N;i++){
        check[i] = 0;
    }

    for(int i=0;i<n;i++){
        if(arr[i] >= 0){
            check[arr[i]] = 1;
        }
    }

    int ans = -1;

    for(int i=1;i<N;i++){
        if(check[i] == false){
            ans = i;
            break;
        }
    }

    cout<<ans<<endl;
}


//maximum subarray sum Brute Force
void maxSubArraySum(int arr[],int n){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = arr[i];
        for(int j=i+1;j<n;j++){
            sum += arr[j];
            maxSum = max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
}


//maximum subarray optimized method 
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


void kadensAlgo(int arr[],int n){
    int curr_sum = 0;
    int max_sum = INT_MIN;

    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        if(curr_sum < 0){
            curr_sum = 0;
        }

        max_sum = max(max_sum, curr_sum);
    }
    cout<<max_sum<<endl;
}

bool pairsum(int arr[], int n, int k){ 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == k){
                cout<<i<<" "<<j;
                return true;
            }
        }
    }
    return false;
}

bool pairsum2(int arr[], int n, int k){
    int low = 0;
    int high = n-1;

    while(low < high){
        if(arr[low] + arr[high] == k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low] + arr[high] > k){
            high--;
        }else{
            low++;
        }
    }
    return false;
}

void palindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
  
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            cout<<"it is not a palindrome"<<endl;
            return;
        }
    }
    cout<<"it is a palindrome"<<str<<endl;
}

//largest word in a sentence
void largestWord(char str[]){
    int i=0;
    int currLen = 0, maxLen = 0;

    while(1){

        if(str[i] == ' ' || str[i] == '\0'){
            if(currLen > maxLen){
                maxLen = currLen;
            }
            currLen = 0;
        }
        else{
        currLen++;

        if(str[i] == '\0')
            break;

        i++;
        }
    }

    cout<<maxLen<<endl;
}

//sieve os eratosthenes
//fibonacci numbers
//longest common subsequence
//subset sum problem
//0-1 knapsack problem


int main(){
    int n,sum;
    cin>>n;

    int arr[n];
    char arr1[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 

    cin>>arr1;
    cin.ignore();
    cin.getline(arr1, n);
    cin.ignore();
    subArraySum(arr,n,sum);
    smallestMissingNumber(arr, n);

    maxSubArraySum(arr,n);
    maxSubArraySum1(arr, n);
    kadensAlgo(arr,n);
    pairsum(arr,n, sum);
    pairsum2(arr, n, sum);
    palindrome(arr1);
    largestWord(arr1);
    return 0; 
}
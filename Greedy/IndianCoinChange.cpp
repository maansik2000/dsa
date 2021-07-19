#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int x;
    cin>>x;

    sort(arr.begin(), arr.end(), greater<int>());

    int ans = 0;

    for(int i=0;i<n;i++){
        ans += x/arr[i];
        x -= x/arr[i] * arr[i];
    }

    return 0;
}
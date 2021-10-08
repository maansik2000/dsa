#include<bits/stdc++.h>
using namespace std;

void findIntersection(int* a, int n, int* b, int m){
    map<int,int> mp;

    for (int i = 0; i < n; i++)
        mp.insert({ a[i], i });
   
    for (int i = 0; i < m; i++)
        mp.insert({ b[i], i });
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first
             << " ";
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n), arr2(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    set<int> s;

    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    for(int i=0;i<n;i++){
        s.insert(arr2[i]);
    }

    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr
             << " "; 
    return 0;
}
#include<bits/stdc++.h> 
using namespace std;
int main()
{
      
    vector<int> v1 = {20, 30, 40, 25, 15};
    is_heap(v1.begin(), v1.end());
    make_heap(v1.begin(), v1.end());

    v1.push_back(50);

    cout << v1.front() << endl;

    make_heap(v1.begin(), v1.end());

    cout << v1.front() << endl;

    sort_heap(v1.begin(), v1.end());

    for (int &x : v1) 
       cout << x << " ";
      
    return 0;
}
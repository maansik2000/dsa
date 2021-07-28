#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> cnt;

    int preSum = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        cnt[preSum]++;
    }

    int ans = 0;

    map<int, int>::iterator it;

    for (it = cnt.begin(); it != cnt.end(); it++)
    {
        int c = it->second;
        ans += (c * (c - 1)) / 2;

        if (it->first == 0)
        {
            cout << "found";
        }
    }

    return 0;
}
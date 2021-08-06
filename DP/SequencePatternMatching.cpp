#include <bits/stdc++.h>
using namespace std;

int L[1001][1001];

int max(int a, int b);

int lcs(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];

    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}


int max(int a, int b)
{
    return (a > b) ? a : b;
}


bool patternMatching(string str1, string str2, int x,int y){
    int l = lcs(str1,str2,x,y);

    if(l == str1.size()){
        return true;
    }else{
        return false;
    }
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int x = str1.size();
    int y = str2.size();

    if(patternMatching(str1, str2, x, y)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}
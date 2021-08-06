#include <bits/stdc++.h>
using namespace std;

int L[1001][1001];

int max(int a, int b);

int lsc(string s1, string s2, int m, int n)
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



//overlapping subproblem
int lcs(string str1, string str2, int m, int n){
    if(n == 0 || m == 0){
        return 0;
    }

    if(str1[n-1] == str2[m-1]){
        return 1 + lcs(str1, str2, m-1, n-1);
    }else{
        return max(lcs(str1, str2, m-1, n), lcs(str1, str2,m, n-1));
    }
}

//memoization
int lcs2(string str1, string str2, int m, int n){
    if(n == 0 || m == 0){
        return 0;
    }

    if(L[m][n] != -1){
        return L[m][n];
    }
    
    if(str1[n-1] == str2[m-1]){
        return L[m][n] = 1 + lcs(str1, str2, m-1, n-1);
    }else{
        return L[m][n] = max(lcs(str1, str2, m-1, n), lcs(str1, str2,m, n-1));
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}


int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    memset(L, -1, sizeof(L));

    int x = str1.size();
    int y = str2.size();

    cout << "Length of LCS is" << lsc(str1, str2, x, y);
    return 0;
}
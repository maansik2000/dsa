#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    
    int t[m+1][n+1];
    
    memset(t , 0 , sizeof(t));
    
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i==0 or j==0) t[i][j] = 0;
        }
    }
    
    for(int i = 1;i<m+1;i++)
    {
        for(int j = 1;j<n+1;j++)
        {
            if(text1[i-1] == text2[j-1])
            {
                t[i][j] = 1+t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    
    return t[m][n];
}
int longestPalindromeSubseq(string s) {
    string s1 = s;
    
    reverse(s.begin() , s.end());
    
    string s2 = s;
    
    return longestCommonSubsequence(s1 , s2);
    
}



int main()
{
    string str = "agbcba";
    cout<<longestPalindromeSubseq(str);

    return 0;
}
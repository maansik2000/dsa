#include<bits/stdc++.h>
using namespace std;

int findLength(string nums1, string nums2) 
    {
        int l1=nums1.size();
        int l2=nums2.size();
        int result=0;
        
        vector<vector<int>> dp(l1+1,vector<int>(l2+1));
        for(int i=0;i<=l1;i++) dp[i][0]=0;
        for(int j=0;j<=l2;j++) dp[0][j]=0;
        
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
                result=max(dp[i][j],result);
            }
        }
        
        return result;
    }

int main(){
    string n1;
    string n2;

    cin>>n1>>n2;

    cout<<findLength(n1, n2);
     return 0;
}
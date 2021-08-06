#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n){
    int L[m+1][n+1];

    int i,j;

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }

    return L[m][n];
}

void minimumInsertionDeletion(string s1, string s2, int m, int n){
    int l = lcs(s1, s2, m ,n);

    cout<<"minimum number of deletion require"<< m - l<<endl;
    cout<<"minimum number of insertion require"<<n - l<<endl;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;

    int m,n;

    m = s1.size();
    n = s2.size();

    minimumInsertionDeletion(s1, s2, m, n);

    return 0;
}
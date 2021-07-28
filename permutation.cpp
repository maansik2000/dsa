#include<iostream>
using namespace std;
int main(){
    long long int n,y,ans,i,j,mod=1000000007;
    cin>>y;
    while(y--)
    {
        cin>>n;
      	long long int ans = 0;
    	ans = ((1 << n) - 1  ) % mod;
        cout<<ans <<"\n";
    }
}
 
#include "bits/stdc++.h"
typedef long long ll; 
using namespace std;


void prime(ll n, ll m)
{
	
	bool prime[n + 1];
  int count=0;
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		
		if (prime[p] == true) 
		{
			
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	
	for (int p = 2; p <= n; p++)
		if (prime[p])
			count++;
  
  	if(count>m){
          cout<<"Divyam"<<endl;
      }
      else{
          cout<<"Chef"<<endl;
      }
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll y,x;
        cin>>x;
        cin>>y;
        prime(x,y);

    }
    return 0;
}

// #include<bits/stdc++.h>
// #define int long long int
// #define fastio ios_base::sync_with_stdio(false);cin.tie(0);
// using namespace std;

// const int N = 1e6+5;
// int res[N];

// void valentine()
// {
//     vector<int>vect;
//     bool prime[N];
//     memset(prime, true, sizeof(prime));
 
//     for (int p = 2; p * p < N; p++)
//     {
//         if (prime[p] == true) 
//         {
//             for (int i = p * p; i < N; i += p)
//                 prime[i] = false;
//         }
//     }
 
//     for (int p = 2; p < N; p++)
//         if (prime[p])
//             vect.push_back(p);

//     auto it = vect.begin();
//     int cnt = 0;
//     for (int i = 0; i < N; i++)
//     {
//         if(*it <= i)
//         {
//             ++cnt;
//             ++it;
//         }
//         res[i] = cnt;
//     }
// }

// signed main()
// {
//     fastio;
//     valentine();
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int x,y;
//         cin>>x>>y;
//         if(res[x] <= y)
//             printf("Chef\n");
//         else
//             printf("Divyam\n");
//     }
//     return 0;
// }

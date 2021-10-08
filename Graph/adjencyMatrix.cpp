#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define setBits(x) builtin_popcount(x)

const int N=1e5+2, MOD = 1e9+7;

vi adL[N]; 

int main(){
    int n,m;

    //adjency matrix
    // cin>>n>>m;

    // vvi adjm(n+1, vi(n+1, 0));

    // rep(i,0,m){
    //     int x,y;
    //     cin>>x>>y;
    //     adjm[x][y] = 1;
    //     adjm[y][x] = 1;
    // }

    // cout<<"adjency matrix of about graph is "<<endl;

    // rep(i,0, n+1){
    //     rep(j,1, n+1){
    //         cout<<adjm[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }

    // cout<<endl<<endl;

    cin>>n>>m;

    rep(i,0, m){
        int x, y;
        cin>>x>>y;

        adL[x].push_back(y);  
        adL[y].push_back(x);
    }

    cout<<"adjacency list of the about graph is given by"<<endl;

    rep(i, 1, n+1){
        cout<<i<<" -> ";
        for(int x: adL[i]){
            cout<<x<<" ";
        }

        cout<<endl;
    }

    return 0;
}
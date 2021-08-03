#include<bits/stdc++.h>
using namespace std;

int main(){
    int ladder, snakes;

    cin>>ladder;
    map<int, int> lad;
    map<int, int> snak;

    for(int i=0;i<ladder;i++){
        int u, v;
        cin>>u>>v;

        lad[u] = v;
    }

    cin>>snakes;
    for(int i=0;i<snakes;i++){
        int u, v;
        cin>>u>>v;
        snak[u] = v;
    }

    int moves = 0;

    queue<int> q;
    q.push(1);

    bool found = false;

    vector<int> vis(101,0);

    vis[1] = 1;

    while(!q.empty() and !found){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            for(int die = 1;die<=6;die++){
                if(t + die == 100){
                    found = true;
                }
                if(t + die <= 100 and lad[t + die] and !vis[t + die]){
                    vis[lad[t + die]] = true;
                    if(lad[t + die] == 100){
                        found = true;
                    }

                    q.push(lad[t + die]);
                }
                else if (t + die <= 100 and snak[t + die] and !vis[snak[t + die]]){
                    vis[snak[t + die]] = true;
                    if(snak[t + die] == 100){
                        found = true;
                    }

                    q.push(snak[t + die]); 
                }else if(t + die <= 100 and !vis[t + die] and !snak[t + die]){
                vis[t+die] = true;
                }
            }
        }
        moves++;
    }
    if(found){
        cout<<moves;
    }else{
        cout<<"-1";
    }
}
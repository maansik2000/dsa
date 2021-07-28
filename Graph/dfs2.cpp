#include<bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> g[], bool *visited){
    visited[s] = true;

    cout<<s<<" ";

    for(int i=0;i<g[s].size();++i){
        if(visited[g[s][i]] == false){
            dfs(g[s][i], g, visited);
        }
    }
}

int main(){
    int V, E;
    cin>>V>>E;

    vector<int> g[V];
    bool visited[V];

    memset(visited, false, sizeof(visited));

    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, g, visited);

    return 0;
}
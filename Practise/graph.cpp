#include<bits/stdc++.h>
using namespace std;


//depth first search
void dfs(int s, vector<int> adj[], bool *visited){
    visited[s] = true;
    cout<<s<<" ";

    vector<int>::iterator it;

    for( it = adj[s].begin();it !=adj[s].end();it++){
        if(visited[*it]);
        else{
            dfs(*it, adj, visited);
        }
    }
}


//breadth first search
void bfs(int s, vector<int> adj[], bool *visited, int N){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout<<curr<<" ";

        vector<int>::iterator it;

        for(it=adj[s].begin();it != adj[s].end();it++){
            if(!visited[*it]){
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}


int main(){
    int E, V;
    cin>>E>>V;

    vector<int> adj[V];     //adjcency list 
    bool visited[V];

    int x, y;
    memset(visited, false, sizeof(visited));

    for(int i=0;i<E;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    dfs(1, adj, visited);

    return 0;
}
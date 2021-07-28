#include<iostream>
#include<vector>
using namespace std;

bool isCycle(int s, vector<vector<int>> &adj, vector<bool> &visited, int parent){
    visited[s] = true;

    for(auto i : adj[s]){
        if(i!=parent){
            if(visited[i]){
                return true;
            }
            if(!visited[i] and isCycle(i, adj, visited, s)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n); //adjencency list 

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u); // putting the node in the list
    }

    bool cycle = false;

    vector<bool> visited(n, false);

    for(int i=0;i<n;i++){
        if(!visited[i] and isCycle(i, adj, visited, -1)){
            cycle = true;
        }
    }

    if(cycle){
        cout<<"cycle is present";
    }else{
        cout<<"cycle is not present";
    }

    return 0;
}
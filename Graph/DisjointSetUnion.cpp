#include<iostream>
#include<vector>
using namespace std;

vector<int> dsuf;

int find(int v){
    if(dsuf[v] == -1){
        return v;
    }

    return find(dsuf[v]);
}

void union_op(int fromP, int toP){
    fromP = find(fromP);
    toP = find(toP);

    dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int, int>> &edge_list){
    for(auto p: edge_list){
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP){
            return true;
        }

        union_op(fromP, toP);

    }

    return false;
}

int main(){
    int E; //No of edges
    int V; //No of Vertices
    cin>>E>>V;

    dsuf.resize(V, -1);
    vector<pair<int, int>> edge_list; //Adjacency list

    for(int i=0;i<E;i++){
        int from, to;
        cin>>from>>to;
 
        edge_list.push_back({from , to});
    }

    if(isCyclic(edge_list)){
        cout<<"True"<<endl;
    }else{
        cout<<"False";
    }
    return 0;

    //time complexity o(e*logn)
}
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int parent;
    int rank;
};

vector<node> dsruf;

int find(int v){
    if(dsruf[v].parent == -1){
        return v;
    }

    return dsruf[v].parent = find(dsruf[v].parent);
}

void unionP(int fromp, int top){
    if(dsruf[fromp].rank > dsruf[top].rank){
        dsruf[top].parent = fromp;
    }else if(dsruf[fromp].rank < dsruf[top].rank){
        dsruf[fromp].parent = top;
    }else{
        dsruf[fromp].parent = top;
        dsruf[top].parent += 1;
    }
}

bool isCyclic(vector<pair<int,int>> &edgeList){
    for(auto p: edgeList){
        int fromp = find(p.first);
        int top = find(p.second);

        if(fromp == top){
            return true;
        }

        unionP(fromp, top);
    }

    return false;
}

int main(){
    int E,V;
    cin>>E>>V;
    dsruf.resize(V);
    for(int i=0;i<V;i++){
        dsruf[i].parent = -1;
        dsruf[i].rank = 0;
    }

    vector<pair<int, int>> edgeList;
    for(int i=0;i<E;i++){
        int from, to;
        cin>>from>>to;
        edgeList.push_back({from, to});
    }

    if(isCyclic(edgeList))
		cout<<"TRUE\n";
	else
		cout<<"FALSE\n";

    return 0;
}


#include<bits/stdc++.h>
using namespace std;

vector<int> dsuf;

//find operation
int find(int v){
    if(dsuf[v] == -1){
        return v;
    }

    return find(dsuf[v]); 
}

//union operation
void unionp(int fromp, int top){
    fromp = find(fromp);
    top = find(top);

    dsuf[fromp] = top;
}

bool isCyclic(vector<pair<int,int>>& edgeList){
    for(auto p : edgeList){
        int fromp = find(p.first);
        int toP = find(p.second);

        if(fromp == toP){
            return true;
        }

        unionp(fromp, toP);
    }

    return false;
}

int main(){
    int E,V;
    cin>>E>>V;

    dsuf.resize(V, -1);

    vector<pair<int, int>> edge_list; //adjencency list

    for(int i=0;i<E;i++){
        int from, to;
        cin>>from>>to;
        edge_list.push_back({from, to});
    }

    if(isCyclic(edge_list)){
        cout<<"true";
    }else{
        cout<<"false";
    }

    return 0;
}
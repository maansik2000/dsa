#include<bits/stdc++.h>
using namespace std;

struct node{
    int parent;
    int rank;
};

struct Edge{
    int src;
    int dist;
    int wt;
};

vector<node> dsruf;
vector<Edge> mst;

int find(int v)
{
	if(dsruf[v].parent==-1)
		return v;
	return dsruf[v].parent=find(dsruf[v].parent);	//Path Compression
}

void union_op(int fromP,int toP)
{

	if(dsruf[fromP].rank > dsruf[toP].rank)	//fromP has higher rank
		dsruf[toP].parent = fromP;
	else if(dsruf[fromP].rank < dsruf[toP].rank)	//toP has higher rank
		dsruf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		dsruf[fromP].parent = toP;
		dsruf[toP].rank +=1;		//Increase rank of parent
	}
}

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}

void printEdgeList(vector<Edge>& edge_List, int V, int E)
{
	for(auto p: edge_List)
		cout<<"src: "<<p.src<<"  dst: "<<p.dist<<"  wt: "<<p.wt<<"\n";
	cout<<"============================================================\n";
}

void Kruskals(vector<Edge> &edge_List, int V, int E){
    sort(edge_List.begin(),edge_List.end(),comparator);

    int i=0, j=0;

    while(i<V-1 && j<E){
        int fromP = find(edge_List[j].src);
        int toP = find(edge_List[j].dist);

        if(fromP == toP)
		{	++j;	continue;	}

        union_op(fromP,toP);

        mst.push_back(edge_List[j]);
        i++;
    }
}

void printMST(vector<Edge>& mst)
{
	cout<<"MST formed is\n";
	for(auto p: mst)
		cout<<"src: "<<p.src<<"  dst: "<<p.dist<<"  wt: "<<p.wt<<"\n";
}

int main(){
    int E;
    int V;
    cin>>E>>V;

    dsruf.resize(V);

    for(int i=0;i<V;i++){
        dsruf[i].parent = -1;
        dsruf[i].rank = 0;
    }

    vector<Edge> edge_List;	//Adjacency list
    Edge temp;

    for(int i=0;i<E;++i)
	{
		int from,to,wt;
		cin>>from>>to>>wt;
		temp.src = from;
		temp.dist = to;
		temp.wt = wt;
		edge_List.push_back(temp);
	}

    Kruskals(edge_List,V,E);
	printMST(mst);

    return 0;
}
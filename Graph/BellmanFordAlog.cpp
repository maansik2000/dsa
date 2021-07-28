#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int src, dst, wt;
};

int V, E;

void bellmanFord(vector<edge> &edge)
{
    int parent[V];
    int cost_parent[V];
    vector<int> value(V, INT_MAX);

    parent[0] = -1;
    value[0] = 0;
    bool updated;

    for (int i = 0; i < V - 1; i++)
    {
        updated = false;

        for (int j = 0; j < E; j++)
        {
            int U = edge[j].src;
            int V = edge[j].dst;
            int wt = edge[j].wt;

            if (value[U] != INT_MAX and value[U] + wt < value[V])
            {
                value[V] = value[U] + wt;
                parent[V] = U;
                cost_parent[V] = value[V];
                updated = true;
            }
        }

        if (updated == false)
            break;
    }

    for (int j = 0; j < E and updated == true; ++j)
    {
        int U = edge[j].src;
        int V = edge[j].dst;
        int wt = edge[j].wt;
        if (value[U] != INT_MAX and value[U] + wt < value[V])
        {
            cout << "Graph has -VE edge cycle\n";
            return;
        }
    }

    for (int i = 1; i < V; ++i)
        cout << "U->V: " << parent[i] << "->" << i << "  Cost to reach " << parent[i] << "from source 0 = " << value[i] << "\n";
}

int main()
{
	cin>>V>>E;	//Enter no of Vertices and Edges
	vector<edge> edge(E);

	//Now input all E edges
	int src,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>src>>dst>>wt;
		edge[i].src = src;
		edge[i].dst = dst;
		edge[i].wt = wt;
	}

	bellmanFord(edge);	
	return 0;
}
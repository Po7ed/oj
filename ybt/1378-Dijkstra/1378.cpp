#include <iostream>
#include <vector>
#include <string>
#define INF 0x3f3f3f3f
using namespace std;

struct graph
{
	graph(int a):n(a){}
	int n;
	vector<vector<int>> edge;
};

int dist[100];
bool vis[100];
void dijkstra(graph G,int u)
{
	vis[u]=true;
	for(int i=1;i<=G.n;i++)
	{
		if(!vis[i])
			dist[i]=G.edge[u][i];
	}
	while(true)
	{
    	int mind=INF,t=-1;
		for(int j=1;j<=G.n;j++)
		{
    		if(!vis[j]&&dist[j]<mind)
			{
        		mind=dist[j];
        		t=j;
			}
		}
		if(t==-1)
    		return;
		vis[t]=true;
		for(int j=1;j<=G.n;j++)
		{
			if(G.edge[t][j]!=INF&&dist[j]>dist[t]+G.edge[t][j])
			{
				dist[j]=dist[t]+G.edge[t][j];
			}
		}
	}
	return;
}

int main()
{
	int n,u;
	scanf("%d\n%d",&n,&u);
	graph G(n);
	string s;
	vector<int> null={};
	G.edge.push_back(null);
	for(int i=1;i<=n;i++)
	{
		G.edge.push_back(null);
		G.edge.back().push_back(0);
		for(int j=1;j<=n;j++)
		{
			cin>>s;
			if(s=="-")
				G.edge.back().push_back(INF);
			else
				G.edge.back().push_back(stoi(s));
		}
	}
	dijkstra(G,u);
	for(int i=1;i<=n;i++)
	{
		if(i!=u)
			printf("(%d -> %d) = %d\n",u,i,dist[i]);
	}
	return 0;
}
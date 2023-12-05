#include <iostream>
#include <cstring>
// #define INF 0x3f3f3f3f
#define INF 1000000
#define MAXN 101
using namespace std;
struct graph
{
	int n,m;
	int edge[MAXN][MAXN];
	graph(int nn,int mm):n(nn),m(mm)
	{
		memset(edge,INF,sizeof(edge));
	}
};

int dijkstra(graph G,int u,int v)
{
	int m=-INF;
	int dist[MAXN];
	bool vis[MAXN];
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
		{
			for(int i=1;i<=G.n;i++)
			{
				m=max(dist[i],m);
			}
			return m;
		}
		vis[t]=true;
		for(int j=1;j<=G.n;j++)
		{
			if(G.edge[t][j]!=INF&&dist[j]>dist[t]+G.edge[t][j])
			{
				dist[j]=dist[t]+G.edge[t][j];
			}
		}
	}
	return 114514+1919810;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	graph G(n,m);
	int a,b,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&v);
		G.edge[a][b]=min(G.edge[a][b],v);
		G.edge[b][a]=G.edge[a][b];
	}
	int d=dijkstra(G,1,n);
	if(d>=INF)
		puts("-1");
	else
		printf("%d",d);
	return 0;
}

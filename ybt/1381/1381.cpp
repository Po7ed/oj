#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
#define MAXN 2001
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
			return dist[v];
		vis[t]=true;
		for(int j=1;j<=G.n;j++)
		{
			if(G.edge[t][j]!=INF&&dist[j]>dist[t]+G.edge[t][j])
			{
				dist[j]=dist[t]+G.edge[t][j];
			}
		}
	}
	return dist[v];
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

/*

DIJKSTRA(Edge,u)
  vis[u]=true
  for i=0 to Edge.length-1
    if !vis[i]
      dist[i]=Edge[u][i]
      if Edge[u][i]!=INF
        p[i]=u
      else
        p[i]=-1
  while true
    mind=INF
    t=-1
    for j=0 to Edge.length-1
      if !vis[j]&&dist[j]<mind
        mind=dist[j]
        t=j
    if t==-1
      return dist,p
    vis[t]=true
    for j=0 to Edge.length-1
      if Edge[t][j]!=INF&&dist[j]>dist[t]+Edge[t][j]
        dist[j]=dist[t]+Edge[t][j]
        p[j]=t

*/
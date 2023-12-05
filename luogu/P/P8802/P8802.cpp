#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int g[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&g[i]);
	}
	int u,v,w;
	int e[n+1][n+1];
	memset(e,INF,sizeof(e));
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u][v]=w+g[v];
		e[v][u]=w+g[u];
	}
	bool vis[n+1];
	memset(vis,false,sizeof(vis));
	vis[1]=true;
	int dist[n+1];
	for(int i=1;i<=n;i++)
	{
		dist[i]=e[1][i];
	}
	while(true)
	{
		int mind=INF,t=-1;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&dist[i]<mind)
			{
				mind=dist[i];
				t=i;
			}
		}
		if(t==-1)
		{
			break;
		}
		vis[t]=true;
		for(int i=1;i<=n;i++)
		{
			if(e[t][i]!=INF&&dist[i]>dist[t]+e[t][i])
			{
				dist[i]=dist[t]+e[t][i];
			}
		}
	}
	printf("%d",dist[n]-g[n]);
}
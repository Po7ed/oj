#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n,m,b,e;
	scanf("%d %d %d %d",&n,&m,&b,&e);
	int u,v,w;
	int Edge[n+1][n+1],dist[n+1];
	bool vis[n+1];
	memset(Edge,INF,sizeof(Edge));
	vis[b]=true;
	for(int i=0;i<=n;i++)
	{
		if(i!=b)
		{
			vis[i]=false;
		}
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		Edge[u][v]=w;
		Edge[v][u]=w;
	}
	for(int i=0;i<=n;i++)
	{
		if(!vis[i])
			dist[i]=Edge[b][i];
	}
	while(true)
	{
		int mind=INF,t=-1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dist[j]<mind)
			{
				mind=dist[j];
				t=j;
			}
		}
		if(t==-1)
			break;
		vis[t]=true;
		for(int j=1;j<=n;j++)
		{
			if(Edge[t][j]!=INF&&dist[j]>dist[t]+Edge[t][j])
			{
				dist[j]=dist[t]+Edge[t][j];
			}
		}
	}
	printf("%d",dist[e]);
	// system("pause");
	return 0;
}

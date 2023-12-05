#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v,w;
	int Edge[n+1][n+1];
	memset(Edge,INF,sizeof(Edge));
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		Edge[u][v]=w;
	}
	int dist[n+1];
	bool vis[n+1];
	for(int i=0;i<=n;i++)
	{
		dist[i]=Edge[1][i];
		vis[i]=false;
	}
	vis[1]=true;
	while(true)
	{
		int t=-1,mind=INF;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&dist[i]<mind)
			{
				mind=dist[i];
				t=i;
			}
		}
		if(t==-1)
			break;
		vis[t]=true;
		for(int i=1;i<=n;i++)
		{
			if(Edge[t][i]!=INF&&dist[i]>dist[t]+Edge[t][i])
			{
				dist[i]=dist[t]+Edge[t][i];
			}
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		ans+=dist[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			swap(Edge[i][j],Edge[j][i]);
		}
	}
	for(int i=0;i<=n;i++)
	{
		dist[i]=Edge[1][i];
		vis[i]=false;
	}
	vis[1]=true;
	while(true)
	{
		int t=-1,mind=INF;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&dist[i]<mind)
			{
				mind=dist[i];
				t=i;
			}
		}
		if(t==-1)
			break;
		vis[t]=true;
		for(int i=1;i<=n;i++)
		{
			if(Edge[t][i]!=INF&&dist[i]>dist[t]+Edge[t][i])
			{
				dist[i]=dist[t]+Edge[t][i];
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		ans+=dist[i];
	}
	printf("%d",ans);
	return 0;
}
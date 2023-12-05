#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][n+1];
	fill(*a,*a+(n+1)*(n+1),0x3f3f3f3f);
	int u,v,w;
	int dis[n+1][n+1];
	fill(*dis,*dis+(n+1)*(n+1),0x3f3f3f3f);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=w;
		dis[u][v]=w;
		a[v][u]=w;
		dis[v][u]=w;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		for(int j=1;j<=n;j++)
		{
			printf("%d ",dis[i][j]);
		}
		puts("");
	}
	return 0;
}
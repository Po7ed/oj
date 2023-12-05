#include <iostream>
using namespace std;

int main()
{
	int n,l,m;
	scanf("%d %d %d\n",&n,&l,&m);
	int f[l+1];
	for(int i=1;i<=l;i++)
	{
		scanf("%d",f+i);
	}
	int dis[n+1][n+1];
	fill(*dis,*dis+(n+1)*(n+1),0x3f3f3f3f);
	int u,v,w;
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=dis[u][v];
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
	int sum,ans=0,tmp=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=l;j++)
		{
			sum+=dis[i][f[j]];
		}
		if(tmp>sum)
		{
			tmp=sum;
			ans=i;
		}
	}
	printf("%d",ans);
	return 0;
}
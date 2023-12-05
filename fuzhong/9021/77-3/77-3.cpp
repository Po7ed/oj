#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	// freopen("floyd.in","r",stdin);
	// freopen("floyd.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][n+1],u,v,w;
	memset(a,0x3f3f3f3f,sizeof(a));
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	int dis[n+1][n+1];
	// memset(dis,0x3f3f3f3f,sizeof(dis));
	memcpy(dis,a,sizeof(dis));
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
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				printf("0 ");
			else
				printf("%d ",(dis[i][j]==0x3f3f3f3f?-1:dis[i][j]));
		}
		puts("");
	}
	return 0;
}
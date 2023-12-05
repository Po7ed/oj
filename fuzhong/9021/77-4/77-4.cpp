#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	int n,m,ans=1919810;
	scanf("%d %d",&n,&m);
	int a[n+1][n+1],u,v,w;
	// memset(a,114514,sizeof(a));
	fill(a[0],a[0]+n*n+2*n+1,1919810);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		if(u==v)
			continue;
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	int dis[n+1][n+1];
	// memset(dis,0x3f3f3f3f,sizeof(dis));
	memcpy(dis,a,sizeof(dis));
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		{
			for(int j=i+1;j<k;j++)
			{
				ans=min(ans,dis[i][j]+a[i][k]+a[k][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}

	}
	if(ans==1919810)
		puts("No solution.");
	else
		printf("%d",ans);
	return 0;
}
#include <iostream>
using namespace std;

typedef long long ll;

bool e[51][51][21];
ll dis[51][51];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u][v][0]=true;
	}
	fill(*dis,*dis+51*51,0x3f3f3f3f3f3f3f3f);
	for(int l=1;l<=20;l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					e[i][j][l]|=(e[i][k][l-1]&&e[k][j][l-1]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=20;k++)
			{
				if(e[i][j][k])
				{
					dis[i][j]=1ll;
					break;
				}
			}
		}
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
	printf("%lld",dis[1][n]);
	return 0;
}
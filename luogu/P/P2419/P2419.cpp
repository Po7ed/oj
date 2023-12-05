#include <iostream>
#include <bitset>
using namespace std;
bitset<114> reach[114];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		reach[u][v]=true;
	}
	for(int i=1;i<=n;i++)
	{
		reach[i][i]=true;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				reach[i][j]=reach[i][j]||(reach[i][k]&&reach[k][j]);
			}
		}
	}
	int ans=0,cnt;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			cnt+=(int)(reach[i][j]||reach[j][i]);
		}
		ans+=(int)(cnt==n);
	}
	printf("%d",ans);
	return 0;
}
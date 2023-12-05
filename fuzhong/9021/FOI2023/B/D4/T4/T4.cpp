#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1][n+1];
	bool vis[n+1];
	fill(vis,vis+(n+1),false);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=n;i>0;i--)
	{
		vis[a[1][i]]=true;
		for(int j=1;j<=n;j++)
		{
			if(!vis[a[a[1][i]][j]])
			{
				ans+=a[a[1][i]][j];
				break;
			}
		}
	}
	printf("%lld",ans+n*(n+1)/2-1);
	return 0;
}
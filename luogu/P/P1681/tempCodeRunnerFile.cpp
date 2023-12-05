#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if((i+j)&1)
			{
				a[i][j]=!a[i][j];
			}
		}
	}
	int dp[n+1][m+1],ans=-1;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
				ans=max(ans,dp[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=!a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
				ans=max(ans,dp[i][j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
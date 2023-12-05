#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int dp[n+1],dis[n+1][n+1];
	memset(dis,0,sizeof(dis));
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[n]=0;
	for(int i=1;i<n;i++)
	{
        for(int j=i+1;j<=n;j++)
		{
			scanf("%d",&dis[i][j]);
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			dp[i]=min(dp[i],dp[j]+dis[i][j]);
		}
	}
	printf("%d",dp[1]);
	return 0;
}

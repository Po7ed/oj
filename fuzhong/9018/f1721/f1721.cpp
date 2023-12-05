#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,W;
	scanf("%d",&n);
	int v[n+1],w[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	scanf("%d",&W);
	int dp[n+1][W+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(j-w[i]>=0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d",dp[n][W]);
	return 0;
}
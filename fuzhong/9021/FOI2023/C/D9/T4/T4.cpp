#include <iostream>
// #include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[2][n+1],s[2][n+1];
	s[0][0]=s[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a[0]+i);
		s[0][i]=s[0][i-1]+a[0][i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a[1]+i);
		s[1][i]=s[1][i-1]+a[1][i];
	}
	int dp[2][n+1][n+1];
	fill(**dp,**dp+(2)*(n+1)*(n+1),0x3f3f3f3f);
	for(int j=0;j<=n;j++)
	{
		dp[0][0][j]=dp[1][0][j]=0;
	}
	// dp[0][0][0]=0;
	// dp[1][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i/* &&i-j<=j/2 */;j++)
		{
			for(int opt=0;opt<2;opt++)
			{
				for(int k=0;k<=j/2;k++)
				{
					dp[opt][i][j]=min(dp[opt][i][j],dp[!opt][i-j][k]);
				}
				dp[opt][i][j]+=(s[opt][i]-s[opt][i-j]);
				printf("%d %d %d %d\n",opt,i,j,dp[opt][i][j]);
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int j=1;j<=n;j++)
	{
		for(int opt=0;opt<2;opt++)
		{
			ans=min(ans,dp[opt][n][j]);
		}
	}
	printf("%d",ans);
	return 0;
}
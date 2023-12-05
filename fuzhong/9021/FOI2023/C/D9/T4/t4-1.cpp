#include <iostream>
// #include <algorithm>
#include <map>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a/* [2][n+1] */,s[2][n+1];
	s[0][0]=s[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a/* [0]+i */);
		s[0][i]=s[0][i-1]+a/* [0][i] */;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a/* [1]+i */);
		s[1][i]=s[1][i-1]+a/* [1][i] */;
	}
	int dp[2][n+1][n+1];
	fill(**dp,**dp+(2)*(n+1)*(n+1),0x3f3f3f3f);
	for(int j=0;j<=n;j++)
	{
		dp[0][0][j]=dp[1][0][j]=0;
	}
	// dp[0][0][0]=0;
	// dp[1][0][0]=0;
	// int mi[2][n+1][n+1];
	// fill(**mi,**mi+(2)*(n+1)*(n+1),0x3f3f3f3f);
	/*  for(int i=0;i<=n;i++)
	{
		mi[0][i][0]=0x3f3f3f3f;
		mi[1][i][0]=0x3f3f3f3f;
	}  */
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n/* &&i-j<=j/2 */;j++)
		{
			for(int opt=0;opt<2;opt++)
			{				
				// dp[opt][i][j]=min(dp[opt][i][j],mi[!opt][i-j][j/2]);
				if(j<=i)
				dp[opt][i][j]=(i==j?0:dp[!opt][i-j][j/2])+(s[opt][i]-s[opt][i-j]);
				dp[opt][i][j]=min(dp[opt][i][j-1],dp[opt][i][j]);
				//printf("*%d %d %d %d %d %d\n",opt,i,j,dp[opt][1][0],dp[opt][1][1],dp[opt][1][2]);
				//  printf("",opt,i,j,dp[opt][i][j]);
				//  printf("",mi[opt][i][j]);
				
			}
		}
	}
	/* int ans=0x3f3f3f3f;
	for(int j=1;j<=n;j++)
	{
		for(int opt=0;opt<2;opt++)
		{
			ans=min(ans,dp[opt][n][j]);
		}
	}
	printf("%d",ans) */
	printf("%d",min(dp[0][n][n],dp[1][n][n]));
	return 0;
}
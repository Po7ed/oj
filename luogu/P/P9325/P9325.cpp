#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int dp[n+1][n+1];
	fill(*dp,*dp+(n+1)*(n+1),0);
	/* for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	} */
	#define r (l+i-1)
	for(int i=2;i<=n;i++)
	{
		for(int l=1;r<=n;l++)
		{
			dp[l][r]=dp[l+1][r-1]+abs(a[l]-a[r]);
		}
	}
	// #undef r
	/* for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
		}
	} */
	int ans;
	for(int i=1;i<=n;i++)
	{
		ans=0x3f3f3f3f;
		for(int l=1;r<=n;l++)
		{
			// for(int r=l+i-1;r<=n;r++)
			// {
				ans=min(ans,dp[l][r]);
			// }
		}
		printf("%d ",ans);
	}
	return 0;
}
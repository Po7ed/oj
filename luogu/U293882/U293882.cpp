#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int dp[n+1][m+1];
	fill(dp[0],dp[0]+(n+1)*(m+1),0);
	int ans=-1;
	dp[1][0]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=(a[i]?dp[i-1][0]+1:0);
		ans=max(ans,dp[i][0]);
	}
	for(int j=1;j<=m;j++)
	{
		dp[1][j]=j+a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i])
				dp[i][j]=dp[i-1][j]+1;
			else
				dp[i][j]=dp[i-1][j-1]+1;
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",min(ans,n));
	return 0;
}

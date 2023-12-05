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
	fill(*dp,*dp+(n+1)*(m+1),0);
	/* for(int i=1;i<=n;i++)
	{
		dp[]
	} */
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j]+(j-a[i]>=0?dp[i-1][j-a[i]]:0);
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}
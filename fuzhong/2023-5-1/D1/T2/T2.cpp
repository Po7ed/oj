#include <iostream>
using namespace std;

int main()
{
	freopen("brother.in","r",stdin);
	freopen("brother.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=0;
	int dp[n+1][n+1];
	fill(dp[0],dp[0]+(n+1)*(n+1),0);
	dp[1][1]=1;
	for(int i=1;i<=n;i++)//country
	{
		for(int j=1;j<n;j++)//day
		{
			for(int k=i+1;k<=min(n,i+a[i]);k++)
			{
				dp[k][j+1]+=dp[i][j];
			}
		}
	}
	for(int j=1;j<=n;j++)
	{
		ans+=(dp[n][j]*dp[n][j]%998244353);
		ans%=998244353;
	}
	printf("%d",ans);
	return 0;
}
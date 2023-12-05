#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sum+=a[i];
	}
	int dp[n+1][sum+1];
	fill(*dp,*dp+(n+1)*(sum+1),-0x3f3f3f3f);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j+a[i]]);
			if(j>=a[i])
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+a[i]);
			}
			else
			{
				dp[i][j]=max(dp[i][j],dp[i-1][a[i]-j]+j);
			}
		}
	}
	if(dp[n][0]>0)
	{
		printf("%d",dp[n][0]);
	}
	else
	{
		puts("Impossible");
	}
	return 0;
}
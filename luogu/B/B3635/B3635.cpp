#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int dp[n+1];
	fill(dp,dp+(n+1),0x3f3f3f3f);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=1)
		{
			dp[i]=min(dp[i],dp[i-1]+1);
		}
		if(i>=5)
		{
			dp[i]=min(dp[i],dp[i-5]+1);
		}
		if(i>=11)
		{
			dp[i]=min(dp[i],dp[i-11]+1);
		}
	}
	printf("%d",dp[n]);
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int dp[n+1];
	fill(dp,dp+n+1,0);
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
			else
			{
				dp[i]=max(dp[i],1);
			}
		}
		// printf("%d:%d",i,dp[i]);
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
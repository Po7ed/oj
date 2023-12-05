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
	int dp[n+1],ans=1000,cnt1=0,cnt2=0;
	for(int k=1;k<=n;k++)
	{
		fill(dp,dp+(n+1),0);
		cnt1=0;
		for(int i=1;i<=k;i++)
		{
			dp[i]=1;
			for(int j=1;j<=i;j++)
			{
				if(a[i]>a[j])
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			cnt1=max(cnt1,dp[i]);
		}
		// cnt=dp[k];
		cnt2=0;
		for(int i=k;i<=n;i++)
		{
			dp[i]=1;
			for(int j=k;j<=i;j++)
			{
				if(a[i]<a[j])
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			cnt2=max(cnt2,dp[i]);
		}
		// cnt+=dp[n];
		ans=min(ans,n-cnt1-cnt2);
	}
	printf("%d",ans+1);
	return 0;
}
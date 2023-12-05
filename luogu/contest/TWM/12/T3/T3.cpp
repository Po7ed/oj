#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],dp[n+1];
	dp[1]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=-1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=a[i-1])
			dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
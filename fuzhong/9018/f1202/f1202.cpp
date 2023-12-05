#include <iostream>
#include <string.h>
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
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	int m=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[i]>=a[j])dp[i]=max(dp[j]+1,dp[i]);
			else dp[i]=max(dp[i],1);
		}
		m=max(m,dp[i]);
	}
	printf("%d",m);
	return 0;
}
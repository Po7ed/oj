#include <iostream>
using namespace std;

const int mod=(1e6+7);

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int dp[m+1];
	fill(dp,dp+(m+1),0);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>0;j--)
		{
			// for(int k=min(a[i],j);k>=0;k--)
			for(int k=1;k<=a[i]&&k<=j;k++)
			{
				dp[j]+=dp[j-k];
				dp[j]%=mod;
			}
		}
	}
	printf("%d",dp[m]%mod);
	return 0;
}
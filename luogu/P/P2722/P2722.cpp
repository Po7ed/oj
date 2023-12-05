#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	int v[n+1],w[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&v[i],&w[i]);
	}
	int dp[m+1];
	fill(dp,dp+(m+1),0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[j]=max(dp[j],(j-w[i]>=0?dp[j-w[i]]+v[i]:-0x3f3f3f3f));
		}
	}
	printf("%d",dp[m]);
	return 0;
}
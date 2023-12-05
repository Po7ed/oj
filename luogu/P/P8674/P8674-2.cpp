#include <iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int dp[n],maxdp=-0x3f3f3f3f;
	// dp[0]=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=i;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[j]=min(dp[j-1]+1,(j-k<0?dp[j-k+n]+1:dp[j-k]+1));
		}
	}
	for(int i=0;i<n;i++)
	{
		maxdp=max(maxdp,dp[i]);
	}
	printf("%d",maxdp);
	return 0;
}
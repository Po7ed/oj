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
	for(int i=1;i<n;i++)
	{
		dp[i]=min(dp[i],(i-k<0?dp[i-k+n]+1:dp[i-k]+1));
		maxdp=max(maxdp,dp[i]);
	}
	printf("%d",maxdp);
	return 0;
}
/*
10 5
*/
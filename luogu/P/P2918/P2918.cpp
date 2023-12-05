#include <iostream>
using namespace std;

int v[114],w[114],dp[100114];

int main()
{
	int n,h;
	scanf("%d %d",&n,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",v+i,w+i);
	}
	fill(dp,dp+100114,0x3f3f3f3f);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=v[i];j<=100114;j++)
		{
			dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
			// if(j<=100)
			// printf("%d %d:%d\n",i,j,dp[j]);
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=h;i<100114;i++)
	{
		ans=min(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
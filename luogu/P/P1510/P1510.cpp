#include <iostream>
using namespace std;
int main()
{
	int m,n,c;
	scanf("%d %d %d",&m,&n,&c);
	int v[n+1],w[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",v+i,w+i);
	}
	int dp[c+1];
	fill(dp,dp+(c+1),0);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j+w[i]<=c;j++)
		{
			dp[j]=max(dp[j],dp[j+w[i]]+v[i]);
			// printf("%d %d:%d\n",i,j,dp[j]);
		}
	}
	for(int j=c;j>=0;j--)
	{
		if(dp[j]>=m)
		{
			printf("%d\n",j);
			return 0;
		}
	}
	puts("Impossible");
	return 0;
}
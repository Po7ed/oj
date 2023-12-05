#include <iostream>
using namespace std;
int f[501],v[501],w[501];
int dp[501][501];
int main()
{
	int V,W,n;
	scanf("%d %d\n%d",&V,&W,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",f+i,v+i,w+i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=V;j>=v[i];j--)
		{
			for(int k=W;k>=w[i];k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-v[i]][k-w[i]]+f[i]);
			}
		}
	}
	printf("%d",dp[V][W]);
	return 0;
}
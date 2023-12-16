#include <iostream>
using namespace std;

constexpr int N=1145;

int dp[N][N],v[N];
int n,m,o;

int main()
{
	scanf("%d %d %d",&n,&m,&o);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",v+i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i,o);j;j--)
		{
			for(int k=v[i];k<=m;k++)
			{
				dp[j][k]=max(dp[j][k],dp[j-1][k-v[i]]+v[i]);
			}
		}
	}
	int ans=0;
	for(int oo=1;oo<=o;oo++)
	{
		ans=max(ans,dp[oo][m]);
	}
	printf("%d",ans);
	return 0;
}
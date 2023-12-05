#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int dp[n+1][m+1];
	fill(*dp,*dp+(n+1)*(m+1),-0x3f3f3f3f);
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
		dp[0][i]=0;
	}
	dp[1][1]=0;
	vector<int> ans[n+1][m+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// dp[i][j]=-0x3f3f3f3f;
			for(int k=1;k<j;k++)
			{
				if(dp[i][j]<dp[i-1][k])
				{
					dp[i][j]=dp[i-1][k];
					ans[i][j]=ans[i-1][k];
				}
			}
			dp[i][j]+=a[i][j];
			ans[i][j].push_back(j);
		}
	}
	vector<int> res;
	int ma=-0x3f3f3f3f;
	for(int i=n;i<=m;i++)
	{
		if(ma<dp[n][i])
		{
			ma=dp[n][i];
			res=ans[n][i];
		}
	}
	printf("%d\n",ma);
	for(int t:res)
	{
		printf("%d ",t);
	}
	return 0;
}
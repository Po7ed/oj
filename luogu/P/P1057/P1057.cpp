#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][j]=(i==1?dp[n][j-1]:dp[i-1][j-1])+(i==n?dp[1][j-1]:dp[i+1][j-1]);
		}
	}
	printf("%d",dp[1][m]);
}
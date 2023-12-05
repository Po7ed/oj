#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	int n=s.length(),m=t.length()/* ,ma=max(n,m) */;
	int dp[n+1][m+1];
	fill(*dp,*dp+(n+1)*(m+1),0);
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=i;
	}
	for(int i=1;i<=m;i++)
	{
		dp[0][i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			}
		}
	}
	// printf("%d",ma-dp[n][m]);
	printf("%d",dp[n][m]);
	return 0;
}
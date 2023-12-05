#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d",&n);
	m=(n+1)*(n)/2;
	if(m&1)
	{
		puts("0");
		return 0;
	}
	int dp[n+1][m/2+1];
	fill(*dp,*dp+(n+1)*(m/2),0x3f3f3f3f);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=m/2;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
		}
	}
	printf("%d",dp[n][m/2]);
	return 0;
}
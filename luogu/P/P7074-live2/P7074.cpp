#include <iostream>
using namespace std;

int a[1145][1145],s[1145][1145],dp[1145][1145];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			s[i][j]=s[i-1][j]+a[i][j];
		}
	}
	fill(*dp,*dp+(1145*1145),-0x3f3f3f3f);
	dp[0][1]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][k]+s[max(j,k)][i]-s[min(j,k)-1][i]);
			}
		}
	}
	printf("%d",dp[m][n]);
	return 0;
}
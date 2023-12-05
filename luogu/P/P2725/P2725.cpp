#include <iostream>
#include <bitset>
using namespace std;

int dp[2000114],ans;
int a[51];
int m,n;

int main()
{
	scanf("%d %d",&m,&n);
	int ma=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		ma=max(ma,a[i]);
	}
	fill(dp,dp+2000114,0x3f3f3f3f);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j<=m*ma;j++)
		{
			dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
	for(int i=0;i<=m*ma+1;i++)
	{
		if(dp[i]>m)
		{
			printf("%d",i-1);
			return 0;
		}
	}
	return 0;
}
#include <iostream>
using namespace std;
int n,a[2114],s[2114],dp[2114][2114];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=a[i];
	}
	#define j (i+l-1)
	for(int l=2;l<=n;l++)
	{
		for(int i=1;j<=n;i++)
		{
			dp[i][j]=max(dp[i+1][j],dp[i][j-1])+s[j]-s[i-1];
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}
#include <iostream>
using namespace std;

int a[2511],dp[2511];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	a[0]=m;
	int t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[i]=a[i-1]+t;
	}
	// puts("");
	for(int i=0;i<=n;i++)
	{
		dp[i]=a[i];
		// printf("%d %d\n",i,dp[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			dp[j]=min(dp[j],dp[j-i]+a[i]+m);
		// printf("%d %d %d\n",i,j,dp[j]);
		}
	}
	printf("%d",dp[n]);
	return 0;
}
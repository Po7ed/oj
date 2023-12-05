#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],b[n+1],id[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		id[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[i]=id[b[i]];
		// printf("*%d*",b[i]);
	}
	// for(int i=1;i<=n;i++)
	int dp[n+1],cnt=1;
	fill(dp,dp+(n+1),0);
	dp[1]=b[1];
	for(int i=2;i<=n;i++)
	{
		if(b[i]>dp[cnt])
		{
			dp[++cnt]=b[i];
		}
		else
		{
			*upper_bound(dp+1,dp+cnt+1,b[i])=b[i];
		}
	}
	printf("%d",cnt);
	return 0;
}
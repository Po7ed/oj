#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	long long a[n+1][m+1]/* ,s[n+1][m+1] */;
	// fill(*s,*s+(n+1)*(m+1),0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
			// s[i][j]=s[i-1][j]+a[i][j];
		}
	}
	long long dp[n+2][m+2][3]/* ,f[n+1][m+1] */;
	fill(**dp,**dp+(n+2)*(m+2)*3,-0x3f3f3f3f3f3f3f3f);
	#define up 0
	#define left 1
	#define down 2
	dp[1][1][up]=a[1][1];
	dp[1][1][left]=a[1][1];
	for(int i=2;i<=n;i++)
	{
		dp[i][1][up]=dp[i-1][1][up]+a[i][1];
	}
	for(int j=2;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][j][left]=max(dp[i][j-1][left],max(dp[i][j-1][up],dp[i][j-1][down]))+a[i][j];
			// if(f[i-1][j]<i)
				// dp[i][j]=dp[i-1][j]+a[i][j];
			/* for(int k=1;k<=n;k++)
			{
				#define l min(i,k)
				#define r max(i,k)
				if(dp[i][j]<(dp[k][j-1]-s[l-1][j]+s[r][j]))
				{
					dp[i][j]=(dp[k][j-1]-s[l-1][j]+s[r][j]);
					// f[i][j]=k;
				}
			} */
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][j][up]=max(dp[i-1][j][up],dp[i-1][j][left])+a[i][j];
		}
		for(int i=n;i>0;i--)
		{
			dp[i][j][down]=max(dp[i+1][j][left],dp[i+1][j][down])+a[i][j];
		}
	}
	printf("%lld",max(dp[n][m][up],dp[n][m][left]));
	return 0;
}
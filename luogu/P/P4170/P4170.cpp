#include <iostream>
#include <cstring>
using namespace std;

const int mn=55;

int dp[mn][mn];
char a[mn];

int main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	fill(*dp,*dp+mn*mn,0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i][j]=0;
		}
		dp[i][i]=1;
	}
	#define j (i+l-1)
	for(int l=2;l<=n;l++)
	{
		for(int i=1;j<=n;i++)
		{
			// if(a[i]==a[j])
			// {
				// dp[i][j]=dp[i+1][j-1];
			// }
			if(a[i]==a[j])
			{
				dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
				/* dp[i][j]=dp[i+1][j-1]+1;
				int last=i,sum=0;
				for(int k=i+1;k<=j;k++)
				{
					if(a[i]==a[k])
					{
						sum+=dp[last+1][k-1];
						last=k;
					}
				}
				dp[i][j]=min(dp[i][j],sum+1); */
			}
			// else
			// {
				for(int k=i;k<j;k++)
				{
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			// }
			#ifndef ONLINE_JUDGE
			printf("%d %d:%d\n",i,j,dp[i][j]);
			#endif
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}
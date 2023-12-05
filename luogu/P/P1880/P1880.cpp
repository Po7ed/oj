#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[2*n+1],s[2*n+1];
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i+n]=a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=n+1;i<=2*n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int dp[2*n+1][2*n+1],dp_[2*n+1][2*n+1];// min,_max
	for(int i=1;i<=2*n;i++)
	{
		dp[i][i]=0;
		dp_[i][i]=0;
	}
	#define j (i+l-1)
	for(int l=2;l<=n;l++)
	{
		for(int i=1;j<=2*n;i++)
		{
			dp[i][j]=0x3f3f3f3f;
			dp_[i][j]=-0x3f3f3f3f;
			for(int k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
				dp_[i][j]=max(dp_[i][j],dp_[i][k]+dp_[k+1][j]+s[j]-s[i-1]);
				/* if(i==1&&j==3)
				{
					printf("%d %d %d %d\n",k,dp[i][k],dp[k+1][j],s[j]-s[i-1]);
				} */
			}
		}
	}
	int mi=0x3f3f3f3f,ma=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		mi=min(mi,dp[i][i+n-1]);
		ma=max(ma,dp_[i][i+n-1]);
	}
	printf("%d %d",mi,ma);
	// printf("\n%d",dp[2][3]);
	return 0;
}
#include <iostream>
using namespace std;

const int mn=114;
int dp[mn*2][mn*2],a[mn*2];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i+n]=a[i];
	}
	#define j (i+l-1)
	for(int l=2;l<=n;l++)
	{
		for(int i=1;j<=2*n;i++)
		{
			for(int k=i;k<j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}
	}
	int l=n,ans=-0x3f3f3f3f;
	for(int i=1;j<=2*n;i++)
	{
		ans=max(ans,dp[i][j]);
	}
	printf("%d",ans);
	return 0;
}
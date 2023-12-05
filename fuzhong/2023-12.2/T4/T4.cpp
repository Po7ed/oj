#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N=5114,L=15,INF=0x3f3f3f3f;

int dp[N][2][N],a[N],b[N],sa[N],sb[N];
int n;

int main()
{
	// freopen("school.in","r",stdin);
	// freopen("school.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i), sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=n;i++)scanf("%d",b+i), sb[i]=sb[i-1]+b[i];
	fill(**dp,**dp+(N*N*2),INF);
	for(int i=0;i<=n;i++)
	{
		dp[0][0][i]=dp[0][1][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=i;k++)
		{
			// for(int l=0;l<=(k>>1);l++)
			// {
				// if(dp[i-k][1][l]>=5e8)break;
				// printf(":%d\n",dp[i-k][1][l]);
				dp[i][0][k]=min(dp[i][0][k],dp[i-k][1][min(k>>1,i-k)]);
			// }
			dp[i][0][k]+=(sa[i]-sa[i-k]);
			// printf("%d %d:%d ",i,k,dp[i][0][k]);
			dp[i][0][k]=min(dp[i][0][k],dp[i][0][k-1]);
			// for(int l=0;l<=(k>>1);l++)
			// {
				// if(dp[i-k][0][l]>=5e8)break;
				// printf(":%d\n",dp[i-k][0][l]);
				dp[i][1][k]=min(dp[i][1][k],dp[i-k][0][min(k>>1,i-k)]);
			// }
			dp[i][1][k]+=(sb[i]-sb[i-k]);
			// printf("%d\n",dp[i][1][k]);
			dp[i][1][k]=min(dp[i][1][k],dp[i][1][k-1]);
		}
	}
	// int ans=INF;
	// for(int k=1;k<=n;k++)
	// {
		// ans=min({ans,dp[n][0][k],dp[n][1][k]});
	// }
	printf("%d",min(dp[n][0][n],dp[n][1][n]));
	return 0;
}
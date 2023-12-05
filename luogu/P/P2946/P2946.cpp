#include <iostream>
using namespace std;
int a[2114],dp[2][1145];
const int mod=1e8;
int main()
{
	int n,k/* ,sum=0 */;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		// sum+=a[i];
	}
	dp[0][0]=dp[1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j>=0;j--)
		{
			dp[(i&1)][j]+=dp[(!(i&1))][(j-a[i]+k*1145)%k];
			dp[(i&1)][j]%=mod;
			// printf("%d %d:%d\n",i,j,dp[(i&1)][j]);
		}
		for(int j=0;j<=k;j++)
		{
			dp[(!(i&1))][j]=dp[(i&1)][j];
		}
		// puts("");
	}
	printf("%d",(dp[0][0]-1+mod)%mod);
	return 0;
}
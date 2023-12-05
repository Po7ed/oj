#include <iostream>
using namespace std;

typedef long long ll;
const int N=1145;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m;
ll a[N][N],dp[N][N][3];
#define dw 0
#define le 1
#define ri 2

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		// a[i][0]=a[i][m+1]=INF;
		dp[i][0][dw]=dp[i][0][le]=dp[i][0][ri]=
		dp[i][m+1][dw]=dp[i][m+1][le]=dp[i][m+1][ri]=INF;
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=n;~i;i--)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j][dw]=min(min(dp[i+1][j][le],dp[i+1][j][ri]),dp[i+1][j][dw])+a[i][j];
			dp[i][j][le]=dp[i][j-1][le]+a[i][j];
		}
		for(int j=m;j;j--)
		{
			dp[i][j][ri]=min(min(dp[i][j+1][dw],dp[i][j+1][ri])+a[i][j],dp[i][j+1][le]);
		}
		for(int j=1;j<=m;j++)
		{
			dp[i][j][le]=min(dp[i][j][le],dp[i][j-1][ri]);
		}
	}
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int j=1;j<=m;j++)
	{
		ans=min(ans,dp[0][j][dw]);
	}
	printf("%lld",ans);
	return 0;
}
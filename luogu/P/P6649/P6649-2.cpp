#include <iostream>
using namespace std;

typedef long long ll;
const int N=1145;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m;
ll a[N][N],dp[N][N],pre[N],suf[N];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=n;i;i--)
	{
		fill(pre,pre+N,INF);
		fill(suf,suf+N,INF);
		for(int j=1;j<=m;j++)
		{
			pre[j]=min(0ll,pre[j-1])+a[i][j];
		}
		for(int j=m;j;j--)
		{
			suf[j]=min(suf[j+1],dp[i+1][j])+a[i][j];
		}
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=min(pre[j]+suf[j]-a[i][j],suf[j]);
		}
	}
	ll ans=INF;
	for(int j=1;j<=m;j++)
	{
		ans=min(ans,dp[1][j]);
	}
	printf("%lld",ans);
	return 0;
}
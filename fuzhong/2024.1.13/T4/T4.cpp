#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=1145141;
constexpr ll INF=1e18;
int n,k;

ll c[N],v[N],dp[N],j[N];

int main()
{
	// freopen("poker.in","r",stdin);
	// freopen("poker.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",c+i),j[c[i]]=-INF;
	for(int i=1;i<=n;i++)scanf("%lld",v+i),v[i]+=v[i-1];
	for(int i=1;i<=n;i++)
	{
		// dp[i]=dp[i-1];
		// for(int j=1;j<i;j++)if(c[j]==c[i])
		// {
		// 	dp[i]=max(dp[i],dp[j-1]+(v[i]-v[j-1]));
		// }
		//! dp[i]=max(dp[i],(dp[j-1]-v[j-1])+v[i]));
		dp[i]=max(dp[i-1],j[c[i]]+v[i]);
		j[c[i]]=max(j[c[i]],dp[i-1]-v[i-1]);
	}
	printf("%lld",dp[n]);
	return 0;
}
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

constexpr int N=13,P=1e8,M=1<<N;
int n,m,k;
bitset<N> a[N];
int dp[N][M];

int main()
{
	scanf("%d %d",&n,&m);
	k=1<<m;
	for(int i=1,o;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&o);
			a[i][j]=bool(o);
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int S=0;S<k;S++)if((S&(S>>1))==0)
		{
			for(int j=0;j<m;j++)
				if(((S>>j)&1)&&!a[i][j])goto con;
			for(int T=0;T<k;T++)if((T&(T>>1))==0&&((S&T)==0))
				(dp[i][S]+=dp[i-1][T])%=P;
			con:;
			// printf("%d %d:%d\n",i,S,dp[i][S]);
		}
	}
	int ans=0;
	for(int S=0;S<k;S++)
		(ans+=dp[n][S])%=P;
	printf("%d",ans);
	return 0;
}
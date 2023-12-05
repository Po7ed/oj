#include <iostream>
#include <bitset>
using namespace std;

constexpr int N=114,M=21,K=25,S=1<<M,INF=0x3f3f3f3f;

int tst[N][3],gl[N];
int dp[S];
// bitset<N> hav;
int n,m,k;// m kinds,n packs,k each.

#define ALL ((1<<m)-1)
#define to(x) (1<<(x-1))

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		gl[i]=ALL;
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&tst[i][j]);
			// hav[tst[i][j]]=true;
			gl[i]=gl[i]&(ALL-to(tst[i][j]));
		}
	}
	int tmp;
	for(int i=1;i<=ALL;i++)
	{
		dp[i]=INF;
		for(int j=1;j<=n;j++)
		{
			tmp=i&gl[j];
			dp[i]=min(dp[i],dp[tmp]+1);
		}
		// printf("%d %d\n",i,dp[i]);
	}
	printf("%d",dp[ALL]==INF?-1:dp[ALL]);
	return 0;
}
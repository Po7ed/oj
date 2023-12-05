#include <iostream>
using namespace std;

typedef long long ll;

ll a[1145][1145],dp[1145][1145],fu[1145][1145],fd[1145][1145];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	fill(*dp,*dp+(1145*1145),-0x3f3f3f3f3f3f3f3fll);
	fill(*fu,*fu+(1145*1145),-0x3f3f3f3f3f3f3f3fll);
	fill(*fd,*fd+(1145*1145),-0x3f3f3f3f3f3f3f3fll);
	dp[1][0]=fu[1][0]=fd[1][0]=0ll;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			fu[i][j]=max(fu[i-1][j],dp[i][j-1])+a[i][j];
		}
		for(int i=n;i>0;i--)
		{
			fd[i][j]=max(fd[i+1][j],dp[i][j-1])+a[i][j];
			dp[i][j]=max(fu[i][j],fd[i][j]);
		}
	}
	printf("%lld",dp[n][m]);
	return 0;
}
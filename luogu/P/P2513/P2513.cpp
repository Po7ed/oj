#include <iostream>
using namespace std;

const int N=1145,MOD=10000;
int dp[N][N],s[N][N],n,k;

int main()
{
	scanf("%d %d",&n,&k);
	dp[1][0]=1;
	for(int j=0;j<=k;j++)
	{
		s[1][j]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j]=(s[i-1][j]-(j>=i?s[i-1][j-i]:0)+MOD)%MOD;
			s[i][j]=((j>0?s[i][j-1]:0)+dp[i][j])%MOD;
		}
	}
	printf("%d",(dp[n][k]+MOD)%MOD);
	return 0;
}
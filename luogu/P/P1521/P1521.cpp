#include <iostream>
using namespace std;

const int N=114,MOD=10000;
int dp[N][N*(N-1)/2],n,k;

int main()
{
	scanf("%d %d",&n,&k);
	dp[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int k=max(0,j-i+1);k<=j;k++)
			{
				dp[i][j]+=dp[i-1][k];
			}
			dp[i][j]%=MOD;
		}
	}
	printf("%d",dp[n][k]);
	return 0;
}
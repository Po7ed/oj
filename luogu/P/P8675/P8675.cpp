#include <iostream>
using namespace std;

const int M=114,mod=1e9+7;

int unl[M][M],dp[M][M][M],s[M][M];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char c;
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c;
			unl[i][j]=unl[i][j-1]+(c=='X');
		}
	}
	int ans=1;
	for(int j=1;j<=m;j++)
	{
		for(int k=j;k<=m;k++)
		{
			dp[1][j][k]=(unl[1][j-1]==unl[1][k]);
			ans+=dp[1][j][k];
			ans%=mod;
		}
	}
	for(int i=2;i<=n;i++)
	{

		for(int j=1;j<=m;j++)
		{
			for(int k=j;k<=m;k++)
			{
				s[j][k]=(((s[j-1][k]+s[j][k-1])%mod-s[j-1][k-1])%mod+dp[i-1][j][k])%mod;
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=j;k<=m;k++)
			{
				if(unl[i][j-1]==unl[i][k])
				{
					dp[i][j][k]=(s[j][n]-s[j][k-1])%mod;//sum[j][m]-sum[0][m]-sum[j][k-1]+sum[0][k-1]
					#ifndef ONLINE_JUDGE
					printf("%d %d %d:ok by %d-%d\n",i,j,k,s[j][n],s[j][k-1]);
					#endif
					ans+=dp[i][j][k];
					ans%=mod;
				}
				#ifndef ONLINE_JUDGE
				printf("%d %d %d:%d\n",i,j,k,dp[i][j][k]);
				#endif
			}
		}
	}
	printf("%d",(ans%mod+mod)%mod);
	return 0;
}
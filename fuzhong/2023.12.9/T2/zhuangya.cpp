#include <iostream>
using namespace std;

constexpr int N=514,C=30;
int n,m;
char s[N][N];
int cost[N][C][C],dp[N][C][C];

int main()
{
	freopen("draw.in","r",stdin);
	freopen("draw.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("\n%s",s[i]+1);
		for(char a=1;a<=26;a++)
			for(char b=1;b<=26;b++)if(a!=b)
				for(int j=1;j<=m;j++)
					cost[i][a][b]+=(s[i][j]!=((j&1)?a:b)+'a'-1);
	}
	fill(**dp+C*C,**dp+N*C*C,0x3f3f3f3f);
	for(int i=1;i<=n;i++)
		for(char c=1;c<=26;c++)
			for(char d=1;d<=26;d++)if(c!=d)
				for(char a=1;a<=26;a++)if(a!=c)
					for(char b=1;b<=26;b++)if(b!=d&&a!=b)
						dp[i][a][b]=min(dp[i][a][b],dp[i-1][c][d]+cost[i][a][b]);
	int ans=0x3f3f3f3f;
	for(char a=1;a<=26;a++)
		for(char b=1;b<=26;b++)if(a!=b)
			ans=min(ans,dp[n][a][b]);
	printf("%d",ans);
	return 0;
}
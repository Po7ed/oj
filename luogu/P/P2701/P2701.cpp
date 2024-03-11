#include <iostream>
using std::max;
using std::min;
constexpr int N=1145;
int n,m;
int a[N][N];
int dp[N][N],ans=-1;

int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	while(m--)scanf("%d %d",&x,&y),a[x][y]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!a[i][j])
			{
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
				ans=max(ans,dp[i][j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
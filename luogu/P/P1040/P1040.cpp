#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int N=35;
ll dp[N][N];
int pre[N][N];
ll val[N];

void dfs(int x,int y)
{
	#ifndef ONLINE_JUDGE
	printf(":%d %d\n",x,y);
	system("pause>nul");
	#endif
	if(x>y)
	{
		return;
	}
	if(x==y)
	{
		printf("%d ",x);
		return;
	}
	printf("%d ",pre[x][y]);
	dfs(x,pre[x][y]-1);
	dfs(pre[x][y]+1,y);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",val+i);
		dp[i][i]=val[i];
		dp[i][i-1]=1;
	}
	// val[0]=1;
	#define j (i+l-1)
	for(int l=2;l<=n;l++)
	{
		for(int i=1;j<=n;i++)
		{
			dp[i][j]=-1;
			for(int k=i;k<j;k++)
			{
				if(dp[i][j]<dp[i][k-1]*dp[k+1][j]+val[k])
				{
					dp[i][j]=dp[i][k-1]*dp[k+1][j]+val[k];
					pre[i][j]=k;
				}
			}
		}
	}
	printf("%lld",dp[1][n]);
	dfs(1,n);
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
int f,dp[1145][1145];
vector<int> e[1145];

void dfs(int now)
{
	for(int to:e[now])
	{
		dfs(to);
		for(int j=m+1;j>=1;j--)
		{
			for(int k=0;k<j;k++)
			{
				dp[now][j]=max(dp[now][j],dp[to][k]+dp[now][j-k]);
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&f,&dp[i][1]);
		e[f].push_back(i);
	}
	dfs(0);
	printf("%d",dp[0][m+1]);
	return 0;
}
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr int N=11451;
int n;
vector<int> e[N];

int dp[N][3];// 0:son 1:me 2:fa
bitset<N> lev;

void dfs(int u=1,int f=0)
{
	for(int v:e[u])if(v!=f)
	{
		dfs(v,u);
		dp[u][2]+=min(dp[v][1],dp[v][0]);
		dp[u][1]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
	}
	dp[u][1]++;
	dp[u][0]=0x3f3f3f3f;
	for(int v:e[u])if(v!=f)
	{
		dp[u][0]=min(dp[u][0],dp[u][2]-min(dp[v][1],dp[v][0])+dp[v][1]);
	}
	// printf("%d:%d %d %d\n",u,dp[u][0],dp[u][1],dp[u][2]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs();
	printf("%d",min(dp[1][0],dp[1][1]));
	return 0;
}
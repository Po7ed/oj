#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr int N=1145;
int n;
vector<int> e[N];

int dp[N];
inline bool cmp(int x,int y)
{
	return dp[x]>dp[y];
}

void dfs(int u,int f=0)
{
	// if(e[u].empty())
	// {
	// 	dp[u]=1;
	// 	return;
	// }
	for(int v:e[u])
	{
		if(v==f)continue;
		dfs(v,u);
	}
	sort(e[u].begin(),e[u].end(),cmp);
	int cnt=1;
	for(int v:e[u])
	{
		if(v==f)continue;
		dp[u]=max(dp[u],dp[v]+(cnt++));
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=2,f;i<=n;i++)
	{
		scanf("%d",&f);
		e[i].push_back(f);
		e[f].push_back(i);
	}
	vector<int> ans;
	int mi=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		fill(dp,dp+N,1);
		dfs(i);
		if(dp[i]==mi)
		{
			ans.push_back(i);
		}
		else if(dp[i]<mi)
		{
			mi=dp[i];
			ans.clear();
			ans.push_back(i);
		}
	}
	printf("%d\n",mi);
	for(int t:ans)
	{
		printf("%d ",t);
	}
	return 0;
}
#include <iostream>
#include <vector>

constexpr int N=114514;
using std::vector;
vector<int> e[N];
int n;
int p[N];

int lf[N],cnt[N];
void dfs(int u=1,int f=0)
{
	if(u!=1&&e[u].size()==1)
	{
		lf[u]=1;
		return;
	}
	for(int v:e[u])if(v!=f)
	{
		dfs(v,u);
		lf[u]+=lf[v];
	}
}

int dp[N];

void dfs_(int u=1,int f=0)
{
	if(u!=1&&e[u].size()==1)
	{
		if(cnt[u])dp[u]=1;
		return;
	}
	int rem=0;
	for(int v:e[u])if(v!=f)
	{
		dfs_(v,u);
		rem+=(lf[v]-dp[v]);
		dp[u]+=dp[v];
	}
	dp[u]+=std::min(rem,cnt[u]);
	// if(rem>=cnt[u])
	// {
	// 	dp[u]+=cnt[u];
	// }
	// else
	// {
	// 	dp[u]+=rem;
	// }
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs();
	for(int i=1;i<=lf[1];i++)
	{
		cnt[p[i]]++;
	}
	dfs_();
	printf("%d",dp[1]);
	return 0;
}
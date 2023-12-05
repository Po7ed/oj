#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N=1145141;

vector<int> e[N];

ll dp[N],dp_[N],sigdp_,sigdp;
int siz[N];
void init(int u=1,int f=0)
{
	int res=0;
	for(int v:e[u])
	{
		if(v==f)continue;
		init(v,u);
		res+=siz[v];
	}
	siz[u]=res+1;
}
void dfs(int u=1,int f=0)
{
	// ll sigsiz=0;
	for(int v:e[u])
	{
		if(v==f)continue;
		dfs(v,u);
		// dp[u]+=dp[v];
		dp_[u]+=(dp_[v]+siz[v]-1);
		// sigsiz+=siz[v];
	}
	sigdp_+=dp_[u];
	for(int v:e[u])
	{
		if(v==f)continue;
		dp[u]+=(siz[v]*(siz[u]-1-siz[v]));
	}
	dp[u]/=2;
	sigdp+=dp[u];
	// printf("%d %lld\n",u,dp[u]);
}

int main()
{
	freopen("orient.in","r",stdin);
	freopen("orient.out","w",stdout);
	int n;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	init();
	dfs();
	// for(int i=1;i<=n;i++)
	// {
	// 	printf("%d %lld\n",i,siz[i]);
	// }
	printf("%lld",1ll*n*n*n-(sigdp*2+sigdp_*2));
	return 0;
}
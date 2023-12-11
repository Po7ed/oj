#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
constexpr int N=514114;
int n,s;

struct edge
{
	int v;
	ll w;
};

vector<edge> e[N];
ll dep[N],ma[N],dp[N];
void init(int u=s,int f=0,int w=0)
{
	ma[u]=dep[u]=dep[f]+1ll*w;
	for(edge to:e[u])if(to.v!=f)
	{
		init(to.v,u,to.w);
		ma[u]=max(ma[u],ma[to.v]);
	}
}
void dfs(int u=s,int f=0)
{
	for(edge to:e[u])if(to.v!=f)
	{
		dfs(to.v,u);
		dp[u]+=(dp[to.v]+(ma[u]-ma[to.v]));
	}
}

int main()
{
	scanf("%d\n%d",&n,&s);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,1ll*w});
		e[v].push_back({u,1ll*w});
	}
	init();
	dfs();
	printf("%lld",dp[s]);
	return 0;
}
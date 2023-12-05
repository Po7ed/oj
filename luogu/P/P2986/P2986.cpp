#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
constexpr int N=114514;
constexpr ll INF=0x7fffffffffffffff;
int n;
int c[N];
struct edge
{
	int v,w;
};
vector<edge> e[N];

int fa[N];
ll dp[N],siz[N];
void init(int u=1,int f=0)
{
	fa[u]=f;
	siz[u]=ll(c[u]);
	for(edge to:e[u])if(to.v!=f)
	{
		init(to.v,u);
		siz[u]+=siz[to.v];
		dp[u]+=(dp[to.v]+siz[to.v]*to.w);
	}
}
ll ans=INF;
void dfs(int u=1,int fw=0)
{
	if(u!=1)dp[u]=dp[fa[u]]+(siz[1]-siz[u]-siz[u])*ll(fw);
	if(ans>dp[u])ans=dp[u];
	for(edge to:e[u])if(to.v!=fa[u])dfs(to.v,to.w);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	init();
	// for(int i=1;i<=n;i++)printf("%d:%lld\n",i,dp[i]);
	dfs();
	// for(int i=1;i<=n;i++)printf("%d:%lld\n",i,dp[i]);
	printf("%lld",ans);
	return 0;
}
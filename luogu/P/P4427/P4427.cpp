#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
constexpr int N=314514,K=51;
constexpr ll mod=998244353;
int n,m;
vector<int> e[N];

int pre[N][K];
namespace hld//todo: for lca
{
	int fa[N],siz[N],son[N],top[N];
	ll dep[N][K];
	inline void init()
	{
		for(int i=1;i<K;i++)dep[0][i]=-1;
	}
	void dfs(int u=1,int f=0)
	{
		pre[u][1]=(pre[f][1]+(dep[u][1]=(dep[fa[u]=f][1]+(siz[u]=1))%mod))%mod;
		for(int i=2;i<K;i++)pre[u][i]=(pre[f][i]+(dep[u][i]=(dep[u][i-1]*dep[u][1])%mod))%mod;
		for(int v:e[u])if(v!=f)
		{
			dfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v])son[u]=v;
		}
	}
	void dfs2(int u=1,int t=1)
	{
		top[u]=t;
		if(son[u])dfs2(son[u],t);
		else return;
		for(int v:e[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
	}
	int lca(int a,int b)
	{
		//todo complete int lca(int,int)
		while(top[a]!=top[b])
		{
			if(dep[top[a]][1]>dep[top[b]][1])swap(a,b);
			b=fa[top[b]];
		}
		return (dep[a][1]<dep[b][1]?a:b);
	}
}//^ namespace hld

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	hld::init();
	hld::dfs();
	hld::dfs2();
	scanf("%d",&m);
	for(int i=1,u,v,k,l;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&k);
		l=hld::lca(u,v);
		// printf("lca:%d\n",l);
		printf("%lld\n",(pre[u][k]+pre[v][k]-pre[l][k]-pre[hld::fa[l]][k]+mod*10ll)%mod);
	}
	return 0;
}
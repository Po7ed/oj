#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;

constexpr ll N=214514;
ll n,d;
struct edge
{
	ll v,w,id;
};
vector<edge> e[N];

ll dep[N],deg[N];
bitset<N> vis;
bool ring;
void dfs(ll u,ll f=0,ll w=0)
{
	// printf("%lld %lld %lld\n",u,f,w);
	if(vis[u]){ring=true;return;}
	vis[u]=true;
	dep[u]=dep[f]+w;
	for(edge to:e[u])if(to.v!=f&&d!=to.id)
	{
		dfs(to.v,u,to.w);
	}
}

int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%lld",&n);
	ll maxw=-0x3f3f3f3f,sumw=0;
	for(ll i=1,u,v,w;i<=n;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		deg[u]++;
		deg[v]++;
		e[u].push_back({v,w,i});
		e[v].push_back({u,w,i});
		maxw=max(maxw,w);
		sumw+=w;
	}
	bool isring=true;
	for(ll i=1;i<=n;i++)
	{
		if(deg[i]!=2)
		{
			isring=false;
		}
	}
	if(isring)
	{
		printf("%lld",sumw-maxw);
		return 0;
	}
	ll tmp,ans=0x3f3f3f3f3f3f3f3f;
	for(d=1;d<=n;d++)
	{
		ring=false;
		dfs(1);
		if(ring){vis.reset();goto con;}
		tmp=-1;
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i])goto con;
			vis[i]=false;
			if(tmp==-1||dep[tmp]<dep[i])
			{
				tmp=i;
			}
		}
		ring=false;
		dfs(tmp);
		if(ring){vis.reset();goto con;}
		tmp=-1;
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i])goto con;
			// vis[i]=false;
			tmp=max(tmp,dep[i]);
		}
		ans=min(ans,tmp);
		con:
		vis.reset();
	}
	printf("%lld",ans);
	return 0;
}
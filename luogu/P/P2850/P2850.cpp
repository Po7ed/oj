#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <algorithm>

constexpr int N=514;
struct edge{int v,w;};
std::vector<edge> e[N];

std::bitset<N> vis;
int n,m,k;
int dis[N],cnt[N];
bool bfm(int s=0)
{
	std::queue<int> q;
	vis.reset();
	std::fill(dis,dis+N,0x3f3f3f3f);
	std::fill(cnt,cnt+N,0);
	dis[s]=0;
	q.push(s);vis[s]=true;
	int u;
	#define v to.v
	#define w to.w
	while(!q.empty())
	{
		u=q.front();q.pop();vis[u]=false;
		for(edge to:e[u])if(dis[v]>dis[u]+w)
		{
			dis[v]=dis[u]+w;
			cnt[v]=cnt[u]+1;
			if(cnt[v]>n)
			return true;
			if(!vis[v])vis[v]=true,q.push(v);
		}
	}
	#undef v
	#undef w
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		e[0].clear();
		for(int i=1;i<=n;i++)e[0].push_back({i,0}),e[i].clear();
		int u,v,w;
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			e[u].push_back({v,-w});
		}
		puts(bfm()?"YES":"NO");
	}
	return 0;
}
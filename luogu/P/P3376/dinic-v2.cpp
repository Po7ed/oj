#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
constexpr int N=214;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
struct edge
{
	int v;
	ll c;
};

vector<edge> es;
vector<int> e[N];

int n,m,s,t;

namespace Dinic
{
	int dis[N],fir[N];
	bool bfs()
	{
		fill(fir,fir+N,0);
		fill(dis,dis+N,0);
		dis[s]=1;
		queue<int> q;
		q.push(s);
		int u,l,v;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			l=e[u].size();
			for(int i=0;i<l;i++)
			{
				v=es[e[u][i]].v;
				if(!dis[v]&&es[e[u][i]].c>0ll)
				{
					dis[v]=dis[u]+1;
					q.push(v);
					if(v==t)return true;
				}
			}
		}
		return false;
	}
	ll dfs(int u=s,ll flow=INF)
	{
		if(u==t)return flow;
		int l=e[u].size(),v;
		ll res=0ll,now,c;
		for(int i=fir[u];i<l;i++)
		{
			fir[u]=i;
			v=es[e[u][i]].v;
			c=es[e[u][i]].c;
			if(dis[v]==dis[u]+1&&c>0ll)
			{
				now=dfs(v,min(flow,c));
				if(now==0ll)dis[v]=0;
				es[e[u][i]].c-=now;
				es[e[u][i]^1].c+=now;
				res+=now;
				flow-=now;
				if(flow==0ll)return res;//! What the fuck?
			}
		}
		return res;
	}
	ll Dinic()
	{
		ll r=0ll;
		while(bfs())r+=dfs();
		return r;
	}
}//^ namespace Dinic

int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back(es.size());
		es.push_back({v,ll(w)});
		e[v].push_back(es.size());
		es.push_back({u,0ll});
	}
	printf("%lld",Dinic::Dinic());
	return 0;
}
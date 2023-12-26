#include <iostream>
#include <vector>
#include <bitset>
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

namespace EK
{
	bitset<N> vis;
	int pre[N];
	ll flow[N];
	bool bfs()
	{
		queue<int> q;
		vis.reset();
		vis[s]=true;
		q.push(s);
		flow[s]=INF;
		int u,l,v;
		ll c;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			l=e[u].size();
			for(int i=0;i<l;i++)
			{
				v=es[e[u][i]].v;
				c=es[e[u][i]].c;
				if(!vis[v]&&c>0)
				{
					vis[v]=true;
					flow[v]=min(flow[u],c);
					pre[v]=e[u][i];
					if(v==t)return true;
					q.push(v);
				}
			}
		}
		return false;
	}
	ll EK()
	{
		ll r=0ll;
		while(bfs())
		{
			r+=flow[t];
			for(int i=t;i!=s;i=es[pre[i]^1].v)
			{
				es[pre[i]].c-=flow[t];
				es[pre[i]^1].c+=flow[t];
			}
		}
		return r;
	}
}//^ namespace EK

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
	printf("%lld",EK::EK());
	return 0;
}
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
	int x;
};

vector<edge> e[N];

int n,m,s,t;

namespace EK
{
	bitset<N> vis;
	pii pre[N];
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
				v=e[u][i].v;
				c=e[u][i].c;
				if(!vis[v]&&c>0)
				{
					vis[v]=true;
					flow[v]=min(flow[u],c);
					pre[v]={u,i};
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
			for(int i=t;i!=s;i=pre[i].first)
			{
				e[pre[i].first][pre[i].second].c-=flow[t];
				e[i][e[pre[i].first][pre[i].second].x].c+=flow[t];
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
		e[u].push_back({v,ll(w),int(e[v].size())});
		e[v].push_back({u,0ll,int(e[u].size()-1)});
	}
	printf("%lld",EK::EK());
	return 0;
}
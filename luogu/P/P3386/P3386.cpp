#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
	int v,c;
};

constexpr int N=1145,INF=0x3f3f3f3f;
int n1,n2,m,s,t;
vector<edge> es;
vector<int> e[N];

inline void add(int u,int v)
{
	e[u].push_back(es.size());
	es.push_back({v,1});
	e[v].push_back(es.size());
	es.push_back({u,0});
}

namespace Dinic
{
	int fir[N],dis[N];
	bool bfs()
	{
		queue<int> q;
		fill(fir,fir+N,0);
		fill(dis,dis+N,0);
		dis[s]=1;
		q.push(s);
		int u,v,c,l;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			l=e[u].size();
			for(int i=0;i<l;i++)
			{
				v=es[e[u][i]].v;
				c=es[e[u][i]].c;
				if(!dis[v]&&c>0)
				{
					dis[v]=dis[u]+1;
					q.push(v);
					if(v==t)return true;
				}
			}
		}
		return false;
	}
	int dfs(int u=s,int flow=INF)
	{
		if(u==t)return flow;
		int v,c,l=e[u].size(),now,res=0;
		for(int i=fir[u];i<l;i++)
		{
			fir[u]=i;
			v=es[e[u][i]].v;
			c=es[e[u][i]].c;
			if(dis[v]==dis[u]+1&&c>0)
			{
				now=dfs(v,min(flow,c));
				if(!now)dis[v]=0;
				es[e[u][i]].c-=now;
				es[e[u][i]^1].c+=now;
				flow-=now;
				res+=now;
				if(!flow)return res;
			}
		}
		return res;
	}
	int Dinic()
	{
		int res=0;
		while(bfs())res+=dfs();
		return res;
	}
}

int main()
{
	scanf("%d %d %d",&n1,&n2,&m);s=0,t=n1+n2+1;
	for(int i=1;i<=n1;i++)add(s,i);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,n1+v);
	}
	for(int i=n1+1;i<=n1+n2;i++)add(i,t);
	printf("%d",Dinic::Dinic());
	return 0;
}
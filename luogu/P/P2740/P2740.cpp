#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int N=214,INF=0x7fffffff;
struct edge
{
	int v,c;
};
vector<edge> es;
vector<int> e[N];
int n,m,s,t;

namespace Dinic
{
	int dis[N],fir[N];
	bool bfs()
	{
		fill(dis,dis+N,0);
		fill(fir,fir+N,0);
		queue<int> q;
		q.push(s);
		dis[s]=1;
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
					if(v==t)return true;
					q.push(v);
				}
			}
		}
		return false;
	}
	int dfs(int u=s,int flow=INF)
	{
		if(u==t)return flow;
		int v,c,l=e[u].size(),res=0,now;
		for(int i=fir[u];i<l;i++)
		{
			fir[u]=i;//! fir[i]=i; ...
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
	scanf("%d %d",&m,&n);s=1,t=n;
	for(int i=1,u,v,c;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&c);
		e[u].push_back(es.size());
		es.push_back({v,c});
		e[v].push_back(es.size());
		es.push_back({u,0});
	}
	printf("%d",Dinic::Dinic());
	return 0;
}
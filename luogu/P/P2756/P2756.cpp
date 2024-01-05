#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int N=114,INF=0x3f3f3f3f;
int m,n;

struct edge{int v,c;};
vector<edge> es;
vector<int> e[N];

namespace Dinic
{
	int dis[N],fir[N];
	bool bfs()
	{
		fill(fir,fir+N,0);
		fill(dis,dis+N,0);
		queue<int> q;
		q.push(0);
		dis[0]=1;
		int u,v,l;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			l=e[u].size();
			for(int i=0;i<l;i++)
			{
				v=es[e[u][i]].v;
				if(!dis[v]&&es[e[u][i]].c>0)
				{
					dis[v]=dis[u]+1;
					if(v==n+1)return true;
					q.push(v);
				}
			}
		}
		return false;
	}
	int dfs(int u=0,int flow=INF)
	{
		// printf("%s%d",u?"->":"*",u);
		if(u==n+1)return flow;
		int res=0,now,v,c,l=e[u].size();
		for(int i=fir[u];i<l;i++)
		{
			fir[u]=i;
			v=es[e[u][i]].v;
			c=es[e[u][i]].c;
			if(dis[u]+1==dis[v]&&c>0)
			{
				now=dfs(v,min(flow,c));
				if(!now)dis[v]=INF;
				es[e[u][i]].c-=now;
				es[e[u][i]^1].c+=now;
				res+=now;
				flow-=now;
				if(!flow)return res;
			}
		}
		return res;
	}
	int Dinic()
	{
		int res=0;
		while(bfs())
		res+=dfs()/* ,puts("") */;
		return res;
	}
}//^ namespace Dinic

inline void add(int u,int v)
{
	e[u].push_back(es.size());
	es.push_back({v,1});
	e[v].push_back(es.size());
	es.push_back({u,0});
}

int main()
{
	scanf("%d %d",&m,&n);//* left:[1,m];right:[m+1,n]
	int u,v;
	for(v=1;v<=m;v++)add(0,v);
	while(true)
	{
		scanf("%d %d",&u,&v);
		if(~u)add(u,v);else break;
	}
	for(u=m+1;u<=n;u++)add(u,n+1);
	printf("%d\n",Dinic::Dinic());
	int l=es.size();
	for(int i=0;i<l;i++)
	{
		u=es[i^1].v,v=es[i].v;
		if(0<u&&u<=m&&m<v&&v<=n&&!es[i].c)printf("%d %d\n",es[i^1].v,es[i].v);
	}
	return 0;
}
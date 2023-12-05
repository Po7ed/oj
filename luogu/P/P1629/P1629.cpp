#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
	int v,w;
};

typedef struct ndfp
{
	int id,dis;
	friend bool operator < (ndfp a,ndfp b)
	{
		return a.dis>b.dis;
	} 
}node;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v,w;
	vector<edge> e[n+1],e_[n+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e_[v].push_back({u,w});
	}
	priority_queue<node> q;
	q.push({1,0});
	int dis[n+1];
	fill(dis,dis+(n+1),0x3f3f3f3f);
	dis[1]=0;
	node t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.dis>dis[t.id])
		{
			continue;
		}
		for(edge to:e[t.id])
		{
			if(dis[to.v]>t.dis+to.w)
			{
				dis[to.v]=t.dis+to.w;
				q.push({to.v,dis[to.v]});
			}
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		ans+=dis[i];
	}
	q.push({1,0});
	fill(dis,dis+(n+1),0x3f3f3f3f);
	dis[1]=0;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.dis>dis[t.id])
		{
			continue;
		}
		for(edge to:e_[t.id])
		{
			if(dis[to.v]>t.dis+to.w)
			{
				dis[to.v]=t.dis+to.w;
				q.push({to.v,dis[to.v]});
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		ans+=dis[i];
	}
	printf("%d",ans);
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
	int v,w;
};

struct node
{
	int id,dis;
	friend bool operator < (node a,node b)
	{
		return a.dis>b.dis;
	}
};

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int u,v,w;
	vector<edge> e[n+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	int dis[n+1];
	fill(dis,dis+(n+1),0x3f3f3f3f);
	priority_queue<node> q;
	q.push({1,0});
	dis[1]=0;
	node t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.dis!=dis[t.id])
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
	int a,b;
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",dis[a]+dis[b]);
	}
	return 0;
}
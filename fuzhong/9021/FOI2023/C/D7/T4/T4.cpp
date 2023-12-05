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
	int dis,id;
	friend bool operator < (ndfp a,ndfp b)
	{
		return a.dis>b.dis;
	}
}node;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int u,v,w;
	vector<edge> e[n+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w+a[v]});
	}
	int dis[n+1];
	fill(dis,dis+(n+1),0x3f3f3f3f);
	dis[1]=a[1];
	priority_queue<node> q;
	q.push({a[1],1});
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
				q.push({dis[to.v],to.v});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dis[i]);
	}
	printf("%d",dis[n]);
	return 0;
}
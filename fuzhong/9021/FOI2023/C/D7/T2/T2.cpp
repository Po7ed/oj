#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* typedef struct ndfp
{
	int id,dis;
	friend bool operator < (ndfp a,ndfp b)
	{
		return a.dis<b.dis;
	}
}node; */

struct edge
{
	int id,w;
};

int main()
{
	int n,m,ss,tt;
	scanf("%d %d %d %d",&n,&m,&ss,&tt);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int u,v,w;
	vector<edge> e[n];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	int dis[n],scr[n];
	fill(dis,dis+n,0x3f3f3f3f);
	fill(scr,scr+n,-0x3f3f3f3f);
	dis[ss]=0;
	scr[ss]=a[ss];
	priority_queue<pair<int,int>> q;
	// q.push({ss,0});
	q.push(make_pair(-dis[ss],ss));
	pair<int,int> t;
	while(!q.empty())
	{
		int d=-q.top().first;
		int id=q.top().second;
		q.pop();
		if(d!=dis[id])
		{
			continue;
		}
		// scr[t.id]+=a[t.id];
		for(edge to:e[id])
		{
			if(dis[to.id]>d+to.w)
			{
				dis[to.id]=d+to.w;
				scr[to.id]=scr[id]+a[to.id];
				q.push({-dis[to.id],to.id});
			}
			else if(dis[to.id]==d+to.w)
			{
				scr[to.id]=max(scr[to.id],scr[id]+a[to.id]);
			}
		}
	}
	printf("%d %d",dis[tt],scr[tt]);
	return 0;
}

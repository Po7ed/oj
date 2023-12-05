#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

struct edge
{
	int v,w;
	friend bool operator < (edge a,edge b)
	{
		return a.w<b.w;
	}
};

int main()
{
	int n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	int u,v,w;
	vector<edge> a1[n+1];
	vector<edge> a2[n+1];//minus gragh
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a1[u].push_back({v,w});
		a2[v].push_back({u,w});
	}
	int dis1[n+1],dis2[n+1];
	fill(dis2,dis2+(n+1),INF);
	dis2[x]=0;
	priority_queue<edge> q;
	q.push({x,0});
	edge t;
	while(!q.empty()) //a2,go to x
	{
		t=q.top();
		q.pop();
		if(dis2[t.v]!=t.w)
		{
			continue;
		}
		for(edge l:a2[t.v])
		{
			if(dis2[l.v]>dis2[t.v]+l.w)
			{
				dis2[l.v]=dis2[t.v]+l.w;
				q.push({l.v,dis2[l.v]});
			}
		}
	}
	fill(dis1,dis1+(n+1),INF);
	dis1[x]=0;
	q.push({x,0});
	while(!q.empty()) //a1,go away from x
	{
		t=q.top();
		q.pop();
		if(dis1[t.v]!=t.w)
		{
			continue;
		}
		for(edge l:a1[t.v])
		{
			if(dis1[l.v]>dis1[t.v]+l.w)
			{
				dis1[l.v]=dis1[t.v]+l.w;
				q.push({l.v,dis1[l.v]});
			}
		}
	}
	int ans=-INF;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dis1[i]+dis2[i]);
	}
	printf("%d",ans);
	return 0;
}
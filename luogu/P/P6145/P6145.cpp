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
	int id,d;
	friend inline bool operator < (node x,node y)
	{
		return x.d>y.d;
	}
};
const int N=114514;
vector<edge> e[N];
int dis[N];

int main()
{
	int n,fvv,m;
	scanf("%d %d %d",&n,&fvv,&m);
	int s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s);
		e[0].push_back({i,s});
	}
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		e[x].push_back({y,z});
	}
	priority_queue<node> q;
	fill(dis,dis+N,-0x3f3f3f3f);
	dis[0]=0;
	q.push({0,0});
	node t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(dis[t.id]!=t.d)continue;
		for(edge to:e[t.id])
		{
			if(dis[to.v]<t.d+to.w)
			{
				dis[to.v]=t.d+to.w;
				q.push({to.v,dis[to.v]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",dis[i]);
	}
	return 0;
}
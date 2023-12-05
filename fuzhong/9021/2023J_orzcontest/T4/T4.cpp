#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

struct node
{
	ll d;
	int id;
};
bool operator < (node x,node y)
{
	return x.d>y.d;
}
struct edge
{
	int v,w;
};

int n,m;
vector<edge> e[114514];
ll dis[114514];
int main()
{
	// freopen("MK.in","r",stdin);
	// freopen("MK.out","w",stdout);
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	fill(dis,dis+(n+1),0x3f3f3f3f3f3f3f3fll);
	priority_queue<node> q;
	q.push({0ll,1});
	dis[1]=0ll;
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(t.d!=dis[t.id])
			continue;
		for(edge to:e[t.id])
		{
			if(dis[to.v]>t.d+to.w)
			{
				dis[to.v]=t.d+to.w;
				q.push({dis[to.v],to.v});
			}
		}
	}
	printf("%d",(dis[n]==0x3f3f3f3f3f3f3f3f?-1:dis[n]));
	return 0;
}
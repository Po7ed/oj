#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
constexpr int N=314514;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;

struct edge
{
	int v;
	ll w;
};
vector<edge> e[N];
int n,m;

struct node
{
	int u;
	ll d;
	friend inline bool operator < (node x,node y)
	{
		return x.d<y.d;
	}
};

ll dis[N];
priority_queue<node> q;
void dijkstra()
{
	fill(dis,dis+N,INF);
	q.push({1,dis[1]=0ll});
	node t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.d!=dis[t.u])continue;
		for(edge to:e[t.u])
		{
			if(t.d+to.w<dis[to.v])
			{
				dis[to.v]=t.d+to.w;
				q.push({to.v,dis[to.v]});
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,ll(w)});
	}
	dijkstra();
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",(dis[i]==INF?-1:dis[i]));
	}
	return 0;
}
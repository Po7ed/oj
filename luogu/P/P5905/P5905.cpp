#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef long long ll;
const int INF=1e9;

int n,m;

struct edge
{
	int v,w;
};

vector<edge> e[3114];
inline void add(int u,int v,int w)
{
	e[u].push_back({v,w});
}

int h[5114];
bool bellmanford(int s=0)
{
	for(int i=1;i<=n;i++)
	{
		add(s,i,0);
	}
	fill(h,h+(n+1),INF);
	h[s]=0;
	#define v to.v
	#define w to.w
	bool relax;
	for(int k=0;k<=n;k++)
	{
		relax=false;
		for(int u=0;u<=n;u++)
		{
			for(edge to:e[u])
			{
				if(h[v]>h[u]+w)
				{
					h[v]=h[u]+w;
					relax=true;
				}
			}
		}
		if(!relax)
		{
			return false;
		}
	}
	return relax;
	#undef v
	#undef w
}

struct node
{
	int id,dis;
};
inline bool operator < (node x,node y)
{
	return x.dis>y.dis;
}

int dis[3114];
priority_queue<node> q;
bitset<3114> vis;
void dijkstra(int s)
{
	fill(dis,dis+(n+1),INF);
	vis.reset();
	#define v to.v
	#define w to.w
	#define u t.id
	#define d t.dis
	dis[s]=0;
	q.push({s,0});
	node t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		vis[u]=true;
		for(edge to:e[u])
		{
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					q.push({v,dis[v]});
				}
			}
		}
	}
	#undef v
	#undef w
	#undef u
	#undef d
}

inline void deneg()
{
	#define v to.v
	#define w to.w
	for(int u=1;u<=n;u++)
	{
		for(edge& to:e[u])
		{
			w=w+h[u]-h[v];
		}
	}
	#undef v
	#undef w
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	if(bellmanford())
	{
		puts("-1");
		return 0;
	}
// for(int i=1;i<=n;i++)printf("0->%d:%d\n",i,h[i]);
	deneg();
	ll ans;
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
		ans=0;
		for(int j=1;j<=n;j++)
		{
			if(dis[j]==INF)
			{
				ans+=(1ll*j*INF);
			}
			else
			{
				ans+=(1ll*j*(dis[j]+h[j]-h[i]));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
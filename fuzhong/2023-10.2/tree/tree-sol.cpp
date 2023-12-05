#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

const int N=314514;

struct edge
{
	int v,w;
};

vector<edge> e[N*2];
vector<int> dof[N];
int n,s,k,p;
int dep[N];

void dfs(int u=1,int f=0)
{
	dep[u]=dep[f]+1;
	for(edge to:e[u])
	{
		if(to.v!=f)
		{
			dfs(to.v,u);
		}
	}
}
inline void init_dof()
{
	for(int i=1;i<=n;i++)
	{
		dof[dep[i]].push_back(i);
	}
}
inline void init_jump()
{
	int cnt=n;
	for(int i=1;!dof[i+k].empty();i++)
	{
		for(int u:dof[i])
		{
			e[u].push_back({cnt+1,p});
			e[cnt+2].push_back({u,0});
		}
		for(int u:dof[i+k])
		{
			e[u].push_back({cnt+2,p});
			e[cnt+1].push_back({u,0});
		}
		cnt+=2;
	}
}

struct node
{
	int id,d;
	friend inline bool operator < (node x,node y)
	{
		return x.d>y.d;
	}
};

int dis[N];
inline void dijkstra()
{
	fill(dis,dis+N,0x3f3f3f3f);
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,0});
	node t;
	while(!q.empty())
	{
		#define u t.id
		#define d t.d
		#define v to.v
		#define w to.w
		t=q.top();
		q.pop();
		if(d!=dis[u])
		{
			continue;
		}
		for(edge to:e[u])
		{
			if(dis[v]>d+w)
			{
				dis[v]=d+w;
				q.push({v,dis[v]});
			}
		}
		#undef u
		#undef d
		#undef v
		#undef w
	}
}

int main()
{
	// freopen("tree.in","r",stdin);
	// freopen("tree.out","w",stdout);
	scanf("%d",&n);
	int u,v,w;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	scanf("%d %d\n%d",&k,&p,&s);
	dfs();
	init_dof();
	init_jump();
	dijkstra();
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",dis[i]);
	}
	return 0;
}
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

vector<edge> e[N];
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
	for(int i=1;!dof[i+k].empty();i++)
	{
		for(int u:dof[i])
		{
			for(int v:dof[i+k])
			{
				e[u].push_back({v,p});
				e[v].push_back({u,p});
			}
		}
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

inline size_t cntedge()
{
	size_t res=0;
	for(int i=1;i<=n;i++)
	{
		res+=e[i].size();
	}
	return res;
}

int ed[(size_t)3e3][(size_t)3e3];
inline void init_ed()
{
	fill(*ed,*ed+(size_t)(9e6),0x3f3f3f3f);
	for(int u=1;u<=n;u++)
	{
		for(edge to:e[u])
		{
			ed[to.v][u]=min(ed[to.v][u],to.w);
			ed[u][to.v]=ed[to.v][u];
		}
	}
}

int dis[N];
inline void dijkstra()
{
	fill(dis,dis+N,0x3f3f3f3f);
	dis[s]=0;
	size_t m=cntedge();
	// if(true)
	if(m>(size_t)3e6&&n<=(int)3e3)// force
	{
		// puts("force");
		init_ed();
		bitset<N> vis;
		vis[s]=true;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				dis[i]=ed[s][i];
			}
		}
		while(true)
		{
			int mind=0x3f3f3f3f,t=-1;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j]&&dis[j]<mind)
				{
					mind=dis[j];
					t=j;
				}
			}
			if(t==-1)
			{
				return;
			}
			vis[t]=true;
			for(int j=1;j<=n;j++)
			{
				if(dis[j]>dis[t]+ed[t][j])
				{
					dis[j]=dis[t]+ed[t][j];
				}
			}
		}
	}
	else
	{
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
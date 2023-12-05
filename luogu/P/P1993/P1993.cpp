#include <iostream>
#include <vector>
using namespace std;

int n,m;

struct edge
{
	int v,w;
};

vector<edge> e[5114];
inline void add(int u,int v,int w)
{
	e[u].push_back({v,w});
}

int dis[5114];
bool bellmanford(int s=1)
{
	fill(dis,dis+(n+1),0x3f3f3f3f);
	dis[s]=0;
	#define v to.v
	#define w to.w
	bool relax;
	for(int k=1;k<=n;k++)
	{
		relax=false;
		for(int u=1;u<=n;u++)
		{
			for(edge to:e[u])
			{
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
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

int main()
{
	scanf("%d %d",&n,&m);
	int opt,u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&opt,&u,&v);
		if(opt==1)
		{
			scanf("%d",&w);
			add(u,v,-w);
		}
		else if(opt==2)
		{
			scanf("%d",&w);
			add(v,u,w);
		}
		if(opt==3)
		{
			add(u,v,0);
			add(v,u,0);
		}
	}
	if(bellmanford())
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
	return 0;
}
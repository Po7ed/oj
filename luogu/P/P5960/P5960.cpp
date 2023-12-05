#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int v,w;
};

int n,m;
int dis[5141];
vector<edge> e[5141];

bool bellmanford(int s=0)
{
	fill(dis,dis+(n+1),0x3f3f3f3f);
	dis[s]=0;
	bool f;
	for(int i=0;i<=n;i++)
	{
		f=false;
		for(int u=0;u<=n;u++)
		{
			if(dis[u]==0x3f3f3f3f)
			{
				continue;
			}
			#define v to.v
			#define w to.w
			for(edge to:e[u])
			{
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					f=true;
				}
			}
			#undef v
			#undef w
		}
		if(!f)
		{
			return false;
		}
	}
	return f;
}

int main()
{
	scanf("%d %d",&n,&m);
	int v,u,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&v,&u,&w);
		e[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
	{
		e[0].push_back({i,0});
	}
	if(bellmanford())
	{
		puts("NO");
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",dis[i]);
		}
	}
	return 0;
}
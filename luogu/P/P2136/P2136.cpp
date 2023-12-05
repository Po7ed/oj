#include <iostream>
#include <vector>
using namespace std;

int n,m;
#define INF 0x3f3f3f3f
struct edge
{
	int v,w;
};
vector<edge> e[1145];

int dis[1145];

bool bellmanford(int s)
{
	fill(dis,dis+(1145),INF);
	dis[s]=0;
	bool f;
	for(int k=1;k<=n;k++)
	{
		f=false;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]!=INF)
			{
				for(edge to:e[i])
				{
					if(dis[to.v]>dis[i]+to.w)
					{
						dis[to.v]=dis[i]+to.w;
						f=true;
					}
				}
			}
		}
		if(!f)
		{
			break;
		}
	}
	return f;
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,-w});
	}
	int ans=0x3f3f3f3f;
	bool f;
	f=bellmanford(1);
	if(f)
	{
		puts("Forever love");
	}
	else
	{
		ans=min(ans,dis[n]);
		f=bellmanford(n);
		if(f)
		{
			puts("Forever love");
		}
		else
		{
			ans=min(ans,dis[1]);
			printf("%d\n",ans);
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

struct edge
{
	int v,w;
};

int dis[2114];

int main()
{
	int T;
	scanf("%d",&T);
	int n,m,u,v,w;
	while(T--)
	{
		scanf("%d %d",&n,&m);
		vector<edge> e[n+1];
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			if(w>=0)
			{
				e[u].push_back({v,w});
				e[v].push_back({u,w});
			}
			else
			{
				e[u].push_back({v,w});
			}
		}
		fill(dis,dis+(2114),INF);
		dis[1]=0;
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
		if(f)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}
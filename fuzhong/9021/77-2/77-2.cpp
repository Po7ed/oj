#include <iostream>
#include <cstring>
using namespace std;

struct edge
{
	int u,v,w;
};

int main()
{
	freopen("bellmanford.in","r",stdin);
	freopen("bellmanford.out","w",stdout);
	int n,m,s;
	scanf("%d %d %d",&n,&m,&s);
	// int u,v,w;
	edge e[m];
	int dis[n+1],cnt=0;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	bool f=true;
	while(f)
	{
		if(cnt>=n)
		{
			puts("GmonkeYC!");
			return 0;
		}
		f=false;
		for(int i=0;i<m;i++)
		{
			if(dis[e[i].v]>dis[e[i].u]+e[i].w)
			{
				f=true;
				dis[e[i].v]=dis[e[i].u]+e[i].w;
			}
		}
		cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",(dis[i]==0x3f3f3f3f?-1:dis[i]));
	}
	return 0;
}
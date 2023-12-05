#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int n,m;

struct edge
{
	int u,v,w;
	friend bool operator < (edge a,edge b)
	{
		return a.w<b.w;
	}
};

int f[11451];
int Find(int x){return (f[x]==x?x:f[x]=Find(f[x]));}

/* inline void print()
{
	for(int j=1;j<=n;j++)
	{
		printf("%d ",f[j]);
	}
	puts("");
} */

int main()
{
	scanf("%d %d",&n,&m);
	iota(f,f+(n+1),0);
	int a[n+1],mia=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		mia=min(mia,a[i]);
	}
	// vector<edge> e[n+1];
	edge e[m+1];
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		// e[u].push_back({v,w+a[v]});
		// e[v].push_back({u,w+a[u]});
		e[i]={u,v,w*2+a[u]+a[v]};
	}
	sort(e+1,e+(m+1));
	int ans=0;
	#define u e[i].u
	#define v e[i].v
	#define w e[i].w
	/* for(int i=1;i<=m;i++)
	{
		printf("%d:(%d,%d,%d)\n",i,u,v,w);
	} */
	for(int i=1;i<=m;i++)
	{
		// printf("(%d,%d,%d)\n",u,v,w);
		if(Find(u)!=Find(v))
		{
			f[Find(u)]=Find(v);
			ans+=w;
		}
		// else
		// {
		// 	print();
		// }
	}
	printf("%d",ans+mia);
	return 0;
}
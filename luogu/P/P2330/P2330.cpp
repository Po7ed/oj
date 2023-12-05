#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct edge
{
	int u,v,w;
	friend bool operator < (edge a,edge b)
	{
		return a.w<b.w;
	}
};

int f[311];
int Find(int x){return (f[x]==x?x:f[x]=Find(f[x]));}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	edge e[m+1];
	iota(f,f+n+1,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+(m+1));
	int ans=-0x3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		if(Find(e[i].u)!=Find(e[i].v))
		{
			f[Find(e[i].u)]=Find(e[i].v);
			ans=max(ans,e[i].w);
		}
		// else puts("pass");
	}
	printf("%d %d",n-1,ans);
	return 0;
}
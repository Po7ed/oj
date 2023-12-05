#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>
using namespace std;

const int N=514514;
vector<int> e[N];
int n,m;
int ls[N],rs[N],ans[N],x[N],y[N],als[N],ars[N],dep[N]/* ,fa[N] */;
bitset<N> vis;

// int f[N];
// inline void init(){iota(f,f+N,0);}
// int Find(int x){return (f[x]==x?x:Find(f[x]));}

void dfs(int u=1,int f=0)
{
	ans[u]=-1;
	vis[u]=true;
	dep[u]=dep[f]+1;
	// fa[u]=f;
	for(int v:e[u])
	{
		if(v!=f)
		{
			dfs(v,u);
		}
	}
}

int now;
void modify(int u,int f)
{
	if(vis[u])
	{
		return;
	}
	ans[u]=now;
	vis[u]=true;
	for(int v:e[u])
	{
		if(v!=f)
		{
			modify(v,u);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",ls+i,rs+i);
		als[i]=ls[i];
		ars[i]=rs[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",x+i,y+i);
		if(y[i]==1)
		{
			als[x[i]]=-1;
		}
		else
		{
			ars[x[i]]=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(als[i]+1)
		{
			e[als[i]].push_back(i);
			e[i].push_back(als[i]);
		}
		if(ars[i]+1)
		{
			e[ars[i]].push_back(i);
			e[i].push_back(ars[i]);
		}
	}
	dfs();
	for(int i=m;i;i--)
	{
		now=i-1;
		if(y[i]==1)
		{
			if(ans[ls[x[i]]])
			{
				modify(x[i],0);
			}
			e[x[i]].push_back(ls[x[i]]);
			e[ls[x[i]]].push_back(x[i]);
		}
		else
		{
			if(ans[rs[x[i]]])
			{
				modify(x[i],0);
			}
			e[x[i]].push_back(rs[x[i]]);
			e[rs[x[i]]].push_back(x[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
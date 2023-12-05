#include <iostream>
#include <vector>
using namespace std;

const int N=514114,L=20;
int mi[L][N];
int n,m,s,ln;
vector<int> e[N];

int dfn[N],cnt,dep[N],fa[N];
inline int getmi(int x,int y)
{
	if(!x)return y;
	if(!y)return x;
	return (dep[x]<dep[y]?x:y);
}

void dfs(int u=s,int f=0)
{
	dfn[u]=++cnt;
	dep[u]=dep[f]+1;
	fa[u]=f;
	mi[0][dfn[u]]=u;
	for(int v:e[u])
	{
		if(v==f)continue;
		dfs(v,u);
	}
}

int d;
int lca(int u,int v)
{
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))
	{
		swap(u,v);
	}
	d=__lg(v-u++);
	return fa[getmi(mi[d][u],mi[d][v-(1<<d)+1])];
}

int main()
{
	scanf("%d %d %d",&n,&m,&s);
	ln=__lg(n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs();
	for(int i=1,j;i<=ln;i++)
	{
		for(j=1;j+(1<<i)-1<=n;j++)
		{
			mi[i][j]=getmi(mi[i-1][j],mi[i-1][j+(i<<(i-1))]);
			// printf("%d %d:%d\n",i,j,mi[i][j]);
		}
		for(;j<=n;j++)
		{
			mi[i][j]=mi[i-1][j];
			// printf("%d %d:%d\n",i,j,mi[i][j]);
		}
	}
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
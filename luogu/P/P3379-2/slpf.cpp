#include <iostream>
#include <vector>
using namespace std;

const int N=514114,L=20;
int mi[L][N];
int n,m,s;
vector<int> e[N];

int dep[N],fa[N],son[N],siz[N],top[N];
void init(int u=s,int f=0)
{
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	for(int v:e[u])
	{
		if(v==f)continue;
		init(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])
		{
			son[u]=v;
		}
	}
}
void dcm(int u=s,int t=s)
{
	top[u]=t;
	if(!son[u])return;
	dcm(son[u],t);
	for(int v:e[u])
	{
		if(v!=fa[u]&&v!=son[u])
		{
			dcm(v,v);
		}
	}
}

int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		(dep[top[u]]>dep[top[v]]?u=fa[top[u]]:v=fa[top[v]]);
	}
	return (dep[u]>dep[v]?v:u);
}

int main()
{
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	init();
	dcm();
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> e[114514];
int dep[114514],jmp[114514][18],dis[114514],deg[114514];
int n,q;

void dfs(int now=1,int pre=0)
{
	jmp[now][0]=pre;
	dep[now]=dep[pre]+1;
	dis[now]=dis[pre]+deg[now];
	for(int son:e[now])
	{
		if(son!=pre)
		{
			dfs(son,now);
		}
	}
}
inline void init()
{
	dfs();
	for(int j=1;j<18;j++)
	{
		for(int i=1;i<=n;i++)
		{
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
		}
	}
}
inline int lca(int x,int y)
{
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	for(int j=17;j>=0;j--)
	{
		if(dep[jmp[y][j]]>=dep[x])
		{
			y=jmp[y][j];
		}
	}
	for(int j=17;j>=0;j--)
	{
		if(jmp[x][j]!=jmp[y][j])
		{
			x=jmp[x][j];
			y=jmp[y][j];
		}
	}
	if(x==y)
	{
		return x;
	}
	return jmp[x][0];
}
inline int getdis(int x,int y)
{
	/* if(x==y)
	{
		return deg[x];
	} */
	int l=lca(x,y);
	return dis[x]+dis[y]-dis[l]-dis[jmp[l][0]];
}

int main()
{
	scanf("%d %d",&n,&q);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	// dfs();
	init();
	while(q--)
	{
		scanf("%d %d",&u,&v);
		printf("%d\n",getdis(u,v));
	}
	return 0;
}
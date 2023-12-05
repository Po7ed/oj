#include <iostream>
#include <vector>
using namespace std;
#define MN 100001

int n,m;
int a[MN];
bool vis[MN];
vector<int> e[MN];

int dfs(int x)
{
	if(a[x])
	{
		return a[x];
	}
	if(vis[x])
	{
		return -1;
	}
	vis[x]=true;
	/* if(e[x].empty())
	{
		return x;
	} */
	int res=x;
	int l=e[x].size();
	for(int i=0;i<l;i++)
	{
		// vis[x]=true;
		res=max(res,dfs(e[x][i]));
		// vis[x]=false;
	}
	vis[x]=false;
	a[x]=res;
	return res;
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		// e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			// vis[i]=true;
			dfs(i);
			// vis[i]=false;
		}
		printf("%d ",a[i]);
	}
	return 0;
}
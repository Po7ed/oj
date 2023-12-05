#include <iostream>
#include <vector>
using namespace std;
#define MN 100001

int n,m;
int a[MN];
bool vis[MN];
vector<int> e[MN];

int root;
void dfs(int x)
{
	/* if(a[x])
	{
		return a[x];
	} */
	if(vis[x])
	{
		return;
	}
	vis[x]=true;
	/* if(e[x].empty())
	{
		return x;
	} */
	// a[x]=max(a[x],root);
	/* if(a[x]>root)
	{
		return;
	}
	else
	{
		a[x]=root;
	} */
	if(a[x])
	{
		return;
	}
	else
	{
		a[x]=root;
	}
	int l=e[x].size();
	for(int i=0;i<l;i++)
	{
		// vis[x]=true;
		dfs(e[x][i]);
		// vis[x]=false;
	}
	vis[x]=false;
	return;
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		// e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=n;i>0;i--)
	{
		// if(!a[i])
		// {
			// vis[i]=true;
		root=i;
			dfs(i);
			// vis[i]=false;
		// }
		// printf("%d ",a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N=114514;
vector<int> e[N],stk;
int dfn[N],low[N],bel[N],scccnt=0,dfncnt=1;
int deg[N];

void tarjan(int u)
{
	dfn[u]=low[u]=dfncnt++;
	stk.push_back(u);
	for(int v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	} 
	if(dfn[u]==low[u])
	{
		scccnt++;
		int t=0;
		while(t!=u)
		{
			t=stk.back();
			stk.pop_back();
			bel[t]=scccnt;
		}
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(int v:e[u])
		{
			if(bel[u]!=bel[v])
			{
				deg[bel[v]]++;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=scccnt;i++)
	{
		if(!deg[i])
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
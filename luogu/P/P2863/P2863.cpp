#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
int n,m;
vector<int> e[11451],stk;
int cnt=0,dfn[11451],low[11451];
bitset<11451> vis,bel;

int dfncnt=1;
void tarjan(int u)
{
	vis[u]=true;
	dfn[u]=low[u]=dfncnt++;
	stk.push_back(u);
	for(int v:e[u])
	{
		if(!vis[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[v])// in stk
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		if(stk.back()!=u)
		{
			cnt++;
		}
		int t;
		while(stk.back()!=u)
		{
			t=stk.back();
			stk.pop_back();
			bel[t]=true;
		}
		bel[u]=true;
		stk.pop_back();
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			tarjan(i);
		}
	}
	printf("%d\n",cnt);
	return 0;
}
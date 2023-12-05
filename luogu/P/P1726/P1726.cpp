#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
int n,m;
vector<int> e[11451],stk;
int bel[11451];
vector<vector<int>> scc={{}};
int cnt=1,dfn[11451],low[11451];
bitset<11451> vis;

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
		int t;
		scc.push_back({});
		while(stk.back()!=u)
		{
			t=stk.back();
			stk.pop_back();
			scc[cnt].push_back(t);
			bel[t]=cnt;
		}
		scc[cnt].push_back(u);
		sort(scc[cnt].begin(),scc[cnt].end());
		bel[u]=cnt++;
		stk.pop_back();
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v,t;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&t);
		if(t-1)
		{
			e[u].push_back(v);
			e[v].push_back(u);
		}
		else
		{
			e[u].push_back(v);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			tarjan(i);
		}
	}
	vis.reset();
	// printf("%d\n",cnt-1);
	int ans=-1,id=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(ans<(int)(scc[bel[i]].size()))
			{
				ans=(scc[bel[i]].size());
				id=i;
			}
			for(int t:scc[bel[i]])
			{
				vis[t]=true;
			}
		}
	}
	printf("%d\n",ans);
	for(int t:scc[bel[id]])
	{
		printf("%d ",t);
	}
	return 0;
}
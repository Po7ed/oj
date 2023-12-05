#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a[11451];
vector<int> e[11451];

int dfn[11451],low[11451],dfstime=1;
int bel[11451],scc=1;
int stk[11451],tail=0;
void tarjan(int u)
{
	dfn[u]=low[u]=dfstime++;
	stk[tail++]=u;
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
		int t;
		while(stk[tail-1]!=u)
		{
			t=stk[--tail];
			bel[t]=scc;
		}
		tail--;
		bel[u]=scc++;
	}
}

vector<int> ne[11451];
int na[11451];
int deg[11451],topo[11451];
queue<int> q;
int dp[11451];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		na[bel[i]]+=a[i];
		for(int j:e[i])
		{
			if(bel[i]!=bel[j])
			{
				ne[bel[i]].push_back(bel[j]);
				deg[bel[j]]++;
			}
		}
	}
	for(int i=1;i<scc;i++)
	{
		if(!deg[i])
		{
			q.push(i);
		}
		dp[i]=na[i];
	}
	int t,ctp=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		topo[ctp++]=t;
		for(int to:ne[t])
		{
			deg[to]--;
			if(!deg[to])
			{
				q.push(to);
			}
		}
	}
	int ans=-1;
	for(int i=1;i<scc;i++)
	{
		ans=max(ans,dp[topo[i]]);
		for(int j:ne[topo[i]])
		{
			dp[j]=max(dp[j],dp[topo[i]]+na[j]);
		}
	}
	printf("%d",ans);
	return 0;
}
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N=11451;
vector<int> e[N],scc[N],stk;
int dfn[N],low[N],bel[N],dfncnt=1,scccnt=1,deg[N];
void tarjan(int u/* ,int f */)
{
	// puts("flag");
	// printf("u:%d\n",u);
	dfn[u]=low[u]=dfncnt++;
	stk.push_back(u);
	for(int v:e[u])
	{
		// printf(" v:%d\n",v);
		// if(v==f)
		// {
		// 	continue;
		// }
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
	if(low[u]==dfn[u])
	{
		// printf("%d is root\n",u);
		int t;
		// for(int ele:stk)
		// {
		// 	printf("%d ",ele);
		// }
		// puts("");
		while(stk.back()!=u)
		{
			t=stk.back();
			// printf(" t:%d\n",t);
			stk.pop_back();
			scc[scccnt].push_back(t);
			bel[t]=scccnt;
		}
		stk.pop_back();
		scc[scccnt].push_back(u);
		bel[u]=scccnt++;
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
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
		for(int j:e[i])
		{
			if(bel[i]!=bel[j])
			{
				deg[bel[i]]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<scccnt;i++)
	{
		if(deg[i]==0)
		{
			if(ans)
			{
				puts("0");
				return 0;
			}
			ans=scc[i].size();
		}
	}
	printf("%d",ans);
	return 0;
}
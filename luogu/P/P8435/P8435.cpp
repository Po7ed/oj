#include <iostream>
#include <vector>
using namespace std;
int n,m;
const int mn=514114;
vector<int> e[mn];

int dfn[mn],low[mn],dfstime=1;
vector<int> stk;
vector<vector<int>> bcc;
void tarjan(int u,int pre)
{
	dfn[u]=low[u]=dfstime++;
	stk.push_back(u);
	int son=0;
	for(int v:e[u])
	{
		if(pre==v)
		{
			continue;
		}
		son++;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v])
			{
				bcc.push_back({u});
				int t;
				do
				{
					t=stk.back();
					bcc.back().push_back(t);
					stk.pop_back();
				}
				while(t!=v);
			}
		}
		else
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(!(pre||son))
	{
		bcc.push_back({u});
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		if(u==v)
		{
			continue;
		}
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i,0);
		}
	}
	printf("%d\n",bcc.size());
	for(vector<int> tb:bcc)
	{
		printf("%d ",tb.size());
		for(int t:tb)
		{
			printf("%d ",t);
		}
		puts("");
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
const int mn=514114;
vector<pair<int,int>> e[mn];

vector<int> stk;
vector<vector<int>> bcc;
int dfn[mn],low[mn],dfstime=1;
void tarjan(int u,int pre=0)// pre:edge id
{
	dfn[u]=low[u]=dfstime++;
	stk.push_back(u);
	#define v to.first
	#define id to.second
	for(pair<int,int> to:e[u])
	{
		if(id!=pre)
		{
			if(!dfn[v])
			{
				tarjan(v,id);
				low[u]=min(low[u],low[v]);
			}
			else
			{
				low[u]=min(low[u],dfn[v]);
			}
		}
	}
	#undef v
	#undef id
	if(dfn[u]==low[u])
	{
		bcc.push_back({});
		int v;
		do
		{
			v=stk.back();
			stk.pop_back();
			bcc.back().push_back(v);
		}
		while(v!=u);
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
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	printf("%d\n",bcc.size());
	for(vector<int> t:bcc)
	{
		printf("%d ",t.size());
		for(int tt:t)
		{
			printf("%d ",tt);
		}
		puts("");
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

constexpr int N=114514;
int n,m;

struct edge
{
	int v,w;
};
vector<edge> e[N];

int pre[N];
void dfs(int u=1,int f=0)
{
	for(edge to:e[u])if(to.v!=f)
	{
		pre[to.v]=pre[u]^to.w;
		dfs(to.v,u);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs();
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		printf("%d\n",pre[u]^pre[v]);
	}
	return 0;
}
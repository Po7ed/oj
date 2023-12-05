#include <iostream>
#include <vector>
using namespace std;

constexpr int N=51411,INF=0x3f3f3f3f;
int n;
vector<int> e[N];

int siz[N],sum[N],dep[N];
int pos=INF,ans=INF;

void init(int u=1,int f=0)
{
	siz[u]=1;
	dep[u]=dep[f]+1;
	sum[1]+=dep[u];
	for(int v:e[u])
	{
		if(v==f)continue;
		init(v,u);
		siz[u]+=siz[v];
	}
}

void dfs(int u=1,int f=0)
{
	if(f)
	{
		sum[u]=sum[f]+(n-siz[u])-siz[u];
	}
	if(ans>sum[u]||(ans==sum[u]&&pos>u))
	{
		ans=sum[u];
		pos=u;
	}
	for(int v:e[u])
	{
		if(v==f)continue;
		dfs(v,u);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[0]=-1;
	init();
	dfs();
	printf("%d %d",pos,ans);
	return 0;
}
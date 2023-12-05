#include <iostream>
#include <vector>
using namespace std;

#define N 100001
int a[N],mi[N],dp[N],t;
vector<int> e[N];
void dfs(int now,int pre,int mx)
{
	bool f=true;
	mx=min(mx,a[now]);
	if(mi[now]>mx)
	{
		f=false;
		mi[now]=mx;
	}
	t=max(dp[pre],a[now]-mx);
	if(dp[now]<t)
	{
		dp[now]=t;
		f=false;
	}
	if(f)
	{
		return;
	}
	for(int to:e[now])
	{
		dfs(to,now,mx);
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	fill(mi,mi+n+1,0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int u,v,type;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&type);
		if(type-1)
		{
			e[u].push_back(v);
			e[v].push_back(u);
		}
		else
		{
			e[u].push_back(v);
		}
	}
	dfs(1,-1,0x3f3f3f3f);
	printf("%d",dp[n]);
	return 0;
}
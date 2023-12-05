#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define N 16001
int n;
int a[N],dp[N],ans=(-0x7fffffff-1);
vector<int> e[N];

void dfs(int now,int pre)
{
	for(int son:e[now])
	{
		if(son!=pre)
		{
			dfs(son,now);
			dp[now]+=(dp[son]>0?dp[son]:0);
		}
	}
	ans=max(ans,dp[now]);
	return;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i]=a[i];
	}
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,-1);
	printf("%d",ans);
	return 0;
}
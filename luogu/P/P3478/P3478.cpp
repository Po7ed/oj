#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N=1145141;
vector<int> e[N];
int n;
ll dep[N],dp[N],siz[N];

void init(int u=1,int f=0)
{
	dep[u]=dep[f]+1;
	int tmp=0,tmp2=0;
	for(int v:e[u])
	{
		if(v==f)continue;
		init(v,u);
		tmp+=dp[v];
		tmp2+=siz[v];
	}
	dp[u]=tmp+dep[u];
	siz[u]=tmp2+1;
		// printf("siz[%d]=%lld\n",u,siz[u]);
}
ll ans=-1;
int id;
void dfs(int u=1,int f=0)
{
	if(u!=1)
	{
		dp[u]=dp[f]-siz[u]+(n-siz[u]);
		if(ans<dp[u])
		{
			ans=dp[u];
			id=u;
		}
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
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[0]=-1;
	init();
	// puts("1");
	dfs();
	// puts("2");
	printf("%d",id);
	return 0;
}

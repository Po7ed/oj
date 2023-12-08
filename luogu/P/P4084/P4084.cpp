#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
constexpr int N=114514;
constexpr ll P=1e9+7;
int n,m;
ll dp[N][4];
int co[N];
vector<int> e[N];

void dfs(int u=1,int f=0)
{
	// if(e[u].size()==1&&u!=1)
	// {
	// 	if(co[u])dp[u][co[u]]=1ll;
	// 	else dp[u][1]=dp[u][2]=dp[u][3]=1ll;
	// 	return;
	// }
	for(int v:e[u])if(v!=f)
	{
		dfs(v,u);
	}
	ll t;
	if(co[u])
	{
		for(int v:e[u])if(co[u]==co[v])printf("0"),exit(0);
		dp[u][co[u]]=1ll;
		for(int v:e[u])if(v!=f)
		{
			t=0ll;
			for(int c=1;c<4;c++)if(co[u]!=c)
			{
				t+=dp[v][c];
				t%=P;
			}
			dp[u][co[u]]*=t;
			dp[u][co[u]]%=P;
		}
	}
	else for(co[u]=1;co[u]<4;co[u]++)
	{
		for(int v:e[u])if(co[u]==co[v])continue;
		dp[u][co[u]]=1ll;
		for(int v:e[u])if(v!=f)
		{
			t=0ll;
			for(int c=1;c<4;c++)if(co[u]!=c)
			{
				t+=dp[v][c];
				t%=P;
			}
			dp[u][co[u]]*=t;
			dp[u][co[u]]%=P;
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1,b,c;i<=m;i++)
	{
		scanf("%d %d",&b,&c);
		co[b]=c;
	}
	dfs();
	printf("%lld",(dp[1][1]+dp[1][2]+dp[1][3])%P);
	return 0;
}
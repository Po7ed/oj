#include <iostream>
#include <vector>
using std::vector;
using std::fill;
typedef long long ll;
constexpr int N=114,mod=1e9+7;
int n,m;
vector<int> e[N];
int siz[N][N];
void dfs(int u,int f=0)
{
	siz[0][u]=1;
	for(int v:e[u])if(v!=f)
	{
		dfs(v,u);
		for(int i=1;i<=n;i++)siz[i][u]+=siz[i-1][v];
	}
}
int dp[N][N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)e[i].clear();
		int u,v;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(m==2){printf("%d\n",n*(n-1)>>1);continue;}
		int ans=0;
		for(int u=1;u<=n;u++) // root
		{
			fill(*siz,*siz+(N*N),0);
			dfs(u);
			for(int dep=0;dep<n;dep++)
			{
				fill(*dp,*dp+(N*N),0);
				dp[0][0]=1;
				int i=1;
				for(int v:e[u]) // son
				{
					dp[i][0]=1;
					for(int j=1;j<=i;j++)
					{
						dp[i][j]=(dp[i-1][j]+1ll*dp[i-1][j-1]*siz[dep][v]%mod)%mod;
					}
					i++;
				}
				ans=(ans+dp[i-1][m])%mod;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
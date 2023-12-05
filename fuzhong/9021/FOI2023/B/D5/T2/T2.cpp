#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int v,w;
};
// typedef long long ll;
const int mod=998244353ll;

int main()
{
	int n,m,l,r;
	scanf("%d %d %d %d",&n,&m,&l,&r);
	vector<edge> e[n+1];
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	int all=(1<<(n+1))-1;
	int dp[all+1][r+1][n+1];
	fill(**dp,**dp+(all+1)*(r+1)*(n+1),0);
	dp[1][0][0]=1;
	for(int s=1;s<=all;s++)
	{
		for(int d=0;d<=r;d++)
		{
			for(int u=0;u<=n;u++)
			{
				if(dp[s][d][u])
				{
					for(edge t:e[u])
					{
						if(d+t.w<=r)
						{
							dp[s|(1<<t.v)][d+t.w][t.v]+=dp[s][d][u];
							dp[s|(1<<t.v)][d+t.w][t.v]%=mod;
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=l;i<=r;i++)
	{
		ans+=dp[all][i][0];
		ans%=mod;
	}
	printf("%d",ans);
	return 0;
}
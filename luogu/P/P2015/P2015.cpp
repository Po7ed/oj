#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N=114;
int n,q,dp[N][N],siz[N];

struct edge
{
	int v,w;
};

vector<edge> e[N];
// bitset<N> hav;
// #define ls e[u][0].v
// #define rs e[u][1].v
// #define lw e[u][0].w
// #define rw e[u][1].w
void dfs(int u=1,int f=0)
{
	int ls=0,rs,lw,rw;// init sons
	for(edge to:e[u])
	{
		if(to.v!=f)
		{
			// printf(" connected:%d\n",to.v);
			if(!ls)
			{
				ls=to.v;
				lw=to.w;
			}
			else
			{
				rs=to.v;
				rw=to.w;
			}
		}
	}
	if(ls)// have sons
	{
		dfs(ls,u);
		dfs(rs,u);
		siz[u]=siz[ls]+siz[rs]+2;
		// printf("siz[%d]=%d\n",u,siz[u]);
		// printf("u:%d\n",u);
		// printf(" lw:%d rw:%d\n",lw,rw);
		for(int i=1;i<=siz[u];i++)
		{
			dp[u][i]=max(dp[ls][i-1]+lw,dp[rs][i-1]+rw);
			for(int l=1;l<i;l++)
			{
				dp[u][i]=max(dp[u][i],dp[ls][l-1]+dp[rs][i-l-1]+lw+rw);
				// printf("l%dr%d:%d\n",l,i-l,dp[ls][l-2]+dp[rs][i-l-2]+lw+rw);
			}
		}
		for(int i=siz[u]+1;i<=n;i++)
		{
			dp[u][i]=-0x3f3f3f3f;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			dp[u][i]=-0x3f3f3f3f;
		}
	}
		// for(int i=0;i<=n;i++)
			// printf("%d %d:%d\n",u,i,dp[u][i]);
	return;
}

int main()
{
	// freopen("P2015_2.in","r",stdin);
	scanf("%d %d",&n,&q);
	int u,v,w;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		// printf("*%d %d %d\n",u,v,w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		// hav[u]=true;
	}
	dfs();
	printf("%d",dp[1][q]);
	return 0;
}
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr int N=11451;
int n;
vector<int> e[N];

int dp[N][3];
bitset<N> lev;

void dfs(int u=1,int f=0)
{
	if(e[u].size()==1&&u!=1)lev[u]=true;
	int s1=0,s2=0;
	for(int v:e[u])if(v!=f)
	{
		dfs(v,u);
		if(lev[v])s2--;
		s1+=dp[v][2];
	}
	dp[u][1]=s1+s2+1;// put,ok
	// 1.v hav ; *2.u hav.
	dp[u][0]=0x3f3f3f3f;
	for(int v:e[u])if(v!=f)// v hav,so u hav,too.
	{
		// other is ok,so  chose v,add other,but v's old.
		dp[u][0]=min(dp[u][0],dp[v][1]+s1-dp[v][2]);
	}
	dp[u][2]=min(dp[u][0],dp[u][1]);
	// fprintf(stderr,"%d:%d %d  (%d)\n",u,dp[u][0],dp[u][1],dp[u][2]);
}

int main()
{
	// freopen("P2899_5.in","r",stdin);
	// freopen("out","w",stdout);
	// freopen("log","w",stderr);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		lev.reset();
		dfs(i,0);
		ans=min(ans,dp[i][2]);
	}
	printf("%d",ans);
	return 0;
}
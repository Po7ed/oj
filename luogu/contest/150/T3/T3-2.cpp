#include <iostream>
// #include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int u,v;
	vector<int> e[n+1];
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int d[n+1],now,pre;
	d[0]=0;
	e[0]={1};
	vector<pair<int,int>> dfs={make_pair(0,-1)};
	int s=0;
	while(!dfs.empty())
	{
		now=dfs.back().first;
		pre=dfs.back().second;
		dfs.pop_back();
		if(now)
		{
			d[now]=d[pre]+1;
		}
		s+=d[now];
		for(int to:e[now])
		{
			if(to!=pre)
			{
				dfs.push_back({to,now});
			}
		}
	}
	if(s&1)
	{
		puts("-1");
		return 0;
	}
	int p[n+1][s+1];
	fill(*p,*p+(n+1)*(s+1),-1);
	int dp[n+1][s+1];
	fill(*dp,*dp+(n+1)*(s+1),-0x3f3f3f3f);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=s/2;j++)
		{
			dp[i][j]=dp[i-1][j+d[i]];
			p[i][j]=true;
			if(j>=d[i])
			{
				if(dp[i][j]<dp[i-1][j-d[i]]+d[i])
				{
					dp[i][j]=dp[i-1][j-d[i]]+d[i];
					p[i][j]=false;
				}
				// dp[i][j]=max();
			}
			else
			{
				if(dp[i][j]<dp[i-1][d[i]-j]+j)
				{
					dp[i][j]=dp[i-1][d[i]-j]+j;
					p[i][j]=false;
				}
				// dp[i][j]=max(dp[i][j],dp[i-1][d[i]-j]+j);
			}
		}
	}
	if(dp[n][0]<=0)
	{
		puts("-1");
	}
	else
	{
		bool w[n+1];
		fill(w,w+(n+1),false);
		int a=n,b=0;
		while(a>0&&b>0)
		{
			if(p[a][b])
			{
				w[a]=true;
				// a-=a[p[a][b]];
				b+=d[a];
				a--;
			}
			else
			{
				w[a]=false;
				b-=d[a];
				a--;
				// b-=a[-p[a][b]];
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d ",(w[i]==true?1:0));
		}
	}
	return 0;
}
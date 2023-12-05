#include <iostream>
// #include <algorithm>
#include <vector>
using namespace std;

int main()
{
	// ********** input ********** //
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
		// while(1)
		puts("-1");
		return 0;
	}
	// ********** dp ********** //
	bool p[n+1][s+1];
	fill(*p,*p+(n+1)*(s+1),false);
	bool dp[n+1][s+1];
	fill(*dp,*dp+(n+1)*(s+1),false);
	dp[0][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=s/2;j++)
		{
			if(dp[i-1][j])
			{
				dp[i][j]=true;
				p[i][j]=false;
				// printf("%d %d by %d %d,%c\n",i,j,i-1,j,"WB"[(int)p[i][j]]);
			}
			else if(dp[i-1][j-d[i]])
			{
				dp[i][j]=true;
				p[i][j]=true;
				// printf("%d %d by %d %d,%c\n",i,j,i-1,j-d[i],"WB"[(int)p[i][j]]);
			}
			else
			{
				dp[i][j]=false;
			}
		}
	}
	// printf("*%c*\n","FT"[p[6][7]]);
	if(!dp[n][s/2])
	{
		puts("-1");
	}
	else
	{
		bool w[n+1];
		fill(w,w+(n+1),false);
		int a=n,b=s/2;
		while(a||b)
		{
			// printf("%d %d\n",a,b);
			if(p[a][b])
			{
				// w[a]=false;
				b-=d[a];
				a--;
				// b-=a[-p[a][b]];
			}
			else
			{
				w[a]=true;
				// a-=a[p[a][b]];
				a--;
				// b-=d[a];
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d ",(w[i]==true?1:0));
		}
	}
	return 0;
}
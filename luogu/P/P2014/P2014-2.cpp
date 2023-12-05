#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int f[n+1],a[n+1],d[n+1];//rudu
	*a=0;
	fill(d,d+(n+1),0);
	vector<int> e[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",f+i,a+i);
		e[f[i]].push_back(i);
		d[i]++;
	}
	queue<int> q;
	q.push(0);
	int tp[n+1],t,cnt=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		tp[cnt++]=t;
		for(int to:e[t])
		{
			d[to]--;
			if(!d[to])
			{
				q.push(to);
			}
		}
	}
	int dp[n+1][m+1];
	fill(*dp,*dp+(n+1)*(m+1),-0x3f3f3f3f);
	#define now tp[i]
	/* for(int i=0;i<=n;i++)
	{
		for(int son:e[now])
		{
			for(int j=0;j<m;j++)
			{
				dp[son][j]=dp[now][j]+a[son];
			}
		}
	} */
	reverse(tp,tp+(n+1));
	// dp[0][0]=0;
	// for(int i=0;i<=n;i++)
	// {
	// 	dp[i][0]=0;
	// }
	for(int i=0;i<=n;i++)
	{
		dp[now][0]=0;
		dp[now][1]=a[now];
		for(int j=2;j<=m;j++)
		{
			// dp[now][j]=0;
			for(int son:e[now])
			{
				for(int k=0;k<j;k++)
				{
					dp[now][j]=max(dp[now][j],dp[now][j-k]+dp[son][k]/* +a[now] */);
			// printf("%d %d %d %d:%d\n",now,j,son,k,dp[now][j]);
				}
			}
			// dp[now][j]=max(dp[now][j],)
		}
	}
	printf("%d",dp[0][m]);
	return 0;
}
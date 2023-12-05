#include <iostream>
#include <vector>
using namespace std;

const int mn=1e5+1,mk=21;

int val[mn],dp[mn][mk];
vector<int> e[mn];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",val+i);
		dp[i][0]=val[i];
	}
	int sum=0,son=0;
	for(int j=1;j<=k;j++)
	{
		for(int u=1;u<=n;u++)
		{
			sum=0;
			son=0;
			for(int v:e[u])
			{
				sum+=dp[v][j-1];
				son++;
			}
			if(j==1)
			{
				dp[u][j]=sum+val[u];
			}
			else
			{
				dp[u][j]=sum-dp[u][j-2]*(son-1);
			}
			#ifndef ONLINE_JUDGE
			printf("%d %d:%d,%d\n",u,j,dp[u][j],sum);
			#endif
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",dp[i][k]);
	}
	return 0;
}
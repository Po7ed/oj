#include <iostream>
using namespace std;

#define M 100001

int dp[M];
int main()
{
	int m,y,n;
	scanf("%d %d %d",&m,&y,&n);
	int v[n+1],w[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	for(int k=0;k<y;k++)
	{
		// fill(dp,dp+M,0);
		for(int i=1;i<=n;i++)
		{
			for(int j=w[i]/1000;j<=m/1000;j++)
			{
				dp[j]=max(dp[j],dp[j-w[i]/1000]+v[i]);
			}
		}
		m+=dp[m/1000];
	}
	printf("%d\n",m);
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int s;
	scanf("%d",&s);
	int v[s+1];
	fill(v,v+s+1,0);
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i%j==0)
			{
				v[i]+=j;
			}
		}
	}
	int dp[s+1];
	fill(dp,dp+s+1,0);
	// dp[1]=1;
	for(int i=1;i<=s;i++)
	{
		for(int j=s;j>=i;j--)
		{
			dp[j]=max(dp[j],dp[j-i]+v[i]);
		}
	}
	printf("%d",dp[s]);
	return 0;
}
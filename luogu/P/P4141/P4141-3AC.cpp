#include <iostream>
#include <cstring>
using namespace std;
int w[2114],dp[2114],t[2114];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",w+i);
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			dp[j]+=dp[j-w[i]];
			dp[j]%=10;
			// printf("%d %d %d\n",i,j,dp[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		t[0]=1;
		for(int j=1;j<=m;j++)
		{
			if(j>=w[i])
			{
				t[j]=(dp[j]-t[j-w[i]]+114000)%10;
			}
			else
			{
				t[j]=dp[j];
			}
			printf("%d",t[j]);
		}
		puts("");
	}
	return 0;
}
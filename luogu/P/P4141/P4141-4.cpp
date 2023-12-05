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
		}
	}
	for(int i=1;i<=n;i++)
	{
		memcpy(t,dp,sizeof(t));
		/* for(int i=1;i<=m;i++)
		{
			printf("%d ",dp[i]);
		}
		puts(""); */
		for(int j=w[i];j<=m;j++)
		{
			t[j]=(t[j]-t[j-w[i]]+10)%10;
		}
		for(int j=1;j<=m;j++)
		{
			printf("%d",t[j]);
		}
		puts("");
	}
	return 0;
}
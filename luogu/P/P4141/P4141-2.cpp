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
		for(int j=w[i];j<=m;j++)
		{
			if(w[i])
			t[j]-=t[j-w[i]];
			t[j]+=(int)1e8;
			t[j]%=10;
		}
		for(int j=1;j<=m;j++)
		{
			printf("%d",(t[j]+(int)1e8)%10);
		}
		puts("");
	}
	return 0;
}
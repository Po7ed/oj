#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m,a,b;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	long long dp[22][22];
	memset(dp,0,sizeof(dp));
	n+=1;
	m+=1;
	a+=1;
	b+=1;
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// if((i==a&&j==b)||(i==a-2&&j==b-1)||(i==a-2&&j==b+1)||(i==a-1&&j==b-2)||(i==a-1&&j==b+2)||(i==a+1&&j==b-2)||(i==a+1&&j==b+2)||(i==a+2&&j==b-1)||(i==a+2&&j==b+1))
			if((i-a)*(i-a)+(j-b)*(j-b)==0||(i-a)*(i-a)+(j-b)*(j-b)==5||i*j==1)
				continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			// printf("!%d %d:%d\n",i,j,dp[i][j]);
		}
	}
	printf("%lld",dp[n][m]);
	return 0;
}
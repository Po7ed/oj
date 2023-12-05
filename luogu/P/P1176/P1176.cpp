#include <iostream>
using namespace std;

int read()
{
	int sgn=0,ret=0;
	char ch=getchar();
	while(ch!=EOF&&!isdigit(ch))
	{
		sgn|=(ch=='-');
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ret=ret*10+(ch-48);
		ch=getchar();
	}
	return (sgn?-ret:ret);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	bool b[n+1][n+1];
	int dp[n+1];
	fill(b[0],b[0]+(n+1)*(n+1),true);
	fill(dp,dp+(n+1),0);
	dp[1]=1;
	int x,y;
	for(int i=0;i<m;i++)
	{
		// scanf("%d %d",&x,&y);
		x=read();
		y=read();
		b[x][y]=false;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==1&&j==1)
				continue;
			if(b[i][j])
				dp[j]+=(j==1?0:dp[j-1]);
			else
				dp[j]=0;
			dp[j]%=100003;
				// dp[j]=((i-1<0?0:dp[i-1][j])+(j-1<0?0:dp[i][j-1]))%100003;
// printf("*%d %d:%d\n",i,j,dp[j]);
		}
	}
	printf("%d",dp[n]);
	return 0;
}
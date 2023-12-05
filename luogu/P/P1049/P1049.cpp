#include <iostream>
using namespace std;
int main()
{
	int v,n;
	scanf("%d\n%d",&v,&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int dp[n+1][v+1];
	fill(*dp,*dp+(n+1)*(v+1),0);
	for(int i=1;i<=v;i++)
	{
		dp[0][i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=v;j++)
		{
			dp[i][j]=min(dp[i-1][j]/* +(j-a[i]) */,(j-a[i]>=0?dp[i-1][j-a[i]]/* +(j-a[i]) */:0x3f3f3f3f));
		}
	}
	printf("%d",dp[n][v]);
	return 0;
}
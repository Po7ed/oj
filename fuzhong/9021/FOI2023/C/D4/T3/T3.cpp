#include <iostream>
#include <string.h>
using namespace std;
const int INF=0x3f3f3f3f;

int main()
{
	int n;
	scanf("%d",&n);
	int s[n],a[n];
	scanf("%d",a);
	*s=*a;
	int t;
	for(int i=1;i<n;i++)//1~n-1
	{
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	int ans=INF;
	int dp[n][n];//min(max) of [i,j]
	for(int w=0;w<n-1;w++)
	{
		swap(a[w],a[w+1]);
		t=s[w];
		s[w]+=(a[w]-a[w+1]);
		// memset(dp,INF,sizeof(dp));
		fill(*dp,*dp+(n)*(n),INF);
		for(int i=0;i<n;i++)//0~n-1
		{
			dp[i][i]=0;
		}
		for(int l=1;l<n;l++)//l=[1,n-1]
		{
			for(int i=0;i<n-l;i++)//i=[0,n-l-1] i+l=j [i,j]
			{
				int j=i+l,sum=(i?s[j]-s[i-1]:s[j]);
				for(int k=i;k<j;k++)//[i,k]&[k+1,j]
				{
					dp[i][j]=min(dp[i][j],sum+dp[i][k]+dp[k+1][j]);
				}
			}
		}
		s[w]=t;
		swap(a[w],a[w+1]);
		ans=min(ans,dp[0][n-1]);
	}
	printf("%d",ans);
	return 0;
}
#include <iostream>
using namespace std;
#define ma(i,j) (dp[i][j]+mi[i][j])
#define mi(i,j) (mi[i][j])

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int dp[n+1][m+1],mi[n+1][m+1];
	fill(*dp,*dp+(n+1)*(m+1),0x3f3f3f3f);
	fill(*mi,*mi+(n+1)*(m+1),-0x3f3f3f3f);
	// dp[0][0]
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=0;
		mi[i][1]=a[i];
	}
	int d;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=min(i,m);j++)
		{
			d=0x3f3f3f3f;
			/* if(!j)
			{
				
			} */
			for(int k=1;k<i-1;k++)
			{
				if(mi(k,j-1)<=a[i]&&a[i]<=ma(k,j-1))
				{
					if(d>dp[k][j-1])
					{
						d=dp[k][j-1];
						mi(i,j)=mi(k,j-1);
					}
				}
				else if(ma(k,j-1)<=a[i])
				{
					if(d>a[i]-mi(k,j-1))
					{
						d=a[i]-mi(k,j-1);
						mi(i,j)=mi(k,j-1);
					}
				}
				else if(a[i]<=mi(k,j-1))
				{
					if(d>ma(k,j-1)-a[i])
					{
						d=ma(k,j-1)-a[i];
						mi(i,j)=a[i];
					}
				}
			}
			dp[i][j]=d;
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=m*2-1;i<=n;i++)
	{
		ans=min(ans,dp[i][m]);
	}
	printf("%d",ans);
	return 0;
}
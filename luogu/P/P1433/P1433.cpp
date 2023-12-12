#include <iostream>
#include <cmath>
using namespace std;

typedef double d;
const int N=16,M=1<<N;
int n,m;
struct p
{
	d x,y;
};
p a[N];

d dp[M][N],dis[N][N];

int main()
{
	scanf("%d",&n);m=1<<n;
	fill(*dp,*dp+N*M,1e9);
	a[0].x=a[0].y=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&a[i].x,&a[i].y);
		for(int j=0;j<i;j++)
		{
			dis[i][j]=dis[j][i]=
			pow((a[i].x-a[j].x)*(a[i].x-a[j].x)+
				(a[i].y-a[j].y)*(a[i].y-a[j].y),0.5);
		}
	}
	dp[0][0]=0;
	for(int S=0;S<m;S++)
	{
		for(int i=1;i<=n;i++)if((S>>(i-1))&1)
		{
			for(int j=0;j<=n;j++)if(!j||(((S>>(j-1))&1)&&i!=j))// j->i
			{
				dp[S][i]=min(dp[S][i],dp[S^(1<<(i-1))][j]+dis[j][i]);
			}
			// printf("%d,%d:%.2lf\n",S,i,dp[S][i]);
		}
	}
	d ans=1e9;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,dp[m-1][i]);
	}
	printf("%.2lf",ans);
	return 0;
}
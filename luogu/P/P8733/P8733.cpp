#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

char Beg;
constexpr int N=22,M=1<<N;//! why
int n;
double d;
double dis[N][N];
struct vi
{
	int x,y;
};
vi a[N];

double dp[M][N];
char End;


int main()
{
	printf("%lluMB\n",(&End-&Beg)/0x100000ull);system("pause>nul");
	int td;
	scanf("%d %d",&n,&td);d=double(td);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		for(int j=0;j<i;j++)
		{
			dis[i][j]=dis[j][i]=sqrt(
			(a[i].x-a[j].x)*(a[i].x-a[j].x)+
			(a[i].y-a[j].y)*(a[i].y-a[j].y));
			if(dis[i][j]>d)dis[i][j]=dis[j][i]=1e9;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	fill(*dp,*dp+M*N,1e9);
	dp[1][0]=0;
	for(int S=1;S<(1<<n);S++)
	{
		for(int i=0;i<n;i++)if((S>>i)&1)
		{
			// printf("%#x %d:%.2lf\n",S,i,dp[S][i]);
			for(int j=0;j<n;j++)if(i!=j&&!((S>>j)&1))// i->j
			{
				dp[S|(1<<j)][j]=min(dp[S|(1<<j)][j],dp[S][i]+dis[i][j]);
			}
		}
	}
	double ans=1e9;
	for(int i=0;i<n;i++)
	{
		ans=min(ans,dis[i][0]+dp[(1<<n)-1][i]);
	}
	printf("%.2lf",ans);
	return 0;
}
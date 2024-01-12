#include <iostream>
using namespace std;

/* 
 * 方格取数，积的十进制 ctz 最小
 * 显然只有 2k*5 产生 0，k ne 0
 * 0 只会变多，不会变少
 * 增加维度：来自
 * 0:D,1:R
 * ***
 * 需要维护路径上 2 的数量、5 的数量（分解质因子）
 */

constexpr int N=1145,INF=0x3f3f3f3f;
int n;
int a[N][N],dp[N][N][2],pre[N][N][2],num[N][N][2];

int cho;
void getpath(int i=n,int j=n)
{
	// printf("%d,%d\n",i,j);system("pause>nul");
	if(i!=1||j!=1)getpath(i-!pre[i][j][cho],j-pre[i][j][cho]),
	printf("%c",pre[i][j][cho]?'R':'D');
}
int ct2(int x)
{
	if(!x)return 0;
	int res=0;
	while(!(x&1))x>>=1,res++;
	return res;
}
int ct5(int x)
{
	if(!x)return 0;
	int res=0;
	while(!(x%5))x/=5,res++;
	return res;
}

int main()
{
	scanf("%d",&n);
	fill(**dp,**dp+(N*N<<1),0x3f3f3f3f);
	int k=0,ans;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",a[i]+j),a[i][j]||(k=i);
			num[i][j][0]=ct2(a[i][j]);
			num[i][j][1]=ct5(a[i][j]);
			// printf("*%d,%d*",num[i][j][0],num[i][j][1]);
		}
	}
	dp[1][1][0]=num[1][1][0];
	dp[1][1][1]=num[1][1][1];
	int l,u;
	for(int k=0;k<2;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=(i-1?1:2);j<=n;j++)
			{
				u=dp[i-1][j][k]+num[i][j][k];
				l=dp[i][j-1][k]+num[i][j][k];
				if(u>l)
				{
					dp[i][j][k]=l;
					pre[i][j][k]=1;
				}
				else
				{
					dp[i][j][k]=u;
					pre[i][j][k]=0;
				}
				// printf("%d,%d,%d:%d\n",i,j,k,dp[i][j][k]);
			}
		}
	}
	ans=min(dp[n][n][0],dp[n][n][1]);
	if(k&&ans>1)
	{
		puts("1");
		for(int i=1;i<k;i++)printf("D");
		for(int i=1;i<n;i++)printf("R");
		for(int i=k;i<n;i++)printf("D");
	}
	else
	{
		printf("%d\n",ans);
		cho=dp[n][n][0]>dp[n][n][1];
		getpath();
	}
	return 0;
}
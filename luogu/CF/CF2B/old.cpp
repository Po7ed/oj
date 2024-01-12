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
int a[N][N],dp2[N][N],dp5[N][N],pre[N][N];

void getpath(int i=n,int j=n)
{
	// printf("%d,%d\n",i,j);
	if(i!=1||j!=1)getpath(i-!pre[i][j],j-pre[i][j]),printf("%c",pre[i][j]?'R':'D');
}
int ct2(int x)
{
	int res=0;
	while(!(x&1))x>>=1,res++;
	return res;
}
int ct5(int x)
{
	int res=0;
	while(!(x%5))x/=5,res++;
	return res;
}

int main()
{
	scanf("%d",&n);
	// fill(**dp,**dp+(N*N<<1),0x3f3f3f3f);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",a[i]+j);
	int tu,tl,c2,c5;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c2=ct2(a[i][j]),c5=ct5(a[i][j]);
			if(i^1)tu=min(dp2[i-1][j]+c2,dp5[i-1][j]+c5);else tu=INF;
			if(j^1)tl=min(dp2[i][j-1]+c2,dp5[i][j-1]+c5);else tl=INF;
			if(tu>tl)pre[i][j]=1,dp2[i][j]=dp2[i][j-1]+c2,dp5[i][j]=dp5[i][j-1]+c5;
			else pre[i][j]=0,dp2[i][j]=dp2[i-1][j]+c2,dp5[i][j]=dp5[i-1][j]+c5;
		}
	}
	printf("%d\n",min(dp2[n][n],dp5[n][n]));
	getpath();
	return 0;
}
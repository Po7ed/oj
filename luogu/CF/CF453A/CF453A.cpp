#include <iostream>
#include <cmath>
using namespace std;

constexpr int N=114514;
int n,m;
double dp[N],suf[N];

int main()
{
	scanf("%d %d",&m,&n);
	double dm=m*1.0;
	for(int i=m;i>=1;i--)
	{
		suf[i]=suf[i+1]+i;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=(dp[i-1]/dm)*dp[i-1]+
		((dm-dp[i-1])/dm)*suf[(int)(double)floor(dp[i-1])+1]/
		(dm-(double)floor(dp[i-1]));
	}
	printf("%.8lf",dp[n]);
	return 0;
}
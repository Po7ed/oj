#include <iostream>
#include <algorithm>
using std::min;
using std::sort;
typedef long long ll;
constexpr int N=2145;
ll dp[N][N];
int a[N],n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),dp[i][i]=0;
	sort(a+1,a+n+1);
	for(int l=2;l<=n;l++)
	{
		#define j (i+l-1)
		for(int i=1;j<=n;i++)
		{
			dp[i][j]=min(dp[i+1][j],dp[i][j-1])+a[j]-a[i];
		}
	}
	printf("%lld",dp[1][n]);
	return 0;
}
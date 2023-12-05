#include <iostream>
#include <vector>
using namespace std;
int main()
{
	// freopen("out","w",stdout);
	int n;
	scanf("%d",&n);
	int ww[n+1],aa[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",ww+i);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",aa+i);
	}
	int m;
	scanf("%d",&m);
	vector<int> w={0};
	vector<int> a={0};
	for(int i=1;i<=n;i++)
	{
		int cur=1;
		while(aa[i]-cur>=0)
		{
			aa[i]-=cur;
			w.push_back(cur*ww[i]);
			a.push_back(cur);
			cur*=2;
		}
		if(aa[i])
		{
			w.push_back((aa[i]*ww[i]));
			a.push_back(aa[i]);
		}
	}
	n=w.size()-1;
	int dp[m+1];
	fill(dp,dp+(m+1),0x3f3f3f3f);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		// for(int j=1;j<w[i]&&j<=m;j++)
		// {
		// 	dp[j]=dp[i-1][j];
		// }
		for(int j=m;j>=w[i];j--)
		{
			dp[j]=min(dp[j],dp[j-w[i]]+a[i]);
			// printf("%d %d:%dby%d %d\n",i,j,dp[i][j],dp[i-1][j],dp[i-1][j-w[i]]+a[i]);
		}
	}
	printf("%d",dp[m]);
	return 0;
}
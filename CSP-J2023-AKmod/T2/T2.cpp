#include <iostream>
#include <vector>
using namespace std;
int dp[21],pre[21];
int dis[21][21],a[21];
int main()
{
	// freopen("trea.in","r",stdin);
	// freopen("trea.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		dp[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			scanf("%d",&dis[i][j]);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dis[i][j])
			{
				if(dp[j]<dp[i]+a[j])
				{
					dp[j]=dp[i]+a[j];
					pre[j]=i;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[ans]<dp[i])
		{
			ans=i;
		}
	}
	int ta=ans;
	vector<int> ord;
	do
	{
		ord.push_back(ta);
		ta=pre[ta];
	}
	while(ta);
	while(!ord.empty())
	{
		printf("%d ",ord.back());
		ord.pop_back();
	}
	printf("\n%d",dp[ans]);
	return 0;
}
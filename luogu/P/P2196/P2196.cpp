#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	vector<int> pre[n+1],nxt[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int t;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			scanf("%d",&t);
			if(t)
			{
				pre[j].push_back(i);
				nxt[i].push_back(j);
			}
		}
	}
	pre[1].push_back(0);
	int dp[n+1],ans=-1;
	fill(dp,dp+(n+1),0);
	// vector<int> end;
	vector<int> pla[n+1];
	vector<int> p;
	for(int i=1;i<=n;i++)
	{
		for(int j:pre[i])
		{
			if(dp[i]<dp[j])
			{
				dp[i]=dp[j];
				pla[i]=pla[j];
			}
		}
		dp[i]+=a[i];
		pla[i].push_back(i);
		if(nxt[i].empty())
		{
			// end.push_back(i);
			if(ans<dp[i])
			{
				ans=dp[i];
				p=pla[i];
			}
			// ans=max(ans,dp[i]);
		}
		// printf("%d %d\n",i,dp[i]);
	}
	int l=p.size();
	for(int i=0;i<l;i++)
	{
		printf("%d%c",p[i]," \n"[i+1==l]);
	}
	printf("%d",ans);
	return 0;
}
#include <iostream>
using namespace std;

int n,a[211451],s[211451],dp[211451];

int main()
{
	// freopen("remove.in","r",stdin);
	// freopen("remove.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	fill(s+1,s+(n+1),-1);
	s[a[1]]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(s[a[i]]!=-1)
		{
			dp[i]=max(dp[i],i+dp[s[a[i]]]-s[a[i]]);
		}
		if(s[a[i]]<0||(dp[s[a[i]]]-s[a[i]]<dp[i-1]-i+1))
		{
			s[a[i]]=i-1;
		}
	}
	printf("%d",dp[n]);
	return 0;
}
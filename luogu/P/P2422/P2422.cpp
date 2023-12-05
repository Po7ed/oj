#include <iostream>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	long long a[n+1],s[n+1],m[n+1],dp[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	s[1]=a[1];
	m[1]=a[1];
	dp[1]=s[1]*m[1];
	for(int i=2;i<=n;i++)
	{
		if((s[i-1]+a[i])*min(m[i-1],a[i])>a[i]*a[i])
		{
			s[i]=s[i-1]+a[i];
			m[i]=min(m[i-1],a[i]);
			dp[i]=s[i]*m[i];
		}
		else
		{
			s[i]=a[i];
			m[i]=a[i];
			dp[i]=s[i]*m[i];
		}
	}
	long long ans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}
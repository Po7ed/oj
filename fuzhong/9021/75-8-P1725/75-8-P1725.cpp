#include <iostream>
#include <deque>
// #include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n,l,r,ans=-0x7fffffff;
	scanf("%d %d %d",&n,&l,&r);
	deque<int> q;
	int a[n+r+1],m[n+r+1],dp[n+r+1];
	fill(a,a+n+r+1,0);
	// fill(m)
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dp[0]=0;
	m[0]=0;
	for(int i=1;i<=n+r;i++)
	{
		/* if(i<l)
		{
			p[i]=(i-r<0?-0x7fffffff:m[i-r])+a[i];
			m[i]=0;
			q.push_back(i);
			continue;
		} */
		if(i<=n)
		{
			dp[i]=(i-l<0?-0x7fffffff:m[i-r])+a[i];
		}
		else
		{
			dp[i]=m[i-r];
			ans=max(ans,dp[i]);
		}
		// m[i]=-0x7fffffff;
		while(!q.empty()&&q.front()<=i-(r-l+1))
			q.pop_front();
		while(!q.empty()&&dp[q.back()]<dp[i])
			q.pop_back();
		q.push_back(i);
		m[i-r+l]=dp[q.front()];
		/* if(i>=r)
		{
			m[i-r]=q.front();
		} */
	}
	printf("%d",ans);
	return 0;
}
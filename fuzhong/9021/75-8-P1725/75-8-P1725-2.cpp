#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// #define INF 0x3f3f3f3f
// #define INF -0x7fffffff
// -0x7fffffff
int main()
{
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	long long a[n+1],m[n+1],m2[n+1];//m[i]:max(dp[i]~dp[i+r-l])
	deque<int> q;
	vector<int> v;
	for(int i=0;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long dp[n+1],ans=-0x7fffffff;
	q.push_back(0);
	v.push_back(0);
	fill(dp,dp+n+1,-0x7fffffff);
	fill(m,m+n+1,-0x7fffffff);
	dp[0]=0;
	m2[0]=0;
	// if(dp)
	for(int i=1;i<=n;i++)
	{
		/* if(i<l)
		{
			if(i==0)
				dp[0]=0;
			else
				dp[i]=-0x7fffffff;
			if(i+r-l<l)
			{
				if(i==0)
					m[i]=0;
				else
					m[i]=-0x7fffffff;
			}
			continue;
		} */
		// dp[i]=m[i-r]+a[i];
		if(r==l)
		{
			dp[i]=(i-l<0?(-0x7fffffff):dp[i-l])+a[i];
		}
		else
		{
			dp[i]=(i-r<0?(i-l<0?(-0x7fffffff):m2[i-l]):m[i-r])+a[i];
		}

		while(!v.empty()&&dp[v.back()]<dp[i])
			v.pop_back();
		v.push_back(i);

		if(!q.empty()&&q.front()<=i-(r-l+1))
			q.pop_front();
		while(!q.empty()&&dp[q.back()]<dp[i])
			q.pop_back();
		q.push_back(i);

		m[i-r+l]=dp[q.front()];
		m2[i]=dp[v.front()];

		if(i+r>n)
		{
			ans=max(ans,dp[i]);
		}
	}
	printf("%lld",ans);
	return 0;
}
/* 
10 5 6
0 10 2 13 24 -5 -6 1 0 3 -1
 */
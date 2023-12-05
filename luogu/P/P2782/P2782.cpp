#include <iostream>
#include <algorithm>
using namespace std;

typedef struct paircities
{
	int x,y;
}pc;
inline bool cmp(pc a,pc b)
{
	return (a.x==b.x?a.y<b.y:a.x<b.x);
}

inline bool cross(pc a,pc b)
{
	return ((a.x<b.x&&a.y>b.y)||(a.x>b.x&&a.y<b.y));
}

int main()
{
	int n;
	scanf("%d",&n);
	pc a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+(n+1),cmp);
	int dp[n+1];
	fill(dp,dp+(n+1),0);
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=i-1;j>0;j--)
		{
			if(!cross(a[i],a[j]))
			{
				// dp[i]=max(dp[i],dp[j]+1);
				dp[i]=dp[j]+1;
				break;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
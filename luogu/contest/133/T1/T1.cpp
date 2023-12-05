#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],dp[n];
	dp[0]=1;
	vector<int> b;
	// b.push_back(0);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			dp[i]=dp[i-1]+1;
		}
		else
		{
			b.push_back(i);
			dp[i]=1;
		}
		x=max(x,dp[i]);
	}
	b.push_back(n);
	int l=b.size(),m=-1;
	for(int i=1;i<l;i++)
	{
		if(a[b[i-1]-1]<a[b[i-1]+1]-1||(b[i-1]-2==(-1)?(-0x3f3f3f3f):a[b[i-1]-2])<a[b[i-1]]-1||b[i]==b[i-1]+1)
			m=max(m,dp[b[i]-1]+dp[b[i-1]-1]);
	}
	printf("%d",max(m,x));
	return 0;
}
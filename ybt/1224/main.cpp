#include <iostream>
#include <string.h>
using namespace std;

int linemax(int n,int a[])
{
	int dp[n];
	dp[0]=max(a[0],-0x3f3f3f3f);
	for(int i=1;i<n;i++)
		dp[i]=max(dp[i-1]+a[i],a[i]);
	int m=-0x3f3f3f3f;
	for(int i=0;i<n;i++)
		if(dp[i]>m)m=dp[i];
	return m;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int ta[n];
	int m=-0x3f3f3f3f;
	for(int i1=0;i1<n;i1++)
		for(int i2=i1;i2<n;i2++)
		{
			memset(ta,0,sizeof(ta));
			for(int i=i1;i<=i2;i++)
				for(int j=0;j<n;j++)
					ta[j]+=a[i][j];
			int t=linemax(n,ta);
			if(t>m)m=t;
		}
	printf("%d",m);
	return 0;
}
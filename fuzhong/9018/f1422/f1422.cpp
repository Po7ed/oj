#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	// int dp[n+1];memset(dp,0,sizeof(dp));
	int sum=0,t,m=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		sum=max(t,sum+t);
		m=max(m,sum);
	}
	printf("%d",m<0?0:m);
	return 0;
}
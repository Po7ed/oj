#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int m=-1;
	int a[100],dp[100];
	int i=0;
	while(scanf("%d",&a[i])!=EOF)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>=a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		m=max(m,dp[i]);
		i++;
	}
	printf("%d",m);
	return 0;
}
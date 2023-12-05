#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
	int m=-1,mi=-1;
	int a[100],dp[100];
	vector<int> v[100];
	int i=0;
	while(scanf("%d",&a[i])!=EOF)
	{
		dp[i]=1;v[i].push_back(a[i]);
		for(int j=0;j<i;j++)
		{
			if(a[j]>=a[i]&&dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
				v[i]=v[j];
				v[i].push_back(a[i]);
			}
		}
		// m=max(m,dp[i]);
		if(m<dp[i])
		{
			m=dp[i];
			mi=i;
		}
		i++;
	}
	printf("%d\n",m);
	for(int t:v[mi])
	{
		printf("%d ",t);
	}
	return 0;
}
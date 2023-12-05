#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sum+=a[i];
	}
	bool dp[sum+1][sum+1];
	fill(*dp,*dp+(sum+1)*(sum+1),false);
	dp[0][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum-a[i];j>=0;j--)
		{
			for(int k=sum-a[i];k>=0;k--)
			{
				dp[j+a[i]][k]|=dp[j][k];
				dp[j][k+a[i]]|=dp[j][k];
			}
		}
	}
	for(int i=sum;i>0;i--)
	{
		if(dp[i][i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("Impossible");
	return 0;
}
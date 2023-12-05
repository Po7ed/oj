#include <iostream>
using namespace std;

int a[1145],dp[1145][1145];

int main()
{
	// freopen("remove.in","r",stdin);
	// freopen("remove.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int l=2;l<=n;l++)
	{
		#define j (i+l-1)
		for(int i=1;j<=n;i++)
		{
			if(a[i]==a[j])
			{
				dp[i][j]=l;
			}
			for(int k=i;k+1<=j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}
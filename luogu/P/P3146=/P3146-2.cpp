#include <iostream>
using namespace std;

const int N=250;
int a[N],dp[N][N];

int main()
{
	int n;
	scanf("%d",&n);
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		dp[i][i]=a[i];
		ans=max(ans,a[i]);
	}
	// size_t now;
	for(int l=2;l<=n;l++)
	{
		#define j (i+l-1)
		#define L [i][k]
		#define R [k+1][j]
		#define N [i][j]
		for(int i=1;j<=n;i++)
		{
			for(int k=i;k<j;k++)
			{
				if(dp L==dp R&&dp L)
				{
					dp N=max(dp N,dp L+1);
				}
			}
			ans=max(ans,dp N);
		}
	}
	printf("%d",ans);
	return 0;
}
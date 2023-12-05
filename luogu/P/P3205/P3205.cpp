#include <iostream>
using namespace std;
int a[1145],dp[1145][1145][2];
const int mod=19650827;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	#define j i+l-1
	for(int l=1;l<=n;l++)
	{
		for(int i=1;j<=n;i++)
		{
			if(i==j)
			{
				dp[i][j][0]=dp[i][j][1]=1;
				if(j<n)
				{
					if(a[i]<a[i+1])
					{
						// dp[i][j+1][0]++;
						dp[i][j+1][1]++;
						dp[i][j+1][1]%=mod;
					}
				}
				if(i>1)
				{
					if(a[i]>a[i-1])
					{
						dp[i-1][j][0]++;
						dp[i-1][j][0]%=mod;
						// dp[i-1][j][1]++;
					}
				}
			}
			else
			{
				if(j<n)
				{
					if(a[i]<a[j+1])
					{
						dp[i][j+1][1]+=dp[i][j][0];
						dp[i][j+1][1]%=mod;
					}
					if(a[j]<a[j+1])
					{
						dp[i][j+1][1]+=dp[i][j][1];
						dp[i][j+1][1]%=mod;
					}
				}
				if(i>1)
				{
					if(a[i]>a[i-1])
					{
						dp[i-1][j][0]+=dp[i][j][0];
						dp[i-1][j][0]%=mod;
					}
					if(a[j]>a[i-1])
					{
						dp[i-1][j][0]+=dp[i][j][1];
						dp[i-1][j][0]%=mod;
					}
				}
			}
		}
	}
	printf("%d",(dp[1][n][0]+dp[1][n][1])%mod);
	return 0;
}
/* 
i     j j+1
[ u ] new
i-1 i     j
new [ u ]
 */
#include <iostream>
using namespace std;

const int N=19,M=(1<<N);
int w[N],dp[M],hav[M];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",w+i);
	}
	dp[0]=0;
	hav[0]=0;
	// int j;	
	for(int i=1;i<(1<<n);i++)
	{
		dp[i]=0x3f3f3f3f;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				if(hav[i^(1<<j)]<w[j]&&dp[i]>=dp[i^(1<<j)]+1)
				{
					hav[i]=max(hav[i],m-w[j]);
					dp[i]=dp[i^(1<<j)]+1;
				}
				else if(dp[i]>=dp[i^(1<<j)])
				{
					hav[i]=max(hav[i],hav[i^(1<<j)]-w[j]);
					dp[i]=dp[i^(1<<j)];
				}
			}
		}
	}
	printf("%d",dp[(1<<n)-1]);
	return 0;
}
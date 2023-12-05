#include <iostream>
using namespace std;

typedef long long ll;
const int mod=1e9+7,N=1145,M=204;
ll dp[M][M],sum[M][M];
char a[N],b[M];

int main()
{
	int n,m,p;
	scanf("%d %d %d\n%s %s",&n,&m,&p,a+1,b+1);
	sum[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=min(m,i);j;j--)
		{
			for(int k=min(p,j);k;k--)
			{
				if(a[i]==b[j])dp[j][k]=dp[j-1][k]+sum[j-1][k-1];
				else dp[j][k]=0;
				sum[j][k]=(sum[j][k]+dp[j][k])%mod;
			}
		}
	}
	printf("%lld",sum[m][p]);
	return 0;
}

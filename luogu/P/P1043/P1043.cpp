#include <iostream>
using namespace std;

const int mod=10;
#define id(_i) ((_i+b-2)%(n)+1)

typedef long long ll;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	ll a[n+1]/* ,s[n+1],sum=0 */;
	// s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		// sum+=a[i];
		// s[i]=s[i-1]+a[i];
	}
	ll dp[n+1][n+1][m+1],dp_[n+1][n+1][m+1],ma=-0x3f3f3f3f3f3f,mi=0x3f3f3f3f3f3f;
	for(int b=1;b<=n;b++)// begin on b 
	{
		fill(**dp,**dp+(n+1)*(n+1)*(m+1),-0x3f3f3f3fll);
		fill(**dp_,**dp_+(n+1)*(n+1)*(m+1),0x3f3f3f3fll);
		// s[0]=0;
		// s[b]=a[b];
		for(int i=1;i<=n;i++)
		{
			dp[i][i][1]=(a[id(i)]+mod*1000)%mod;
			dp_[i][i][1]=(a[id(i)]+mod*1000)%mod;
			// s[id(i)]=(s[id(i-1)]+a[id(i)]+mod*10)%mod;
		}
		for(int l=1;l<n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				// dp[l][r][1]=dp_[l][r][1]=(s[id(r)]-s[id(l-1)]+mod*10)%mod;
				dp[l][r][1]=dp_[l][r][1]=(dp[l][r-1][1]+a[id(r)]+mod*1000)%mod;
			}
		}
		// dp[1][n][1]=sum;
		for(int l=1;l<n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				for(int i=2;i<=min(m,r-l+1);i++)
				{
					// dp[l][r][i]
					for(int k=l;k<r;k++)// [i,k],[k+1,r]
					{
						for(int li=1;(li<=k-l+1)&&(i-li<=r-k)&&(li<i);li++)
						{
							if(dp[l][k][li]>-0x3f3f3f3fll&&dp[k+1][r][i-li]>-0x3f3f3f3fll)
								dp[l][r][i]=max(dp[l][r][i],dp[l][k][li]*dp[k+1][r][i-li]);
							if(dp_[l][k][li]<0x3f3f3f3fll&&dp_[k+1][r][i-li]<0x3f3f3f3fll)
								dp_[l][r][i]=min(dp_[l][r][i],dp_[l][k][li]*dp_[k+1][r][i-li]);
							/* if(l==1&&r==4&&i==2)
							{
							} */
							/* printf("%2d %2d %2d %15lld %15lld\n",l,r,i,dp_[l][k][li],dp_[k+1][r][i-li]);
							if(dp_[k+1][r][i-li]<0)
							{
								printf("*%d %d %d\n",k+1,r,i-li);
							} */
						}
					}
					// puts("");
				}
			}
		}
		ma=max(ma,dp[1][n][m]);
		mi=min(mi,dp_[1][n][m]);
	}
	printf("%lld\n%lld",mi,ma);
	return 0;
}
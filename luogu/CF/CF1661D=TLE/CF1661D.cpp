#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll a[314514];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	ll neg,ans=0;
	for(int i=n;i>0;i--)
	{
		if(a[i]>0)
		{
			if(i-k<0)
			{
				neg=(ll)ceil((double)a[i]/(double)i);
				ans+=neg;
				for(int j=1;j<=k;j++)
				{
					a[j]-=(j*neg);
				}
			}
			else
			{
				neg=(ll)ceil((double)a[i]/(double)k);
				ans+=neg;
				for(int j=1;j<=k;j++)
				{
					a[i-k+j]-=(j*neg);
				}

			}
		}
		// printf("%d %lld\n",i,neg);
		// for(int j=1;j<=n;j++)
		// {
		// 	printf("%lld ",a[j]);
		// }
		// puts("");
	}
	printf("%lld",ans);
	return 0;
}
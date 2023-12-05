#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	scanf("%d",&n);
	ll a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	int q;
	scanf("%d",&q);
	ll l0,r0;
	scanf("%lld %lld",&l0,&r0);
	ll rg=a[l0],mid=l0;
	for(int i=l0+1;i<=r0;i++)
	{
		rg=__gcd(rg,a[i]);
	}
	printf("%lld\n",rg%11);
	ll l,r,lg[n+1];
	for(int i=2;i<=q;i++)
	{
		scanf("%lld %lld",&l,&r);
		if(mid<l)
		{
			mid=r;
			rg=a[r];
			lg[mid]=a[mid];
			for(int j=mid-1;j>=l;j--)
			{
				lg[j]=__gcd(lg[j+1],a[j]);
			}
		}
		else
		{
			for(int j=r0+1;j<=r;j++)
			{
				rg=__gcd(rg,a[j]);
			}
		}
		printf("%lld\n",__gcd(lg[l],rg)%11);
		l0=l;
		r0=r;
	}
	return 0;
}
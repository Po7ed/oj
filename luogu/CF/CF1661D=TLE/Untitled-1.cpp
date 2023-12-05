#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
const int N=300005;
int n,k;
ll ans,sum1,sum2;
ll a[N],c[N];

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=n;i>0;i--)
	{
		sum1+=c[i];
		sum2+=sum1;
		ll l=max(1,i-k+1),len=i-l+1,d=(a[i]+sum2+len-1)/len;
		if(d>0)
		{
			ans+=d;
			if(l-2>0)
			{
				c[l-2]-=d;
			}
			c[i-1]+=(len+1)*d;
			sum1-=len*d;
			sum2-=len*d;
		}
	}
	printf("%lld",ans);
	return 0;
}
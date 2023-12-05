#include <iostream>
using namespace std;

typedef long long ll;
const int N=5145141,mod=998244353;
ll a[N];

ll qpow(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}

int main()
{
	freopen("circle1.in","r",stdin);
	freopen("circle.out","w",stdout);
	int n;
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sum+=a[i];
	}
	int j=1;
	ll dis=0,cnt=0;
	for(int i=1;j<=n;i++)
	{
		while(dis<sum/2&&j<=n)
		{
			dis+=a[j];
			j++;
		}
		if(j>n)
		{
			break;
		}
		if(dis==sum/2)
		{
			cnt++;
		}
		dis-=a[i];
	}
	printf("%lld",qpow(2,cnt)-1-cnt);
	return 0;
}
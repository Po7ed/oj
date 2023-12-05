#include <iostream>
using namespace std;
// Sn=(a^n-1)/(a-1) mod m
typedef long long ll;
ll a,k,m;
int qpow(ll a,ll b)
{
	ll ans=1ll;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
			ans%=m;
		}
		a*=a;
		a%=m;
		b>>=1;
	}
	return ans%m;
}

ll inv(ll a)
{
    return qpow(a,m-2);
}

int main()
{
	scanf("%lld %lld %lld",&a,&k,&m);
	if(k<=1000000)
	{
		ll ans=1ll,tmp=1ll;
		for(int i=1;i<=k;i++)
		{
			tmp*=a;
			tmp%=m;
			ans+=tmp;
			ans%=m;
		}
		printf("%lld",ans);
		return 0;
	}
	ll sum=(qpow(a,k)-1)%m*inv(a-1)%m;
	printf("%lld",sum);
	return 0;
}
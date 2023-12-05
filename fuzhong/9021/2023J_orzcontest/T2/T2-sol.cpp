#include <iostream>
using namespace std;
typedef long long ll;
ll a,k,mod;
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1ll;
	}
	return ans%mod;
}
ll get(ll x)
{
	if(!x) 
	{
		return 1;
	}
	ll tmp=get((x-1)>>1)%mod*(qpow(a,((x+1)>>1))+1)%mod;
	if(x&1^1)
	{
		tmp=(tmp+qpow(a,x))%mod;
	}
	return tmp%mod;
}
int main()
{
	// freopen("genshin.in","r",stdin);
	// freopen("genshin.out","w",stdout);
	scanf("%lld %lld %lld",&a,&k,&mod);
	printf("%lld",get(k));
	return 0;
}
#include <iostream>
using namespace std;

typedef long long ll;

const ll mod=19260817;

#include <cctype>
ll read()
{
	ll res=0;
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	while(isdigit(c))
	{
		res=(res*10+c-'0')%mod;
		c=getchar();
	}
	return res;
}

ll qpow(ll base,ll exp)
{
	ll ans=1;
	while(exp)
	{
		if(exp&1)
		{
			ans*=base;
			ans%=mod;
		}
		base*=base;
		base%=mod;
		exp>>=1ll;
	}
	return ans%mod;
}

inline ll inv(ll x)
{
	return qpow(x,mod-2);
}

int main()
{
	ll a,b;
	a=read();
	b=read();
	if(!b)
	{
		puts("Angry!");
		return 0;
	}
	printf("%lld",(a*inv(b)%mod+mod)%mod);
	return 0;
}
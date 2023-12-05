#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll n,p;
ll a[1000114];
const ll mod=998244353ll;

#include <cstdio>
#include <cctype>
const ll BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
inline char getch(){
    if(is == it)
        it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
    return is == it ? EOF : *is++;
}
inline ll read(){
    ll res = 0, neg = 0;
	char ch = getch();
    while(!(isdigit(ch) or ch == '-') and ch != EOF)
        ch = getch();
    if(ch == '-')
        neg = 1, ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return neg ? -res : res;
}

// ll mem[50000114];
// unordered_map<ll,ll> mem;
ll qpow(ll x)
{
	ll res=1,tp=p;
	while(x)
	{
		if(x&1)
		{
			res=(res*tp)%mod;
		}
		tp=(tp*tp)%mod;
		x>>=1;
	}
	return res%mod;
}

int main()
{
	// fill(mem,mem+100114,-1);
	// scanf("%lld %lld",&n,&p);
	n=read();
	p=read();
	for(int i=1;i<=n;i++)
	{
		// scanf("%lld",a+i);
		a[i]=read();
		// printf("%d\n",a[i]);
	}
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=((ll)(qpow(a[i])%mod+1)%mod);
		ans%=mod;
		// printf("%lld\n",ans);
	}
	printf("%lld",ans%mod);
	return 0;
}
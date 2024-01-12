#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=5114514;

#include <cctype>
template<typename T>
void read(T &x)
{
	x=0;char c;
	do c=getchar();while(!isdigit(c));
	while(isdigit(c))x=x*10ll+c-'0',c=getchar();
}
template<typename T,typename ...Args>
inline void read(T &x,Args &...o){read(x),read(o...);}

int n;
ll p,k;
ll a[N],s[N],sinv[N];

ll qpow(ll base,ll pow=p-2ll)
{
	ll res=1ll;
	while(pow)
	{
		if(pow&1ll)res=res*base%p;
		base=base*base%p;
		pow>>=1ll;
	}
	return res;
}

int main()
{
	// scanf("%d %lld %lld",&n,&p,&k);
	read(n,p,k);
	s[0]=1ll;
	for(int i=1;i<=n;i++)/* scanf("%lld",a+i) */read(a[i]),s[i]=s[i-1]*a[i]%p;
	sinv[n]=qpow(s[n]);
	for(int i=n-1;i;i--)sinv[i]=sinv[i+1]*a[i+1]%p;
	ll ans=0ll,kpow=k;
	for(int i=1;i<=n;i++,kpow=kpow*k%p)ans=(ans+((sinv[i]*s[i-1])%p*kpow)%p)%p;
	printf("%lld",ans);
	return 0;
}
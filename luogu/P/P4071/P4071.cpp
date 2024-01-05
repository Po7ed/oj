#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=1145141;
constexpr ll mod=1e9+7;

ll f[N];
int T,n,m;

ll fac[N];
ll inv(ll base)
{
	ll res=1ll,pow=mod-2ll;
	base%=mod;
	while(pow)
	{
		if(pow&1)res=res*base%mod;
		base=base*base%mod;
		pow>>=1ll;
	}
	return res;
}

inline void init()
{
	fac[0]=1ll;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
	f[0]=1ll,f[1]=0ll;for(int i=2;i<N;i++)f[i]=(i-1)*((f[i-1]+f[i-2])%mod)%mod;
}

inline ll C(int n,int m){return fac[n]*inv(fac[m])%mod*inv(fac[n-m])%mod;}

inline ll solve(int n,int m){return C(n,m)*f[n-m]%mod;}

#include <cctype>
inline int read()
{
	int res=0ll;char c;
	do c=getchar();while(!isdigit(c));
	while(isdigit(c))res=res*10+c-'0',c=getchar();
	return res;
}

int main()
{
	init();/* T=read();
	while(T--){n=read(),m=read(),printf("%lld\n",solve(n,m));} */
	for(int i=1;i<=20;i++)printf("%d,",f[i]);
	return 0;
}
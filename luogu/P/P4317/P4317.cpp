#include <iostream>
using namespace std;

typedef long long ll;
constexpr int LN=51;
constexpr ll mod=10000007;

int a[LN];
ll n;
int m;

ll mem[LN][LN][2],ans[LN];
#define now mem[i][sum][small]
ll dfs(int i,int sum=0,bool small=false)
{
	if(~now)return now;
	if(!i)return now=(sum==m);
	now=0ll;
	now+=dfs(i-1,sum,small||a[i]);
	if(small||a[i])now+=dfs(i-1,sum+1,small||!a[i]);
	return now;
}
ll calc(ll x)
{
	fill(**mem,**mem+(LN*LN<<1),-1ll);
	int cnt=0;
	while(x)
	{
		a[++cnt]=x&1ll;
		x>>=1ll;
	}
	return dfs(cnt);
}

ll qpow(ll base,ll pow)
{
	ll res=1;
	while(pow)
	{
		if(pow&1ll)res=res*base%mod;
		base=base*base%mod;
		pow>>=1ll;
	}
	return res;
}

int main()
{
	scanf("%lld",&n);
	ll ans=1;
	for(m=1;m<=50;m++)
	{
		ans=ans*qpow(m,calc(n))%mod;
	}
	printf("%lld",ans);
	return 0;
}
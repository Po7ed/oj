#include <iostream>
using namespace std;

typedef long long ll;
constexpr ll mod=1e9+7,B=10,S[B]={0,1,3,6,10,15,21,28,36,45};
constexpr int N=20;
int T;

ll dp[N];
void init()
{
	ll mi=1;
	for(int i=1;i<N;i++)
	{
		dp[i]=(dp[i-1]*B+S[9]*mi)%mod;
		mi*=B;
	}
}

ll calc(ll x)
{
	ll tx=x,res=0,tmp,mi=1;
	for(int i=1;tx;i++)
	{
		tmp=tx%B;
		(res+=(dp[i-1]*tmp+S[tmp]*mi))%=mod;
		tx/=B;mi*=B;
	}
	return res;
}

int main()
{
	scanf("%d",&T);
	int l,r;
	init();
	while(T--)
	{
		scanf("%d %d",&l,&r);
		printf("%lld\n",calc(r)-calc(l-1));
	}
	return 0;
}
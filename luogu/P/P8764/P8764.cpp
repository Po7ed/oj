#include <iostream>
using namespace std;

typedef long long ll;
constexpr int LN=64;

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


int main()
{
	scanf("%lld %d",&n,&m);
	printf("%lld",calc(n));
	return 0;
}
#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=20,S=N*10;
int T;
int a[N];
ll mem[N][S][2];
#define now mem[i][sum][small]
ll dfs(int i,int sum=0,bool small=false)
{
	if(~now)return now;
	if(!i)return now=ll(sum);
	now=0;
	for(int j=0;j<=9;j++)if(small||j<=a[i])
		now+=dfs(i-1,sum+j,small||j^a[i]);
	return now;
}

ll calc(ll x)
{
	if(x<=0)return 0ll;
	fill(**mem,**mem+(N*S<<1),-1ll);
	int cnt=0;
	while(x)a[++cnt]=x%10ll,x/=10ll;
	return dfs(cnt);
}

int main()
{
	scanf("%d",&T);
	ll l,r;
	while(T--)
	{
		scanf("%lld %lld",&l,&r);
		printf("%lld\n",calc(r)-calc(l-1));
	}
	return 0;
}
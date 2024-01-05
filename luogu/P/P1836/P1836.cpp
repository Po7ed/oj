#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=10,S=N*10;

int a[N];
ll mem[N][S][2];
#define now mem[i][sum][small]
ll dfs(int i,int sum=0,bool small=false)
{
	if(~now)return now;
	if(!i)return now=ll(sum);
	now=0;
	for(int j=0;j<=9;j++)if(small||j<=a[i])
		now+=dfs(i-1,sum+j,small||j<a[i]);// or small||j^a[i]
	return now;
}

ll calc(ll x)
{
	fill(**mem,**mem+(N*S<<1),-1ll);
	int cnt=0;
	while(x)a[++cnt]=x%10ll,x/=10ll;
	return dfs(cnt);
}

int main()
{
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",calc(n));
	return 0;
}
#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=11,INF=0x3f3f3f3f;

int a[N];

ll mem[N][N][2][2];
#define now mem[i][lst][zero][small]
ll dfs(int i,int lst=0,bool zero=true,bool small=false)
{
	if(~now)return now;
	if(!i)return now=1ll;
	now=0ll;
	for(int j=0;j<=9;j++)if((zero||abs(j-lst)>=2)&&(small||j<=a[i]))
	{
		now+=dfs(i-1,j,zero&&!j,small||j^a[i]);
	}
	return now;
}

ll calc(ll x)
{
	fill(***mem,***mem+(N*N<<2),-1ll);
	int cnt=0;
	while(x)a[++cnt]=x%10ll,x/=10ll;
	return dfs(cnt);
}

int main()
{
	ll l,r;
	scanf("%lld %lld",&l,&r);
	printf("%lld",calc(r)-calc(l-1));
}
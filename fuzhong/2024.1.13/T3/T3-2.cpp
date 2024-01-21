#include <iostream>
#include <map>
#include <unordered_map>
#include <ctime>
using namespace std;

typedef long long ll;
typedef short sh;
#define ci constexpr int
// ci p2[]={1,0,1,0,2,0,1,0,3,0};
// ci p3[]={0,0,0,1,0,0,1,0,0,2};
// ci p5[]={1,0,0,0,0,1,0,0,0,0};
// ci p7[]={0,0,0,0,0,0,0,1,0,0};
ci N=20;

// ll qpow(ll base,sh pow){ll res=1;while(pow)(pow&1)&&(res*=base),base*=base,pow>>=1;return res;}

sh get(ll x)// O(1)~O(log x)
{
	ll tmp;
	while(x>9){tmp=1;while(x)tmp*=(x%10),x/=10;x=tmp;}
	return sh(x);
}

unordered_map<ll,ll> mem[2][2][N];
#define now mem[zero][small][i][mul]
// #define exi ~now
#define exi mem[zero][small][i].count(mul)
sh a[N];
ll cnt;
// zero,small : what to dfs, pre-mul:the result of dfs
ll dfs(sh d,sh i,ll mul=1,bool zero=true,bool small=false)
{
	if(exi)return cnt++,now;
	if(!i)return now=(d==get(mul)&&!zero)/* ,printf("*%lld*\n",now),now */;
	now=0;
	for(sh j=0;j<=9;j++)if(small||j<=a[i])
	{
		if(!zero||j)now+=dfs(d,i-1,mul*j,zero&&!j,small||j^a[i]);
		else now+=dfs(d,i-1,mul,zero&&!j,small||j^a[i]);
	}
	return now;
}

ll calc(ll x,sh d)
{
	if(!x)return !d;
	// printf("%lld",x);
	for(int i=0;i<N;i++)
	{
		mem[0][0][i].clear();
		mem[0][1][i].clear();
		mem[1][0][i].clear();
		mem[1][1][i].clear();
	}
	// fill(***mem,***mem+(N*60<<2),-1);
	sh cnt=0;
	while(x)a[++cnt]=x%10,x/=10;
	ll res=dfs(d,cnt);
	// printf(",%d:%lld\n",d,res);
	return res;
}

int main()
{
	clock_t beg=clock();
	freopen("draw.in","r",stdin);
	freopen("draw.out","w",stdout);
	int T;
	scanf("%d",&T);
	ll l,r;
	while(T--)
	{
		scanf("%lld %lld",&l,&r);
		for(sh d=0;d<=9;d++)printf("%lld%c",calc(r,d)-calc(l-1,d),(d==9?'\n':' '));
	}
	printf("*%lld*,%ldms",cnt,clock()-beg);
	return 0;
}

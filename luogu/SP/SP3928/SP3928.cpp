#include <iostream>
using namespace std;

typedef long long ll;
constexpr int LN=10;
ll l,r;

ll mem[LN][LN][2][2];

int a[LN];

#define now mem[i][sum][zero][small]
ll dfs(int i,int d,int sum=0,bool zero=true,bool small=false)
{
	if(!i)return now=sum;
	if(~now)return now;
	now=0;
	for(int j=0;j<=9;j++)if(small||j<=a[i])
	{
		now+=dfs(i-1,d,sum+(j==d&&(j||!zero)),zero&&!j,small||j^a[i]);
	}
	return now;
}

ll calc(ll r,int d)
{
	fill(***mem,***mem+(LN*LN<<2),-1ll);
	int cnt=0;
	while(r)
	{
		a[++cnt]=r%10ll;
		r/=10ll;
	}
	return dfs(cnt,d);
}

int main()
{
	while(true)
	{
		scanf("%lld %lld",&l,&r);
		if(!l&&!r)return 0;
		if(l>r)swap(l,r);
		for(int i=0;i<=9;i++)printf("%lld%c",calc(r,i)-calc(l-1,i),i^9?' ':'\n');
	}
	return 0;
}